/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala-ba <jsala-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 07:00:36 by jsala-ba          #+#    #+#             */
/*   Updated: 2023/11/03 17:00:23 by jsala-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "check.h"
# include "graphics.h"
# include "helper.h"
# include "messages.h"
# include <stddef.h>
# define DEFAULT_FILE "maps/data6.ber"
# define TEST 0
# define COLC 2
# define ROWC 3
# define P_CNT 4
# define C_CNT 5
# define E_CNT 6
# define COL_POS 7
# define ROW_POS 8
# define COL_ORG 9
# define ROW_ORG 10
# define MOV_CNT 11
# define CAD_CNT 12
# define CAD_DONE 13
# define CAD_CHECK 14
# define GAME_END 15
# define KEY_CODE 16
# define PLAY_STAT 17
# define CYCLES_ACT 18
# define GIFT_MEM 19
# define COL_TRACK 20
# define ROW_TRACK 21
# define IMG_TRACK 22
# define LAST_NOT_LF 23
# define LCNT_MAX 24
# define ROW 0
# define COL 1
# define TRACK_SIZE 8
# define TEXT_POS 20
# define H_MESSAGE 4
# define H_FILL 10

t_coord	get_coord(int col, int row);
char	*get_next_line(int fd);
int		get_file_size(char *dict_path);
char	*read_file(t_context *ct);
int		get_line_size(char *buf, size_t size, size_t *lcnt);
int		display_graphics(t_context *ct);
int		track(t_coord *coord, t_context *ct);
void	track_init(t_context *ct);
void	put_image(t_context *ct, int index, t_coord *pos);
int		read_image(void **img, int ind, char *path);
int		get_index(char val, size_t *lcnt);
void	clear_mlx_font(t_context *ct);
void	*get_image1(void **img);
void	fill_header(t_context *ct, int start, int stop, int img_ind);
void	fill_message(t_context *ct, int img_ind);
void	init_vars(size_t *lcnt);
void	restart_game(t_context *ct);
void	track_init(t_context *ct);
int		check_elem(char a);
void	jump(t_context *ct);
void	check_bomb_pos(t_context *ct);
int		extra_rows(void);
#endif
