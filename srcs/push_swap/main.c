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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	(void)stack_b;
	ft_check_args(argc, argv);
	ft_stack_init(&stack_a, &argv[1]);
	// ft_sa(&stack_a);
	ft_show_list(&stack_a);
}
