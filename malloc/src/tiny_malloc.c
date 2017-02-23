/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:51:06 by barbare           #+#    #+#             */
/*   Updated: 2017/02/18 16:29:33 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "malloc.h"

void		print_ntoa(uintmax_t hex, char *base)
{
	int			cmp;
	uintmax_t	x;
	int			len;
	char		addr[20];

	cmp = 0;
	x = hex;
	if ((len = ft_strlen(base)) <= 1)
		ft_putstr ("( NULL )");
	if (hex == 0)
		ft_putstr("0");
	while (x > 0)
	{
		x /= len;
		cmp++;
	}
	addr[cmp] = '\0';
	while (--cmp >= 0)
	{
		addr[cmp] = base[(hex % len)];
		hex /= len;
	}
	write(1, &addr[cmp + 1], ft_strlen(&addr[cmp + 1]));
}

void		rec_block_read(t_block *block)
{
	if (block->next != NULL)
	{
		//print_ntoa((unsigned long)block->mem, BASE16);
		dprintf(1, C_CYAN"block : %p - mem : %p - size : %lu - free : %d - next : %p%s\n", block, block->mem, block->size, block->free, block->next, C_NONE);
		return (rec_block_read(block->next));
	}
}

void		show_alloc_mem()
{
	t_metadata		*meta;

	meta = get_unit()->tiny;
	ft_putendl("\n\t\t============ SHOW ALLOC MEM =============");
	while (meta)
	{
		rec_block_read((void *)meta + sizeof(t_metadata));
		meta = meta->next;
	}
	meta = get_unit()->small;
	while (meta)
	{
		rec_block_read((void *)meta + sizeof(t_metadata));
		meta = meta->next;
	}
	meta = get_unit()->big;
	while (meta)
	{
		rec_block_read((void *)meta + sizeof(t_metadata));
		meta = meta->next;
	}
}
