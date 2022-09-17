/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 02:00:37 by bena              #+#    #+#             */
/*   Updated: 2022/09/17 15:50:09 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "movements.h"
#include "checker_bonus.h"

static char	*read_input(void)
{
	int32_t	rd;
	char	*buffer;
	char	*moves;

	moves = NULL;
	rd = 1;
	while (rd > 0)
	{
		buffer = ft_calloc(1, 1);
		rd = read(0, buffer, 1);
		moves = ft_append_char(moves, buffer[0]);
	}
	return (free(buffer), moves);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_data	data;

	stack_a = NULL;
	stack_b = NULL;
	ft_check_args(argc, argv);
	ft_stack_init(&stack_a, &argv[1]);
	ft_check_duplicates(&stack_a);
	data.stack_a = stack_a;
	data.stack_b = stack_b;
	data.sz_a = ft_lst_size(&stack_a);
	data.sz_b = ft_lst_size(&stack_b);
	ft_free_stacks(data.stack_a, data.stack_b);
	printf("test(%s)\n", read_input());
}

// int	main(int argc, char **argv)
// {
// 	char	*input;
// 	char	*test;

// 	input = ft_append_char(test, 'c');
// 	printf("moves (%s)\n", input);
// 	free(test);
// 	free(input);
