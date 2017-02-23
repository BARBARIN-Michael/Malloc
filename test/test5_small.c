/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:47:57 by barbare           #+#    #+#             */
/*   Updated: 2017/02/18 17:00:51 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //TO DEL
#include "malloc.h"

#define VALUETINY 12000
#define NBMALLOC 5
#define DEBUG

int main(void)
{
	int		a;
	void *str[NBMALLOC + 1];

	a = NBMALLOC;
	while (--a > -1)
		str[a] = ft_malloc(VALUETINY);
	a = NBMALLOC;
	show_alloc_mem();
	ft_free(str[2]);
	dprintf(1, "realloc str[%d] = ", 2);
		dprintf(1, "%p\n", str[2]);
	str[2] = ft_malloc(3900);
	dprintf(1, "realloc str[%d] = ", 2);
		dprintf(1, "%p\n", str[2]);
	show_alloc_mem();
	dprintf(1, "C'est la fin des concombres de campagnile\n");
	printf("ZOOZ\n");
	return (0);
}
