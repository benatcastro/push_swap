/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
/*   Updated: 2022/09/17 21:11:49 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_error(int n)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Number: (", 2);
	ft_putnbr_fd(n, 2);
	ft_putstr_fd(") ", 2);
	ft_putstr_fd("is duplicated ❌", 2);
}

/**
 * @brief
 * Checks for duplicates numbers in the arguments
 * @param stack head of the initialized stack A
 */
void	ft_check_duplicates(t_stack **stack)
{
	t_stack		*index;
	t_stack		*aux;
	int32_t		n;
	u_int32_t	key;

	index = (*stack);
	while (index->next)
	{
		n = index->n;
		key = index->key;
		aux = (*stack);
		while (aux)
		{
			if (aux->n == n && aux->key != key)
			{
				ft_free_stacks(*stack, NULL);
				ft_print_error(n);
				exit(EXIT_FAILURE);
			}
			aux = aux->next;
		}
		index = index->next;
	}
}

void	ft_check_args(int count, char **args)
{
	int	i;
	int	j;

	i = 0;
	if (count <= 1)
	{
		ft_putstr_fd("Error\nMissing arguments ❌\n", 2);
		exit (EXIT_FAILURE);
	}
	while (args[++i])
	{
		j = -1;
		while (args[i][++j])
		{
			if (!ft_isdigit(args[i][j]) || (args[i][j] == '-' && j != 0))
			{
				ft_putstr_fd("Error\nArgument number ", 2);
				ft_putnbr_fd(i, 2);
				ft_putstr_fd(" isn't a digit ❌\n", 2);
				exit (EXIT_FAILURE);
			}
		}
	}
}
