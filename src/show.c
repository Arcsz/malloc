/*
** show.c for  in /home/baillyj
**
** Made by
** Login   <baillyj@epitech.net>
**
** Started on  Fri Jan 27 17:13:21 2017
** Last update Fri Jan 27 17:13:21 2017
*/

#include <stdio.h>
#include "malloc.h"

void		show_alloc_mem()
{
  t_node	*cur_ptr;

  printf("break : %p\n", sbrk(0));
  if (head)
    {
      cur_ptr = head;
      while (cur_ptr != get_block_at(last, last->size))
	{
	  if (!cur_ptr->is_free)
	    printf("%p - %p : %lu bytes\n",
		   cur_ptr + 1,
		   get_block_at(cur_ptr, cur_ptr->size),
		   cur_ptr->size);
	  cur_ptr = get_block_at(cur_ptr, cur_ptr->size);
	}
    }
}
