/*
** utils.c for corewar in /home/alif_m/tek1/CPE/CPE_2015_corewar
**
** Made by Alif Matthias
** Login   <alif_m@epitech.net>
**
** Started on  Sun Mar 27 09:34:47 2016 Alif Matthias
** Last update Mon Apr  4 16:16:55 2016 Alif Matthias
*/

#include <unistd.h>
#include "vm.h"
#include "op.h"

void	my_putnbr_hexa(const unsigned int nb, const int loop)
{
  if (loop == 2)
    return ;
  my_putnbr_hexa(nb / 16, loop + 1);
  write(1, &(("0123456789ABCDEF")[nb % 16]), 1);
}

void	aff_mem(t_vm *vm)
{
  int	i;

  i = 0;
  while (i < MEM_SIZE)
    {
      my_putnbr_hexa(vm->mem[i++], 0);
      if (i % 32 == 0)
	write(1, "\n", 1);
    }
}

void	put_in_mem(int value, t_vm *vm, int pos, int size)
{
  int	i;

  i = size - 1;
  while (i >= 0)
    {
      if (i < 3)
	vm->mem[pos] = (value % my_pow(256, i + 1)) / my_pow(256, i);
      else
	vm->mem[pos] = value / my_pow(256, i);
      i--;
      pos++;
    }
}

void			mcpy(void *dest,
			     const void *src,
			     unsigned long int n)
{
  char			*dst;
  const char		*tmp;
  unsigned long int	i;

  if (!(dst = dest) || !(tmp = src))
    return ;
  i = 0;
  while (i < n)
    {
      *(dst + i) = *(tmp + i);
      i++;
    }
}
