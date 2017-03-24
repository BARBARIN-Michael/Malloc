/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:46:59 by barbare           #+#    #+#             */
/*   Updated: 2017/03/24 15:03:36 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "libft.h"

static t_block	*check_block(t_block *block, void *mem)
{
	if (block == NULL)
		return (NULL);
	if (block->mem == mem)
		return (block);
	return (check_block(block->next, mem));
}

static t_block	*get_block(t_metadata *md, void *mem)
{
	t_block		*blk;

	if (md == NULL)
		return (NULL);
	if ((blk = check_block((void *)md + sizeof(t_metadata), mem)) != NULL)
		return (blk);
	return (get_block(md->next, mem));
}

void			*realloc(void *mem, size_t size)
{
	t_block		*tmp;
	void		*newmalloc;

	if (!mem)
	{
		newmalloc = malloc(size);
		return (newmalloc);
	}
	pthread_mutex_lock(&(get_unit()->mutex));
	if (!(tmp = get_block(get_unit()->tiny, mem)) &&
			!(tmp = get_block(get_unit()->small, mem)) &&
				!(tmp = get_block(get_unit()->big, mem)))
	{
		pthread_mutex_unlock(&(get_unit()->mutex));
		return (NULL);
	}
	pthread_mutex_unlock(&(get_unit()->mutex));
	if (tmp->size > size)
	{
		return (tmp->mem);
	}
	newmalloc = malloc(size);
	ft_memcpy(newmalloc, tmp->mem, tmp->size);
	free(tmp->mem);
	return (newmalloc);
}
