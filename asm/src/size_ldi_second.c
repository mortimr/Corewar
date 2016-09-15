/*
** size_ldi_second.c for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat Mar 26 17:38:10 2016 Iulian Rotaru
** Last update Sat Mar 26 17:39:00 2016 Iulian Rotaru
*/

#include "asm.h"

void	size_ldi_second(t_op_stock *tmp, int *out)
{
  if (is_it_reg(tmp->command[2]) == 0)
    *out += 1;
  else if (is_it_direct(tmp->command[2]) == 0)
    *out += 2;
  if (is_it_reg(tmp->command[3]) == 0)
    *out += 1;
}

int	size_ldi(t_op_stock *tmp)
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
	out += 2;
      else if (is_it_direct(tmp->command[1]) == 0)
	out += 2;
      size_ldi_second(tmp, &out);
    }
  return (size_ldi_label(tmp, &out));
}

void	size_sti_second_label(t_op_stock *tmp, int *out)
{
  if (is_it_reg(tmp->command[3]) == 0)
    *out += 1;
  else if (is_it_direct(tmp->command[3]) == 0)
    *out += 2;
  else if (is_it_indi(tmp->command[3]) == 0)
    *out += 2;
  if (is_it_direct(tmp->command[4]) == 0)
    *out += 2;
  else if (is_it_reg(tmp->command[4]) == 0)
    *out += 1;
}

int	size_sti_label(t_op_stock *tmp, int *out)
{
  if (tmp->label == 1)
    {
      if (tmp->nb != 5)
	return (-1);
      if (is_it_reg(tmp->command[2]) == 0)
	*out += 1;
      size_sti_second_label(tmp, out);
    }
  return (*out);
}

void	size_sti_second(t_op_stock *tmp, int *out)
{
  if (is_it_reg(tmp->command[2]) == 0)
    *out += 1;
  else if (is_it_direct(tmp->command[2]) == 0)
    *out += 2;
  else if (is_it_indi(tmp->command[2]) == 0)
    *out += 2;
  if (is_it_direct(tmp->command[3]) == 0)
    *out += 2;
  else if (is_it_reg(tmp->command[3]) == 0)
    *out += 1;
}
