# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 14:13:12 by ghoyuelo          #+#    #+#              #
#    Updated: 2022/09/28 00:12:51 by ghoyuelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIB = ./libft/

MLX = mlx/

SRC = 	so_long.c\
		checker1.c\
		checker2.c\
		checker3.c\
		get_map.c\
		player_move.c\
		hooking.c\
		mlx_functions.c\

SRC_BONUS = 	

OBJS = $(SRC:.c=.o)

OBJS_BONUS = $(SRC_BONUS:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

RM = rm -f

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -Imlx -c $^ -o $@

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIB)
	@$(MAKE) -C $(MLX)
	@cp  $(LIB)libft.a .
	@$(CC) $(FLAGS)  libft.a -Imlx -Iso_long.h -Lmlx -lmlx -framework OpenGL -framework AppKit  $^ -o $@
	

bonus: $(OBJS_BONUS)
	$(CC) $(FLAGS)  libft.a -Imlx -Iso_long_bonus.h -Lmlx -lmlx -framework OpenGL -framework AppKit  $^ -o $(NAME)
	
clean:
	$(RM) $(OBJS) $(OBJS_BONUS) $(LIB)*.o $(MLX)*.o

fclean: clean
	$(RM) $(NAME) $(LIB)libft.a $(MLX)libmlx.a libft.a libmlx.a

re: fclean all

.PHONY: all clean fclean re bonus
