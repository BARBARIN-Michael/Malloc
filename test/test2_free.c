/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:47:57 by barbare           #+#    #+#             */
/*   Updated: 2017/02/18 13:04:27 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //TO DEL
#include "malloc.h"

int main(void)
{
	void *test;
	void *test2;
	void *str[5];

	str[0] = ft_malloc(2);
	test = ft_malloc(2);
	test2 = malloc(3);
	dprintf(1, "\tTest void * : %p\n", test);
	dprintf(1, "\tTest void * with malloc : %p\n", test2);
	str[1] = ft_malloc(3);
	str[2] = ft_malloc(3);
	str[3] = ft_malloc(3);
	str[4] = ft_malloc(3);
	show_alloc_mem();
	dprintf(1, "On cherche a free %p\n", str[0]);
	ft_free(str[0]);
	show_alloc_mem();
	dprintf(1, "On cherche a free %p\n", str[1]);
	ft_free(str[1]);
	show_alloc_mem();
	dprintf(1, "On cherche a free %p\n", str[2]);
	ft_free(str[2]);
	show_alloc_mem();
	dprintf(1, "On cherche a free %p\n", str[3]);
	ft_free(str[3]);
	show_alloc_mem();
	dprintf(1, "On cherche a free %p\n", str[4]);
	ft_free(str[4]);
	show_alloc_mem();
	return (0);
}
