/*
** empty_error.c for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Mar 27 15:10:47 2016 Iulian Rotaru
** Last update Sun Mar 27 16:41:07 2016 Iulian Rotaru
*/

#include "asm.h"

int	empty_error(int line, int err)
{
  if (err == 1)
    return (reterrline("Syntax error line ", line, -1));
  if (err == 2)
    return (reterrline("Label error line ", line, -1));
  if (err == 3)
    return (reterr_classic("Can't perform malloc\n", -1));
  return (0);
}

int	read_commands_list(t_op_stock *start)
{
  if (fill_list(start) == 1)
    return (-1);
  return (0);
}

int	my_normal_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i])
    i++;
  return (i);
}

int	read_commands(t_op_stock *start, int fd)
{
  char	*extract;
  int	line;
  int	ret;

  start->next = NULL;
  line = 2;
  start->code = 0;
  while ((extract = get_term_line(fd)))
    {
      if (check_if_empty(extract) == 1)
	{
	  clean_line(extract);
	  rm_coms(extract);
	  if (my_normal_strlen(extract) > 1
	      && extract[0] != COMMENT_CHAR && extract[0] != '.')
	    {
	      if ((ret = fill_command(extract, start)) != 0)
		return (empty_error(line, ret));
	    }
	  free(extract);
	}
      line++;
    }
  return (read_commands_list(start));
}

int	is_it_far(char *str)
{
  int	i;

  i = 0;
  while (*(str + i))
    {
      if (*(str + i) == '/')
	return (1);
      i++;
    }
  return (0);
}
