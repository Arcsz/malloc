/*
** utils.c for utils in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Jan 26 10:49:07 2017 David Zeng
** Last update Thu Jan 26 10:49:07 2017 David Zeng
*/

#include <stdio.h>
#include "malloc.h"

size_t	next_pow2(size_t size)
{
  --size;
  size |= size >> 1;
  size |= size >> 2;
  size |= size >> 4;
  size |= size >> 8;
  size |= size >> 16;
  ++size;
  return (size);
}

t_node	*ptr_to_block(void *ptr)
{
  return ((t_node*)ptr - 1);
}

t_node	*get_block_at(t_node *block, size_t size)
{
  return ((t_node*)((char*)(block + 1) + size));
}

void		show_alloc_mem()
{
  t_node	*cur_ptr;
  t_node	*free_node;

  printf("break : %p\n", sbrk(0));
  cur_ptr = g_head;
  free_node = g_free_blocks;
  while (cur_ptr && cur_ptr < get_block_at(g_last, g_last->size))
    {
      if (cur_ptr != free_node)
	printf("%p - %p : %lu bytes\n", cur_ptr + 1,
	       get_block_at(cur_ptr, cur_ptr->size), cur_ptr->size);
      else
	free_node = free_node->next;
      cur_ptr = get_block_at(cur_ptr, cur_ptr->size);
    }
}
