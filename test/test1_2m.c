/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:47:57 by barbare           #+#    #+#             */
/*   Updated: 2017/02/18 12:50:53 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h> //TO DEL
#include "malloc.h"

int main(void)
{
	char *str[2];

	str[0] = ft_malloc(2);
	show_alloc_mem();
	dprintf(1, "Fin du test : %p", str);
	return (0);
}
