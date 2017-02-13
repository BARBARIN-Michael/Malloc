/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 11:18:40 by barbare           #+#    #+#             */
/*   Updated: 2017/02/13 11:21:25 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../inc/malloc.h"

t_block		*new_unitsmemory(t_block *block, int type)
{
	void		*mem;
	size_t		maplen;

	maplen = GET_ALIGN(type * get_unit().pagesize * UNITS);
	mem = mmap(0, maplen, PROT, MAP, -1, 0);
	block->mem = mem;
	block->size = GET_ALIGN(type * get_unit().pagesize * UNITS);
	return (block);
}

