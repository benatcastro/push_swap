#---------NAMES--------------
NAME = push_swap
LIB_NAME 	= 42lib.a
LIBFT 		= libft
GNL 		= gnl
PRINTF 		= ft_printf
ARGS		=	29825 12178 13547 4012 18707 22781 4494 210 23347 11873 28390 11388 12833 7301 7614 30915 25211 6433 31462 20158 19607 17019 2149 18606 27495 2828 28135 18618 25387 15690 21099 20749 17830 9791 12676 4712 16879 24462 26241 5403 7644 32360 5260 427 9499 19721 21678 31755 27094 20088 30699 10470 3623 16186 7936 7328 17889 30354 32095 32156 2564 11305 2946 14302 30183 9682 5691 8565 29865 31749 7034 27140 22547 28628 32158 11719 15562 7600 28730 2692 30708 11926 10926 3491 11150 23675 21869 532 22845 193 30102 21660 25622 41000 12 64 86 95 123 654
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
