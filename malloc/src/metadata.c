/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metadata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:32:48 by barbare           #+#    #+#             */
/*   Updated: 2017/03/23 17:37:45 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "malloc.h"

t_metadata		*create_metadata(void)
{
	void		*mem;
	t_metadata	nm;
	size_t		maplen;

	maplen = getpagesize();
	if (!(mem = mmap(0, maplen, PROT, MAP, -1, 0)))
		return (NULL);
	maplen = (maplen - ALIGN4(SIZEOF_ALIGN(t_metadata)));
	maplen /= ALIGN4((SIZEOF_ALIGN(t_block)));
	maplen--;
	nm = (t_metadata) {.c_nblocks = maplen, .nblocks = maplen, .next = NULL};
	ft_memcpy(mem, &nm, SIZEOF_ALIGN(t_metadata));
	return (mem);
}

t_return		set_metadata(t_return ass, size_t size)
{
	t_metadata	*md;
	size_t		nsize;

	md = NULL;
	//On recupere la taille en trop dans le block
	nsize = size + MARGE(size);
	nsize = ass.block && (ass.block->size - size) > nsize ?
		ass.block->size - size : 0;
	//On doit recreer un metadata car trop plein????
	if (!ass.lastmeta || (!ass.freemeta && (!ass.block || nsize > 0)))
	{
		md = create_metadata();
		((!ass.lastmeta) ? (ass.lastmeta = md) : (ass.lastmeta->next = md));
		if (!ass.freemeta)
			ass.freemeta = md;
	}
	return (ass);
}
