/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:00:36 by pmallard          #+#    #+#             */
/*   Updated: 2022/12/08 15:48:59 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int			i;
	int			j;
	char		*res;
	
	i = 0;
	j = 0;
	if (s1 == 0)
		return (NULL);
	res = malloc(sizeof(char *) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i + j] = s2[j];
		i++;
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

char	*ft_strchr(char *str, char c)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

void	*ft_calloc(size_t size)
{
	size_t	i;
	char	*res;

	i = 0;
	res = malloc(size);
	if (!res)
		return (NULL);
	while (i < size)
	{
		res[i] = '\0';
		i++;
	}
	return (res);
}
