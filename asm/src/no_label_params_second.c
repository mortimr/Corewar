/*
** no_label_params_second.c for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat Mar 26 17:11:34 2016 Iulian Rotaru
** Last update Sun Mar 27 21:15:19 2016 Alif Matthias
*/

#include "asm.h"

int	no_label_params_second(t_op_stock *tmp)
{
  if (tmp->nb > 2)
    {
      if (is_it_reg(tmp->command[2]) == 0)
	tmp->codage += 1 << 4;
      else if (is_it_direct(tmp->command[2]) == 0)
	tmp->codage += 1 << 5;
      else if (is_it_indi(tmp->command[2]) == 0)
	tmp->codage += ((1 << 4) + (1 << 5));
    }
  return (no_label_params_third(tmp));
}

int	no_label_params(t_op_stock *tmp)
{
  if ((my_strcmp(tmp->command[0], g_tab[0].mnemonique) == 0)
      || (my_strcmp(tmp->command[0], g_tab[8].mnemonique) == 0)
      || (my_strcmp(tmp->command[0], g_tab[11].mnemonique) == 0)
      || (my_strcmp(tmp->command[0], g_tab[14].mnemonique) == 0))
    {
      tmp->codage = 0;
      return (0);
    }
  if (is_it_reg(tmp->command[1]) == 0)
    tmp->codage += 1 << 6;
  else if (is_it_direct(tmp->command[1]) == 0)
    tmp->codage += 1 << 7;
  else if (is_it_indi(tmp->command[1]) == 0)
    tmp->codage += ((1 << 6) + (1 << 7));
  return (no_label_params_second(tmp));
}

int		fill_params(t_op_stock *start)
{
  t_op_stock	*tmp;

  tmp = start;
  while (tmp->next)
    {
      tmp->codage = 0;
      if (tmp->label == 1 && tmp->nb == 1)
	{
	  tmp->codage = 0;
	  tmp->size = 0;
	}
      else if (tmp->label == 1 && tmp->nb > 2)
	label_params(tmp);
      else if (tmp->label == 0 && tmp->nb > 1)
	no_label_params(tmp);
      tmp = tmp->next;
    }
  return (0);
}

int	size_live(t_op_stock *tmp)
{
  (void)tmp;
  return (5);
}

int	size_ld_label(t_op_stock *tmp, int *out)
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
