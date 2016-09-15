/*
** write_lld_label.c for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Mar 27 15:26:53 2016 Iulian Rotaru
** Last update Sun Mar 27 18:02:04 2016 Iulian Rotaru
*/

#include <unistd.h>
#include "asm.h"

int	write_lld_label(t_op_stock *tmp, t_op_stock *start, int fd)
{
  int	i;

  if (tmp->label == 1)
    {
      if (tmp->nb != 4)
	return (1);
      i = 2;
      while ((unsigned int)i < tmp->nb)
	{
	  if (write_param_nb(tmp, i - 1, start, fd) == 1)
	    return (1);
	  i++;
	}
    }
  return (0);
}

int	write_lld(t_op_stock *tmp, t_op_stock *start, int fd)
{
  int	i;
  char	lab;

  lab = 13;
  write(fd, &lab, sizeof(char));
  write(fd, &tmp->codage, sizeof(char));
  if (tmp->label == 0)
    {
      if (tmp->nb != 3)
	return (1);
      i = 1;
      while ((unsigned int)i < tmp->nb)
	{
	  if (write_param_nb(tmp, i, start, fd) == 1)
	    return (1);
	  i++;
	}
    }
  return (write_lld_label(tmp, start, fd));
}

int	write_fork(t_op_stock *tmp, t_op_stock *start, int fd)
{
  char	lab;
  int	param_idx;
  int	out;

  lab = 12;
  write(fd, &lab, sizeof(char));
  if (tmp->label == 1)
    param_idx = 2;
  else
    param_idx = 1;
  if ((tmp->command[param_idx][0] == DIRECT_CHAR
       && tmp->command[param_idx][1] == LABEL_CHAR)
      && (my_strlen(tmp->command[param_idx]) > 2))
    {
      if ((out = check_if_dir_label
	   (tmp->command[param_idx] + 2, start, tmp->idx)) == 0)
	return (1);
    }
  else if ((tmp->command[param_idx][0] == DIRECT_CHAR)
	   && (is_it_num(tmp->command[param_idx] + 1) == 0))
    out = my_getnbr(tmp->command[param_idx] + 1);
  write_short(out, fd);
  return (0);
}

int	write_lfork(t_op_stock *tmp, t_op_stock *start, int fd)
{
  char	lab;
  int	param_idx;
  int	out;

  lab = 15;
  write(fd, &lab, sizeof(char));
  if (tmp->label == 1)
    param_idx = 2;
  else
    param_idx = 1;
  if ((tmp->command[param_idx][0] == DIRECT_CHAR
       && tmp->command[param_idx][1] == LABEL_CHAR)
      && (my_strlen(tmp->command[param_idx]) > 2))
    {
      if ((out = check_if_dir_label
	   (tmp->command[param_idx] + 2, start, tmp->idx)) == 0)
	return (1);
    }
  else if ((tmp->command[param_idx][0] == DIRECT_CHAR)
	   && (is_it_num(tmp->command[param_idx] + 1) == 0))
    out = my_getnbr(tmp->command[param_idx] + 1);
  write_short(out, fd);
  return (0);
}

void	make_tab_end(int (**tab)(t_op_stock *, t_op_stock *, int fd))
{
  tab[0] = &write_live;
  tab[1] = &write_ld;
  tab[2] = &write_st;
  tab[3] = &write_add;
  tab[4] = &write_sub;
  tab[5] = &write_and;
  tab[6] = &write_or;
  tab[7] = &write_xor;
  tab[8] = &write_zjmp;
  tab[9] = &write_ldi;
  tab[10] = &write_sti;
  tab[11] = &write_fork;
  tab[12] = &write_lld;
  tab[13] = &write_lldi;
  tab[14] = &write_lfork;
  tab[15] = &write_aff;
}
