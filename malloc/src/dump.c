/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:16:53 by mbarbari          #+#    #+#             */
/*   Updated: 2017/03/24 14:48:41 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "malloc.h"

static void		print_hex(uintmax_t hex, char *base)
{
	int		cmp;
	char	str[3];
	int		len;

	cmp = 0;
	len = ft_strlen(base);
	cmp = 2;
	str[cmp--] = '\0';
	while (cmp >= 0)
	{
		str[cmp--] = base[(hex % len)];
		hex /= len;
	}
	write(1, str, 2);
}

static void		print_memory(uint8_t *memory, size_t size)
{
	size_t		i;
	int32_t		a;

	i = 0;
	while (i < size)
	{
		a = 0;
		if (i > 0 && (i % 32) == 0)
			write(1, "\n", 1);
		print_hex((uintmax_t)(memory[i]), BASE16);
		++i;
		write(1, " ", 1);
	}
	ft_putendl("\n");
}

static void		rec_block_read(t_block *block, void *mem)
{
	if (block == NULL)
		return ;
	if ((mem == NULL || mem == block->mem) && block->free != FREE)
	{
		ft_putstr("DUMP MEMORY :");
		print_ptr((uintmax_t)block->mem);
		ft_putendl("");
		print_memory(block->mem, block->size);
	}
	return (rec_block_read(block->next, mem));
}

static void		read_by_meta(t_metadata *meta, void *mem)
{
	while (meta)
	{
		rec_block_read((void *)meta + sizeof(t_metadata), mem);
		meta = meta->next;
	}
}

void			dump_memory(char *mem)
{
	pthread_mutex_lock(&(get_unit()->mutex));
	read_by_meta(get_unit()->tiny, mem);
	read_by_meta(get_unit()->small, mem);
	read_by_meta(get_unit()->big, mem);
	pthread_mutex_unlock(&(get_unit()->mutex));
}
