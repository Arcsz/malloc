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
  void		*break_ptr;
  void		*cur_ptr;
  void		*start_block;
  unsigned int	cur_size;

  break_ptr = sbrk(0);
  printf("break : %p\n", break_ptr);
  if (head)
    {
      cur_ptr = head;
      while (cur_ptr != last)
	{
	  cur_size = ((t_node *)cur_ptr)->size;
	  if (!((t_node *)cur_ptr)->is_free)
	    {
	      cur_ptr = (t_node *)cur_ptr + 1;
	      start_block = cur_ptr;
	      cur_ptr = (char *)cur_ptr + cur_size;
	      printf("%p - %p : %u bytes\n", start_block, cur_ptr, cur_size);
	    }
	  else
	    {
	      cur_ptr = (t_node *)cur_ptr + 1;
	      cur_ptr = (char *)cur_ptr + cur_size;
	    }
	}
    }
}
