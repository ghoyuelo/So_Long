/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:47:48 by ghoyuelo          #+#    #+#             */
/*   Updated: 2022/09/28 03:42:57 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_game *st)
{
	st->mlx = mlx_init();
	st->win = mlx_new_window(st->mlx, st->col * 64, st->row * 64, "So_Long");
}

void	file_to_img(t_game *st)
{
	printf("Assets saving...\n");
	st->ig.wll = mlx_xpm_file_to_image(st->mlx,
			"./assets/bricksx64.xpm", &st->ig.cols, &st->ig.rows);
	st->ig.gr = mlx_xpm_file_to_image(st->mlx,
			"./assets/grass.xpm", &st->ig.cols, &st->ig.rows);
	st->ig.cns = mlx_xpm_file_to_image(st->mlx,
			"./assets/coin.xpm", &st->ig.cols, &st->ig.rows);
	st->ig.xt = mlx_xpm_file_to_image(st->mlx,
			"./assets/exit.xpm", &st->ig.cols, &st->ig.rows);
	st->ig.plyf = mlx_xpm_file_to_image(st->mlx,
			"./assets/Santafront.xpm", &st->ig.cols, &st->ig.rows);
	printf("Assets saved!\n");
}

void	image_to_window(t_game *st, size_t x, size_t y)
{
	mlx_put_image_to_window(st->mlx, st->win, st->ig.gr, x * 64, y * 64);
	if (st->map[y][x] == '1')
		mlx_put_image_to_window(st->mlx, st->win, st->ig.wll, x * 64, y * 64);
	else if (st->map[y][x] == 'C')
		mlx_put_image_to_window(st->mlx, st->win, st->ig.cns, x * 64, y * 64);
	else if (st->map[y][x] == 'P')
		mlx_put_image_to_window(st->mlx, st->win, st->ig.plyf, x * 64, y * 64);
	else if (st->map[y][x] == 'E')
		mlx_put_image_to_window(st->mlx, st->win, st->ig.xt, x * 64, y * 64);
}

void	fill_window(t_game *st)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (st->map[y])
	{
		x = 0;
		while (x < st->col)
		{
			image_to_window(st, x, y);
			x++;
		}
		y++;
	}
	printf("Movements: %zu\n", st->player_movements);
}
