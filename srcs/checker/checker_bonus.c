/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 02:00:37 by bena              #+#    #+#             */
/*   Updated: 2022/09/16 18:37:47 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "movements_bonus.h"
#include "checker_bonus.h"

static char	*read_input(void)
{
	int32_t	rd;
	char	*buffer;
	char	*moves;

	moves = NULL;
	rd = 1;
	buffer = ft_calloc(1, 1);
	while (rd > 0)
	{
		rd = read(0, buffer, 1);
		moves = ft_append_char(moves, buffer[0]);
		//printf("MOVES (%s)\n", moves);
	}
	return (free(buffer), moves);
}

int	main(int argc, char **argv)
{
	char	*input;
	char	*test;

	test = ft_strdup("hello");
	input = ft_append_char(test, 'c');
	printf("moves (%s)\n", input);
	free(test);
	free(input);
}
