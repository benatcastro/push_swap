/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 20:22:28 by becastro          #+#    #+#             */
/*   Updated: 2022/09/19 19:10:43 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "stdbool.h"
#include "libft.h"

/**
 * @brief
 * Takes a string as a paramter and appends the char c to the end of it
 * @param str
 * @param c
 * @return char*
 */
char	*ft_append_char(char *str, char c)
{
	char	*tmp;
	size_t	str_len;

	if (!str)
	{
		str = ft_calloc(2, sizeof(char));
		str[0] = c;
		str[1] = '\0';
		return (str);
	}
	str_len = ft_strlen(str) + 1;
	tmp = ft_strdup(str);
	free(str);
	str = ft_calloc(str_len + 1, sizeof(char));
	ft_strlcpy(str, tmp, str_len);
	free(tmp);
	str[str_len - 1] = c;
	return (str);
}

/**
 * @brief
 * Str compare refactorized
 * @param s1
 * @param s2
 * @return true
 * @return false
 */
bool	ft_strcmp(char *s1, char *s2)
{
	int32_t	i;

	if (ft_strlen(s1) != ft_strlen(s2))
		return (false);
	i = -1;
	while (s1[++i])
		if (s1[i] != s2[i])
			return (false);
	return (true);
}
