/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 05:17:51 by becastro          #+#    #+#             */
/*   Updated: 2022/09/15 15:14:27 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	check(t_data *data)
{
	ft_show_double_list(&data->stack_a, &data->stack_b);
	if (ft_check_short(&data->stack_a))
		printf("CORRECTLY SORTED!");
	else
		printf("NOT SORTED!\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_data	data;

	stack_a = ft_calloc(1, sizeof(t_stack));
	stack_b = ft_calloc(1, sizeof(t_stack));
	stack_a = NULL;
	stack_b = NULL;
	ft_check_args(argc, argv);
	ft_stack_init(&stack_a, &argv[1]);
	ft_check_duplicates(&stack_a);
	data.stack_a = stack_a;
	data.stack_b = stack_b;
	data.sz_a = ft_lst_size(&stack_a);
	data.sz_b = ft_lst_size(&stack_b);
	ft_sorter_manager(&data);
}
