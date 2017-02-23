/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:47:57 by barbare           #+#    #+#             */
/*   Updated: 2017/02/18 16:16:06 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //TO DEL
#include "malloc.h"

#define VALUETINY 450
#define NBMALLOC 10000

int main(void)
{
	int		a;
	void *str[NBMALLOC];

	a = NBMALLOC;
	while (--a > -1)
	{
		str[a] = ft_malloc(VALUETINY);
		dprintf(1, "Malloc de str[%d] %d / %d \
	executeexecute\n", a, a, NBMALLOC);
	}
	show_alloc_mem();
	dprintf(1, "C'est la fin des haricots verts !\n");
	a = NBMALLOC;
	while (--a > -1)
	{
		dprintf(1, "On test str[%d] = ", a);
		dprintf(1, "%p\n", str[a]);
	}
	dprintf(1, "C'est la fin des concombres de campagnile\n");
	printf("ZOOZ\n");
	return (0);
}
