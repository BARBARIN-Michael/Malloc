/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:47:57 by barbare           #+#    #+#             */
/*   Updated: 2017/02/13 11:16:43 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <unistd.h> //TO DEL

int main(void)
{
	char *str;

	if ((str = malloc(20)) == NULL)
		write(1, "STR IS NULL\n", 23);
	else
		write(1, "STR IS NOT NULL\n", 25);
	return (0);
}
