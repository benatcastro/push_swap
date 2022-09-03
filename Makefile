#---------NAMES--------------
NAME = push_swap
LIB_NAME 	= 42lib.a
LIBFT 		= libft
GNL 		= gnl
PRINTF 		= ft_printf
ARGS	=	1000 12 64 86 95 123 654
#---------GCC and FLAGS----------

CC 	 		= gcc
AR			= ar rc
#CFLAGS 		= -Wall -Wextra -Werror
SANITIZE 	= -fsanitize=address -g3
VALGRIND 	= valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

#---------DIRECTORIES-----------
SRC_DIR = srcs/
OBJ_DIR = objs/
INC_DIR = includes/
LIB_DIR = libraries/
PROJECT_DIR = $(SRC_DIR)$(NAME)/
SORTERS_DIR = $(SRC_DIR)$(NAME)/sorters/

#---------------PREFIX and SUFFIX-----------------


#OBJF = .cache_exists
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

sanitize: 42lib
	@$(CC) $(CFLAGS) $(SANITIZE) $(PROJECT_DIR)*.c $(SORTERS_DIR)*.c $(LIB_DIR)$(LIB_NAME) -I $(INC_DIR) -o $(NAME)
	@echo "Push_swap with sanitize Compiled"
	@clear
	@./$(NAME) $(ARGS)

run: all
	@clear
	@./$(NAME) $(ARGS)

valgrind:
	@clear
	@$(VALGRIND) ./$(NAME) $(ARGS)

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
