/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_aux1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: jsala-ba <jsala-ba@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/10/19 12:42:02 by jsala-ba          #+#    #+#             */
/*   Updated: 2023/10/19 12:42:02 by jsala-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_key_index(int keycode, int game_over)
{
	if (game_over)
		return (0);
	if (keycode == LEFT || keycode == LEFT_A)
		return (1);
	if (keycode == RIGHT || keycode == RIGHT_D)
		return (2);
	if (keycode == DOWN || keycode == DOWN_S)
		return (3);
	if (keycode == UP || keycode == UP_W)
		return (4);
	return (0);
}

int	move_to(t_coord *pos1, t_coord *pos2, t_context *ct, int val)
{
	int	key_index;

	if (check_game_end(ct, val))
		return (0);
	ct->lcnt[MOV_CNT]++;
	if (val == 'C')
	{
		ct->lcnt[CAD_CNT]++;
		if (ct->lcnt[CAD_CNT] == ct->lcnt[C_CNT])
			ct->lcnt[CAD_DONE] = 1;
	}
	key_index = get_key_index(ct->lcnt[KEY_CODE], ct->lcnt[GAME_END]);
	ct->lcnt[PLAY_STAT] = key_index;
	put_image(ct, PLAYER + key_index, pos2);
	put_image(ct, SPACE, pos1);
	sval(ct, pos1, '0');
	sval(ct, pos2, 'P');
	if (track(pos2, ct))
		return (0);
	show_counters(ct->lcnt);
	wshow_counter(ct->lcnt[MOV_CNT], ct);
	return (0);
}

int	move_check(int keycode, t_context *context)
{
	t_coord	c1;
	t_coord	c2;
	int		val;

	c1.col = context->lcnt[COL_POS];
	c1.row = context->lcnt[ROW_POS];
	c2 = c1;
	context->lcnt[KEY_CODE] = keycode;
	if (keycode == UP || keycode == UP_W)
		c2.row--;
	else if (keycode == DOWN || keycode == DOWN_S)
		c2.row++;
	else if (keycode == LEFT || keycode == LEFT_A)
		c2.col--;
	else if (keycode == RIGHT || keycode == RIGHT_D)
		c2.col++;
	val = gval(context->buf, c2.row, c2.col, context->lcnt);
	if (val == '0' || val == 'C' || val == 'E')
		move_to(&c1, &c2, context, val);
	return (0);
}

void	clean_image(t_context *context, int index)
{
	if (context->img[MLX] && context->img[index])
		mlx_destroy_image(context->img[MLX], context->img[index]);
}

void	clean_memory(t_context *context)
{
	int	n;

	free(context->buf);
	mlx_clear_window(context->img[MLX], context->img[WIN1]);
	mlx_destroy_window(context->img[MLX], context->img[WIN1]);
	n = SPACE;
	while (n < IMG_SIZE)
	{
		clean_image(context, n);
		n++;
	}
	clear_mlx_font(context);
	free(context->img[MLX]);
	n = 0;
	while (n < IMG_SIZE)
	{
		context->img[n] = NULL;
		n++;
	}
}
