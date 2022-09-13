/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
/*   Updated: 2022/09/13 17:28:20 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_error(int n)
{
	ft_putstr_fd("Number: (", 1);
	ft_putnbr_fd(n, 1);
	ft_putstr_fd(") ", 1);
	ft_putstr_fd("is duplicated ❌", 1);
}

/**
 * @brief
 * Checks for duplicates numbers in the arguments
 * @param stack head of the initialized stack A
 */
void	ft_check_duplicates(t_stack **stack)
{
	t_stack	*index;
	t_stack	*aux;
	int		n;
	int		key;

	index = (*stack);
	while (index->next)
	{
		n = index->n;
		key = index->key;
		aux = (*stack);
		while (aux->next)
		{
			if ((aux->n == n && aux->key != key) || aux->n == aux->next->n)
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
		ft_putstr_fd("Error, missing arguments ❌\n", 1);
		exit (EXIT_FAILURE);
	}
	while (args[++i])
	{
		j = -1;
		while (args[i][++j])
		{
			if (!ft_isdigit(args[i][j]))
			{
				ft_putstr_fd("Error, argument number ", 1);
				ft_putnbr_fd(i, 1);
				ft_putstr_fd(" isn't a digit ❌\n", 1);
				exit (EXIT_FAILURE);
			}
		}
	}
}
