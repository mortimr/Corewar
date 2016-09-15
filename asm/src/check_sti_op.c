/*
** check_sti_op.c for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat Mar 26 16:47:51 2016 Iulian Rotaru
** Last update Sat Mar 26 16:48:51 2016 Iulian Rotaru
*/

#include "asm.h"

int	check_sti_op(t_op_stock *line)
{
  if ((line->label == 0 && line->nb != 4)
      || (line->label == 1 && line->nb != 5))
    return (1);
  if (line->label == 0)
    {
      if (is_it_reg(line->command[1]) == 1)
	return (1);
      if ((is_it_reg(line->command[2]) == 1)
	  && (is_it_direct(line->command[2]) == 1)
	  && (is_it_indi_warn(line->command[2]) == 1))
	return (1);
      if ((is_it_direct(line->command[3]) == 1)
	  && (is_it_reg(line->command[3]) == 1))
	return (1);
    }
  return (check_sti_op_label(line));
}

int	check_fork_op(t_op_stock *line)
{
  if ((line->label == 0 && line->nb != 2)
      || (line->label == 1 && line->nb != 3))
    return (1);
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

int	check_lld_op_label(t_op_stock *line)
{
  if (line->label == 1)
    {
      if ((is_it_direct(line->command[2]) == 1)
	  && (is_it_indi_warn(line->command[2]) == 1))
	return (1);
      if (is_it_reg(line->command[3]) == 1)
	return (1);
    }
  return (0);
}

int	check_lld_op(t_op_stock *line)
{
  if ((line->label == 0 && line->nb != 3)
      || (line->label == 1 && line->nb != 4))
    return (1);
  if (line->label == 0)
    {
      if ((is_it_direct(line->command[1]) == 1)
	  && (is_it_indi_warn(line->command[1]) == 1))
	return (1);
      if (is_it_reg(line->command[2]) == 1)
	return (1);
    }
  return (check_lld_op_label(line));
}

int	check_lldi_op_label(t_op_stock *line)
{
  if (line->label == 1)
    {
      if ((is_it_reg(line->command[2]) == 1)
	  && (is_it_direct(line->command[2]) == 1)
	  && (is_it_indi_warn(line->command[2]) == 1))
	return (1);
      if ((is_it_reg(line->command[3]) == 1)
	  && (is_it_direct(line->command[3]) == 1))
	return (1);
      if (is_it_reg(line->command[4]) == 1)
	return (1);
    }
  return (0);
}
