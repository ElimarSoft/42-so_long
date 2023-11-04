/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: jsala-ba <jsala-ba@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/10/02 06:59:16 by jsala-ba          #+#    #+#             */
/*   Updated: 2023/10/02 06:59:16 by jsala-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int	init_graphics(void **img, size_t *lcnt)
{
	int	ps;
	int	error;

	error = 0;
	ps = PS;
	img[MLX] = mlx_init();
	img[WIN1] = mlx_new_window(img[MLX], lcnt[COLC] * ps, (lcnt[ROWC]
				+ extra_rows()) * ps, "Win the Game!");
	img[BLANK] = get_image1(img);
	error += read_image(img, SPACE, "textures/fondo02.xpm");
	error += read_image(img, WALL, "textures/wall02.xpm");
	error += read_image(img, GIFT1, "textures/gift01.xpm");
	error += read_image(img, GIFT2, "textures/gift02.xpm");
	error += read_image(img, EXIT, "textures/door02.xpm");
	error += read_image(img, PLAYER, "textures/mario01.xpm");
	error += read_image(img, PLAYER_L, "textures/mario03L.xpm");
	error += read_image(img, PLAYER_R, "textures/mario03R.xpm");
	error += read_image(img, PLAYER_U, "textures/mario03U.xpm");
	error += read_image(img, PLAYER_D, "textures/mario03D.xpm");
	error += read_image(img, BOMB, "textures/bomba2.xpm");
	error += read_image(img, BLAST, "textures/explosion21.xpm");
	return (error);
}

int	get_index(char val, size_t *lcnt)
{
	int	img_ind;

	if (val == '1')
		img_ind = WALL;
	else if (val == 'E')
		img_ind = EXIT;
	else if (val == 'C')
		img_ind = GIFT1;
	else if (val == 'B')
		img_ind = BLAST;
	else if (val == 'P')
		img_ind = PLAYER + lcnt[PLAY_STAT];
	else
		img_ind = SPACE;
	return (img_ind);
}

int	key_event(int keycode, void *param)
{
	t_context	*context;

	context = (t_context *)param;
	if (keycode == ESC)
	{
		clean_memory(context);
		exit(0);
	}
	if (keycode == KEY_SP)
		jump(context);
	if (keycode == KEY_R)
		restart_game(context);
	if (!context->lcnt[GAME_END])
		move_check(keycode, context);
	if (TEST)
		show_key_code(keycode);
	return (1);
}

int	loop_hook(void *param)
{
	t_context	*context;

	context = (t_context *)param;
	context->lcnt[CYCLES_ACT]++;
	if (context->lcnt[CYCLES_ACT] >= 1000)
	{
		redraw_gifts(context);
		check_bomb_pos(context);
		context->lcnt[CYCLES_ACT] = 0;
	}
	return (0);
}

int	display_graphics(t_context *ct)
{
	track_init(ct);
	if (init_graphics(ct->img, ct->lcnt))
	{
		clean_memory(ct);
		return (show_message("Image file error\n"));
	}
	redraw(ct);
	mlx_hook(ct->img[WIN1], KEYPRESS, KEYPRESSMASK, key_event, ct);
	mlx_hook(ct->img[WIN1], DESTROYNOTIFY, STRUCTURENOTIFYMASK, close_event,
		ct);
	mlx_hook(ct->img[WIN1], RESIZEREQUEST, RESIZEREDIRECTMASK, resize_event,
		ct);
	mlx_loop_hook(ct->img[MLX], loop_hook, ct);
	mlx_loop(ct->img[MLX]);
	return (1);
}
