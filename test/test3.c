/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:47:57 by barbare           #+#    #+#             */
/*   Updated: 2017/02/14 13:53:03 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //TO DEL
#include "malloc.h"

int main(void)
{
	void *str[5];
	void *realloc;

	str[0] = ft_malloc(2);
	str[1] = ft_malloc(3);
	str[2] = ft_malloc(3);
	str[3] = ft_malloc(3);
	str[4] = ft_malloc(3);
	show_alloc_mem();
	ft_free(str[0]);
	show_alloc_mem();
	ft_free(str[1]);
	show_alloc_mem();
	realloc = ft_malloc(3);
	dprintf(1, "Creation d'un realloc : %p\n", realloc);
	ft_free(str[2]);
	show_alloc_mem();
	ft_free(str[3]);
	show_alloc_mem();
	ft_free(str[4]);
	show_alloc_mem();
	return (0);
}
