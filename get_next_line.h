/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:54:44 by pmallard          #+#    #+#             */
/*   Updated: 2022/12/08 15:48:28 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#   define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_save(char	*buffer);
char	*ft_read(int fd, char *save);
char	*ft_get_line(char *save);
char	*ft_strchr(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t size);
size_t	ft_strlen(const char *str);

#endif