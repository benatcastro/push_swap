/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
/*   Updated: 2022/09/15 13:50:54 by becastro         ###   ########.fr       */
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
	GEN_SHORT,
};

typedef struct s_data
{
	int				sorter;
	int				sz_a;
	int				sz_b;
	size_t			total_moves;
	struct s_moves	mv;
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;

}	t_data;
//--------------PROGRAM LOGIC-----------------//

void	ft_sorter_manager(t_data *data);
//--------------SWAP FNCS-----------------//

void	ft_sa(t_stack **head_a, bool print);
void	ft_sb(t_stack **head_b, bool print);
void	ft_ss(t_stack **head_a, t_stack **head_b);
void	ft_pa( t_data *data);
void	ft_pb(t_data *data);
void	ft_ra(t_stack **head_a, bool print);
void	ft_rb(t_stack **head_b, bool print);
void	ft_rr(t_stack **head_a, t_stack **head_b);
void	ft_rra(t_data *data, bool print);
void	ft_rrb(t_data *data, bool print);
void	ft_rrr(t_data *data);
//----------------LIST UTILS---------------- //

void	print_data(t_data *data);
void	print_struct(t_data *data);
int		ft_find_min_nbr(t_stack **stack);
t_stack	*ft_find_nbr_node(t_stack **stack, int nbr);
int		ft_find_n_node(t_stack **stack, int ref);
void	ft_moveto_head(t_stack **stack_a,
			t_stack **stack_b, t_data *data, int ref);
int		ft_get_median(t_stack **stack);
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

void	ft_short_keys(t_data *data);
bool	ft_check_short(t_stack	**stack);
void	ft_general_short(t_data *data);
void	ft_get_moves_a(t_data *data);
void	ft_get_moves_b(t_data *data);
void	ft_cmp_mv(t_stack *stack);
void	ft_reset_stack(t_stack	*stack);
void	ft_reset_data(t_data	*data);
//----------------SORT 3---------------- //
void	ft_sort_3_logic(t_data *data);
void	ft_sort_3_cases(int top, int mid, int bot, t_data *data);
//----------------SORT 5---------------- //
void	ft_sort_5_logic(t_data *data);
#endif
