/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 11:17:29 by barbare           #+#    #+#             */
/*   Updated: 2017/02/17 13:34:23 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "malloc.h"

//static t_block		*get_final_block(t_block *block)
//{
//	if (block->next == NULL)
//		return (block);
//	return (get_old_block(block->next));
//}
//
//static t_block		*create_block(t_associate ass, void *mem, MEMSIZE size)
//{
//	t_block		newblock;
//
//	newblock = (t_block) {FREE, size, NULL, mem};
//	if (ass.metadata.nblock == ass.metadata.c_nblocks) //TODO : nouvelle creation du metadata
//		ft_memcpy(blocks, &newblock, sizeof(t_block));
//	ft_memcpy(blocks, &newblock, sizeof(t_block));
//	return (blocks);
//}
//
//static void		*cutblock(t_metadata *data, t_block *block, MEMSIZE size)
//{
//	block->free = !FREE;
//	if (!block->next && (block->size - size) > 0)
//		block->next = new_block((void *)block + sizeof(t_block), block->mem + size, block->size - size);
//	block->size = size;
//	data->nblock--;
//	return (block->mem);
//}
//
//static t_metadata	*create_metadata(size_t size)
//{
//	void		*alloc_blocks;
//	t_metadata	nm;
//	size_t		maplen;
//
//	maplen = get_unit()->pagesize;
//	if (!(alloc_blocks = mmap(0, maplen, PROT, MAP, -1, 0)))
//		return (NULL);
//	maplen = (maplen - sizeof(t_metadata)) / (sizeof(t_block));
//	nm = (t_metadata) {.c_nblocks = maplen, .nblocks = maplen, .next = NULL};
//	ft_memcpy(mem, &nm, sizeof(t_metadata));
//	return (alloc_blocks);
//}
//
//t_associate		manage_block(t_associate ass, size_t size, t_type type)
//{
//	t_block	*block;
//	size_t	nsize;
//
//	block = ass.block;
//	if (block == NULL)
//	{
//		ass.metadata
//	}
//	{
//		nsize = block->size - size;
//		create_block(ass.metadata, nsize, block->mem + nsize);
//		block->size = size;
//	}
//	else
//		while (block)
//}
//
//t_associate		rec_block_assign(t_block *first, t_associate old, size_t size)
//{
//	if (first->size > size &&
//			(old.block == NULL || old.block->size > first->size))
//		old.block = first;
//	if (first->next != NULL)
//		return (rec_block(first->next, old, size));
//	else
//	{
//		if (old.metablock == NULL)
//			old.metablock = first;
//		return (old);
//	}
//}
//
//t_associate		rec_get_best_config(t_metadata *mdata, t_associate ass,
//										size_t size, t_type type)
//{
//	if (mdata && mdata->nblock > 0 &&
//			(!ass.metadata || ass.metadata->nblock > mdata->nblock))
//	{
//		ass.metadata = mdata;
//		ass.metablock = NULL;
//	}
//	if (mdata)
//		ass = rec_block_assign(mdata + sizeof(t_metadata), ass, size);
//	if (mdata && mdata->next != NULL)
//		return (rec_get_best_config(mdata->next, ass, size, type));
//	else
//	{
//		if (ass.metadata == NULL || ass.metadata->nblock <= 1)
//		{
//			if (mdata)
//				mdata->next = create_metadata();
//			else
//				mdata = create_metadata();
//			ass.metadata = mdata->next ?  mdata->next : mdata;
//			create_block(ass.metadata, NULL, 0);
//		}
//		return (manage_block(ass, size));
//	}
//}
//
//t_block			*get_block_assign(t_metadata *mdata, size_t size, t_type type)
//{
//	t_block		*newblock;
//	t_metadata	*md;
//	t_block		*block;
//	t_block		*res;
//
//	res == NULL;
//	md = NULL;
//	while(mdata)
//	{
//		block = mdata->typeblock[type];
//		while (block)
//		{
//			if (block->free == FREE && block->size > size &&
//					(res == NULL || res->size > block->size))
//				res = block;
//			if (block->next == NULL && mdata->nblock > 0 &&
//					(md == NULL || md->nblock > mdata->nblock))
//			{
//				md = mdata;
//				newblock = block;
//			}
//			block = block->next;
//		}
//		mdata = mdata->tmp;
//	}
//	if (res == NULL && md != NULL)
//		return (create_block(mdata));
//	return (res);
//}
//
//void			*get_zone(t_metadata **metadata, size_t size, t_type type)
//{
//	t_block		*block;
//	
//	if ((block = get_block_assign(*metadata, size, type)) == NULL)
//		block = create_meta(metadata);
//}
//
//void			*to_define_name(t_metadata **metadata, size_t size, int type)
//{
//	t_block		block_assign;
//	t_block		*tmp;
//	t_block		*old;
//	t_block		*smetadata;
//
//	smetadata = *metadata;
//	tmp = *metadata + sizeof(t_metadata);
//	old = NULL;
//	while (tmp)
//	{
//		if (tmp->size >= size && tmp->free == FREE)
//			return (cutblock(tmp, size));
//		old = tmp;
//		tmp = tmp->next;
//		if (tmp == NULL && *smetadata->next != NULL)
//		{
//			smetadata = smetadata->next;
//			tmp = *smetadata + sizeof(t_metadata);
//		}
//	}
//	smetadata = smetadata != NULL ? smetadata->next : *metadata;
//	smetadata = new_metadata();
//	block_assign = new_unitsmemory(type);
//	ft_memcpy(smetadata->next + sizeof(t_metadata), &block_assign, sizeof(t_block));
//	return (cutblock(*ass, size));
//}
