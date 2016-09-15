/*
** asm.h for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat Mar 26 13:51:35 2016 Iulian Rotaru
** Last update Sun Mar 27 23:15:13 2016 Iulian Rotaru
*/

#ifndef ASM_H_
# define ASM_H_

# include <stdlib.h>
# include "op.h"

int	reterr(char *msg, char *file, int ret);
int	my_strlen(char *str);
char	*get_term_line(int fd);
char	*my_strdup(char *str);
int	is_it_in(char find, char *str);
void	empty_stamp(t_header *stamp);
void	my_putstr_guill(char *str);
int	cache_cache(char *find, char *foret);
int	reterrline(char *msg, int line, int ret);
void	my_put_nbr(int nb, int fd);
void	print_tab(char **str);
int	check_if_empty(char *str);
int	fill_stamp(t_header *stamp, char *name, char *comment, char *str);
void	fill_name_stamp(t_header *stamp, char *name);
int	check_name_comm(char *name, char *comment, char *str);
int	my_getnbr(char *nb);
int	my_gethexa(char *nb);
int	ret_index(char c, char *str);
int	power(int nb, int pow);
int	my_strcmp(char *one, char *two);
int	is_it_num_deci(char *str);
int	is_it_direct(char *str);
int	is_it_reg(char *str);
int	is_it_indi(char *str);
int	is_it_indi_warn(char *str);
int	check_ld_op_label(t_op_stock *line);
int	check_st_op(t_op_stock *line);
int	check_st_op_label(t_op_stock *line);
int	check_live_op(t_op_stock *line);
int	is_it_num(char *str);
int	check_sub_op(t_op_stock *line);
int	check_sub_op_label(t_op_stock *line);
int	check_add_op(t_op_stock *line);
int	check_add_op_label(t_op_stock *line);
int	check_ld_op(t_op_stock *line);
int	check_xor_op_label(t_op_stock *line);
int	check_or_op(t_op_stock *line);
int	check_or_op_label(t_op_stock *line);
int	check_and_op(t_op_stock *line);
int	check_and_op_label(t_op_stock *line);
int	check_sti_op_label(t_op_stock *line);
int	check_ldi_op(t_op_stock *line);
int	check_ldi_op_next(t_op_stock *line);
int	check_zjmp_op(t_op_stock *line);
int	check_xor_op(t_op_stock *line);
int	check_lldi_op_label(t_op_stock *line);
int	check_lld_op(t_op_stock *line);
int	check_lld_op_label(t_op_stock *line);
int	check_fork_op(t_op_stock *line);
int	check_sti_op(t_op_stock *line);
int	check_if_empty_label_line(t_op_stock *line);
void	fill_tab(int (**tab)(t_op_stock *));
int	check_aff_op(t_op_stock *line);
int	check_lfork_op(t_op_stock *line);
int	check_lldi_op(t_op_stock *line);
void	fill_command_case_one(char *line, t_op_stock *tmp, int *i, int *lab);
void	fill_command_setuper(t_op_stock *tmp, int *i);
int	check_label(t_op_stock *tmp);
int	check_if_line_good(t_op_stock *line);
int	check_if_line_end(t_op_stock *line,
			  int command,
			  int (**tab)(t_op_stock *));
void	clean_line(char *line);
void	clean_line_small(char *line);
int	fill_command(char *line, t_op_stock *start);
int	fill_command_last_checks(t_op_stock *tmp,
				 int *i,
				 int *lab,
				 char *line);
int	fill_command_case_two(char *line, t_op_stock *tmp, int *i);
int	no_label_params_third(t_op_stock *tmp);
int	label_params(t_op_stock *tmp);
int	label_params_second(t_op_stock *tmp);
int	label_params_third(t_op_stock *tmp);
void	rm_coms(char *str);
int	size_ld_label(t_op_stock *tmp, int *out);
int	size_live(t_op_stock *tmp);
int	fill_params(t_op_stock *start);
int	no_label_params(t_op_stock *tmp);
int	no_label_params_second(t_op_stock *tmp);
int	size_sub(t_op_stock *tmp);
int	size_add(t_op_stock *tmp);
int	size_st(t_op_stock *tmp);
int	size_st_label(t_op_stock *tmp, int *out);
int	size_ld(t_op_stock *tmp);
void	size_or_second_label(t_op_stock *tmp, int *out);
int	size_and(t_op_stock *tmp);
void	size_and_second(t_op_stock *tmp, int *out);
int	size_and_label(t_op_stock *tmp, int *out);
void	size_and_second_label(t_op_stock *tmp, int *out);
int	size_xor_label(t_op_stock *tmp, int *out);
void	size_xor_second_label(t_op_stock *tmp, int *out);
int	size_or(t_op_stock *tmp);
void	size_or_second(t_op_stock *tmp, int *out);
int	size_or_label(t_op_stock *tmp, int *out);
int	size_ldi_label(t_op_stock *tmp, int *out);
void	size_ldi_second_label(t_op_stock *tmp, int *out);
int	size_zjmp(t_op_stock *tmp);
int	size_xor(t_op_stock *tmp);
void	size_xor_second(t_op_stock *tmp, int *out);
void	size_sti_second(t_op_stock *tmp, int *out);
int	size_sti_label(t_op_stock *tmp, int *out);
void	size_sti_second_label(t_op_stock *tmp, int *out);
int	size_ldi(t_op_stock *tmp);
void	size_ldi_second(t_op_stock *tmp, int *out);
void	size_lldi_second_label(t_op_stock *tmp, int *out);
int	size_lld(t_op_stock *tmp);
int	size_lld_label(t_op_stock *tmp, int *out);
int	size_fork(t_op_stock *tmp);
int	size_sti(t_op_stock *tmp);
int	size_aff(t_op_stock *tmp);
int	size_lfork(t_op_stock *tmp);
int	size_lldi(t_op_stock *tmp);
void	size_lldi_second(t_op_stock *tmp, int *out);
int	size_lldi_label(t_op_stock *tmp, int *out);
int	reterr_classic(char *str, int ret);
int	fill_list(t_op_stock *start);
int	fill_idx(t_op_stock *start);
int	fill_size(t_op_stock *start);
void	fill_second_tab(int (**tab)(t_op_stock *));
int	is_it_far(char *str);
int	read_commands(t_op_stock *start, int fd);
int	my_normal_strlen(char *str);
int	read_commands_list(t_op_stock *start);
int	empty_error(int line, int err);
int	write_live_label(t_op_stock *tmp,
			 int fd,
			 t_op_stock *start,
			 int *param);
