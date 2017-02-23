/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:47:57 by barbare           #+#    #+#             */
/*   Updated: 2017/02/14 16:40:30 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //TO DEL
#include "malloc.h"

#define VALUETINY 3

int main(void)
{
	int		i;
	int		a;
	void *str[4097];

	i = 6;
	a = 4096;
	while (a > 0)
	{
		i = 6;
		while (--i > 0 && a > 0)
			str[--a] = ft_malloc(VALUETINY);
		dprintf(1, "Malloc de %d / 4096 execute\n", a);
	}
	dprintf(1, "C'est la fin des haricots verts !\n");
	a = 4096;
	while (--a > -1)
		dprintf(1, "%p\n", str[a]);
	return (0);
}
