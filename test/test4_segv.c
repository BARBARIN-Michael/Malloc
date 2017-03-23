/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:47:57 by barbare           #+#    #+#             */
/*   Updated: 2017/03/22 15:40:17 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //TO DEL
#include "malloc.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define VALUETINY 4500
#define BUFFEROVERFLOW 7000
#define VALUEBIG	145000

#define NBMALLOC 300

static void rand_string(char str[], size_t size)
{
	static int test = 0;
	if (test && size >  VALUEBIG)
	{
		test = 1;
		dprintf(1, "test de str : %s\n", str);
	}
	const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJK...";
	dprintf(1, "Lecture de size : %zu\n", size);
	if (size) {
		--size;
		for (size_t n = 0; n < size; n++) {
			int key = rand() % (int) (sizeof charset - 1);
			str[n] = charset[key];
		}
		str[size] = '\0';
	}
}

int main(void)
{
	int		a;
	void	*str[NBMALLOC];
	int		b;

	srand(time(NULL) * 200);
	a = NBMALLOC;
	while (--a > -1)
	{
		b = rand() % 3;
		if (b == 1)
		{
			usleep(10);
			b = (rand() % BUFFEROVERFLOW) + VALUEBIG;
			str[a] = ft_malloc(b);
		}
		else
		{
			usleep(10);
			b = rand() % BUFFEROVERFLOW;
			str[a] = ft_malloc(b);
		}
		usleep(100);
		if (b > VALUEBIG)
			b = b - 1;
		else
			b = rand() % BUFFEROVERFLOW;
		rand_string(str[a], b);
		usleep(10);
	}
	a = 0;
	while (a < NBMALLOC)
	{
		dprintf(2, "On test str[%d] = ", a);
		dprintf(2, "%p = %s\n", str[a], (char *)str[a]);
		usleep(100);
		b = rand() % 2;
		if (b == 1)
			ft_free(str[a]);
		++a;
	}
	show_alloc_mem();
	return (0);
}
