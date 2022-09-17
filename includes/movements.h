/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:31:38 by becastro          #+#    #+#             */
/*   Updated: 2022/09/17 19:28:37 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENTS_H
# define MOVEMENTS_H
# include "structures.h"
# include <stdbool.h>
//--------------SWAP MOVEMENTS-----------------//

void	ft_sa(t_stack **head_a, bool print);
void	ft_sb(t_stack **head_b, bool print);
void	ft_ss(t_stack **head_a, t_stack **head_b, bool print);
void	ft_pa( t_data *data, bool print);
void	ft_pb(t_data *data, bool print);
void	ft_ra(t_stack **head_a, bool print);
void	ft_rb(t_stack **head_b, bool print);
void	ft_rr(t_stack **head_a, t_stack **head_b, bool print);
void	ft_rra(t_data *data, bool print);
void	ft_rrb(t_data *data, bool print);
void	ft_rrr(t_data *data, bool print);
#endif
