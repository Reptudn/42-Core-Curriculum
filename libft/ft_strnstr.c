/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 01:22:58 by jonask            #+#    #+#             */
/*   Updated: 2023/10/08 12:19:02 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	get_length(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != 0)
	{
		len++;
	}
	return (len);
}

int	substrcmp(const char *s1, const char *s2, int start_index)
{
	int	i;

	i = 0;
	while (s1[start_index + i] != 0 && s2[i] != 0)
	{
		if (s1[start_index + i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	l_len;

	i = 0;
	l_len = 0;
	if (get_length(little) < 1)
		return ((char *)big);
	while (big[i] != 0 && i < len)
	{
		if (big[i] == little[0] && substrcmp(big, little, i))
			return (&(((char*)big)[i]));
		i++;
	}
	return (0);
}