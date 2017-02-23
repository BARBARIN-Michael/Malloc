/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:47:57 by barbare           #+#    #+#             */
/*   Updated: 2017/02/18 13:26:46 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //TO DEL
#include "malloc.h"

#define VALUETINY 3

int main(void)
{
	int		a;
	void *str[255];

	a = 255;
	while (--a > -1)
	{
		str[a] = ft_malloc(VALUETINY);
		dprintf(1, "Malloc de str[%d] %d / 255 execute\n", a, a);
		show_alloc_mem();
	}
	dprintf(1, "C'est la fin des haricots verts !\n");
	a = 255;
	while (--a > -1)
	{
		dprintf(1, "On test str[%d] = ", a);
		dprintf(1, "%p\n", str[a]);
	}
	dprintf(1, "C'est la fin des concombres de campagnile\n");
	return (0);
}
