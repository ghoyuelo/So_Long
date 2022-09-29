/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:51:27 by ghoyuelo          #+#    #+#             */
/*   Updated: 2022/09/28 01:23:54 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_validator_aux(t_game *st, int fd)
{
	int	i;

	i = 0;
	st->buffer = get_map(fd);
	if (st->buffer == NULL)
	{
		printf("Empty map.\n");
		return (0);
	}
	if (ft_check_map(st) == 0)
	{
		printf("The map has doble '\\n'.\n");
		free(st->buffer);
		return (0);
	}
	st->map = ft_split(st->buffer, '\n');
	if (check_map(st) == 0)
	{
		free(st->buffer);
		while (st->map[i])
			free(st->map[i++]);
		free(st->map);
		return (0);
	}
	return (1);
}

int	map_validator(char *argv, t_game *st)
{
	int		i;
	int		fd;

	i = 0;
	check_extension(argv);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		printf("Error.\nThe map could't be read.\n");
		exit (1);
	}
	if (map_validator_aux(st, fd) == 0)
		return (0);
	printf("Correct map!\n");
	free(st->buffer);
	close(fd);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	st;

	st.player_movements = 0;
	check_arguments(argc);
	if (map_validator(argv[1], &st) == 0)
		return (0);
	init_mlx(&st);
	file_to_img(&st);
	fill_window(&st);
	mlx_hook(st.win, 2, 1L << 0, hooking, &st);
	mlx_hook(st.win, 17, 1L << 5, close_window, &st);
	mlx_loop(st.mlx);
	return (0);
}
