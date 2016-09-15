/*
** rm_coms.c for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat Mar 26 17:02:29 2016 Iulian Rotaru
** Last update Sun Mar 27 23:35:09 2016 Iulian Rotaru
*/

#include "asm.h"

void	rm_coms(char *str)
{
  int	i;

  i = 0;
  while (*(str + i))
    {
      if (*(str + i) == ';' || *(str + i) == COMMENT_CHAR)
	{
	  *(str + i) = 0;
	  return;
	}
      i++;
    }
}

int	label_params_third(t_op_stock *tmp)
{
  if (tmp->nb > 4)
    {
      if (is_it_reg(tmp->command[4]) == 0)
	tmp->codage += 1 << 2;
      else if (is_it_direct(tmp->command[4]) == 0)
	tmp->codage += 1 << 3;
      else if (is_it_indi(tmp->command[4]) == 0)
	tmp->codage += ((1 << 2) + (1 << 3));
    }
  return (0);
}

int	label_params_second(t_op_stock *tmp)
{
  if (tmp->nb > 3)
    {
      if (is_it_reg(tmp->command[3]) == 0)
	tmp->codage += 1 << 4;
      else if (is_it_direct(tmp->command[3]) == 0)
	tmp->codage += 1 << 5;
      else if (is_it_indi(tmp->command[3]) == 0)
	tmp->codage += ((1 << 4) + (1 << 5));
    }
  return (label_params_third(tmp));
}

int	label_params(t_op_stock *tmp)
{
  if ((my_strcmp(tmp->command[1], g_tab[0].mnemonique) == 0)
      || (my_strcmp(tmp->command[1], g_tab[8].mnemonique) == 0)
      || (my_strcmp(tmp->command[1], g_tab[11].mnemonique) == 0)
      || (my_strcmp(tmp->command[1], g_tab[14].mnemonique) == 0))
    {
      tmp->codage = 0;
      return (0);
    }
  if (is_it_reg(tmp->command[2]) == 0)
    tmp->codage += 1 << 6;
  else if (is_it_direct(tmp->command[2]) == 0)
    tmp->codage += 1 << 7;
  else if (is_it_indi(tmp->command[2]) == 0)
    {
      tmp->codage += ((1 << 6) + (1 << 7));
    }
  return (label_params_second(tmp));
}

int	no_label_params_third(t_op_stock *tmp)
{
  if (tmp->nb > 3)
    {
      if (is_it_reg(tmp->command[3]) == 0)
	tmp->codage += 1 << 2;
      else if (is_it_direct(tmp->command[3]) == 0)
	tmp->codage += 1 << 3;
      else if (is_it_indi(tmp->command[3]) == 0)
	tmp->codage += ((1 << 2) + (1 << 3));
    }
  return (0);
}
