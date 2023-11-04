/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_aux_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala-ba <jsala-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 07:55:08 by jsala-ba          #+#    #+#             */
/*   Updated: 2023/10/23 07:55:08 by jsala-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_context *ct, int index, t_coord *pos)
{
	mlx_put_image_to_window(ct->img[MLX], ct->img[WIN1], ct->img[index],
		pos->col * PS, (pos->row + extra_rows()) * PS);
}

t_coord	get_coord(int col, int row)
{
	t_coord	cd;

	cd.col = col;
	cd.row = row;
	return (cd);
}

void	redraw(t_context *ct)
{
	t_coord	pos;
	int		img_ind;
	char	val;

	pos.row = 0;
	while (pos.row < ct->lcnt[ROWC])
	{
		pos.col = 0;
		while (pos.col < ct->lcnt[COLC])
		{
			val = gval(ct->buf, pos.row, pos.col, ct->lcnt);
			img_ind = get_index(val, ct->lcnt);
			put_image(ct, img_ind, &pos);
			pos.col++;
		}
		pos.row++;
	}
	fill_header(ct, 0, ct->lcnt[COLC], BLANK);
}

void	redraw_gifts(t_context *ct)
{
	t_coord	pos;
	char	val;

	if (ct->lcnt[GIFT_MEM] == 0)
		ct->lcnt[GIFT_MEM] = 1;
	else
		ct->lcnt[GIFT_MEM] = 0;
	pos.row = 0;
	while (pos.row < ct->lcnt[ROWC])
	{
		pos.col = 0;
		while (pos.col < ct->lcnt[COLC])
		{
			val = gval(ct->buf, pos.row, pos.col, ct->lcnt);
			if (val == 'C')
			{
				put_image(ct, GIFT1 + ct->lcnt[GIFT_MEM], &pos);
			}
			pos.col++;
		}
		pos.row++;
	}
}

int	read_image(void **img, int ind, char *path)
{
	int	ps;

	ps = PS;
	img[ind] = mlx_xpm_file_to_image(img[MLX], path, &ps, &ps);
	if (img[ind] == NULL)
		return (1);
	else
		return (0);
}
