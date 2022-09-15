/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:39:28 by becastro          #+#    #+#             */
/*   Updated: 2022/09/15 13:50:51 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_lst(t_stack *stack)
{
	while (stack)
	{
		printf("%d	->	%d,	", stack->key, stack->n);
		printf("%d ra,	%d rb,	%d rr	", stack->s_mv.ra, stack->s_mv.rb, stack->s_mv.rr);
		printf("%d rra,	%d rrb,	%d rrr ", stack->s_mv.rra, stack->s_mv.rrb, stack->s_mv.rrr);
		printf("Total moves -> %d\n", stack->s_mv.moves);
		stack = stack->next;
	}
}

void	print_struct(t_data *data)
{
	printf("--- sizez ----\n A: (%d)\nB: (%d)\n", data->sz_a, data->sz_b);
	write(1, "\n--- Stack a ---\n", 18);
	print_lst(data->stack_a);
	write(1, "\n--- Stack b ---\n", 18);
	print_lst(data->stack_b);
}
