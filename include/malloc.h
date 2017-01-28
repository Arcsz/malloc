/*
** malloc.h for malloc in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Jan 24 21:09:27 2017 David Zeng
** Last update Tue Jan 24 21:09:27 2017 David Zeng
*/

#ifndef MALLOC_H_
# define MALLOC_H_

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <pthread.h>

# define HEADER_SIZE sizeof(t_node)
# define SBRK_FAILED (void*)-1
# define MIN_BLOCK_SIZE 1
# define PAGE_NUMBER 32
# define PAGE_MAX 64

typedef struct		s_node
{
  size_t		size;
  struct s_node		*next;
  struct s_node		*prev;
  bool			is_free;
}			t_node;

extern pthread_mutex_t	g_lock;
extern t_node		*g_free_blocks;
extern t_node		*g_head;
extern t_node		*g_last;

void			show_alloc_mem();
t_node			*ptr_to_block(void *ptr);
t_node			*get_block_at(t_node *block, size_t size);

#endif /* !MALLOC_H_ */
