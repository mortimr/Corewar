/*
** others.c for corewar in /home/alif_m/tek1/CPE/CPE_2015_corewar
**
** Made by Alif Matthias
** Login   <alif_m@epitech.net>
**
** Started on  Sun Mar 27 16:54:43 2016 Alif Matthias
** Last update Sun Mar 27 20:34:24 2016 Alif Matthias
*/

#include <stdlib.h>
#include <unistd.h>
#include "vm.h"

int	alive(t_vm *vm, t_ch *ch)
{
  int	cnt;
  t_ch	*tmp;

  tmp = ch;
  cnt = 0;
  vm->care = 0;
  while (tmp->next)
    {
      if (tmp->live != 0)
	{
	  vm->current = tmp->nb;
	  cnt++;
	}
      tmp->live = 0;
      tmp = tmp->next;
    }
  return (cnt);
}

void	put(int nb)
{
  char	c;

  if (nb >= 10)
    put(nb / 10);
  c = nb % 10 + 48;
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i])
    i++;
  return (i);
}

void	aff_end(t_vm *vm, t_ch *ch)
{
  t_ch	*tmp;
  int	draw;

  aff_mem(vm);
  tmp = ch;
  draw = 0;
  while (tmp->next)
    {
      if (tmp->nb == vm->current)
	{
	  draw++;
	  write(1, "Le joueur ", 10);
	  put(tmp->nb);
	  write(1, "(", 1);
	  write(1, tmp->head.prog_name,
		my_strlen(tmp->head.prog_name));
	  write(1, ") a gagné.\n", 12);
	  return ;
	}
      tmp = tmp->next;
    }
  if (draw == 0)
    write(1, "Draw\n", 5);
}

void	my_free_all(t_ch *ch)
{
  if (ch->next != NULL)
    my_free_all(ch->next);
  free(ch);
}
