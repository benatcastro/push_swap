/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
/*   Updated: 2022/08/12 19:43:40 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stdio.h"

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
//----------------LIST UTILS---------------- //

void	ft_swap_node(t_stack *node1, t_stack *node2);
int		ft_stack_size(t_stack **head);
void	ft_show_list(t_stack **head);
t_stack	*ft_lastnode(t_stack **head);

void	ft_free_node(t_stack **head, t_stack *ref_node);
void	ft_create_node(t_stack **head, int n);
void	ft_addnode(t_stack **head, t_stack *node);

void	ft_check_args(int count, char **args);
void	ft_stack_init(t_stack **head, char **args);
#endif
