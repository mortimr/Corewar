/*
** corewar.h for corewar in /home/alif_m/tek1/CPE/CPE_2015_corewar
**
** Made by Alif Matthias
** Login   <alif_m@epitech.net>
**
** Started on  Wed Mar 16 21:17:23 2016 Alif Matthias
** Last update Thu Sep 15 15:23:58 2016 ROTARU Iulian
*/

#ifndef COREWAR_H_
# define COREWAR_H_

# include "op.h"

typedef struct	s_ch
{
  int		r[REG_NUMBER + 1];
  int		pc;
  int		pos;
  int		carry;
  int		nb;
  char		*name;
  int		wait;
  t_op		curr;
  int		op;
  int		live;
  int		args[MAX_ARGS_NUMBER];
  int		types[MAX_ARGS_NUMBER];
  int		order;
  t_header	head;
  int		fd;
  struct s_ch	*next;
}		t_ch;

typedef struct	s_vm
{
  int		nb_progs;
  int		fd[4];
  unsigned char	mem[MEM_SIZE];
  int		cycle;
  int		store;
  int		current;
  int		check;
  int		dump;
  int		nbr_lives;
  int		care;
}		t_vm;

int	read_files(char **, t_vm *, t_ch *);
void	live(t_vm *vm, t_ch *ch);
void	ld(t_vm *vm, t_ch *ch);
void	st(t_vm *vm, t_ch *ch);
void	add(t_vm *vm, t_ch *ch);
void	sub(t_vm *vm, t_ch *ch);
void	and(t_vm *vm, t_ch *ch);
void	or(t_vm *vm, t_ch *ch);
void	xor(t_vm *vm, t_ch *ch);
void	zjmp(t_vm *vm, t_ch *ch);
void	ldi(t_vm *vm, t_ch *ch);
void	sti(t_vm *vm, t_ch *ch);
void	mfork(t_vm *vm, t_ch *ch);
void	lld(t_vm *vm, t_ch *ch);
void	lldi(t_vm *vm, t_ch *ch);
void	lfork(t_vm *vm, t_ch *ch);
void	aff(t_vm *vm, t_ch *ch);
void	aff_mem(t_vm *);
int	my_pow(int , int);
void	put(int);
void	mcpy(void *, const void *, unsigned long int);
void	put_in_mem(int, t_vm *vm, int, int);
int	my_strlen(char *);
void	store_in_mem(t_vm *, t_ch *);
int	parse_args(char **, t_vm *, t_ch *);
int	main_loop(t_vm *, t_ch *);
int	part(t_vm *, t_ch *);
void	get_byte(t_vm *, t_ch *);
void	act(t_vm *, t_ch *);
int	alive(t_vm *, t_ch *);
void	aff_end(t_vm *, t_ch *);
void	my_free_all(t_ch *);
int	my_getnbr(char *);
int	adjust(int);

#endif /* !COREWAR_H_ */
