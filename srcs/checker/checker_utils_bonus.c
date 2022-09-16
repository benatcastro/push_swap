/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 20:22:28 by becastro          #+#    #+#             */
/*   Updated: 2022/09/16 20:31:25 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "libft.h"

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
	str = ft_calloc(str_len, sizeof(char));
	ft_strlcpy(str, tmp, str_len);
	free(tmp);
	str[str_len - 1] = c;
	str[str_len] = 0;
	return (str);
}
