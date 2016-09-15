##
## Makefile for makefile in /home/alif_m/tek1/CPE/CPE_2015_BSQ
## 
## Made by Matthias alif
## Login   <alif_m@epitech.net>
## 
## Started on  Thu Dec  3 11:01:23 2015 Matthias alif
## Last update Thu Sep 15 15:23:16 2016 ROTARU Iulian
##

CC	=	gcc -g

RM	=	rm -f

NAME1	=	./corewar/corewar

NAME2	=	./asm/asm

CFLAGS	+= 	-Wextra -Wall -Werror

CFLAGS	+= 	-I./include

SRCS1	=	corewar/vm.c		\
		corewar/op.c		\
		corewar/storage.c 	\
		corewar/pc.c		\
		corewar/my_getnbr.c	\
		corewar/parse.c		\
		corewar/op_base.c	\
		corewar/op_next.c	\
		corewar/op_again.c	\
		corewar/op_final.c	\
		corewar/utils.c		\
		corewar/deroul.c	\
		corewar/others.c	\

SRCS2	= 	asm/src/main.c \
	  	asm/src/op.c \
	 	asm/src/is_it_in.c \
	 	asm/src/my_put_nbr.c \
	 	asm/src/check_name_comm.c \
	 	asm/src/my_strcmp.c \
	 	asm/src/is_it_indi_warn.c \
	 	asm/src/is_it_num.c \
	 	asm/src/check_ld_op.c \
	 	asm/src/check_and_op_label.c \
	 	asm/src/check_xor_op.c \
	 	asm/src/check_sti_op.c \
	 	asm/src/check_lldi_op.c \
	 	asm/src/check_if_line_good.c \
	 	asm/src/fill_command_case_two.c \
	 	asm/src/rm_coms.c \
	  	asm/src/no_label_params_second.c \
		asm/src/size_ld.c \
		asm/src/size_and_second_label.c \
		asm/src/size_or_label.c \
		asm/src/size_xor_second.c \
		asm/src/size_ldi_second.c \
		asm/src/size_sti.c \
		asm/src/size_lldi_label.c \
		asm/src/fill_second_tab.c \
		asm/src/empty_error.c \
		asm/src/my_strcmp_label.c \
		asm/src/write_live.c \
		asm/src/write_indi_label.c \
		asm/src/write_param_nb_spe_end.c \
		asm/src/write_st.c \
		asm/src/write_and_label.c \
		asm/src/write_xor.c \
		asm/src/write_lldi.c \
		asm/src/write_lld_label.c \
		asm/src/write_code.c \
		asm/src/file_new_second.c \
		asm/src/is_it_direct.c 

OBJS1	=	$(SRCS1:.c=.o)

OBJS2	=	$(SRCS2:.c=.o)

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJS1)
	@echo -e "\033[3;34m" 
	$(CC) -o $(NAME1) $(OBJS1)
	@echo "------------"
	@echo "| VM [OK] |"
	@echo "------------"
	@echo -e "\033[0m" 


$(NAME2): $(OBJS2)
	@echo -e "\033[3;32m" 
	$(CC) -o $(NAME2) $(OBJS2)
	@echo "------------"
	@echo "| ASM [OK] |"
	@echo "------------"
	@echo -e "\033[0m" 

clean:
	$(RM) $(OBJS1)
	$(RM) $(OBJS2)

fclean: clean
	$(RM) $(NAME1)
	$(RM) $(NAME2)

re: fclean all

.PHONY: all clean fclean re
