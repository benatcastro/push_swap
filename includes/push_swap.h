/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
/*   Updated: 2022/07/19 02:29:44 by bena             ###   ########.fr       */
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
//----------------LIST UTILS---------------- //

int		ft_stack_size(t_stack **head);
void	ft_show_list(t_stack **head);

void	ft_check_args(int count, char **args);
void	ft_stack_init(t_stack **head, char **args);
#endif
