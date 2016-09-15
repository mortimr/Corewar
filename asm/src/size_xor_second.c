/*
** size_xor_second.c for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat Mar 26 17:36:15 2016 Iulian Rotaru
** Last update Sun Mar 27 16:07:18 2016 Iulian Rotaru
*/

#include "asm.h"

void	size_xor_second(t_op_stock *tmp, int *out)
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

int	size_xor(t_op_stock *tmp)
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
      size_xor_second(tmp, &out);
    }
  return (size_xor_label(tmp, &out));
}

int	size_zjmp(t_op_stock *tmp)
{
  (void)tmp;
  return (3);
}

void	size_ldi_second_label(t_op_stock *tmp, int *out)
{
  if (is_it_reg(tmp->command[3]) == 0)
    *out += 1;
  else if (is_it_direct(tmp->command[3]) == 0)
    *out += 2;
  if (is_it_reg(tmp->command[4]) == 0)
    *out += 1;
}

int	size_ldi_label(t_op_stock *tmp, int *out)
{
  if (tmp->label == 1)
    {
      if (tmp->nb != 5)
	return (-1);
      if (is_it_reg(tmp->command[2]) == 0)
	*out += 1;
      else if (is_it_indi(tmp->command[2]) == 0)
	*out += 2;
      else if (is_it_direct(tmp->command[2]) == 0)
	*out += 2;
      size_ldi_second_label(tmp, out);
    }
  return (*out);
}
