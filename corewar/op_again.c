/*
** op_again.c for corewar in /home/alif_m/tek1/CPE/CPE_2015_corewar
**
** Made by Alif Matthias
** Login   <alif_m@epitech.net>
**
** Started on  Sun Mar 27 08:45:29 2016 Alif Matthias
** Last update Sun Mar 27 18:46:19 2016 Alif Matthias
*/

#include <stdlib.h>
#include "vm.h"
#include "op.h"

void	ldi(t_vm *vm, t_ch *ch)
{
  int	tmp;

  tmp = 0;
  if (ch->types[0] == 1)
    tmp = ch->r[ch->args[0]];
  if (ch->types[0] == 2)
    tmp = ch->pos + ch->args[1];
  if (ch->types[0] == 3)
    tmp = vm->mem[adjust(ch->pos + (ch->args[0] % IDX_MOD))];
  if (ch->types[1] == 3)
    tmp += ch->args[1];
  if (ch->types[1] == 1)
    tmp += ch->r[ch->args[1] % REG_NUMBER];
  ch->r[ch->args[2] % REG_NUMBER] = tmp;
}

void	sti(t_vm *vm, t_ch *ch)
{
  int	tmp;

  tmp = 0;
  if (ch->types[1] == 1)
    tmp = ch->r[ch->args[1] % REG_NUMBER];
  if (ch->types[1] == 2)
    tmp = ch->args[1];
  if (ch->types[1] == 3)
    tmp = vm->mem[adjust(ch->args[1])];
  if (ch->types[2] == 1)
    tmp += ch->r[ch->args[2] % REG_NUMBER];
  if (ch->types[2] == 2)
    tmp += ch->args[2];
  put_in_mem(ch->r[(ch->args[0] % REG_NUMBER)],
	     vm, adjust(ch->pos + tmp), 4);
}

void	mfork(t_vm *vm, t_ch *ch)
{
  t_ch	*tmp;
  t_ch	*new;
  t_ch	*tr;

  (void)vm;
  tmp = ch;
  tr = ch->next;
  if ((new = malloc(sizeof(t_ch))) != NULL)
    {
      tmp->next = new;
      mcpy(new, ch, sizeof(t_ch));
      new->pc = adjust(ch->pos + (ch->args[0] % IDX_MOD));
      new->wait = 0;
      new->op = -1;
      new->next = tr;
    }
}

void	lld(t_vm *vm, t_ch *ch)
{
  if (ch->types[0] == 2)
    ch->r[ch->args[0]] = ch->args[1];
  if (ch->types[0] == 3)
    ch->r[ch->args[0]] = vm->mem[adjust(ch->pos +
					(ch->args[1] % IDX_MOD))];
}

void	lldi(t_vm *vm, t_ch *ch)
{
  int	tmp;

  tmp = 0;
  if (ch->types[0] == 1)
    tmp = ch->r[ch->args[0]];
  if (ch->types[0] == 2)
    tmp = ch->pos + ch->args[1];
  if (ch->types[0] == 3)
    tmp = vm->mem[adjust(ch->pos + ch->args[0])];
  if (ch->types[1] == 3)
    tmp += ch->args[1];
  if (ch->types[1] == 1)
    tmp += ch->r[ch->args[1] % REG_NUMBER];
  ch->r[ch->args[2] % REG_NUMBER] = tmp;
}
