/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:29:26 by becastro          #+#    #+#             */
/*   Updated: 2022/09/15 16:52:35 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "stdio.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_moves
{
	u_int32_t	ra;
	u_int32_t	rb;
	u_int32_t	rr;
	u_int32_t	rra;
	u_int32_t	rrb;
	u_int32_t	rrr;
	u_int32_t	moves;
}	t_moves;

typedef struct s_stack
{
	u_int32_t		key;
	int32_t			n;
	struct s_moves	s_mv;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	int				sorter;
	u_int32_t		sz_a;
	u_int32_t		sz_b;
	struct s_moves	mv;
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;

}	t_data;

#endif // STRUCTURES_H
