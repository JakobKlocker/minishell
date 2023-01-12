/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:47:22 by jklocker          #+#    #+#             */
/*   Updated: 2022/11/09 17:40:43 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

//Main Calls
char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd > 4095)
	{
		if (buffer[fd])
		{
			free(buffer[fd]);
			buffer[fd] = NULL;
		}
		return (NULL);
	}
	buffer[fd] = read_file(fd, buffer[fd]);
	line = get_line_only(buffer[fd]);
	if (line == NULL)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	if (line != NULL || buffer[fd] != NULL)
		buffer[fd] = swap_new_line(buffer[fd]);
	return (line);
}

//Reads file till '\n' found or nothing left to read, returns NULL if error
char	*read_file(int fd, char *buffer)
{
	char	*tmp;
	char	*read_fd;
	int		bytes_read;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	read_fd = ft_calloc(BUFFER_SIZE + 1, 1);
	bytes_read = 1;
	while (bytes_read > 0 && ft_strchr(buffer, '\n') == 0)
	{
		bytes_read = read(fd, read_fd, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(read_fd);
			return (NULL);
		}
		read_fd[bytes_read] = '\0';
		tmp = ft_strjoin(buffer, read_fd);
		free(buffer);
		buffer = tmp;
	}
	free(read_fd);
	return (buffer);
}

char	*get_line_only(char *buffer)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (buffer == NULL || *buffer == 0)
	{
		return (NULL);
	}
	while (buffer[i] && buffer[i] != '\n')
		i++;
	ret = ft_calloc(i + 2, 1);
	if (ret == NULL)
		return (NULL);
	while (buffer[j] && buffer[j] != '\n')
	{
		ret[j] = buffer[j];
		j++;
	}
	return (ret);
}

//Swap Everthing after New Line to Front
char	*swap_new_line(char *buffer)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i])
		i++;
	ret = ft_calloc(i + 1, 1);
	if (ret == NULL)
		return (NULL);
	while (buffer[j] && buffer[j] != '\n')
		j++;
	if (i == j)
	{
		free(ret);
		free(buffer);
		return (NULL);
	}
	i = 0;
	while (buffer[j])
		ret[i++] = buffer[++j];
	free(buffer);
	return (ret);
}

/*
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ret;

	ret = check_malloc(s1, s2);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	return (ret);
}
*/