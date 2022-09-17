/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:01:40 by becastro          #+#    #+#             */
/*   Updated: 2022/09/17 21:16:08 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include "structures.h"
# include <stdbool.h>

char	*ft_append_char(char *str, char c);
void	parse_input(t_data *data);
bool	ft_strcmp(char *s1, char *s2);

#endif
