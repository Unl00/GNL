/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmallard <pmallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:00:36 by pmallard          #+#    #+#             */
/*   Updated: 2022/09/29 16:24:25 by pmallard         ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int	len_tot;
	int	i;
	int	j;
	char		*res;
	
	len_tot = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	res = malloc(sizeof(char) * (len_tot + 1));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[len_tot] = 0;
	return (res);
}

char	*ft_strchr(const char *str, int c)
{
	while (str && *str != c)
		str++;
	if (*str == c)
		return ((char *)str);
	return ((char *)NULL);
}

void	ft_bzero(void	*str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)str)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*res;

	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	ft_bzero(res, (nmemb * size));
	return (res);
}

