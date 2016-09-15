/*
** check_if_line_good.c for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat Mar 26 16:54:17 2016 Iulian Rotaru
** Last update Sun Mar 27 21:11:11 2016 Alif Matthias
*/

#include "asm.h"

int	check_if_line_end(t_op_stock *line,
			  int command,
			  int (**tab)(t_op_stock *))
{
  if (command == -1)
    return (1);
  else if (tab[(int)line->opcode](line) == 1)
    return (1);
  return (0);
}

int	check_if_line_good(t_op_stock *line)
{
  int	command;
  int	i;
  int	(*tab[16])(t_op_stock *);

  command = -1;
  i = 0;
  fill_tab(tab);
  if (check_if_empty_label_line(line) == 1)
    return (0);
  while (i < 16)
    {
      if (line->label == 1 && line->nb > 1)
	{
	  if (my_strcmp(*(line->command + 1), g_tab[i].mnemonique) == 0)
	    command = i;
	}
      else if (line->label == 0 && line->nb > 1)
	{
	  if (my_strcmp(*line->command, g_tab[i].mnemonique) == 0)
	    command = i;
	}
      i++;
    }
  line->opcode = command;
  return (check_if_line_end(line, command, tab));
}

int	check_label(t_op_stock *tmp)
{
  int	i;

  if (tmp->label == 1)
    {
      if (my_strlen(*tmp->command) <= 1)
	return (1);
      i = 0;
      while (*(*(tmp->command) + i) && i < my_strlen(tmp->command[0]) - 1)
	{
	  if (is_it_in(*(*(tmp->command) + i), LABEL_CHARS) == 1)
	    return (1);
	  i++;
	}
      return (0);
    }
  return (0);
}

void	fill_command_setuper(t_op_stock *tmp, int *i)
{
  *(*(tmp->command + *(i + 1)) + *(i + 2)) = 0;
  clean_line_small(*(tmp->command + *(i + 1)));
  *(i + 1) += 1;
  *(i + 2) = 0;
}

void	fill_command_case_one(char *line, t_op_stock *tmp, int *i, int *lab)
{
  if (*(i + 1) == 0 && *i != 0 && *lab == 0)
    {
      if (*(line + *i - 1) == LABEL_CHAR)
	{
	  fill_command_setuper(tmp, i);
	  *lab = 1;
	}
      else if ((*(line + *i) == ' ' || *(line + *i) == '\t')
	       && (*(line + *i - 1) != ' ' && *(line + *i - 1) != '\t'))
	fill_command_setuper(tmp, i);
    }
  else if (*(i + 1) == 1 && *i != 0 && *lab == 1)
    {
      if ((*(line + *i) == ' ' || *(line + *i) == '\t')
	  && (*(line + *i - 1) != ' ' && *(line + *i - 1) != '\t'))
	{
	  fill_command_setuper(tmp, i);
	  *lab = 2;
	}
    }
}
