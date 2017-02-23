/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 12:57:39 by barbare           #+#    #+#             */
/*   Updated: 2017/02/18 16:36:19 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "malloc.h"

static int	check_block(t_block *block, void *mem)
{
	if (block->mem == mem)
	{
		block->free = FREE;
		return (TRUE);
	}
	else if (block->next)
		return (check_block(block->next, mem));
	else
		return (FALSE);
}

static int	check_free(t_metadata *md, void *mem)
{
	if (check_block((void *)md + sizeof(t_metadata), mem) == TRUE)
		return (TRUE);
	else if (md->next != NULL)
		return (check_free(md->next, mem));
	else
		return (FALSE);
}

void		ft_free(void *mem)
{
	dprintf(1, "Tentative de free de la mem %p\n", mem);
	if ((get_unit()->tiny && check_free(get_unit()->tiny, mem)) ||
			(get_unit()->small && check_free(get_unit()->small, mem)) ||
				(get_unit()->big && check_free(get_unit()->big, mem)))
		return ;
}

