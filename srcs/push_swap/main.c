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
	printf("==INITIAL A===\n");
	ft_show_list(&stack_a);
	printf("===MOVEMENTS===\n");
	// ft_pb(&stack_a, &stack_b);
	//printf("HEADS A (%d) B (%d)\n", stack_a->key, stack_b->key);
	//ft_ra(&stack_a, true);
	// ft_rrb(&stack_b, true);
	// ft_rra(&stack_a, true);
	//ft_rra(&stack_a, true);
	//ft_rrr(&stack_a, &stack_b);
	//ft_sa(&stack_a);
	//ft_pa(&stack_a, &stack_b);
	//ft_ra(&stack_a);
	//ft_rra(&stack_a);
	//ft_ss(&stack_a, &stack_b);
	//ft_rrr(&stack_a, &stack_b);
	//ft_sa(&stack_a);
	//ft_sb(&stack_b);
	//ft_pb(&stack_a, &stack_b);
	//ft_pa(&stack_a, &stack_b);
	printf("===STACK A===\n");
	ft_show_list(&stack_a);
	printf("===STACK B===\n");
	ft_show_list(&stack_b);
}
