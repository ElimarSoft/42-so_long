/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wshow_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala-ba <jsala-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:17:12 by jsala-ba          #+#    #+#             */
/*   Updated: 2023/11/03 16:17:12 by jsala-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	wshow_counter(int val, t_context *ct)
{
	t_coord	pos;
	int		color;
	char	*str[2];

	str[0] = ft_itoa(val);
	pos = get_coord(10, TEXT_POS);
	color = 0xffffff;
	fill_header(ct, 0, H_MESSAGE, BLANK);
	str[1] = ft_strjoin("Pasos = ", str[0]);
	mlx_string_put(ct->img[MLX], ct->img[WIN1], pos.col, pos.row, color,
		str[1]);
	free(str[0]);
	free(str[1]);
}

void	wshow_message(char *str, t_context *ct, int color)
{
	t_coord	pos;

	pos = get_coord(4 * PS, TEXT_POS);
	fill_header(ct, H_MESSAGE, H_FILL, BLANK);
	mlx_string_put(ct->img[MLX], ct->img[WIN1], pos.col, pos.row, color, str);
}

void	fill_header(t_context *ct, int start, int stop, int img_ind)
{
	int		n;
	t_coord	pos;

	n = start;
	while (n < stop)
	{
		pos = get_coord(n, -1);
		put_image(ct, img_ind, &pos);
		n++;
	}
}

void	fill_message(t_context *ct, int img_ind)
{
	if (ct->lcnt[COLC] > H_FILL + 4)
		fill_header(ct, H_FILL, ct->lcnt[COLC] - 2, img_ind);
}

int	extra_rows(void)
{
	return (1);
}
