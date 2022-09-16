#---------NAMES--------------
NAME = push_swap
CHECKER_NAME = checker_bonus
LIB_NAME 	= 42lib.a
LIBFT 		= libft
GNL 		= gnl
PRINTF 		= ft_printf
ARGS		=	10 10
#---------GCC and FLAGS----------

CC 	 		= gcc
AR			= ar rc
#CFLAGS 		= -Wall -Wextra -Werror -g3
SANITIZE 	= -fsanitize=address -g3
VALGRIND 	= valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

#---------DIRECTORIES-----------
SRC_DIR = srcs/
OBJ_DIR = objs/
INC_DIR = includes/
LIB_DIR = libraries/
PROJECT_DIR = $(SRC_DIR)$(NAME)/
SORTERS_DIR = $(SRC_DIR)$(NAME)/sorters/
CHECKER_DIR = $(SRC_DIR)/checker/

#---------------PREFIX and SUFFIX-----------------

all: push_swap

42lib: libft
	@$(AR) $(LIB_DIR)$(LIB_NAME) $(OBJ_DIR)*
	@ranlib $(LIB_DIR)$(LIB_NAME)
	@echo "42 Lib Compiled"

mk_dirs:
	@mkdir -p $(LIB_DIR)
	@mkdir -p $(OBJ_DIR)

push_swap: 42lib
	@$(CC) $(CFLAGS) $(PROJECT_DIR)*.c $(SORTERS_DIR)*.c $(LIB_DIR)$(LIB_NAME) -I $(INC_DIR) -o $(NAME)
	@echo "Push_swap Compiled"

valgrind:
	@clear
	@$(VALGRIND) ./$(NAME) $(ARGS)

checker: push_swap
	@$(CC) $(CFLAGS) $(CHECKER_DIR)*.c $(LIB_DIR)$(LIB_NAME) -I $(INC_DIR) -o $(CHECKER_NAME)
	@echo "Checker Compiled"

sanitize_checker: push_swap
	@$(CC) $(CFLAGS) $(SANITIZE) $(CHECKER_DIR)*.c $(LIB_DIR)$(LIB_NAME) -I $(INC_DIR) -o $(CHECKER_NAME)
	@echo "Checker sanitize Compiled"

valgrind_checker: checker
	@clear
	@$(VALGRIND) ./$(CHECKER_NAME)

run: all
	@clear
	@echo "====STARTS======"
	@./$(NAME) $(ARGS)

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
	@rm $(NAME)
	@rm checker_bonus

re: clean all
