#---------NAMES--------------
NAME = push_swap
CHECKER_NAME = checker_bonus
LIB_NAME 	= 42lib.a
LIBFT 		= libft
GNL 		= gnl
PRINTF 		= ft_printf
ARGS		=	10 10
#---------GCC and FLAGS----------
LIB_FLAGS	= $(LIB_DIR)$(LIB_NAME) -I $(INC_DIR)
CC 	 		= gcc
AR			= ar rc
CFLAGS 		= -Wall -Wextra -Werror #$(SANITIZE)
SANITIZE 	= -fsanitize=address -g3
VALGRIND 	= valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

#---------DIRECTORIES-----------
SRC_DIR = srcs/
OBJ_DIR = objs/
OBJ_PUSH_SWAP = $(OBJ_DIR)/push_swap
INC_DIR = includes/
LIB_DIR = libraries/
PROJECT_DIR = $(SRC_DIR)$(NAME)/
SORTERS_DIR = $(SRC_DIR)$(NAME)/sorters/
CHECKER_DIR = $(SRC_DIR)/checker/
EXECS_DIR	= execs/


#--------------------SOURCES-------------------------
SOURCES =	check_args		\
			find_fncs		\
			fncs_push		\
			fncs_rev_rotate	\
			fncs_rotate		\
			fncs_swap		\
			list_fncs		\
			list_utils		\
			mv_nodes		\
			stack_init		\

SOURCES_SORTERS =	defined_cases		\
					defined_cases_utils	\
					gen_short			\
					mv_utils			\
					reset_fncs			\
					sort_by_key			\
					sorter_logic		\

SOURCES_CHECKER =	checker_utils_bonus	\
#---------------PREFIX and SUFFIX-------------------

SRC = $(addprefix $(PROJECT_DIR), $(addsuffix .c, $(SOURCES)))

SRC_SORTERS = $(addprefix $(SORTERS_DIR), $(addsuffix .c, $(SOURCES_SORTERS)))

SRC_CHECKER = $(addprefix $(CHECKER_DIR), $(addsuffix .c, $(SOURCES_CHECKER)))


#---------------------RULES---------------------------
all: $(NAME)

$(NAME): 42lib
	@mkdir -p $(EXECS_DIR)
	@$(CC) $(CFLAGS) $(SRC) $(PROJECT_DIR)main.c $(SRC_SORTERS) $(LIB_FLAGS) -o $(EXECS_DIR)$(NAME)
	@echo "Push_swap Compiled"

42lib: libft

	@$(AR) $(LIB_DIR)$(LIB_NAME) $(OBJ_DIR)*
	@ranlib $(LIB_DIR)$(LIB_NAME)
	@echo "42 Lib Compiled"

mk_dirs:
	@mkdir -p $(LIB_DIR)
	@mkdir -p $(OBJ_DIR)

push_swap: 42lib

valgrind:
	@clear
	@$(VALGRIND) ./$(NAME) $(ARGS)

bonus: push_swap
	@mkdir -p $(EXECS_DIR)
	@$(CC) $(CFLAGS) $(SRC) $(CHECKER_DIR)main_bonus.c $(SRC_SORTERS) $(SRC_CHECKER) $(LIB_FLAGS) -o $(EXECS_DIR)$(CHECKER_NAME)
	@echo "Checker Compiled"

sanitize_checker: push_swap
		@$(CC) $(CFLAGS) $(SANITIZE) $(SRC) $(CHECKER_DIR)main_bonus.c $(SRC_SORTERS) $(SRC_CHECKER) $(LIB_FLAGS) -o $(CHECKER_NAME)
	@echo "Checker sanitize Compiled"

valgrind_checker: checker
	@clear
	@$(VALGRIND) ./$(CHECKER_NAME) 2 1

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
	@rm -rf $(OBJ_DIR)
	@echo "Clean done"

fclean: clean
	@rm -rf $(LIB_DIR)
	@rm -rf $(EXECS_DIR)
	@echo "Fclean Done"

re: clean all

.PHONY: all 42lib mk_dirs push_swap valgrind bonus sanitize_checker sanitize valgrind valgrind_checker run clean fclean re
