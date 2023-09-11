# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tofujiwa <tofujiwa@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/31 15:26:11 by tofujiwa          #+#    #+#              #
#    Updated: 2023/09/11 20:21:47 by tofujiwa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
SRCS = check_map.c main.c read_map.c init.c check_path.c copy_map.c
OBJS = $(SRCS:.c=.o)
PRINTF = ft_printf/libftprintf.a
GNL = get_next_line/get_next_line.a

all : $(NAME)

$(NAME): $(OBJS)
	make -C ft_printf
	make -C get_next_line
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(GNL) $(MLX_FLAGS) -o $(NAME)

# ft_printf/libftprintf.a noato $(MLX_FLAGS)

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