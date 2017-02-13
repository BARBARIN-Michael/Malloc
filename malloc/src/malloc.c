/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:36:09 by barbare           #+#    #+#             */
/*   Updated: 2017/02/10 18:06:54 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //TO DEL
#include <unistd.h> //TO DEL
#include "../inc/malloc.h"

t_unit		get_unit(void)
{
	static t_unit unit = { NULL, NULL, NULL, 0 };

	if (unit.pagesize == 0)
		unit.pagesize = (size_t)getpagesize();
	return (unit);
}

void		test_getpagesize(void)
{
	dprintf(1, "getpagesize : %d\n", get_unit().pagesize);
}

void		*ft_malloc(size_t size)
{
	size_t		align;

	align = GET_ALIGN(size);
	test_getpagesize();
	if (align <= (size_t)(TINY * get_unit().pagesize))
		return (ft_tinymalloc(align));
	else if (align <= (size_t)(SMALL * get_unit().pagesize))
		return (/*ft_smallmalloc(align)*/NULL);
	else
		return (/*ft_bigmalloc(align)*/NULL);
}
