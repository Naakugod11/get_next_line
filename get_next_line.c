/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgulec <dgulec@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:30:47 by dgulec            #+#    #+#             */
/*   Updated: 2025/01/02 16:26:34 by dgulec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	left_c[BUFFER_SIZE + 1];
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		left_c[0] = '\0';
		return (NULL);
	}
	result = ft_strdup(left_c);
	if (!result)
	{
		left_c[0] = '\0';
		return (NULL);
	}
	result = read_and_store(fd, &result, left_c);
	if (!result)
	{
		left_c[0] = '\0';
		return (NULL);
	}
	return (split_line(result, left_c));
}

char	*read_and_store(int fd, char **result, char *left_c)
{
	char	*temp;
	ssize_t	bytes_read;

	while (!ft_strchr(*result, '\n'))
	{
		bytes_read = read(fd, left_c, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			left_c[0] = '\0';
			return (free(*result), NULL);
		}
		if (bytes_read == 0)
		{
			left_c[0] = '\0';
			break ;
		}
		left_c[bytes_read] = '\0';
		temp = ft_strjoin(*result, left_c);
		if (temp == NULL)
			return (free(*result), NULL);
		free(*result);
		*result = temp;
	}
	return (*result);
}

char	*split_line(char *result, char *left_c)
{
	char	*line;
	char	*newline_pos;
	ssize_t	len;

	line = NULL;
	newline_pos = ft_strchr(result, '\n');
	if (newline_pos)
	{
		len = newline_pos - result + 1;
		line = ft_substr(result, 0, len);
		if (line == NULL)
			return (free(result), NULL);
		update_leftover(left_c, newline_pos + 1);
	}
	else
	{
		if (result[0] == '\0')
			return (free(result), NULL);
		line = ft_strdup(result);
		left_c[0] = '\0';
	}
	free(result);
	return (line);
}

void	update_leftover(char *left_c, char *new_leftover)
{
	while (new_leftover && *new_leftover)
	{
		*left_c = *new_leftover;
		left_c++;
		new_leftover++;
	}
	*left_c = '\0';
}
