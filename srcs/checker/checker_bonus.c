/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 02:00:37 by bena              #+#    #+#             */
/*   Updated: 2022/09/16 16:02:02 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "movements_bonus.h"

static size_t	read_size(void)
{
	int32_t	rd;
	size_t	sz;
	char	*buffer;

	rd = 1;
	sz = 1;
	buffer = ft_calloc(1, 1);
	while (rd > 0)
	{
		rd = read(0, buffer, 1);
		printf("buffer (%c)\n", buffer[0]);
		sz++;
	}
	return (sz);
}

int	main(int argc, char **argv)
{
	char	*commands;

	commands = ft_calloc(read_size(), sizeof(char));
	printf("TEST1 (%zu)\n", read_size());
	// read(0, commands, read_size());
	// printf("Commands(%s)\n", commands);
}
