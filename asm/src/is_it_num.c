/*
** is_it_num.c for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat Mar 26 16:36:00 2016 Iulian Rotaru
** Last update Sun Mar 27 16:15:14 2016 Iulian Rotaru
*/

#include "asm.h"

int	is_it_num(char *str)
{
  int	i;
  char	*hexa;

  i = 0;
  hexa = "0123456789ABCDEF";
  if ((my_strlen(str) > 2)
      && (*str == '0' && *(str + 1) == 'x'))
    {
      i = 0;
      while (*(str + 2 + i))
	{
	  if (is_it_in(*(str + 2 + i), hexa) == 1)
	    return (1);
	  i++;
	}
      return (0);
    }
  else if (my_strlen(str) > 1)
    return (is_it_num_deci(str));
  return (0);
}

int	check_live_op(t_op_stock *line)
{
  if (line->label == 0)
    {
      if (is_it_direct(line->command[1]) == 1)
	return (1);
    }
  else if (line->label == 1)
    {
      if (is_it_direct(line->command[2]) == 1)
	return (1);
    }
  return (0);
}

int	check_st_op_label(t_op_stock *line)
{
  if (line->label == 1)
    {
      if (is_it_reg(line->command[2]) == 1)
	return (1);
      if ((is_it_reg(line->command[3]) == 1)
	  && (is_it_indi(line->command[3]) == 1))
	return (1);
    }
  return (0);
}

int	check_st_op(t_op_stock *line)
{
  if ((line->label == 0 && line->nb != 3)
      && (line->label == 1 && line->nb != 4))
    return (1);
  if (line->label == 0)
    {
      if (is_it_reg(line->command[1]) == 1)
	return (1);
      if ((is_it_reg(line->command[2]) == 1)
	  && (is_it_indi(line->command[2]) == 1))
	return (1);
    }
  return (check_st_op_label(line));
}

int	check_ld_op_label(t_op_stock *line)
{
  if (line->label == 1)
    {
      if (is_it_direct(line->command[2]) == 1
	  && is_it_indi_warn(line->command[2]) == 1)
	return (1);
      if (is_it_reg(line->command[3]) == 1)
	return (1);
    }
  return (0);
}
