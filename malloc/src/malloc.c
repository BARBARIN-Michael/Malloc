/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:36:09 by barbare           #+#    #+#             */
/*   Updated: 2017/03/24 12:38:12 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //TO DEL
#include <unistd.h> //TO DEL
#include "libft.h"
#include "malloc.h"
#include <stdalign.h>


t_unit		*get_unit(void)
{
	static t_unit unit = { NULL, NULL, NULL, 0, PTHREAD_MUTEX_INITIALIZER};

	if (unit.pagesize == 0)
		unit.pagesize = (size_t)getpagesize();
	return (&unit);
}

void		*malloc(size_t size)
{
	size_t		align;
	void		*mem;

	pthread_mutex_lock(&(get_unit()->mutex));
	align = ALIGN4(size);
	if (align <= (size_t)(SMALL))
		mem = insert_malloc(&get_unit()->tiny, align, tiny);
	else if (align <= (size_t)(LARGE))
		mem = insert_malloc(&get_unit()->small, align, small);
	else
		mem = insert_malloc(&get_unit()->big, align, big);
	pthread_mutex_unlock(&(get_unit()->mutex));
	return (mem);
}
