#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct t_stack
{
	t_num	**numbers;

}	t_stack;

typedef struct t_num
{
	int		n;
	t_num	*next;
	t_num	*before;
}	t_num
#endif
