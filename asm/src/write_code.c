/*
** write_code.c for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Mar 27 15:28:27 2016 Iulian Rotaru
** Last update Thu Sep 15 15:22:38 2016 ROTARU Iulian
*/

#include <unistd.h>
#include "asm.h"

int		write_code(t_op_stock *start, int fd)
{
  t_op_stock	*tmp;
  int		(*tab[16])(t_op_stock *, t_op_stock *, int fd);

  tmp = start;
  make_tab_end(tab);
  while (tmp->next)
    {
      if (tmp->opcode != -1)
	{
	  if (tab[(int)tmp->opcode](tmp, start, fd) == 1)
	    return (1);
	}
      tmp = tmp->next;
    }
  return (0);
}

int		fill_headsize(t_op_stock *start, t_header *stamp)
{
  t_op_stock	*tmp;

  tmp = start;
  while (tmp && tmp->next && tmp->next->next)
    tmp = tmp->next;
  stamp->prog_size = tmp->idx + tmp->size;
  return (0);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

int	preliminary_tests(int *fd,
			  t_op_stock *start,
			  char *str,
			  t_header *stamp)
{
  while (((start->name = get_term_line(*fd)) != NULL)
	 && ((start->name[0] == COMMENT_CHAR)
	     || (classic_strlen(start->name) == 0)))
    if (start->name == NULL)
      return (1);
  while (((start->comment = get_term_line(*fd)) != NULL)
	 && ((start->comment[0] == COMMENT_CHAR)
	     || (classic_strlen(start->name) == 0)))
    if (start->comment == NULL)
      return (1);
  if (fill_stamp(stamp, start->name, start->comment, str) == -1)
    return (1);
  if (read_commands(start, *fd) == -1)
    return (1);
  return (0);
}

void	empty_file_new(t_op_stock *start)
{
  int	i;

  i = 0;
  while (i < 1024)
    {
      *(start->file_new + i) = 0;
      i += 1;
    }
}
