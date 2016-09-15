/*
** size_ld.c for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat Mar 26 17:22:50 2016 Iulian Rotaru
** Last update Sun Mar 27 16:07:40 2016 Iulian Rotaru
*/

#include "asm.h"

int	size_ld(t_op_stock *tmp)
{
  int	out;

  out = 2;
  if (tmp->label == 0)
    {
      if (tmp->nb != 3)
	return (-1);
      if (is_it_indi(tmp->command[1]) == 0)
	out += IND_SIZE;
      else if (is_it_direct(tmp->command[1]) == 0)
	out += DIR_SIZE;
      if (is_it_reg(tmp->command[2]) == 0)
	out += 1;
    }
  return (size_ld_label(tmp, &out));
}

int	size_st_label(t_op_stock *tmp, int *out)
{
  if (tmp->label == 1)
    {
      if (tmp->nb != 4)
	return (-1);
      if (is_it_reg(tmp->command[2]) == 0)
	*out += 1;
      if (is_it_indi(tmp->command[3]) == 0)
	*out += IND_SIZE;
      else if (is_it_reg(tmp->command[3]) == 0)
	*out += 1;
    }
  return (*out);
}

int	size_st(t_op_stock *tmp)
{
  int	out;

  out = 2;
  if (tmp->label == 0)
    {
      if (tmp->nb != 3)
	return (-1);
      if (is_it_reg(tmp->command[1]) == 0)
	out += 1;
      if (is_it_indi(tmp->command[2]) == 0)
	out += IND_SIZE;
      else if (is_it_reg(tmp->command[2]) == 0)
	out += 1;
    }
  return (size_st_label(tmp, &out));
}

int	size_add(t_op_stock *tmp)
{
  (void)tmp;
  return (5);
}

int	size_sub(t_op_stock *tmp)
{
  (void)tmp;
  return (5);
}
