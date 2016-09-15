/*
** fill_command_case_two.c for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat Mar 26 16:57:07 2016 Iulian Rotaru
** Last update Sun Mar 27 16:13:25 2016 Iulian Rotaru
*/

#include "asm.h"

int	fill_command_case_two(char *line, t_op_stock *tmp, int *i)
{
  if (*(line + *i) == SEPARATOR_CHAR && *(i + 1) < 5)
    {
      *i += 1;
      *(*(tmp->command + *(i + 1)) + *(i + 2)) = 0;
      clean_line_small(*(tmp->command + *(i + 1)));
      *(i + 2) = 0;
      *(i + 1) += 1;
    }
  else if (*(line + *i) == SEPARATOR_CHAR && *(i + 1) >= 5)
    return (1);
  if (*(i + 2) < 100)
    *(*(tmp->command + *(i + 1)) + *(i + 2)) = *(line + *i);
  *(i + 2) += 1;
  *i += 1;
  return (0);
}

int	fill_command_last_checks(t_op_stock *tmp, int *i, int *lab, char *line)
{
  *(*(tmp->command + *(i + 1)) + *(i + 2)) = 0;
  clean_line_small(*(tmp->command + *(i + 1)));
  if ((*lab >= 1) || (*i > 0 && *(line + *i - 1) == LABEL_CHAR))
    {
      tmp->label = 1;
      if (check_label(tmp) == 1)
	return (2);
    }
  else
    tmp->label = 0;
  tmp->nb = *(i + 1) + 1;
  if (check_if_line_good(tmp) == 1)
    return (1);
  if ((tmp->next = malloc(sizeof(t_op_stock))) == NULL)
    return (3);
  return (0);
}

int	fill_command(char *line, t_op_stock *start)
{
  int	i[3];
  int	lab;
  t_op_stock	*tmp;

  tmp = start;
  while (tmp->next)
    tmp = tmp->next;
  *i = 0;
  *(i + 1) = 0;
  *(i + 2) = 0;
  lab = 0;
  if (my_strlen(line) == 0)
    return (1);
  while ((*(line + *i) == ' ' || *(line + *i) == '\t') && *(line + ++*i));
  *(i + 2) = 0;
  while (*(line + *i))
    {
      fill_command_case_one(line, tmp, i, &lab);
      fill_command_case_two(line, tmp, i);
    }
  return (fill_command_last_checks(tmp, i, &lab, line));
}

void	clean_line_small(char *line)
{
  int	i[2];

  *i = 0;
  while (*(line + *i) && (*(line + *i) == '\t' || *(line + *i) == ' '))
    {
      if ((*(line + *i) == ' ' || *(line + *i) == '\t'))
	{
	  *(i + 1) = *i + 1;
	  while (*(line + *(i + 1)))
	    {
	      *(line + *(i + 1) - 1) = *(line + *(i + 1));
	      *(i + 1) += 1;
	    }
	  *(line + *(i + 1) - 1) = 0;
	  *i -= 1;
	}
      *i += 1;
    }
  *i = 0;
  while (*(line + *i) != '\t' && *(line + *i) != ' ' && *(line + *i))
    *i += 1;
  *(line + *i) = 0;
}

void	clean_line(char *line)
{
  int	i[2];

  *i = 0;
  while (*(line + *i) && (*(line + *i) == '\t' || *(line + *i) == ' '))
    {
      if ((*(line + *i) == ' ' || *(line + *i) == '\t'))
	{
	  *(i + 1) = *i + 1;
	  while (*(line + *(i + 1)))
	    {
	      *(line + *(i + 1) - 1) = *(line + *(i + 1));
	      *(i + 1) += 1;
	    }
	  *(line + *(i + 1) - 1) = 0;
	  *i -= 1;
	}
      *i += 1;
    }
}
