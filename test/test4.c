/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:47:57 by barbare           #+#    #+#             */
/*   Updated: 2017/03/17 16:24:01 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //TO DEL
#include "malloc.h"

#define VALUETINY 3

int main(void)
{
	int		i;
	int		a;
	void *str[255];

	i = 6;
	a = 255;
	while (a > 0)
	{
		i = 6;
		while (--i > 0 && a > 0)
			str[--a] = ft_malloc(VALUETINY);
		dprintf(2, "Malloc de %d / 255 execute\n", a);
	}
	dprintf(2, "\n\nC'est la fin des haricots verts !\n");
	show_alloc_mem();
	a = 255;
	while (--a > -1)
		dprintf(2, "%p\n", str[a]);
	return (0);
}
