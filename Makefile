# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsala-ba <jsala-ba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 15:46:38 by jsala-ba          #+#    #+#              #
#    Updated: 2023/11/04 13:06:20 by jsala-ba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

LIBFT_P = libft/

OS = $(shell uname)

ifeq ($(OS), Linux)
$(info Linux Make)
	SANITIZER_C = -Wno-gnu-include-next -I .lib/LeakSanitizerLinux/include
	SANITIZER_L = -rdynamic -L .lib/LeakSanitizerLinux -llsan -ldl -lstdc++
	# CFLAGS = -Wall -Wextra -Werror -I .lib/minilibx-linux -I libft -g -D LINUX
	CFLAGS = -Wall -Wextra -I .lib/minilibx-linux -I libft -g -D LINUX
	LFLAGS = -L .lib/minilibx-linux  -lmlx -L /usr/lib -lXext -lX11 -lm
	MLX_AUX = mlx_aux_linux.c
else
$(info macOS Make)
	SANITIZER_C = -Wno-gnu-include-next -I .lib/LeakSanitizer/include
	SANITIZER_L = -L .lib/LeakSanitizer -llsan -lc++
	CFLAGS = -Wall -Wextra -I .lib/minilibx_opengl -I libft -g $(SANITIZER_C)
	# CFLAGS = -Wall -Wextra -Werror -I .lib/minilibx_opengl -I libft -g
	LFLAGS = -L .lib/minilibx_opengl -lmlx -framework OpenGL -framework AppKit $(SANITIZER_L)
	MLX_AUX = mlx_aux.c
endif

EXTRA_BASE = track1.c track2.c wshow.c
EXTRA_BONUS = track1_bonus.c track2_bonus.c wshow_bonus.c

LIBFT_N = ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_itoa.c ft_strjoin.c
LIBFT = $(addprefix $(LIBFT_P), $(LIBFT_N))
SRCS = so_long.c utils.c check.c check_aux.c helper.c graphics.c \
	graphics_aux1.c graphics_aux2.c graphics_aux3.c graphics_aux4.c \
	$(MLX_AUX)

CC = cc
RM = rm -f

SRCS_BASE = $(SRCS) $(EXTRA_BASE)
SRCS_BONUS = $(SRCS) $(EXTRA_BONUS)

OBJS_BASE = $(SRCS_BASE:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)
OBJS_LIBFT = $(LIBFT:%.c=%.o)

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS_BASE) $(OBJS_LIBFT)
	@$(CC) -o $(NAME) $(OBJS_BASE) $(OBJS_LIBFT) $(LFLAGS)

$(NAME_BONUS): $(OBJS_BONUS) $(OBJS_LIBFT)
	@$(CC) -o $(NAME_BONUS) $(OBJS_BONUS) $(OBJS_LIBFT) $(LFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJS_BASE)
	$(RM) $(OBJS_BONUS)
	$(RM) $(OBJS_LIBFT)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re:	fclean all

re_bonus: fclean bonus

os:
	@echo $(OS)

git:
	git add *.h
	git add *.c
	git add Makefile
	git add libft\*.h
	git add libft\*.c
	git add .lib/minilibx_opengl/mlx.h
	git add .lib/minilibx_opengl/libmlx.a



