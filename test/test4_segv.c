/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:47:57 by barbare           #+#    #+#             */
/*   Updated: 2017/02/23 13:54:59 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //TO DEL
#include "malloc.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define VALUETINY 450
#define BUFFEROVERFLOW 550

#define NBMALLOC 10

static void rand_string(char str[], size_t size)
{
	const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJK...";
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
	char	buf[BUFFEROVERFLOW];
	int		b;

	srand(time(NULL) * 200);
	a = NBMALLOC;
	while (--a > -1)
	{
		str[a] = malloc(VALUETINY);
		b = rand() % BUFFEROVERFLOW;
		rand_string(buf, b);
		snprintf(str[a], b, "%s", buf);
		usleep(10);
	}
	a = 0;
	while (a < NBMALLOC)
	{
		dprintf(1, "On test str[%d] = ", a);
		dprintf(1, "%p = %s\n", str[a], str[a]);
		free(str[a]);
		++a;
	}
	return (0);
}
