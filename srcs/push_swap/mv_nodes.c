/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_nodes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:01:14 by becastro          #+#    #+#             */
/*   Updated: 2022/08/18 16:44:39 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_push(t_stack **stack_a, t_stack **stack_b, int ref)
{
	printf("stack a:\n");
	ft_show_list(stack_a);
	printf("stack b:\n");
	ft_show_list(stack_b);

	int	max_ref;

	if (stack_a)
	{
		max_ref = ft_lastnode(stack_a)->key;
		printf("ref (%d) max ref (%d)\n", ref, max_ref);
		if ((max_ref - ref) >= ref)
			printf("move up B");
		else
		{
			ft_rra(stack_a, true);
			printf("====test====\n");
			ft_show_list(stack_a);
		}
	}
	if (stack_b)
	{
		max_ref = ft_lastnode(stack_b)->key;
		printf("ref (%d) max ref (%d)\n", ref, max_ref);
		if (max_ref - ref > (ref))
			printf("move down");
	}
}
