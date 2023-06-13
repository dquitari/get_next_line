/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquitari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:36:14 by dquitari          #+#    #+#             */
/*   Updated: 2023/05/26 10:36:15 by dquitari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define  BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
ssize_t	ft_strclen(const char *s, int c);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char const *s, unsigned int start, ssize_t len);
char	*ft_strdup(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif
