/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquitari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:52:43 by dquitari          #+#    #+#             */
/*   Updated: 2023/05/30 14:52:45 by dquitari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_trimmed_temp(char *temp)
{
	char	*new_temp;
	ssize_t	line_len;
	ssize_t	temp_len;

	line_len = ft_strclen(temp, '\n');
	if (line_len == -1)
	{
		free(temp);
		return (NULL);
	}
	temp_len = ft_strclen(temp, '\0');
	new_temp = ft_substr(temp, line_len + 1, temp_len - line_len);
	if (!new_temp)
		return (NULL);
	free(temp);
	return (new_temp);
}

char	*get_new_line(char *temp)
{
	ssize_t	line_len;
	char	*line;

	if (!temp[0])
		return (NULL);
	line_len = ft_strclen(temp, '\n');
	if (line_len == -1)
	{
		line_len = ft_strclen(temp, '\0');
		line = ft_substr(temp, 0, line_len + 1);
	}
	else
		line = ft_substr(temp, 0, line_len + 2);
	return (line);
}

char	*clean_memory(char *buf, char *temp)
{
	if (buf)
		free(buf);
	if (temp)
		free(temp);
	return (NULL);
}

char	*get_temp(int fd, char *temp)
{
	char		*buf;
	int			bytes_read;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (bytes_read != 0 && !(ft_strchr(temp, '\n')))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (clean_memory(buf, temp));
		buf[bytes_read] = '\0';
		if (!buf)
			return (NULL);
		temp = ft_strjoin(temp, buf);
	}
	free(buf);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = get_temp(fd, temp);
	if (!temp)
		return (NULL);
	line = get_new_line(temp);
	if (!line)
		return (NULL);
	temp = get_trimmed_temp(temp);
	return (line);
}

/*int	main(void)
{
	char	*line;
	int		i;
	int		fd1;

	fd1 = open("tests/testlong1", O_RDONLY);
	i = 1;
	while (i <= 20)
	{
		line = get_next_line(fd1);
		if (!line)
			return (0);
		printf("line [%02d]: <%s>\n", i, line);
		free(line);
		i++;
	}
	free(line);
	close(fd1);
	return (0);
}*/
