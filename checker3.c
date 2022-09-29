/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 22:55:55 by ghoyuelo          #+#    #+#             */
/*   Updated: 2022/09/27 23:07:49 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls_aux(t_game *st, int i, int j)
{
	while (st->map[i][j])
	{
		if (st->map[i][j] == 'P')
		{
			st->play_y = i;
			st->play_x = j;
		}
		if (st->map[i][j] != '1')
			return (0);
		j++;
	}
	return (0);
}
