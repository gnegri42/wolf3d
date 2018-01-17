# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gnegri <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/04 09:53:23 by gnegri            #+#    #+#              #
#    Updated: 2018/01/08 10:49:06 by bmuselet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 			wolf3d

SRCS = 			main.c\
				ft_reader.c\
				ft_atoi_wolf.c\
				ft_check_errors.c\
				ft_keycode.c\
				ft_init.c\
				ft_calc.c\
				ft_draw.c\
				ft_move.c\
				ft_textures.c\
				ft_no_textures.c\
				ft_weapon.c\
				ft_mouse_events.c\
				ft_minimap.c\
				ft_keycode2.c\
				ft_exit_properly.c\
				ft_calc_weapon_hit.c\
				ft_sky_and_floor.c\
				ft_fill_pixel.c\

OBJS = 			$(SRCS:.c=.o)

INC = 			libft.h\
				fractol.h\

CC = 			gcc

FLAGS = 		-Wall -Wextra -Werror -flto

FLAGS2 = 		-lmlx -framework OpenGl -framework AppKit

LIB_PATH = 		libft/

LIB = 			libft/libft.a

.PHONY: all clean fclean re

all : 	lib $(NAME)

lib :
	@make -C $(LIB_PATH)

$(NAME) : $(OBJS)
	@echo "\033[1;91mCompilation... wolf3d\033[0m"
	@$(CC) $(FLAGS) -c $(SRCS)
	@$(CC) $(FLAGS) $(FLAGS2) -o $(NAME) $(OBJS) $(LIB) -Wunused-command-line-argument
	@echo "\033[1;91mCompilation complete !\033[0m"

$(OBJS): $(SRCS)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@make clean -C $(LIB_PATH)
	@/bin/rm -f $(OBJS)
	@echo "\033[1;91m$(OBJS) removed !\033[0m"

fclean: clean
	@make fclean -C $(LIB_PATH)
	@/bin/rm -f $(NAME)
	@echo "\033[1;91m$(NAME) removed !\033[0m"

re: fclean all
