/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
/*   Updated: 2022/08/17 00:12:00 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stdio.h"
# include "stdbool.h"

typedef struct t_stack
{
	int				key;
	int				n;
	struct t_stack	*next;
	struct t_stack	*prev;
}	t_stack;

//--------------SWAP FNCS-----------------//

void	ft_sa(t_stack **head_a);
void	ft_sb(t_stack **head_b);
void	ft_ss(t_stack **head_a, t_stack **head_b);
void	ft_pa(t_stack **head_a, t_stack **head_b);
void	ft_pb(t_stack **head_a, t_stack **head_b);
void	ft_ra(t_stack **head_a);
void	ft_rb(t_stack **head_b);
void	ft_rr(t_stack **head_a, t_stack **head_b);
void	ft_rra(t_stack **head_a, bool print);
void	ft_rrb(t_stack **head_b, bool print);
void	ft_rrr(t_stack **head_a, t_stack **head_b);
//----------------LIST UTILS---------------- //

void	ft_swap_node(t_stack **head, t_stack *node1, t_stack *node2);
void	ft_swap_head_node(t_stack **head, t_stack *node1, t_stack *node2);
int		ft_stack_size(t_stack **head);
void	ft_show_list(t_stack **head);
t_stack	*ft_lastnode(t_stack **head);
t_stack	*ft_find_node(t_stack **head, int ref);
void	ft_arrange_links(t_stack **head_a, t_stack **head_b);

void	ft_free_node(t_stack **head, t_stack *ref_node);
void	ft_create_node(t_stack **head, int n);
void	ft_addnode(t_stack **head, t_stack *node);

void	ft_check_args(int count, char **args);
void	ft_stack_init(t_stack **head, char **args);
#endif
