/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquitari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:02:22 by dquitari          #+#    #+#             */
/*   Updated: 2023/05/24 15:02:24 by dquitari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strclen(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == (char)c)
		return (i);
	else
		return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	new = malloc(sizeof(char) *((ft_strclen(s1, '\0')
					+ ft_strclen(s2, '\0')) + 1));
	if (!new)
		return (NULL);
	while (s1[++i])
		new[i] = s1[i];
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	free(s1);
	return (new);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t				i;

	s = src;
	d = dst;
	i = 0;
	if (!s && !d)
		return (0);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, ssize_t len)
{
	char	*new;
	int		i;

	if (start > ft_strclen(s, '\0'))
	{
		new = malloc(sizeof(char));
		if (!new)
			return (NULL);
		return (new);
	}
	if (len > ft_strclen(s, '\0') - start + 1)
		len = ft_strclen(s, '\0') - start + 1;
	new = (char *)malloc(sizeof(*s) * len);
	if (!new)
		return (NULL);
	i = len;
	while (len != 0)
	{
		new[len - 1] = s[len - 1 + start];
		len--;
	}
	new[i - 1] = '\0';
	return (new);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	else
		return (NULL);
}
