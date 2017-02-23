/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:47:57 by barbare           #+#    #+#             */
/*   Updated: 2017/02/14 13:58:48 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //TO DEL
#include "malloc.h"

int main(void)
{
	int		i;
	char	*str[5];

	i = 5;
	str[0] = ft_malloc(2);
	str[1] = ft_malloc(3);
	str[2] = ft_malloc(3);
	str[3] = ft_malloc(3);
	str[4] = ft_malloc(3);
	show_alloc_mem();
	while (i-- < 4)
		dprintf(1, "%p ", str[i]);
	dprintf(1, "\n");
	return (0);
}
