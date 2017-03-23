/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 11:27:35 by barbare           #+#    #+#             */
/*   Updated: 2017/03/23 17:37:29 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "malloc.h"

t_return		rec_block_assign(t_block *first, t_return old, size_t size)
{
	if (first->size >= size && first->free == FREE &&
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
	ass.lastmeta = mdata;
	if (mdata && mdata->nblocks > 0 &&
			(!ass.freemeta || ass.freemeta->nblocks > mdata->nblocks))
		ass.freemeta = mdata;
	if (mdata)
		ass = rec_block_assign((void *)mdata + SIZEOF_ALIGN(t_metadata), ass, size);
	if (mdata && mdata->next != NULL)
		return (rec_get_best_config(mdata->next, ass, size, type));
	else
		return (ass);
}

t_return		set_config(t_return ass, size_t size, t_type type)
{
	ass = set_metadata(ass, size);
	ass = set_blockdata(ass, size, type);
	return (ass);
}

void			*insert_malloc(t_metadata **mdata, size_t size, t_type type)
{
	t_return	ass;

	ass = (t_return) {.freemeta = NULL, .block = NULL, .lastmeta = *mdata};
	ass = rec_get_best_config(*mdata, ass, size, type);
	ass = set_config(ass, size, type);
	if (!*mdata)
		*mdata = ass.lastmeta;
	ass.block->free = 0;
	return (ass.block->mem);
}
