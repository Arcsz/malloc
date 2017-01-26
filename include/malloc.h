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
# include <assert.h>

# define HEADER_SIZE sizeof(t_node)
# define SBRK_FAILED (void*)-1
# define MIN_BLOCK_SIZE 128
# define PAGE_NUMBER 32

typedef struct		s_node
{
  size_t		size;
  bool			is_free;
  struct s_node		*next;
  struct s_node		*prev;
}			t_node;

typedef struct		s_list
{
  t_node		*head;
  t_node		*last;
}			t_list;

extern t_list		allocated_blocks;
/* extern t_list		free_blocks; */
extern pthread_mutex_t	lock;

void			show_alloc_mem();
t_node			*ptr_to_block(void *ptr);

//lists functions
void			push_back(t_list *list, t_node *block);

#endif /* !MALLOC_H_ */
