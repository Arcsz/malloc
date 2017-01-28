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

  printf("break : %p\n", sbrk(0));
  cur_ptr = g_head;
  while (cur_ptr && cur_ptr != get_block_at(g_last, g_last->size))
    {
      if (!cur_ptr->is_free)
	printf("%p - %p : %lu bytes\n",
	       cur_ptr + 1,
	       get_block_at(cur_ptr, cur_ptr->size),
	       cur_ptr->size);
      cur_ptr = get_block_at(cur_ptr, cur_ptr->size);
    }
}
