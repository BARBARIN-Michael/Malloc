/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 11:18:40 by barbare           #+#    #+#             */
/*   Updated: 2017/03/23 17:35:23 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "malloc.h"

t_block		create_memory(t_type type, size_t size)
{
	t_block			block;
	size_t			maplen;

	if (type == tiny)
		maplen = REGION_TINY;
	else if (type == small)
		maplen = REGION_SMALL;
	else
	{
		maplen = getpagesize();
		maplen *= CEIL((size / (float)maplen));
	}
	block = (t_block) {FREE, maplen, NULL, NULL};
	if (!(block.mem = mmap(0, maplen, PROT, MAP, -1, 0)))
		return (BLOCK_EMPTY);
	block.size = maplen;
	return (block);
}
