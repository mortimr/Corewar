/*
** check_lldi_op.c for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat Mar 26 16:49:54 2016 Iulian Rotaru
** Last update Sat Mar 26 16:50:37 2016 Iulian Rotaru
*/

#include "asm.h"

int	check_lldi_op(t_op_stock *line)
{
  if ((line->label == 0 && line->nb != 4)
      && (line->label == 1 && line->nb != 5))
    return (1);
  if (line->label == 0)
    {
      if ((is_it_reg(line->command[1]) == 1)
	  && (is_it_direct(line->command[1]) == 1)
	  && (is_it_indi_warn(line->command[1]) == 1))
	return (1);
      if ((is_it_reg(line->command[2]) == 1)
	  && (is_it_direct(line->command[2]) == 1))
	return (1);
      if (is_it_reg(line->command[3]) == 1)
	return (1);
    }
  return (check_lldi_op_label(line));
}

int	check_lfork_op(t_op_stock *line)
{
  if ((line->label == 0 && line->nb != 2)
      && (line->label == 1 && line->nb != 3))
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

int	check_aff_op(t_op_stock *line)
{
  if ((line->label == 0 && line->nb != 2)
      && (line->label == 1 && line->nb != 3))
    return (1);
  if (line->label == 0)
    {
      if (is_it_reg(line->command[1]) == 1)
	return (1);
    }
  else if (line->label == 1)
    {
      if (is_it_reg(line->command[2]) == 1)
	return (1);
    }
  return (0);
}

void	fill_tab(int (**tab)(t_op_stock *))
{
  tab[0] = &check_live_op;
  tab[1] = &check_ld_op;
  tab[2] = &check_st_op;
  tab[3] = &check_add_op;
  tab[4] = &check_sub_op;
  tab[5] = &check_and_op;
  tab[6] = &check_or_op;
  tab[7] = &check_xor_op;
  tab[8] = &check_zjmp_op;
  tab[9] = &check_ldi_op;
  tab[10] = &check_sti_op;
  tab[11] = &check_fork_op;
  tab[12] = &check_lld_op;
  tab[13] = &check_lldi_op;
  tab[14] = &check_lfork_op;
  tab[15] = &check_aff_op;
}

int	check_if_empty_label_line(t_op_stock *line)
{
  if (line->label == 1 && line->nb == 1)
    {
      line->opcode = -1;
      return (1);
    }
  return (0);
}
