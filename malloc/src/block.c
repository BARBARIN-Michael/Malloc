/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 11:17:29 by barbare           #+#    #+#             */
/*   Updated: 2017/03/24 12:45:31 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "malloc.h"

t_return		set_blockdata(t_return ass, size_t size, t_type type)
{
	t_block		tmp;
	size_t		nsize;

	if (ass.block && !ass.block->mem)
	{
		tmp = create_memory(type, size);
		ass.block->mem = tmp.mem;
		ass.block->size = tmp.size;
	}
	else if (!ass.block)
	{
		ass.block = last_block(ass.freemeta);
		tmp = create_memory(type, size);
		ft_memcpy(ass.block, &tmp, SIZEOF_ALIGN(t_block));
	}
	nsize = size + MARGE(size);
	nsize = ass.block &&
		(ass.block->size >= size && (ass.block->size - size) > nsize) ?
		ass.block->size - size : 0;
	if (nsize > 0)
	{
		ass.block->size = size;
		create_block(ass.freemeta, ass.block->mem + ass.block->size, nsize);
	}
	return (ass);
}

t_block			*last_block(t_metadata *meta)
{
	t_block		*block;

	block = (void *)meta + SIZEOF_ALIGN(t_metadata);
	while (block->next)
		block = block->next;
	if (meta->c_nblocks - meta->nblocks > 0)
	{
		block->next = (void *)block + sizeof(t_block);
		--meta->nblocks;
		return (block->next);
	}
	--meta->nblocks;
	return (block);
}

t_block			*create_block(t_metadata *meta, void *mem, MEMSIZE size)
{
	t_block		*block;
	t_block		newblock;

	newblock = (t_block) {FREE, size, NULL, mem};
	block = last_block(meta);
	ft_memcpy(block, &newblock, SIZEOF_ALIGN(t_block));
	return (NULL);
}
