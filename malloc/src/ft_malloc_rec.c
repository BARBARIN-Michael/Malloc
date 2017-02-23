/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 11:27:35 by barbare           #+#    #+#             */
/*   Updated: 2017/02/18 17:57:22 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "malloc.h"

static t_block		*last_block(t_metadata *meta)
{
	t_block		*block;

	if (meta->c_nblocks == meta->nblocks)
		return (NULL);
	block = (void *)meta + SIZEOF_ALIGN(t_metadata);
	while (block->next)
		block = block->next;
	return (block);
}

static t_block		*create_block(t_metadata *meta, void *mem, MEMSIZE size)
{
	t_block		*block;
	t_block		newblock;

	newblock = (t_block) {FREE, size, NULL, mem};
	block = last_block(meta);
	ft_memcpy(block ? block : (void *)meta + SIZEOF_ALIGN(t_metadata),
			&newblock, SIZEOF_ALIGN(t_block));
	--meta->nblocks;
	if (block)
		block->next = (void *)block + SIZEOF_ALIGN(t_block);
	return (block ? block : (void *)block + SIZEOF_ALIGN(t_block));
}

static t_metadata	*create_metadata(void)
{
	void		*mem;
	t_metadata	nm;
	size_t		maplen;

	maplen = getpagesize();
	if (!(mem = mmap(0, maplen, PROT, MAP, -1, 0)))
		return (NULL);
	maplen = (maplen - ALIGN4(SIZEOF_ALIGN(t_metadata)));
	maplen /= ALIGN4((SIZEOF_ALIGN(t_block)));
	maplen--;
	nm = (t_metadata) {.c_nblocks = maplen, .nblocks = maplen, .next = NULL};
	ft_memcpy(mem, &nm, SIZEOF_ALIGN(t_metadata));
	//dprintf(1, C_MAGENTA"Creation d'une metadata %p - metalen : %lu block : %lu maplen : %lu%s\n",
	//		mem, (SIZEOF_ALIGN(t_metadata)), ALIGN4((SIZEOF_ALIGN(t_block))), maplen, C_NONE);
	return (mem);
}

t_return		rec_block_assign(t_block *first, t_return old, size_t size)
{
	if (first->size > size && first->free == FREE &&
			(old.block == NULL || old.block->size > first->size))
		old.block = first;
	if (first->next != NULL)
		return (rec_block_assign(first->next, old, size));
	else
		return (old);
}

t_return		rec_get_best_config(t_metadata *mdata, t_return ass,
													size_t size, t_type type)
{
	if (mdata && mdata->nblocks > 0 &&
			(!ass.freemeta || ass.freemeta->nblocks > mdata->nblocks))
		ass.freemeta = mdata;
	if (mdata)
		ass = rec_block_assign((void *)mdata + SIZEOF_ALIGN(t_metadata), ass, size);
	if (mdata && mdata->next != NULL)
	{
		ass.lastmeta = mdata->next;
		return (rec_get_best_config(mdata->next, ass, size, type));
	}
	else
		return (ass);
}

t_return		set_config(t_return ass, size_t size, t_type type)
{
	t_metadata	*md;
	t_block		*block;
	size_t		nsize;

	md = NULL;
	nsize = MARGE(size);
	nsize = ass.block && (ass.block->size - size) > nsize ?
		ass.block->size - size : 0;
	if (!ass.lastmeta || (!ass.freemeta && (!ass.block || nsize > 0)))
	{
		md = create_metadata();
		((!ass.lastmeta) ? (ass.lastmeta = md) : (ass.lastmeta->next = md));
		if (!ass.freemeta)
			ass.freemeta = md;
	}
	if (!ass.block)
	{
		ass.block = last_block(ass.freemeta);
		if (ass.block)
			*((void *)ass.block + sizeof(t_block)) = create_memory(type, size);
		else
			ass.freemeta
				//TODO: deplacer sur le premier block (peut etre faire une fonction non?
	}
	ass.block->size = ass.block->size - nsize;
	if (nsize > 0)
		create_block(ass.freemeta, ass.block->mem + ass.block->size, nsize);
	return (ass);
}

void			*insert_malloc(t_metadata **mdata, size_t size, t_type type)
{
	t_return	ass;

	ass = (t_return) {.freemeta = NULL, .block = NULL, .lastmeta = *mdata};
	//dprintf(1, "On tente de recuperer une config freemeta + block\n");
	ass = rec_get_best_config(*mdata, ass, size, type);
	dprintf(1, "On a trouve : freemeta = %p freemeta->size = %d, \
			lastmeta = %p, block {%p - size : %lu - mem %p}\n",
			ass.freemeta,
			ass.freemeta ? ass.freemeta->nblocks : 0,
			ass.lastmeta,
			ass.block,
			ass.block ? ass.block->size : 0,
			ass.block ? ass.block->mem : NULL);
	ass = set_config(ass, size, type);
	if (!*mdata)
		*mdata = ass.lastmeta;
	ass.block->free = 0;
	return (ass.block->mem);
}
