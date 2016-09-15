/*
** main.c for corewar in /home/alif_m/tek1/CPE/CPE_2015_corewar/assembleur
**
** Made by Alif Matthias
** Login   <alif_m@epitech.net>
**
** Started on  Mon Mar 14 15:40:29 2016 Alif Matthias
** Last update Sun Mar 27 21:55:08 2016 Alif Matthias
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "op.h"
#include "vm.h"

void	mset(unsigned char *tab, int size, int value)
{
  int	i;

  i = 0;
  while (i < size)
    tab[i++] = value;
}

void	set_base(t_ch *ch)
{
  int	i;
  t_ch *tmp;

  tmp = ch;
  while (tmp)
    {
      i = 1;
      while (i < REG_NUMBER)
	tmp->r[i++] = 0;
      tmp->r[1] = tmp->nb;
      tmp = tmp->next;
    }
}

int	check_env()
{
  if (REG_NUMBER < 2 || MAX_ARGS_NUMBER < 3 ||
      MEM_SIZE < 2000 || IDX_MOD < 100)
    return (-1);
  return (0);
}

int	main(int ac, char **av)
{
  t_vm	vm;
  t_ch	*ch;

  if ((check_env()) == -1)
    {
      write(2, "Bad macros\n", 11);
      return (-1);
    }
  if (ac < 2 || (ch = malloc(sizeof(t_ch))) == NULL)
    return (EXIT_FAILURE);
  vm.store = 0;
  vm.nb_progs = 0;
  mset(vm.mem, MEM_SIZE, 0);
  if ((parse_args(av, &vm, ch)) == -1)
    {
      write(2, "Syntax error\n", 13);
      return (EXIT_FAILURE);
    }
  set_base(ch);
  main_loop(&vm, ch);
  return (0);
}
