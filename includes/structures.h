/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:29:26 by becastro          #+#    #+#             */
/*   Updated: 2022/09/15 15:37:55 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "stdio.h"

enum e_sorters
{
	SORT_3,
	SORT_5,
	GEN_SHORT,
};

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_moves
{
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		moves;
}	t_moves;

typedef struct s_stack
{
	int				key;
	int				n;
	struct s_moves	s_mv;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	int				sorter;
	int				sz_a;
	int				sz_b;
	struct s_moves	mv;
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;

}	t_data;

#endif // STRUCTURES_H
