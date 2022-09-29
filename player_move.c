/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:04:22 by ghoyuelo          #+#    #+#             */
/*   Updated: 2022/09/27 21:51:49 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *st)
{
	if (st->map[st->play_y - 1][st->play_x] == '0')
	{
		st->map[st->play_y][st->play_x] = '0';
		st->map[st->play_y - 1][st->play_x] = 'P';
		st->player_movements++;
		st->play_y -= 1;
	}
	else if (st->map[st->play_y - 1][st->play_x] == 'E' && st->coins == 0)
	{
		close_window(st);
	}
	else if (st->map[st->play_y - 1][st->play_x] == 'C')
	{
		st->map[st->play_y][st->play_x] = '0';
		st->map[st->play_y - 1][st->play_x] = 'P';
		st->player_movements++;
		st->play_y -= 1;
		st->coins--;
	}
	mlx_clear_window(st->mlx, st->win);
	fill_window(st);
}

void	move_down(t_game *st)
{
	if (st->map[st->play_y + 1][st->play_x] == '0')
	{
		st->map[st->play_y][st->play_x] = '0';
		st->map[st->play_y + 1][st->play_x] = 'P';
		st->player_movements++;
		st->play_y += 1;
	}
	else if (st->map[st->play_y + 1][st->play_x] == 'E' && st->coins == 0)
	{
		close_window(st);
	}
	else if (st->map[st->play_y + 1][st->play_x] == 'C')
	{
		st->map[st->play_y][st->play_x] = '0';
		st->map[st->play_y + 1][st->play_x] = 'P';
		st->player_movements++;
		st->play_y += 1;
		st->coins--;
	}
	mlx_clear_window(st->mlx, st->win);
	fill_window(st);
}

void	move_left(t_game *st)
{
	if (st->map[st->play_y][st->play_x - 1] == '0')
	{
		st->map[st->play_y][st->play_x] = '0';
		st->map[st->play_y][st->play_x - 1] = 'P';
		st->player_movements++;
		st->play_x -= 1;
	}
	else if (st->map[st->play_y][st->play_x - 1] == 'E' && st->coins == 0)
	{
		close_window(st);
	}
	else if (st->map[st->play_y][st->play_x - 1] == 'C')
	{
		st->map[st->play_y][st->play_x] = '0';
		st->map[st->play_y][st->play_x - 1] = 'P';
		st->player_movements++;
		st->play_x -= 1;
		st->coins--;
	}
	mlx_clear_window(st->mlx, st->win);
	fill_window(st);
}

void	move_right(t_game *st)
{
	if (st->map[st->play_y][st->play_x + 1] == '0')
	{
		st->map[st->play_y][st->play_x] = '0';
		st->map[st->play_y][st->play_x + 1] = 'P';
		st->player_movements++;
		st->play_x += 1;
	}
	else if (st->map[st->play_y][st->play_x + 1] == 'E' && st->coins == 0)
	{
		close_window(st);
	}
	else if (st->map[st->play_y][st->play_x + 1] == 'C')
	{
		st->map[st->play_y][st->play_x] = '0';
		st->map[st->play_y][st->play_x + 1] = 'P';
		st->player_movements++;
		st->play_x += 1;
		st->coins--;
	}
	mlx_clear_window(st->mlx, st->win);
	fill_window(st);
}

void	movements(t_game *st)
{
	mlx_string_put(st->mlx, st->mlx_win,
		st->pixel * st->col * (0.84), 10, 0x080000,
		"Movements: ");
	mlx_string_put(st->mlx, st->mlx_win,
		st->pixel * st->col * (0.96), 10, 0x080000,
		ft_itoa(st->player_movements));
}
