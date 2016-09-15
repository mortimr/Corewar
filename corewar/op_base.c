/*
** op_base.c for corewar in /home/alif_m/tek1/CPE/CPE_2015_corewar
**
** Made by Alif Matthias
** Login   <alif_m@epitech.net>
**
** Started on  Sun Mar 27 08:41:30 2016 Alif Matthias
** Last update Thu Sep 15 15:26:45 2016 ROTARU Iulian
*/

#include <unistd.h>
#include "vm.h"

void	live(t_vm *vm, t_ch *ch)
{
  if (ch->args[0] >= 0 && ch->args[0] < 4)
    {
      write(1, "Le joueur ", 10);
      put(ch->nb);
      write(1, "(", 1);
      write(1, ch->head.prog_name, my_strlen(ch->head.prog_name));
      write(1, ") est en vie\n", 13);
      ch->live = 1;
      vm->nbr_lives++;
    }
}

void	ld(t_vm *vm, t_ch *ch)
{
  ch->carry = 1;
  if (ch->types[0] == 2)
    ch->r[ch->args[1]] = ch->args[0];
  else if (ch->types[0] == 3)
    ch->r[ch->args[1]] = vm->mem[adjust(ch->pos +
				  (ch->args[0] % IDX_MOD))];
  else
    ch->carry = 0;
}

void	st(t_vm *vm, t_ch *ch)
{
  if (ch->types[1] == 1)
    ch->r[ch->args[1] % REG_NUMBER] =
      ch->r[ch->args[0] % REG_NUMBER];
  if (ch->types[1] == 3)
    {
      put_in_mem(ch->r[ch->args[0] % REG_NUMBER], vm,
		 adjust(ch->pos + ch->args[1]), REG_SIZE);
   }
}

void	add(t_vm *vm, t_ch *ch)
{
  (void)vm;
  ch->carry = 1;
  ch->r[ch->args[2] % REG_NUMBER] =
    ch->r[ch->args[1] % REG_NUMBER] +
    ch->r[ch->args[0] % REG_NUMBER];
}

void	sub(t_vm *vm, t_ch *ch)
{
  (void)vm;
  ch->carry = 1;
  ch->r[ch->args[2] % REG_NUMBER] =
    ch->r[ch->args[1] % REG_NUMBER] -
    ch->r[ch->args[0] % REG_NUMBER];
}
