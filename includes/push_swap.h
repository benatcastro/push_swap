/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
/*   Updated: 2022/08/19 06:41:06 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stdio.h"
# include "stdbool.h"

enum e_sorters
{
	SORT_3,
	SORT_5,
	QUICK_SHORT
};

typedef struct s_stack
{
	int				key;
	int				n;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;
typedef struct s_data
{
	int				sorter;
	size_t			stack_size;
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;

}	t_data;
//--------------PROGRAM LOGIC-----------------//

void	ft_sorter_manager(t_data *data);
//--------------SWAP FNCS-----------------//

void	ft_sa(t_stack **head_a, bool print);
void	ft_sb(t_stack **head_b, bool print);
void	ft_ss(t_stack **head_a, t_stack **head_b);
void	ft_pa(t_stack **head_a, t_stack **head_b);
void	ft_pb(t_stack **head_a, t_stack **head_b);
void	ft_ra(t_stack **head_a, bool print);
void	ft_rb(t_stack **head_b, bool print);
void	ft_rr(t_stack **head_a, t_stack **head_b);
void	ft_rra(t_stack **head_a, bool print);
void	ft_rrb(t_stack **head_b, bool print);
void	ft_rrr(t_stack **head_a, t_stack **head_b);
//----------------LIST UTILS---------------- //

void	ft_moveto_head(t_stack **stack_a, t_stack **stack_b, int ref);
int		*find_min_n(t_stack **stack);
int		ft_stack_size(t_stack **head);
void	ft_swap_node(t_stack **head, t_stack *node1, t_stack *node2);
void	ft_swap_head_node(t_stack **head, t_stack *node1, t_stack *node2);
void	ft_arrange_links(t_stack **head_a, t_stack **head_b);
void	ft_free_node(t_stack **head, t_stack *ref_node);
void	ft_create_node(t_stack **head, int n);
void	ft_addnode(t_stack **head, t_stack *node);
void	ft_check_args(int count, char **args);
void	ft_check_duplicates(t_stack **stack);
void	ft_stack_init(t_stack **head, char **args);
size_t	ft_lst_size(t_stack **head);
t_stack	*ft_lastnode(t_stack **head);
t_stack	*ft_find_node(t_stack **head, int ref);
t_stack	*ft_find_prev(t_stack **head, int ref);
//show lists
void	ft_show_double_list(t_stack **stack_a, t_stack **stack_b);
void	ft_show_list(t_stack **head);

//----------------SORTING---------------- //

bool	ft_check_short(t_stack	**stack);
//----------------SORT 3---------------- //
void	ft_sort_3_logic(t_stack **stack);
void	ft_sort_3_cases(int top, int mid, int bot, t_stack **stack);
//----------------SORT 5---------------- //
void	ft_sort_5_logic(t_data *data);
#endif
