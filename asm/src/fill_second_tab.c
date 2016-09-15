/*
** fill_second_tab.c for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Mar 27 15:08:36 2016 Iulian Rotaru
** Last update Sun Mar 27 16:42:05 2016 Iulian Rotaru
*/

#include <unistd.h>
#include "asm.h"

void	fill_second_tab(int (**tab)(t_op_stock *))
{
  tab[0] = &size_live;
  tab[1] = &size_ld;
  tab[2] = &size_st;
  tab[3] = &size_add;
  tab[4] = &size_sub;
  tab[5] = &size_and;
  tab[6] = &size_or;
  tab[7] = &size_xor;
  tab[8] = &size_zjmp;
  tab[9] = &size_ldi;
  tab[10] = &size_sti;
  tab[11] = &size_fork;
  tab[12] = &size_lld;
  tab[13] = &size_lldi;
  tab[14] = &size_lfork;
  tab[15] = &size_aff;
}

int		fill_size(t_op_stock *start)
{
  t_op_stock	*tmp;
  int		(*tab[16])(t_op_stock *);

  tmp = start;
  fill_second_tab(tab);
  while (tmp->next)
    {
      tmp->size = 0;
      if (tmp->opcode != -1)
	tmp->size = tab[(int)tmp->opcode](tmp);
      tmp = tmp->next;
    }
  return (0);
}

int		fill_idx(t_op_stock *start)
{
  int		increm;
  t_op_stock	*tmp;

  tmp = start;
  increm = 0;
  while (tmp->next)
    {
      tmp->idx = increm;
      increm += tmp->size;
      tmp = tmp->next;
    }
  return (0);
}

int	fill_list(t_op_stock *start)
{
  if (fill_params(start) == 1)
    return (1);
  if (fill_size(start) == 1)
    return (1);
  if (fill_idx(start) == 1)
    return (1);
  return (0);
}

int	reterr_classic(char *str, int ret)
{
  write(2, str, my_strlen(str));
  return (ret);
}
