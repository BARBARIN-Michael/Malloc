/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 11:17:29 by barbare           #+#    #+#             */
/*   Updated: 2017/02/13 11:18:21 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../inc/malloc.h"

void		*cutblock(t_block *block, MEMSIZE size)
{
	block->free = !FREE;
	block->next = new_block(block, block->mem + size, block->size - size);
	block->size = size;
	return (block->mem);
}

t_block		*new_block(void *blocks, void *mem, MEMSIZE size)
{
	t_block		newblock;

	newblock = (t_block) {FREE, size, NULL, mem};
	ft_memcpy(blocks, &newblock, sizeof(t_block));
	return (blocks);
}

t_block		*new_unitsblock(t_block *block)
{
	void		*alloc_block;
	size_t		maplen;

	maplen = GET_ALIGN(sizeof(t_block) * get_unit().pagesize * UNITS);
	alloc_block = mmap(0, maplen, PROT, MAP, -1, 0);
	if (block)
		block->next = new_block(alloc_block, NULL, 0);
	else
		block = new_block(alloc_block, NULL, 0);
	return (block);
}

void		*get_freeblock(t_block **block, size_t size, int type)
{
	size_t		maplen;
	t_block		*tmp;
	t_block		*old;

	tmp = *block;
	maplen = GET_ALIGN(size * get_unit().pagesize);
	while (tmp)
	{
		if (tmp->size >= size && tmp->free == FREE)
			return (cutblock(tmp, maplen));
		old = tmp;
		tmp = tmp->next;
	}
	if (!block || !tmp)
	{
		tmp = new_unitsblock(*block ? old : *block);
		if (tmp)
			tmp = new_unitsmemory(tmp, type);
	}
	return (cutblock(tmp, maplen));
}

