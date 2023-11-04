/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_aux4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala-ba <jsala-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:36:28 by jsala-ba          #+#    #+#             */
/*   Updated: 2023/10/30 16:36:28 by jsala-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define BITS_PER_PIXEL 0
#define SIZE_LINE 1
#define ENDIAN 2
#define OFF1 4

int	get_pos_color(int pos)
{
	int	color;

	if (pos < OFF1)
		color = CL_YELLOW;
	else if (pos > PS - OFF1 - 1)
		color = CL_YELLOW;
	else
		color = CL_BLUE;
	return (color);
}

void	*get_image1(void **img)
{
	void	*image;
	int		*data;
	int		params[3];
	int		n;
	int		m;

	image = mlx_new_image(img[MLX], PS, PS);
	data = (int *)mlx_get_data_addr(image, params, params + 1, params + 2);
	m = 0;
	while (m < PS)
	{
		n = 0;
		while (n < PS)
		{
			data[m * PS + n] = get_pos_color(m);
			n++;
		}
		m++;
	}
	return (image);
}

void	restart_game(t_context *ct)
{
	ct->lcnt[MOV_CNT] = 0;
	ct->lcnt[CAD_CNT] = 0;
	ct->lcnt[CAD_DONE] = 0;
	ct->lcnt[GAME_END] = 0;
	ct->lcnt[COL_POS] = ct->lcnt[COL_ORG];
	ct->lcnt[ROW_POS] = ct->lcnt[ROW_ORG];
	track_init(ct);
	free(ct->buf);
	read_file(ct);
	redraw(ct);
}
