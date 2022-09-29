/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:18:05 by ghoyuelo          #+#    #+#             */
/*   Updated: 2022/09/27 21:52:18 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *st)
{
	int	i;

	i = 0;
	mlx_clear_window(st->mlx, st->win);
	mlx_destroy_window(st->mlx, st->win);
	while (st->map[i])
		free(st->map[i++]);
	free(st->map);
	exit(1);
	return (0);
}

int	hooking(int key, t_game *st)
{
	if (key == 53)
		close_window(st);
	if (key == 13)
		move_up(st);
	if (key == 0)
		move_left(st);
	if (key == 1)
		move_down(st);
	if (key == 2)
		move_right(st);
	return (0);
}
