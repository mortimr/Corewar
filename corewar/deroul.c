/*
** deroul.c for corewar in /home/alif_m/tek1/CPE/CPE_2015_corewar
**
** Made by Alif Matthias
** Login   <alif_m@epitech.net>
**
** Started on  Sun Mar 27 09:42:54 2016 Alif Matthias
** Last update Fri Apr  1 12:17:32 2016 Alif Matthias
*/

#include "vm.h"
#include "op.h"

int	my_pow(int nb, int pow)
{
  int	i;
  int	tmp;

  i = 1;
  if (pow == 0)
    return (1);
  tmp = nb;
  while (i < pow)
    {
      nb *= tmp;
      i++;
    }
  return (nb);
}

int	octal(t_ch *ch, int type)
{
  int	size;

  size = 0;
  if (ch->order != 0 && ch->op == 10 && ch->types[ch->order] == 2)
    size = 2;
  else if (ch->order != 2 && ch->op == 9 && ch->types[ch->order] == 2)
    size = 2;
  else
    {
      if (type == 1)
	size = 1;
      if (type == 2)
	size = DIR_SIZE;
      if (type == 3)
	size = IND_SIZE;
    }
  return (size);
}

void	read_type(int type, t_vm *vm, t_ch *ch)
{
  int	i;
  int	size;
  char	tmp;
  short	trs;

  i = -1;
  size = octal(ch, type);
  ch->args[ch->order] = 0;
  while (++i < size)
    ch->args[ch->order] +=
      (vm->mem[adjust(ch->pc++)] * my_pow(256, size - (i + 1)));
  if (size == 1)
    {
      tmp = ch->args[ch->order];
      ch->args[ch->order] = tmp;
    }
  if (size == 2)
    {
      trs = ch->args[ch->order];
      ch->args[ch->order] = trs;
    }
}

void	get_byte(t_vm *vm, t_ch *ch)
{
  int	b;
  int	store;
  int	pc;

  b = 8;
  store = 1;
  ch->order = 0;
  ch->types[0] = 0;
  pc = vm->mem[adjust(ch->pc++)];
  while (--b >= 0)
    {
      if ((1 << b) & pc)
	ch->types[ch->order] += 1 << store;
      store--;
      if (store < 0 && ch->order < ch->curr.nbr_args)
	{
	  read_type(ch->types[ch->order], vm, ch);
	  ch->types[++ch->order] = 0;
	  store = 1;
	}
    }
}

static void	(* const g_fct[])(t_vm *vm, t_ch *ch) = {
  live,
  ld,
  st,
  add,
  sub,
  and,
  or,
  xor,
  zjmp,
  ldi,
  sti,
  mfork,
  lld,
  lldi,
  lfork,
  aff
};

void	act(t_vm *vm, t_ch *ch)
{
  if (ch->op < 16 && ch->op >= 0)
    g_fct[ch->op](vm, ch);
  else
    ch->pc++;
  ch->args[0] = 0;
  ch->args[1] = 0;
  ch->args[2] = 0;
  ch->types[0] = 0;
  ch->types[1] = 0;
  ch->types[2] = 0;
}
