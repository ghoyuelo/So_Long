/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:09:42 by ghoyuelo          #+#    #+#             */
/*   Updated: 2022/09/27 23:34:12 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*join(char *line, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (line[i])
		i++;
	str = malloc(i + 2);
	i = 0;
	while (line[i])
	{
		str[i] = line[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(line);
	return (str);
}

int	checking(int fd, char **line, int *rd)
{
	*rd = 1;
	if (fd < 0)
	{
		*line = NULL;
		return (0);
	}
	*line = malloc(1);
	*line[0] = '\0';
	return (1);
}

int	free_line(char *line)
{
	if (line[0] == '\0')
	{
		free(line);
		return (0);
	}
	return (0);
}

char	*get_map(int fd)
{
	char	buffer;
	char	*line;
	int		rd;

	checking(fd, &line, &rd);
	while (!check(line) && rd > 0)
	{
		rd = read(fd, &buffer, 1);
		if (rd == 0)
			free_line(line);
		if (rd < 0)
		{
			free(line);
			return (NULL);
		}
		line = join(line, buffer);
	}
	return (line);
}
