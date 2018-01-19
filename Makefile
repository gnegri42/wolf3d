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

NAME = wolf3d

SRC_PATH = srcs
SRC_NAME = main.c\
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
			ft_tools.c\
			ft_fill_pixel.c\
			ft_dmg_walls.c\
			ft_modif_textures.c\

OBJ_PATH = objs
OBJ_NAME = $(SRC_NAME:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

CPPFLAGS = -I includes -I libft/libft.h

LDFLAGS = -L libft
LDLIBS = -lft -lm -lmlx -framework OpenGL -framework AppKit

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: libft $(NAME)

$(NAME): $(OBJ) libft/libft.a
	@$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@
	@echo "\033[1;91mCompilation Wolf3d complete !\033[0m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $< $(CPPFLAGS) -o $@

libft:
	@make -C libft

clean:
	@make -C libft clean
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "\033[1;91m$(OBJ_NAME) removed !\033[0m"

fclean:
	@make -C libft fclean
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "\033[1;91m$(OBJ_NAME) removed !\033[0m"
	@rm -f $(NAME)
	@echo "\033[1;91m$(NAME) removed !\033[0m"

re: fclean all

norme:
	norminette $(SRC)
	norminette includes/*.h

.PHONY: all clean fclean re libft norme