/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
/*   Updated: 2022/07/31 18:26:06 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stdio.h"

typedef struct t_stack
{
	int				n;
	struct t_stack	*next;
	struct t_stack	*before;

}	t_stack;

//--------------SWAP FNCS-----------------//

void	ft_sa(t_stack **head_a);
void	ft_sb(t_stack **head_b);
void	ft_ss(t_stack **head_a, t_stack **head_b);
//----------------LIST UTILS---------------- //

int		ft_stack_size(t_stack **head);
void	ft_show_list(t_stack **head);
void	ft_free_node(t_stack **head, t_stack *ref_node);
void	ft_create_node(t_stack **head, int n);
void	ft_addstack(t_stack **head, t_stack *node);

void	ft_check_args(int count, char **args);
void	ft_stack_init(t_stack **head, char **args);
#endif
