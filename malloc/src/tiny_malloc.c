/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:51:06 by barbare           #+#    #+#             */
/*   Updated: 2017/02/13 11:40:21 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../inc/malloc.h"

void		show_alloc_mem()
{
	t_block		*block;

	block = get_unit().tiny;
	ft_putstr("TINY :");
	ft_putstr(ft_ntoa(TINY, "0123456789ABCDEF"));
	ft_putendl("");
	while (block)
	{
		ft_putstr(ft_ntoa((uintmax_t)block->mem, "0123456789ABCDEF"));
		ft_putstr(" - ");
		ft_putendl(ft_ntoa((uintmax_t)(block->mem + block->size), "0123456789ABCDEF"));
		block = block->next;
	}
}

void		*ft_tinymalloc(size_t size)
{
	t_block *block;

	block = get_unit().tiny;
	return (get_freeblock(&block, size, TINY));
}
