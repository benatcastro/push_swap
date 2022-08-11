/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fncs_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
/*   Updated: 2022/08/11 19:10:41 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Takes the first element of the stack B and pushes it to the top of the stack A
If the stack B is empty it does nothing*/
void	ft_pa(t_stack **head_a, t_stack **head_b)
{
	ft_putstr_fd("pa\n", 1);
	if (!(*head_b))
		return ;
	ft_create_node(head_a, (*head_b)->n);
	ft_free_node(head_b, (*head_b));
}

void	ft_pb(t_stack **head_a, t_stack **head_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	ft_putstr_fd("pb\n", 1);
	if (!(*head_a))
		return ;
	tmp_a = (*head_a);
	tmp_b = (*head_b);
	(*head_a) = (*head_a)->next;
	tmp_a->next = NULL;
	if (!head_b)
		(*head_b) = tmp_a;
	else
	{
		tmp_a->next = tmp_b;
		(*head_b) = tmp_a;
	}
}
