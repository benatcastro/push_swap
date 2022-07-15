#include "push_swap.h"

static	t_num	*ft_create_num(t_num **head, int n)
{
	t_num	*node;

	node = malloc(sizeof(t_num));
	node->n = n;
	node->next = NULL;
	return (node);
}

static void	ft_lstadd_num(t_num **head, t_num node)
{
	if (!head)
	{

	}
}

/*
initializes stacks A and B
n = number of digits on the input
*/
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		n;
	int		i;

	n = argc -1;
	i = 1;
	while (i < n)
	{
	}
}
