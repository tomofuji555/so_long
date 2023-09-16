# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tofujiwa <tofujiwa@student.42.jp>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/31 15:26:11 by tofujiwa          #+#    #+#              #
#    Updated: 2023/09/16 16:28:28 by tofujiwa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
SRCS = check_map.c error.c main.c read_map.c init_map.c check_path.c copy_map.c init_mlx_img.c move.c move_utils.c render.c game_finish.c
OBJS = $(SRCS:.c=.o)
PRINTF = ft_printf/libftprintf.a
GNL = get_next_line/get_next_line.a

all : $(NAME)

$(NAME): $(OBJS)
	make -C ft_printf
	make -C get_next_line
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(GNL) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	make -C ft_printf clean
	make -C get_next_line clean
	rm -f $(OBJS)

fclean : clean
	make -C ft_printf fclean
	make -C get_next_line fclean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re