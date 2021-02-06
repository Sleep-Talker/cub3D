
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almarsel <almarsel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/25 09:20:37 by almarsel          #+#    #+#              #
#    Updated: 2021/02/05 07:16:51 by almarsel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
LIBFT = libft
OS	= $(shell uname)
DIR_S = srcs
INCLUDES = -I includes/ -I libft/ -I $(MLX_DIR) -I get_next_line/
CC = clang
CFLAGS	= -O3 -Wall -Wextra -Werror
LIBS	= -L libft/ -lft ${MLX_LNK} -lm
GNLBUFF = -D BUFFER_SIZE=100
SOURCES =  srcs/move_cam.c \
	   srcs/parse_map.c \
	   srcs/parse_camera.c \
	   srcs/ray_casting.c \
	   srcs/sprites.c \
	   srcs/hooks.c \
	   srcs/dda.c \
	   srcs/draw.c \
	   srcs/parse_color.c \
	   srcs/parse_main.c \
	   srcs/parse_utils.c \
	   srcs/flood_fill.c \
	   srcs/screenshot.c \
	   srcs/exit.c \
	   srcs/error.c \
	   srcs/cub3d.c

OBJS	= ${SOURCES:.c=.o}
MLX_DIR	= mlx/minilibx-linux/
MLX_LNK	= -L ${MLX_DIR} -lmlx -lXext -lX11 -lbsd
SOURCES += mlx/get_next_line.c

.c.o:
	${CC} ${CFLAGS} ${GNLBUFF} -c $< -o ${<:.c=.o} ${INCLUDES}

all : $(NAME)

${NAME}: ${OBJS} ft mlx
		${CC} ${CFLAGS} ${INCLUDES} ${OBJS} ${LIBS} -o ${NAME}

mlx:
	@make -C $(MLX_DIR)

ft:
	@make -C libft

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/*.h
	@mkdir -p objs
	@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<
clean :
	@rm -f $(OBJS)
	@make clean -C $(LIBFT)
	@make clean -C $(MLX_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@make clean -C $(MLX_DIR)

re: fclean all

.PHONY:	clean fclean all re mlx ft