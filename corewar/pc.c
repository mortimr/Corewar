/*
** pc.c for vm in /home/alif_m/tek1/CPE/CPE_2015_corewar
**
** Made by Alif Matthias
** Login   <alif_m@epitech.net>
**
** Started on  Mon Mar 21 20:57:30 2016 Alif Matthias
** Last update Fri Sep 02 19:29:21 2016 ROTARU Iulian
*/

#include <stdlib.h>
#include <unistd.h>
#include "vm.h"

void	get_all(t_vm *vm, t_ch *ch)
{
  ch->pc = adjust(ch->pc);
  ch->pos = ch->pc;
  if ((ch->op = vm->mem[ch->pc++] - 1) >= 0 && ch->op < 16)
    {
      ch->curr = g_tab[ch->op];
      if (ch->op == 0 || ch->op == 8 ||
	  ch->op == 11 || ch->op == 14)
	part(vm, ch);
      else
	get_byte(vm, ch);
      ch->wait = ch->curr.nbr_cycles;
    }
  else
    ch->pc++;
}

void	store_op(t_vm *vm, t_ch *ch)
{
  if (ch->op >= 0 && ch->op < 16)
    act(vm, ch);
  get_all(vm, ch);
}

void	act_or_not(t_vm *vm, t_ch *ch)
{
  t_ch	*tmp;

  tmp = ch;
  while (tmp->next)
    {
      if (tmp->wait <= 0)
	store_op(vm, tmp);
      tmp->wait -= 1;
      tmp = tmp->next;
    }
}

void	init_loop(t_vm *vm, t_ch *ch)
{
  t_ch	*tmp;

  vm->cycle = 0;
  vm->check = CYCLE_TO_DIE;
  vm->care = 0;
  vm->nbr_lives = 0;
  vm->current = -1;
  tmp = ch;
  while (tmp->next)
    {
      tmp->wait = 0;
      tmp->live = 0;
      tmp->r[1] = tmp->nb;
      tmp = tmp->next;
    }
}

int	main_loop(t_vm *vm, t_ch *ch)
{
  init_loop(vm, ch);
  while (vm->nb_progs > 1)
    {
      act_or_not(vm, ch);
      if (vm->care >= vm->check)
	vm->nb_progs = alive(vm, ch);
      if (vm->nbr_lives >= NBR_LIVE)
      	{
      	  vm->check -= CYCLE_DELTA;
      	  vm->nbr_lives = 0;
      	}
      vm->cycle += 1;
      vm->care++;
    }
  aff_end(vm, ch);
  my_free_all(ch);
  return (0);
}
