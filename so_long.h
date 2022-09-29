/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:54:16 by ghoyuelo          #+#    #+#             */
/*   Updated: 2022/09/28 00:13:58 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_img
{
	int		cols;
	int		rows;
	void	*gr;
	void	*cns;
	void	*xt;
	void	*wll;
	void	*plyf;
}	t_img;

typedef struct s_game
{
	size_t	col;
	size_t	row;
	size_t	coins;
	size_t	exits;
	size_t	players;
	size_t	map_tot;
	size_t	map_x;
	size_t	map_y;
	int		play_x;
	int		play_y;
	size_t	player_movements;
	char	**map;
	char	*buffer;
	int		pixel;
	void	*mlx_win;
	void	*mlx;
	void	*win;
	void	*img;
	t_img	ig;
}	t_game;

void	check_arguments(int argc);
int		map_validator(char *argv, t_game *st);
void	check_extension(char *argv);

/*************** Get the map *****************/
char	*get_map(int fd);
int		free_line(char *line);
int		checking(int fd, char **line, int *rd);
char	*join(char *line, char c);
int		check(char *str);

/*************** Check the map ***************/
int		check_map(t_game *st);
int		check_rectangle(t_game *st);
int		check_chars(t_game *st);
int		check_walls(t_game *st);
int		check_walls_aux(t_game *st, int i, int j);
int		check_pce(t_game *st);
int		ft_check_map(t_game *st);

/*************** Fill the window *************/
void	img_var_int(t_img ig);
void	init_mlx(t_game *st);
void	file_to_img(t_game *st);
void	fill_window(t_game *st);

/************* Player Movements **************/
void	move_up(t_game *st);
void	move_down(t_game *st);
void	move_left(t_game *st);
void	move_right(t_game *st);
void	movements(t_game *st);

int		hooking(int keyhook, t_game *st);
int		close_window(t_game *st);

#endif
