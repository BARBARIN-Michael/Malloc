/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:37:14 by barbare           #+#    #+#             */
/*   Updated: 2017/02/13 11:35:37 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <stdlib.h>
# include <sys/mman.h>

# define FREE	1
# define TINY	sizeof(void *)
# define SMALL	1024
# define BIG	4096
# define UNITS	100
# define PROT	PROT_READ | PROT_WRITE
# define MAP	MAP_PRIVATE | MAP_ANONYMOUS

# define NBADDR 1024

# define GET_ALIGN(X) (((((X) - 1) >> 2) << 2) + 4)
# define MEMSIZE	size_t

typedef struct s_unit	t_unit;
typedef struct s_block	t_block;

struct					s_unit
{
	t_block				*tiny;
	t_block				*small;
	t_block				*big;
	int					pagesize;
};

struct					s_block
{
	int		free;
	size_t	size;
	void	*next;
	void	*mem;
};

void				show_alloc_mem();

void				ft_free(void *ptr);
void 				*ft_malloc(size_t size);
//void 				*ft_realloc(void *ptr, size_t size);

void				*ft_tinymalloc(size_t size);
void				*ft_smallmalloc(size_t size);
void				*ft_bigmalloc(size_t size);

t_unit				get_unit(void);

void				*cutblock(t_block *block, MEMSIZE size);
t_block				*new_block(void *blocks, void *mem, MEMSIZE size);
t_block				*new_unitsblock(t_block *block);
t_block				*new_unitsmemory(t_block *block, int type);
void				*get_freeblock(t_block **block, size_t size, int type);
void				*ft_tinymalloc(size_t size);

#endif
