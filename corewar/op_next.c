/*
** op_next.c for corewar in /home/alif_m/tek1/CPE/CPE_2015_corewar
**
** Made by Alif Matthias
** Login   <alif_m@epitech.net>
**
** Started on  Sun Mar 27 08:44:28 2016 Alif Matthias
** Last update Thu Sep 15 15:35:16 2016 ROTARU Iulian
*/

#include "vm.h"
#include "op.h"

int	fill_tmp(t_vm *vm, t_ch *ch)
{
  int	tmp;

  tmp = 0;
  if (ch->types[0] == 1)
    tmp = ch->r[ch->args[0] % REG_NUMBER];
  if (ch->types[0] == 2)
    tmp = ch->args[0];
  if (ch->types[0] == 3)
    tmp = vm->mem[adjust(ch->pos + (ch->args[0] % IDX_MOD))];
  return (tmp);
}

void	and(t_vm *vm, t_ch *ch)
{
  int	tmp;
  int	rmp;

  rmp = 0;
  ch->carry = 1;
  tmp = fill_tmp(vm, ch);
  if (ch->types[1] == 1)
    rmp = ch->r[ch->args[1] % REG_NUMBER];
  if (ch->types[1] == 2)
    rmp = ch->args[1];
  if (ch->types[1] == 3)
    rmp = vm->mem[adjust(ch->pos + (ch->args[1] % IDX_MOD))];
  ch->r[ch->args[2] % REG_NUMBER] = tmp & rmp;
}

void	or(t_vm *vm, t_ch *ch)
{
  int	tmp;
  int	rmp;

  rmp = 0;
  tmp = fill_tmp(vm, ch);
  if (ch->types[1] == 1)
    rmp = ch->r[ch->args[1] % REG_NUMBER];
  if (ch->types[1] == 2)
    rmp = ch->args[1];
  if (ch->types[1] == 3)
    rmp = vm->mem[adjust(ch->pos + (ch->args[1] % IDX_MOD))];
  ch->r[ch->args[2] % REG_NUMBER] = tmp | rmp;
}

void	xor(t_vm *vm, t_ch *ch)
{
  int	tmp;
  int	rmp;

  tmp = fill_tmp(vm, ch);
  rmp = 0;
  if (ch->types[1] == 1)
    rmp = ch->r[ch->args[1] % REG_NUMBER];
  if (ch->types[1] == 2)
    rmp = ch->args[1];
  if (ch->types[1] == 3)
    rmp = vm->mem[adjust(ch->pos + (ch->args[1] % IDX_MOD))];
  ch->r[ch->args[2] % REG_NUMBER] = tmp ^ rmp;
}

void	zjmp(t_vm *vm, t_ch *ch)
{
  (void)vm;
  ch->pos += ch->args[0];
  ch->pc = adjust(ch->pos);
}
