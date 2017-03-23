/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:47:57 by barbare           #+#    #+#             */
/*   Updated: 2017/03/22 18:11:15 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h> //TO DEL
#include "malloc.h"

int main(void)
{
	char *str;

	str = ft_malloc(19);
	show_alloc_mem();
	snprintf(str, 5, "%s", "toto\0");
	dprintf(1, "%s\n", str);
	str = ft_realloc(str, 255);
	show_alloc_mem();
	dprintf(1, "%s\n", str);
	dprintf(1, "Fin du test : %p", str);
	return (0);
}
