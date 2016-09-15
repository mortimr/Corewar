/*
** check_name_comm.c for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat Mar 26 13:57:15 2016 Iulian Rotaru
** Last update Sun Mar 27 16:52:06 2016 Iulian Rotaru
*/

#include <unistd.h>
#include "asm.h"

int	check_name_comm(char *name, char *comment, char *str)
{
  if (cache_cache(NAME_CMD_STRING, name) == 1)
    return (reterr("Error: Can't find name in file ", str, -1));
  if (cache_cache(COMMENT_CMD_STRING, comment) == 1)
    return (reterr("Error: Can't find comment in file ", str, -1));
  return (0);
}

void	fill_name_stamp(t_header *stamp, char *name)
{
  int	i;
  int	j;

  i = 0;
  while (*(name + i) != 34 && *(name + i))
    i++;
  if (*(name + i))
    i++;
  j = 0;
  while (*(name + i) != 34 && *(name + i) && j < PROG_NAME_LENGTH)
    *(stamp->prog_name + j++) = *(name + i++);
  while (j < PROG_NAME_LENGTH + 1)
    *(stamp->prog_name + j++) = 0;
}

int	fill_stamp(t_header *stamp, char *name, char *comment, char *str)
{
  int	i;
  int	j;

  empty_stamp(stamp);
  if (check_name_comm(name, comment, str) == -1)
    return (-1);
  fill_name_stamp(stamp, name);
  i = 0;
  while (*(comment + i) != 34 && *(comment + i))
    i++;
  if (*(comment + i))
    i++;
  j = 0;
  while (*(comment + i) != 34 && *(comment + i) && j < COMMENT_LENGTH)
    *(stamp->comment + j++) = *(comment + i++);
  while (j < COMMENT_LENGTH + 1)
    *(stamp->comment + j++) = 0;
  stamp->magic = COREWAR_EXEC_MAGIC;
  return (0);
}

int	check_if_empty(char *str)
{
  int	i;

  i = 0;
  while (*(str + i))
    {
      if (*(str + i) != ' ' && *(str + i) != '\t')
	return (1);
      i++;
    }
  return (0);
}

void	print_tab(char **str)
{
  int	i;

  i = 0;
  while (*(str + i))
    {
      write(1, *(str + i), my_strlen(*(str + i)));
      write(1, "\n", 1);
      i++;
    }
}
