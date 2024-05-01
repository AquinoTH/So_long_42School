# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taquino- <taquino-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 17:49:56 by taquino-          #+#    #+#              #
#    Updated: 2024/05/01 17:42:10 by taquino-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_PATH = ./srcs/
SRCS_PATH_BONUS = ./srcs_bonus/
OBJS_PATH = ./objs/
OBJS_PATH_BONUS = ./objs_bonus/
HEADERS_PATH = ./headers/
LIBFT_PATH = ./libft/
FT_PRINTF_PATH = ./ft_printf/

SRC_FILES = so_long.c check_map.c end_game.c check_valid_path.c read_map.c \
			check_valid_path_utils.c render.c moves_game.c init_game.c destroy_img.c

SRC_FILES_BONUS = so_long_bonus.c check_map_bonus.c end_game_bonus.c \
				check_valid_path_bonus.c moves_game_bonus.c destroy_img_bonus.c \
				read_map_bonus.c check_valid_path_utils_bonus.c render_bonus.c  \
				init_game_bonus.c handle_keypress_bonus.c bonus.c

SRCS = $(addprefix $(SRCS_PATH), $(SRC_FILES))

SRCS_BONUS = $(addprefix $(SRCS_PATH_BONUS), $(SRC_FILES_BONUS))

OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))

OBJ_FILES_BONUS = $(patsubst %.c, %.o, $(SRC_FILES_BONUS))

OBJS = $(addprefix $(OBJS_PATH), $(OBJ_FILES))

OBJS_BONUS = $(addprefix $(OBJS_PATH_BONUS), $(OBJ_FILES_BONUS))

LIBFT_A = $(LIBFT_PATH)libft.a

LIBFT_PRINTF_A = $(FT_PRINTF_PATH)libftprintf.a

MKDIR = mkdir -p

NAME = so_long

NAME_BONUS = so_long_bonus

CC   = cc

CFLAGS = -Wall -Wextra -Werror -I $(HEADERS_PATH)

MLXFLAGS = -lX11 -lXext -lmlx

RM  =  rm -f

all: $(NAME)

bonus: $(NAME_BONUS)

$(LIBFT_A):
	@cd $(LIBFT_PATH) && $(MAKE)

$(LIBFT_PRINTF_A):
	@cd $(FT_PRINTF_PATH) && $(MAKE)

$(NAME): $(LIBFT_A) $(LIBFT_PRINTF_A) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLXFLAGS) -L $(LIBFT_PATH) -lft -L $(FT_PRINTF_PATH) -lftprintf

$(NAME_BONUS): $(LIBFT_A) $(LIBFT_PRINTF_A) $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(MLXFLAGS) -L $(LIBFT_PATH) -lft -L $(FT_PRINTF_PATH) -lftprintf

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c
	@$(MKDIR) $(OBJS_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_PATH_BONUS)%.o : $(SRCS_PATH_BONUS)%.c
	@$(MKDIR) $(OBJS_PATH_BONUS)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS) $(OBJS_BONUS)
		$(MAKE) clean -C $(LIBFT_PATH)
		$(MAKE) clean -C $(FT_PRINTF_PATH)

fclean: clean
	    $(RM) $(NAME) $(NAME_BONUS)
		$(MAKE) fclean -C $(LIBFT_PATH)
		$(MAKE) fclean -C $(FT_PRINTF_PATH)

re:   fclean all

.PHONY: all clean fclean re bonus