/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:47:57 by barbare           #+#    #+#             */
/*   Updated: 2017/03/17 16:07:16 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //TO DEL
#include "malloc.h"

int main(void)
{
	void *str[5];
	void *realloc;

	str[0] = ft_malloc(2);
	str[1] = ft_malloc(2);
	show_alloc_mem();
	ft_free(str[0]);
	show_alloc_mem();
	realloc = ft_malloc(3);
	dprintf(1, "Creation d'un realloc : %p\n", realloc);
	show_alloc_mem();
	return (0);
}
