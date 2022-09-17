/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 02:00:37 by bena              #+#    #+#             */
/*   Updated: 2022/09/17 21:04:16 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "movements.h"
#include "checker_bonus.h"

/**
 * @brief
 * Prints the erro message and exits the program
 * @param data
 */
static void	print_error(t_data *data)
{
	ft_putstr_fd("Error\n", 2);
	ft_free_stacks(data->stack_a, data->stack_b);
	exit (EXIT_FAILURE);
}

/**
 * @brief
 * Checks if the stack is sorted after the inputs
 * Prints "KO" or "OK" and exits the program
 * @param data
 */
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

/**
 * @brief
 *Taking the input of fd 0 executes the movements
 * @param s
 * @param data
 */
static void	check_moves(char *s, t_data *data)
{
	if (ft_strcmp(s, "sa\n"))
		ft_sa(&data->stack_a, false);
	else if (ft_strcmp(s, "sb\n"))
		ft_sb(&data->stack_b, false);
	else if (ft_strcmp(s, "ss\n"))
		ft_ss(&data->stack_b, &data->stack_b, false);
	else if (ft_strcmp(s, "pa\n"))
		ft_pa(data, false);
	else if (ft_strcmp(s, "pb\n"))
		ft_pb(data, false);
	else if (ft_strcmp(s, "ra\n"))
		ft_ra(&data->stack_a, false);
	else if (ft_strcmp(s, "rb\n"))
		ft_rb(&data->stack_b, false);
	else if (ft_strcmp(s, "rr\n"))
		ft_rr(&data->stack_a, &data->stack_b, false);
	else if (ft_strcmp(s, "rra\n"))
		ft_rra(data, false);
	else if (ft_strcmp(s, "rrb\n"))
		ft_rrb(data, false);
	else if (ft_strcmp(s, "rrr\n"))
		ft_rrr(data, false);
	else if (ft_isprint(s[0]))
		print_error(data);
}

/**
 * @brief
 * reads from fd 0 returning every command till it finds a '\n'
 * @param data
 * @return char*
 */
static void	*read_input(t_data *data)
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
		if (buffer == '\n')
		{
			check_moves(moves, data);
			free(moves);
			moves = NULL;
		}
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_data	data;

	if (argc == 1)
		return (0);
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
