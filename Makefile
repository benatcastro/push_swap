#---------NAMES--------------
NAME = push_swap
CHECKER_NAME = checker_bonus
LIB_NAME 	= 42lib.a
LIBFT 		= libft
GNL 		= gnl
PRINTF 		= ft_printf
ARGS		=	10 10
#---------GCC and FLAGS----------
LIB_FLAG	= $(LIB_DIR)$(LIB_NAME)
INC_FLAG	= -I $(INC_DIR)
CFLAGS 		= -Wall -Wextra -Werror
CC 	 		= gcc
AR			= ar rc
SANITIZE 	= -fsanitize=address -g3
VALGRIND 	= valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

#---------DIRECTORIES-----------
SRC_DIR = srcs/
OBJ_DIR = objs
PUSH_SWAP_OBJ_DIR = $(OBJ_DIR)/push_swap/
CHECKER_OBJ_DIR = $(OBJ_DIR)/checker/
INC_DIR = includes/
LIB_DIR = libraries/
PROJECT_DIR = $(SRC_DIR)$(NAME)/
SORTERS_DIR = $(SRC_DIR)$(NAME)/sorters/
CHECKER_DIR = $(SRC_DIR)checker/
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
			push_swap		\

SOURCES_SORTERS =	defined_cases		\
					defined_cases_utils	\
					gen_short			\
					mv_utils			\
					reset_fncs			\
					sort_by_key			\
					sorter_logic		\

SOURCES_CHECKER =	checker_utils_bonus	\
					checker_bonus		\
#---------------PREFIX and SUFFIX-------------------


PUSH_SWAP_LOGIC_OBJS = $(addprefix $(PUSH_SWAP_OBJ_DIR)$(OBJ_PUSH_SWAP), $(addsuffix .o, $(SOURCES)))

PUSH_SWAP_SORTERS_OBJS = $(addprefix $(PUSH_SWAP_OBJ_DIR)$(OBJ_PUSH_SWAP), $(addsuffix .o, $(SOURCES_SORTERS)))

CHECKER_LOGIC_OBJS = $(addprefix $(CHECKER_OBJ_DIR)$(OBJ_CHECKER), $(addsuffix .o, $(SOURCES_CHECKER)))

PUSH_SWAP_OBJS += $(PUSH_SWAP_LOGIC_OBJS) $(PUSH_SWAP_SORTERS_OBJS)

CHECKER_OBJS += $(filter-out $(PUSH_SWAP_OBJ_DIR)push_swap.o, $(PUSH_SWAP_OBJS)) $(CHECKER_LOGIC_OBJS)


#---------------------RULES---------------------------
all: $(NAME)

$(NAME): 42lib $(PUSH_SWAP_LOGIC_OBJS) $(PUSH_SWAP_SORTERS_OBJS)
	@mkdir -p $(EXECS_DIR)
	$(CC) $(CFLAGS) $(PUSH_SWAP_OBJS) $(INC_FLAG) $(LIB_FLAG) -o $(EXECS_DIR)$(NAME)

$(PUSH_SWAP_OBJ_DIR)%.o: $(PROJECT_DIR)%.c
	@mkdir -p $(PUSH_SWAP_OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(PUSH_SWAP_OBJ_DIR)%.o: $(SORTERS_DIR)%.c
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@


bonus: $(CHECKER_LOGIC_OBJS) $(PUSH_SWAP_OBJS) 42lib
	@mkdir -p $(EXECS_DIR)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) $(INC_FLAG) $(LIB_FLAG) -o $(EXECS_DIR)$(CHECKER_NAME)

$(CHECKER_OBJ_DIR)%.o: $(CHECKER_DIR)%.c
	@mkdir -p $(CHECKER_OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

42lib: libft
	@$(AR) $(LIB_DIR)$(LIB_NAME) $(OBJ_DIR)/42lib/*.o
	@ranlib $(LIB_DIR)$(LIB_NAME)
	@echo "42 Lib Compiled"

mk_dirs:
	@mkdir -p $(OBJ_DIR)/42lib
	@mkdir -p $(LIB_DIR)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/$(NAME)


valgrind:
	@clear
	@$(VALGRIND) ./$(NAME) $(ARGS)

sanitize: $(NAME)
	$(CC) $(CFLAGS) $(SANITIZE) $(PUSH_SWAP_OBJS) $(INC_FLAG) $(LIB_FLAG) -o $(EXECS_DIR)$(NAME)_sanitize


sanitize_checker: bonus
	$(CC) $(CFLAGS) $(SANITIZE) $(CHECKER_OBJS) $(INC_FLAG) $(LIB_FLAG) -o $(EXECS_DIR)$(CHECKER_NAME)_sanitize


valgrind_checker: bonus
	@clear
	@$(VALGRIND) ./$(EXECS_DIR)$(CHECKER_NAME) 1

tester:
	@echo "Cloning testers..."
	@git submodule init
	@git submodule update
	@clear
	@echo "Testers cloned!"

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

.PHONY: testers all 42lib mk_dirs push_swap valgrind bonus sanitize_checker sanitize valgrind valgrind_checker run clean fclean re
