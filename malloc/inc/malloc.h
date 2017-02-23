/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:37:14 by barbare           #+#    #+#             */
/*   Updated: 2017/02/18 17:20:52 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <stdio.h> //TODO : a del
# include <stdlib.h>
# include <sys/mman.h>
# include <stdalign.h>

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

# define CEIL(X) ((int)X)
# define ALIGN4(X) (((((X) - 1) >> 2) << 2) + 4)
# define MEMSIZE	size_t
# define SIZEOF_ALIGN(X) (ALIGN4(sizeof(X)))

typedef struct s_unit		t_unit;
typedef struct s_block		t_block;
typedef struct s_metadata	t_metadata;
typedef struct s_return		t_return;
typedef enum e_type			t_type;

enum					e_type
{
	tiny = 0,
	small = 1,
	big = 2
};

struct					s_return
{
	t_metadata			*freemeta;
	t_metadata			*lastmeta;
	t_block				*block;
};

struct					s_unit
{
	t_metadata			*tiny;
	t_metadata			*small;
	t_metadata			*big;
	int					pagesize;
};

struct					s_metadata
{
	int					c_nblocks;
	int					nblocks;
	t_metadata			*next;
};

struct					s_block
{
	int					free;
	size_t				size;
	t_block				*next;
	void				*mem;
};

extern void			show_alloc_mem();

extern void			ft_free(void *ptr);
extern void 		*ft_malloc(size_t size);
extern void 		*realloc(void *ptr, size_t size);

void				*ft_tinymalloc(size_t size);
void				*ft_smallmalloc(size_t size);
void				*ft_bigmalloc(size_t size);

t_unit				*get_unit(void);

t_block				new_unitsmemory(int type);
void				*get_zone(t_block **block, size_t size, int type);

t_return			rec_block_assign(t_block *first, t_return old, size_t size);
t_return			rec_get_best_config(t_metadata *mdata, t_return ass,
										size_t size, t_type type);
t_block				create_memory(t_type type, size_t size);
t_return			set_config(t_return ass, size_t size, t_type type);
void				*insert_malloc(t_metadata **md, size_t size, t_type type);

#endif
