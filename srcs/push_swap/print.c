/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:42:19 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/09/01 13:39:57 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_lst(t_stack *stack, t_moves *moves)
{
	while (stack)
	{
		printf("%d	->	%d,	", stack->key, stack->n);
		printf("%d ra,	%d rb,	%d rr	", moves->ra, moves->rb, moves->rr);
		printf("%d rra,	%d rrb,	%d rrr ", moves->rra, moves->rrb, moves->rrr);
		printf("Total moves -> %d\n", moves->total_moves);
		stack = stack->next;
	}
}

void	print_struct(t_data *data, t_moves *moves)
{
	write(1, "\n--- Stack a ---\n", 18);
	print_lst(data->stack_a, moves);
	write(1, "\n--- Stack b ---\n", 18);
	print_lst(data->stack_b, moves);
}
