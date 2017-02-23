/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:36:09 by barbare           #+#    #+#             */
/*   Updated: 2017/02/18 16:47:56 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //TO DEL
#include <unistd.h> //TO DEL
#include "libft.h"
#include "malloc.h"
#include <stdalign.h>

t_unit		*get_unit(void)
{
	static t_unit unit = { NULL, NULL, NULL, 0 };

	if (unit.pagesize == 0)
		unit.pagesize = (size_t)getpagesize();
	return (&unit);
}

void		*ft_malloc(size_t size)
{
	size_t		align;

	align = ALIGN4(size);
//	dprintf(1, "On rentre dans Malloc\n");
	if (align <= (size_t)(SMALL))
		return (insert_malloc(&get_unit()->tiny, align, tiny));
	else if (align <= (size_t)(LARGE))
		return (insert_malloc(&get_unit()->small, align, small));
	else
		return (insert_malloc(&get_unit()->big, align, big));
}
