/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala-ba <jsala-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 07:11:33 by jsala-ba          #+#    #+#             */
/*   Updated: 2023/11/02 16:01:15 by jsala-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H
# include "events.h"
# include "colors.h"
# define MLX 0
# define WIN1 1
# define SPACE 2
# define WALL 3
# define GIFT1 4
# define GIFT2 5
# define EXIT 6
# define PLAYER 7
# define PLAYER_L 8
# define PLAYER_R 9
# define PLAYER_D 10
# define PLAYER_U 11
# define BLAST 12
# define BOMB 13
# define BLANK 14
# define IMG_SIZE 15
# define PS 40
# ifdef LINUX
#  define LEFT 65361
#  define RIGHT 65363
#  define DOWN 65364
#  define UP 65362
#  define ESC 65307
#  define LEFT_A 97
#  define RIGHT_D 100
#  define DOWN_S 115
#  define UP_W 119
#  define KEY_R 114
#  define KEY_SP 32
# else
#  define LEFT 123
#  define RIGHT 124
#  define DOWN 125
#  define UP 126
#  define ESC 53
#  define LEFT_A 0
#  define RIGHT_D 2
#  define DOWN_S 1
#  define UP_W 13
#  define KEY_R 15
#  define KEY_SP 49
# endif

# include "helper.h"
# include "mlx.h"
# include <stdlib.h>

int		move_check(int keycode, t_context *context);
void	clean_memory(t_context *context);
void	wshow_counter(int val, t_context *context);
void	redraw(t_context *ct);
void	redraw_gifts(t_context *ct);
void	wshow_message(char *str, t_context *context, int color);
int		resize_event(void *param);
int		close_event(t_context *cn);
int		check_game_end(t_context *ct, int val);
#endif
