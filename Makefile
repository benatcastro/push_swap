#---------NAMES--------------
NAME = push_swap
LIB_NAME 	= 42lib.a
LIBFT 		= libft
GNL 		= gnl
PRINTF 		= ft_printf
#---------GCC and FLAGS----------

CC 	 		= gcc
AR			= ar rc
CFLAGS 		= -Wall -Wextra -Werror
SANITIZE 	= -fsanitize=address -g3
VALGRIND 	= valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

#---------DIRECTORIES-----------
SRC_DIR = srcs/
OBJ_DIR = objs/
INC_DIR = includes/
LIB_DIR = libraries/

#---------FILES----------------

FILES_PUSH_SWAP = main


#---------------PREFIX and SUFFIX-----------------

SRC = $(addprefix $(SRC_DIR)push_swap/, $(addsuffix .c, $(FILES_PUSH_SWAP)))

#OBJF = .cache_exists

all: push_swap
	@$(AR) $(LIB_DIR)$(LIB_NAME) $(OBJ_DIR)*
	@ranlib $(LIB_DIR)$(LIB_NAME)
	@echo "42 Lib Compiled"

mk_dirs:
	@mkdir -p $(LIB_DIR)
	@mkdir -p $(OBJ_DIR)
push_swap: libft
	@$(CC) $(CFLAGS) $(SRC) -I $(INC_DIR) -o $(NAME)

libft: mk_dirs
	@make -C srcs/libft
	@clear
	@echo "Libft Compiled"

printf: mk_dirs libft
	@make -C srcs/ft_printf
	@clear
	@echo "Printf Compiled"

gnl: mk_dirs
	@make -C srcs/gnl
	@clear
	@echo "GNL Compiled"


clean:
	@make clean -C srcs/libft
	@make clean -C srcs/ft_printf
	@make clean -C srcs/gnl
	@clear

fclean: clean
	@rm -rf $(OBJ_DIR)
	@rm -rf $(LIB_DIR)
re: clean all
