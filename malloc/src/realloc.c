/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:46:59 by barbare           #+#    #+#             */
/*   Updated: 2017/03/23 17:41:03 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "libft.h"

static t_block	*check_block(t_block *block, void *mem)
{
	if (block->mem == mem)
		return (block);
	else if (block->next)
		return (check_block(block->next, mem));
	else
		return (NULL);
}

static t_block	*get_block(t_metadata *md, void *mem)
{
	t_block		*blk;

	if ((blk = check_block((void *)md + sizeof(t_metadata), mem)) != NULL)
		return (blk);
	else if (md->next != NULL)
		return (get_block(md->next, mem));
	else
		return (NULL);
}

void		*realloc(void *mem, size_t size)
{
	t_block		*tmp;
	void		*newmalloc;

	if (!(tmp = get_block(get_unit()->tiny, mem)) &&
			!(tmp = get_block(get_unit()->small, mem)) &&
				!(tmp = get_block(get_unit()->big, mem)))
		return (NULL);
	if (tmp->size > size)
		return (tmp->mem);
	newmalloc = malloc(size);
	ft_memcpy(newmalloc, tmp->mem, tmp->size);
	free(tmp->mem);
	return (tmp);
}
