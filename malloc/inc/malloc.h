/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:37:14 by barbare           #+#    #+#             */
/*   Updated: 2017/03/24 13:11:36 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <stdlib.h>
# include <sys/mman.h>
# include <stdalign.h>
# include <pthread.h>

# define LENGTH_MB 8388608

# if __LP64__
#  define SMALL 992
#  define LARGE 125000
#  define REGION_TINY LENGTH_MB * 2
#  define REGION_SMALL LENGTH_MB * 16
# else
#  define SMALL 496
#  define LARGE 15000
#  define REGION_TINY LENGTH_MB
#  define REGION_SMALL LENGTH_MB * 8
# endif

# define BASE16 "0123456789ABCDEF"

# define FREE	1
# define UNITS	100
# define PROT	PROT_READ | PROT_WRITE
# define MAP	MAP_PRIVATE | MAP_ANONYMOUS
# define MARGE(X) (((X) * 25) / 100)

# define NBADDR 1024

# define CEIL(X) ((X - (int)(X)) > 0 ? (int)(X + 1) : (int)(X))
# define ALIGN4(X) (((((X) - 1) >> 2) << 2) + 4)
# define MEMSIZE	size_t
# define SIZEOF_ALIGN(X) (ALIGN4(sizeof(X)))
# define BLOCK_EMPTY (t_block) {.mem = NULL}

typedef struct s_unit		t_unit;
typedef struct s_block		t_block;
typedef struct s_metadata	t_metadata;
typedef struct s_return		t_return;
typedef enum e_type			t_type;

enum				e_type
{
	tiny = 0,
	small = 1,
	big = 2
};

struct				s_return
{
	t_metadata		*freemeta;
	t_metadata		*lastmeta;
	t_block			*block;
};

struct				s_unit
{
	t_metadata		*tiny;
	t_metadata		*small;
	t_metadata		*big;
	int				pagesize;
	pthread_mutex_t	mutex;
};

struct				s_metadata
{
	int				c_nblocks;
	int				nblocks;
	t_metadata		*next;
};

struct				s_block
{
	int				free;
	size_t			size;
	t_block			*next;
	void			*mem;
};

extern void			show_alloc_mem();
extern void			free(void *ptr);
extern void			*malloc(size_t size);
extern void			*realloc(void *ptr, size_t size);

/*
** Global
*/

t_unit				*get_unit(void);

/*
** ft_malloc_rec.c
** search function
*/

t_return			rec_block_assign(t_block *first, t_return old, size_t size);
t_return			rec_get_best_config(t_metadata *mdata, t_return ass,
										size_t size, t_type type);
t_return			set_config(t_return ass, size_t size, t_type type);
void				*insert_malloc(t_metadata **md, size_t size, t_type type);

/*
** memory.c
*/

t_block				create_memory(t_type type, size_t size);

/*
** metadata.c
*/

t_metadata			*create_metadata(void);
t_return			set_metadata(t_return ass, size_t size);

/*
** block.c
*/

t_return			set_blockdata(t_return ass, size_t size, t_type type);
t_block				*last_block(t_metadata *meta);
t_block				*create_block(t_metadata *meta, void *mem, MEMSIZE size);

/*
** print_memory.c
*/
void				print_block(t_block *blk, const char *type);
void				print_ptr(uintmax_t hex);

#endif
