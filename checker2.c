/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 21:46:41 by ghoyuelo          #+#    #+#             */
/*   Updated: 2022/09/28 00:07:55 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_game *st)
{
	int	i;
	int	j;

	i = 0;
	while (st->map[i])
	{
		if (i == 0 || st->map[i + 1] == NULL)
		{
			j = 0;
			check_walls_aux(st, i, j);
		}
		else
		{
			if (st->map[i][0] != '1'
				|| st->map[i][ft_strlen(st->map[i]) - 1] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}

void	get_player(t_game *st)
{
	int	i;
	int	j;

	i = 0;
	while (st->map[i])
	{
		j = 0;
		while (st->map[i][j])
		{
			if (st->map[i][j] == 'P')
			{
				st->play_y = i;
				st->play_x = j;
			}
			j++;
		}
		i++;
	}
}

int	check_pce(t_game *st)
{
	int	j;

	j = 0;
	st->coins = 0;
	st->exits = 0;
	st->players = 0;
	get_player(st);
	while (st->buffer[j])
	{
		if (st->buffer[j] == 'C')
			st->coins++;
		if (st->buffer[j] == 'E')
			st->exits++;
		if (st->buffer[j] == 'P')
			st->players++;
		j++;
	}
	if (st->exits != 1 || st->players != 1 || st->coins < 1)
	{
		printf("Error.\nThe number of Players, Coins or Exits aren´t right.\n");
		free(st->buffer);
		exit(1);
	}
	return (1);
}

int	check_map(t_game *st)
{
	if (!check_rectangle(st))
	{
		printf("Error\nMap is not rectangle\n");
		return (0);
	}
	if (!check_chars(st))
	{
		printf("Error\nMap has invalid chraracters\n");
		return (0);
	}
	if (!check_walls(st))
	{
		printf("Error\nMap is not closed\n");
		return (0);
	}
	if (!check_pce(st))
	{
		printf("Error\nMap needs at least an 'C', 'P' and 'E'\n");
		return (0);
	}
	return (1);
}
