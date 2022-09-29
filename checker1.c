/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:48:07 by ghoyuelo          #+#    #+#             */
/*   Updated: 2022/09/28 01:19:02 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_arguments(int argc)
{
	if (argc != 2)
	{
		if (argc < 2)
		{
			printf("Error.\nInsufficient arguments!\n");
			exit (1);
		}
		if (argc > 2)
		{
			printf("Error.\nToo many  arguments!\n");
			exit (1);
		}
		printf("Put: ./so_long [MAP].ber\n");
	}
}

void	check_extension(char *argv)
{
	int	len;

	if (argv == NULL)
	{
		printf("Error.\nThe file doesn´t exist.\n");
		printf("Put: ./so_long [MAP].ber\n");
		exit (1);
	}
	len = ft_strlen(argv) - 1;
	if (!(argv[len] == 'r' && argv[len - 1] == 'e'
			&& argv[len - 2] == 'b' && argv[len - 3] == '.'))
	{
		printf("Error.\nThe file extension is no correct.\n");
		printf("Put: ./so_long [MAP].ber\n");
		exit (1);
	}
}

int	check_rectangle(t_game *st)
{
	int		i;
	int		j;
	int		n;

	if (!st->map[0])
		return (0);
	st->col = ft_strlen(st->map[0]);
	n = 0;
	i = 0;
	while (st->map[i])
	{
		j = 0;
		while (st->map[i][j])
			j++;
		if (!st->map[i + 1] && st->buffer[ft_strlen(st->buffer) - 1] != '\n')
			j--;
		if (n != 0 && n != j)
			return (0);
		n = j;
		i++;
	}
	st->row = i;
	return (1);
}

int	ft_check_map(t_game *st)
{
	int	i;

	i = 0;
	while (st->buffer[i])
	{
		if (st->buffer[i] == '\n'
			&& st->buffer[i + 1] == '\n' && st->buffer[i + 2])
			return (0);
		i++;
	}
	return (1);
}

int	check_chars(t_game *st)
{
	int	i;
	int	j;

	j = 0;
	while (st->map[j])
	{
		i = 0;
		while (st->map[j][i])
		{
			if (!(st->map[j][i] == '0' || st->map[j][i] == '1'
				|| st->map[j][i] == '\n' || st->map[j][i] == 'C'
				|| st->map[j][i] == 'E' || st->map[j][i] == 'P'))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}