int	write_int(int in, int fd);
int	write_short(short in, int fd);
int	check_if_dir_label(char *str, t_op_stock *start, int idx);
int	my_strcmp_label(char *one, char *two);
int	write_direct_spe(t_op_stock *tmp,
			 t_op_stock *start,
			 int fd,
			 int param);
void	write_direct_spe_label(t_op_stock *tmp,
			       t_op_stock *start,
			       u_shortochar *hey,
			       int param);
int	write_direct(t_op_stock *tmp, t_op_stock *start, int fd, int param);
void	write_direct_label(t_op_stock *tmp,
			   t_op_stock *start,
			   u_intochar *hey,
			   int param);
int	write_live(t_op_stock *tmp, t_op_stock *start, int fd);
int	write_param_nb(t_op_stock *tmp, int param, t_op_stock *start, int fd);
int	write_param_nb_end(t_op_stock *tmp,
			   int param,
			   t_op_stock *start,
			   int fd);
int	write_reg(t_op_stock *tmp, t_op_stock *start, int fd, int param);
int	write_indi(t_op_stock *tmp, t_op_stock *start, int fd, int param);
void	write_indi_label(t_op_stock *tmp,
			 t_op_stock *start,
			 int param,
			 u_shortochar *hey);
int	write_st_label(t_op_stock *tmp, t_op_stock *start, int fd);
int	write_ld(t_op_stock *tmp, t_op_stock *start, int fd);
int	write_ld_label(t_op_stock *tmp, t_op_stock *start, int fd);
int	write_param_nb_spe(t_op_stock *tmp,
			   int param,
			   t_op_stock *start,
			   int fd);
int	write_param_nb_spe_end(t_op_stock *tmp,
			       int param,
			       t_op_stock *start,
			       int fd);
int	write_sub(t_op_stock *tmp, t_op_stock *start, int fd);
int	write_sub_label(t_op_stock *tmp, t_op_stock *start, int fd);
int	write_add(t_op_stock *tmp, t_op_stock *start, int fd);
int	write_add_label(t_op_stock *tmp, t_op_stock *start, int fd);
int	write_st(t_op_stock *tmp, t_op_stock *start, int fd);
int	write_xor_label(t_op_stock *tmp, t_op_stock *start, int fd);
int	write_or(t_op_stock *tmp, t_op_stock *start, int fd);
int	write_or_label(t_op_stock *tmp, t_op_stock *start, int fd);
int	write_and(t_op_stock *tmp, t_op_stock *start, int fd);
int	write_and_label(t_op_stock *tmp, t_op_stock *start, int fd);
int	write_lldi_label(t_op_stock *tmp, t_op_stock *start, int fd);
int	write_ldi(t_op_stock *tmp, t_op_stock *start, int fd);
int	write_ldi_label(t_op_stock *tmp, t_op_stock *start, int fd);
int	write_zjmp(t_op_stock *tmp, t_op_stock *start, int fd);
int	write_xor(t_op_stock *tmp, t_op_stock *start, int fd);
int	write_aff(t_op_stock *tmp, t_op_stock *start, int fd);
int	write_aff_label(t_op_stock *tmp, t_op_stock *start, int fd);
int	write_sti(t_op_stock *tmp, t_op_stock *start, int fd);
int	write_sti_label(t_op_stock *tmp, t_op_stock *start, int fd);
int	write_lldi(t_op_stock *tmp, t_op_stock *start, int fd);
void	make_tab_end(int (**tab)(t_op_stock *, t_op_stock *, int fd));
int	write_lfork(t_op_stock *tmp, t_op_stock *start, int fd);
int	write_fork(t_op_stock *tmp, t_op_stock *start, int fd);
int	write_lld(t_op_stock *tmp, t_op_stock *start, int fd);
int	write_lld_label(t_op_stock *tmp, t_op_stock *start, int fd);
void	empty_file_new(t_op_stock *start);
int	preliminary_tests(int *fd,
			  t_op_stock *start,
			  char *str,
			  t_header *stamp);
void	my_putstr(char *str);
int	fill_headsize(t_op_stock *start, t_header *stamp);
int	write_code(t_op_stock *start, int fd);
int	end_it(t_op_stock *start, t_header *stamp, int *new);
int	handle_endian(t_header *stamp, u_intochar *conv);
int	file_new_end(int *i, t_op_stock *start);
void	file_new_first(int *i, char *str, t_op_stock *start, char *end);
void	file_new_second(int *i, t_op_stock *start, char *end);
int	compile_it(char *str);
int	is_it_direct_end(char *str);
int	classic_strlen(char *str);

#endif /* !ASM_H_ */
