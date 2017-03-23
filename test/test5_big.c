/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:47:57 by barbare           #+#    #+#             */
/*   Updated: 2017/03/22 14:19:47 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //TO DEL
#include "malloc.h"

#define VALUEBIG 145000
#define NBMALLOC 5
#define DEBUG

int main(void)
{
	void *str;

	str = ft_malloc(VALUEBIG);
	show_alloc_mem();
	ft_free(str);
	//show_alloc_mem();
	return (0);
}
