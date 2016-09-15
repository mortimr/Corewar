/*
** op.h for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Fri Mar 25 16:39:26 2016 Iulian Rotaru
** Last update Wed Apr  6 15:24:08 2016 Alif Matthias
*/

#ifndef OP_H_
# define OP_H_

# ifndef MEM_SIZE
#  define MEM_SIZE (6*1024)
# endif /* !MEM_SIZE */

# ifndef IDX_MOD
#  define IDX_MOD (512)
# endif /* !IDX_MOD */

# ifndef MAX_ARGS_NUMBER
#  define MAX_ARGS_NUMBER (4)
# endif /* !MAX_ARGS_NUMBER */

# ifndef COMMENT_CHAR
#  define COMMENT_CHAR ('#')
# endif /* !COMMENT_CHAR */

# ifndef LABEL_CHAR
#  define LABEL_CHAR (':')
# endif /* !LABEL_CHAR */

# ifndef DIRECT_CHAR
#  define DIRECT_CHAR ('%')
# endif /* !DIRECT_CHAR */

# ifndef SEPARATOR_CHAR
#  define SEPARATOR_CHAR (',')
# endif /* !SEPARATOR_CHAR */

# ifndef LABEL_CHARS
#  define LABEL_CHARS ("abcdefghijklmnopqrstuvwxyz_0123456789")
# endif /* !LABEL_CHARS */

# ifndef NAME_CMD_STRING
#  define NAME_CMD_STRING (".name")
# endif /* !NAME_CMD_STRING */

# ifndef COMMENT_CMD_STRING
#  define COMMENT_CMD_STRING (".comment")
# endif /* !COMMENT_CMD_STRING */

# ifndef REG_NUMBER
#  define REG_NUMBER (16)
# endif /* !REG_NUMBER */

# ifndef T_REG
#  define T_REG (1)
# endif /* !T_REG */

# ifndef T_DIR
#  define T_DIR (2)
# endif /* !T_DIR */

# ifndef T_IND
#  define T_IND (4)
# endif /* T_IND */

# ifndef T_LAB
#  define T_LAB (8)
# endif /* !T_LAB */

# ifndef IND_SIZE
#  define IND_SIZE (2)
# endif /* !IND_SIZE */

# ifndef REG_SIZE
#  define REG_SIZE (4)
# endif /* !REG_SIZE */

# ifndef DIR_SIZE
#  define DIR_SIZE (REG_SIZE)
# endif /* !DIR_SIZE */

# ifndef PROG_NAME_LENGTH
#  define PROG_NAME_LENGTH (128)
# endif /* !PROG_NAME_LENGTH */

# ifndef COMMENT_LENGTH
#  define COMMENT_LENGTH (2048)
# endif /* !COMMENT_LENGTH */

# ifndef COREWAR_EXEC_MAGIC
#  define COREWAR_EXEC_MAGIC (0xea83f3)
# endif /* !COREWAR_EXEC_MAGIC */

# ifndef CYCLE_TO_DIE
#  define CYCLE_TO_DIE (1536)
# endif /* !CYCLE_TO_DIE */

# ifndef CYCLE_DELTA
#  define CYCLE_DELTA (5)
# endif /* !CYCLE_DELTA */

# ifndef NBR_LIVE
#  define NBR_LIVE (40)
# endif /* !NBR_LIVE */

typedef char	args_type_t;

typedef struct	s_op
{
   char         *mnemonique;
   char         nbr_args;
   args_type_t  type[MAX_ARGS_NUMBER];
   char         code;
   int          nbr_cycles;
   char         *comment;
}		t_op;

typedef struct	s_header
{
  int		magic;
  char		prog_name[PROG_NAME_LENGTH+1];
  int		prog_size;
  char		comment[COMMENT_LENGTH+1];
}		t_header;

typedef struct		s_op_stock
{
  char			file_new[1024];
  int			code;
  char			*code_string;
  char			size;
  unsigned char		codage;
  int			idx;
  char			opcode;
  char			command[6][100];
  unsigned int		nb;
  int			label;
  char			*name;
  char			*comment;
  struct s_op_stock	*next;
}			t_op_stock;

typedef union		s_intochar
{
  int			in;
  unsigned char		out[4];
}			u_intochar;

typedef union		s_shortochar
{
  short			in;
  unsigned char		out[2];
}			u_shortochar;

extern t_op	g_tab[];

#endif /* !OP_H_ */
