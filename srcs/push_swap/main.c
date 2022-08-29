/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
/*                                                                            */

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
	data.stack_size = ft_lst_size(&stack_a);
	ft_sorter_manager(&data);
	//check(&data);
}
