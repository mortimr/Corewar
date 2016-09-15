/*
** size_sti.c for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat Mar 26 17:43:23 2016 Iulian Rotaru
** Last update Sun Mar 27 16:06:46 2016 Iulian Rotaru
*/

#include "asm.h"

int	size_sti(t_op_stock *tmp)
{
  int	out;

  out = 2;
  if (tmp->label == 0)
    {
      if (tmp->nb != 4)
	return (-1);
      if (is_it_reg(tmp->command[1]) == 0)
	out += 1;
      size_sti_second(tmp, &out);
    }
  return (size_sti_label(tmp, &out));
}

int	size_fork(t_op_stock *tmp)
{
  (void)tmp;
  return (3);
}

int	size_lld_label(t_op_stock *tmp, int *out)
{
  if (tmp->label == 1)
    {
      if (tmp->nb != 4)
	return (-1);
      if (is_it_indi(tmp->command[2]) == 0)
	*out += IND_SIZE;
      else if (is_it_direct(tmp->command[2]) == 0)
	*out += DIR_SIZE;
      if (is_it_reg(tmp->command[3]) == 0)
	*out += 1;
    }
  return (*out);
}

int	size_lld(t_op_stock *tmp)
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
  return (size_lld_label(tmp, &out));
}

void	size_lldi_second_label(t_op_stock *tmp, int *out)
{
  if (is_it_direct(tmp->command[3]) == 0)
    *out += DIR_SIZE;
  else if (is_it_reg(tmp->command[3]) == 0)
    *out += 1;
  if (is_it_reg(tmp->command[4]) == 0)
    *out += 1;
}
