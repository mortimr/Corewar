/*
** size_or_label.c for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat Mar 26 17:31:36 2016 Iulian Rotaru
** Last update Sat Mar 26 17:32:40 2016 Iulian Rotaru
*/

#include "asm.h"

int	size_or_label(t_op_stock *tmp, int *out)
{
  if (tmp->label == 1)
    {
      if (tmp->nb != 5)
	return (-1);
      if (is_it_reg(tmp->command[2]) == 0)
	*out += 1;
      else if (is_it_indi(tmp->command[2]) == 0)
	*out += IND_SIZE;
      else if (is_it_direct(tmp->command[2]) == 0)
	*out += DIR_SIZE;
      size_or_second_label(tmp, out);
    }
  return (*out);
}

void	size_or_second(t_op_stock *tmp, int *out)
{
  if (is_it_reg(tmp->command[2]) == 0)
    *out += 1;
  else if (is_it_indi(tmp->command[2]) == 0)
    *out += IND_SIZE;
  else if (is_it_direct(tmp->command[2]) == 0)
    *out += DIR_SIZE;
  if (is_it_reg(tmp->command[3]) == 0)
    *out += 1;
}

int	size_or(t_op_stock *tmp)
{
  int	out;

  out = 2;
  if (tmp->label == 0)
    {
      if (tmp->nb != 4)
	return (-1);
      if (is_it_reg(tmp->command[1]) == 0)
	out += 1;
      else if (is_it_indi(tmp->command[1]) == 0)
	out += IND_SIZE;
      else if (is_it_direct(tmp->command[1]) == 0)
	out += DIR_SIZE;
      size_or_second(tmp, &out);
    }
  return (size_or_label(tmp, &out));
}

void	size_xor_second_label(t_op_stock *tmp, int *out)
{
  if (is_it_reg(tmp->command[3]) == 0)
    *out += 1;
  else if (is_it_indi(tmp->command[3]) == 0)
    *out += IND_SIZE;
  else if (is_it_direct(tmp->command[3]) == 0)
    *out += DIR_SIZE;
  if (is_it_reg(tmp->command[4]) == 0)
    *out += 1;
}

int	size_xor_label(t_op_stock *tmp, int *out)
{
  if (tmp->label == 1)
    {
      if (tmp->nb != 5)
	return (-1);
      if (is_it_reg(tmp->command[2]) == 0)
	*out += 1;
      else if (is_it_indi(tmp->command[2]) == 0)
	*out += IND_SIZE;
      else if (is_it_direct(tmp->command[2]) == 0)
	*out += DIR_SIZE;
      size_xor_second_label(tmp, out);
    }
  return (*out);
}
