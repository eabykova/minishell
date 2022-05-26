# FOR MAC_OS
NAME	=	minishell
NAME_B	=	minishell_bonus

HEAD	=	minishell.h
HEAD_B	=	minishell_bonus.h

SRC		=	main.c \
				src/pipex.c

#SRC_B		=

LIB_DIR	=	./lib/
LIB		=	libft.a

OBJ		=	$(SRC:%.c=%.o)
OBJ_B	=	$(SRC_B:%.c=%.o)

D_FIL	=	$(SRC:%.c=%.d)
D_FIL_B	=	$(SRC_B:%.c=%.d)

FLAG	=	-Imlx -g -Wall -Werror -Wextra
#-fsanitize=address -g

CC		=	gcc -O2 -MD
RM		=	rm -f

.PHONY		:	all clean fclean re bonus

all			:	libmake $(NAME) Makefile

$(NAME)		:	$(OBJ) $(LIB_DIR)$(LIB)
	$(CC) $(FLAG) $(OBJ) $(LIB_DIR)$(LIB) -o $(NAME)
	@echo "✅	Minishell is ready. Enjoy     ✅ "

bonus		:	 all $(NAME_B) Makefile

$(NAME_B)	:	$(OBJ_B) $(LIB_DIR)$(LIB)
	$(CC) $(FLAG) $(OBJ_B) $(LIB_DIR)$(LIB) -o $(NAME_B)
	@echo "✅	Minishell_bonus is ready. Enjoy     ✅ "

libmake	:
	@make -C $(LIB_DIR)

%.o		:	%.c $(HEAD) $(HEAD_B)
	$(CC) $(FLAG) -c $< -o $@

include $(wildcard $(D_FIL) $(D_FIL_B))

clean		:
	@make clean -C $(LIB_DIR)

	$(RM) $(OBJ) $(D_FIL) $(OBJ_B) $(D_FIL_B)
fclean		:	clean
	@make fclean -C $(LIB_DIR)
	$(RM) $(NAME) $(NAME_B)

re		:	fclean all
