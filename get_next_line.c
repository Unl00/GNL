/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:39:23 by pmallard          #+#    #+#             */
/*   Updated: 2022/12/08 15:52:15 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	static	char	*buffer;
	char			*line;
	
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	line = ft_get_line(buffer);
	buffer = ft_save(buffer);
	return (line);
}

char	*ft_save(char *buffer)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	res = ft_calloc(ft_strlen(buffer) - i + 1);
	if (!res)
		return (NULL);
	i++;
	while (buffer[i])
	{
		res[len] = buffer[i];
		len++;
		i++;
	}
	res[len] = 0;
	free (buffer);
	return (res);
}

char	*ft_read(int fd, char *save)
{
	int		size_read;
	char	*buff;
	char	*line;

	size_read = 1;
	if (!save)
		save = ft_calloc(1);
	buff = ft_calloc(BUFFER_SIZE);
	if (!buff)
		return (NULL);
	while (size_read > 0 && !ft_strchr(save, '\n'))
	{
		size_read = read(fd, buff, BUFFER_SIZE);
		if (size_read == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[size_read] = 0;
		line = ft_strjoin(save, buff);
		free(save);
		save = line;
	}
	free(buff);
	return (save);
}

char	*ft_get_line(char *save)
{
	int		i;
	char	*res;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	res = ft_calloc(i + 2);
	if (!res)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		res[i] = save[i];
		i++;
	}
	if (save[i] && save[i] == '\n')
		res[i++] = '\n';
	res[i] = 0;
	return (res);
}