/*
** op_final.c for corewar in /home/alif_m/tek1/CPE/CPE_2015_corewar
**
** Made by Alif Matthias
** Login   <alif_m@epitech.net>
**
** Started on  Sun Mar 27 08:47:39 2016 Alif Matthias
** Last update Sun Mar 27 18:59:35 2016 Alif Matthias
*/

#include <stdlib.h>
#include "op.h"
#include "vm.h"

void	lfork(t_vm *vm, t_ch *ch)
{
  t_ch	*tmp;

  (void)vm;
  tmp = ch;
  while (tmp)
    tmp = tmp->next;
  if ((tmp = malloc(sizeof(t_ch))))
    {
      mcpy(tmp, ch, sizeof(t_ch));
      tmp->pc = adjust(ch->pos + ch->args[0]);
      tmp->wait = 1;
      tmp->op = -1;
      tmp->nb = ch->nb;
      tmp->next = NULL;
    }
}

void	aff(t_vm *vm, t_ch *ch)
{
  (void)vm;
  if (ch->args[0] > 0 && ch->args[0] < 16)
    put(ch->r[ch->args[0]]);
}

int	part(t_vm *vm, t_ch *ch)
{
  int	i;
  int	size;
  short	conv;

  ch->args[0] = 0;
  if (ch->op == 0)
    size = 4;
  else
    size = 2;
  i = -1;
  while (++i < size)
    ch->args[0] += vm->mem[adjust(ch->pc++)] * my_pow(256, size - (i + 1));
  if (size == 2)
    {
      conv = ch->args[0];
      ch->args[0] = conv;
    }
  return (0);
}
