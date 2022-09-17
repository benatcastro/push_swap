/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 02:00:37 by bena              #+#    #+#             */
/*   Updated: 2022/09/17 20:00:32 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "movements.h"
#include "checker_bonus.h"

static void	checker_sorting(t_data *data)
{
	if (ft_check_short(&data->stack_a))
	{
		ft_putstr_fd("OK\n", 1);
		ft_free_stacks(data->stack_a, data->stack_b);
		exit (EXIT_SUCCESS);
	}
	else
	{
		ft_putstr_fd("KO\n", 1);
		ft_free_stacks(data->stack_a, data->stack_b);
		exit (EXIT_SUCCESS);
	}
}

static void	parse_moves(char *s, t_data *data)
{
	if (ft_strcmp(s, "sa\n"))
		ft_sa(&data->stack_a, true);
	else if (ft_strcmp(s, "sb\n"))
		ft_sb(&data->stack_b, true);
	else if (ft_strcmp(s, "ss\n"))
		ft_ss(&data->stack_b, &data->stack_b, true);
	else if (ft_strcmp(s, "pa\n"))
		ft_pa(data, true);
	else if (ft_strcmp(s, "pb\n"))
		ft_pb(data, true);
	else if (ft_strcmp(s, "ra\n"))
		ft_ra(&data->stack_a, true);
	else if (ft_strcmp(s, "ra\n"))
		ft_rb(&data->stack_b, true);
	else if (ft_strcmp(s, "rr\n"))
		ft_rr(&data->stack_a, &data->stack_b, true);
	else if (ft_strcmp(s, "rra\n"))
		ft_rra(data, true);
	else if (ft_strcmp(s, "rrb\n"))
		ft_rrb(data, true);
	else if (ft_strcmp(s, "rrr\n"))
		ft_rrr(data, true);
	else
		ft_putstr_fd("Error\n", 2);
}

char	*read_input(t_data *data)
{
	int32_t	rd;
	char	buffer;
	char	*moves;

	moves = NULL;
	rd = 1;
	while (rd > 0)
	{
		rd = read(0, &buffer, 1);
		moves = ft_append_char(moves, buffer);
		// printf("char (%c)\n", buffer);
		if (buffer == '\n')
		{
			printf("moves (%s)\n", moves);
			parse_moves(moves, data);
			free(moves);
			moves = NULL;
		}
	}
	return (moves);
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
	read_input(&data);
	checker_sorting(&data);
	ft_free_stacks(data.stack_a, data.stack_b);
}
