/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track2 _bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala-ba <jsala-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:16:41 by jsala-ba          #+#    #+#             */
/*   Updated: 2023/11/03 16:16:41 by jsala-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define DIST 3

static int	bomb_close_to_player(t_context *ct)
{
	size_t	diff1;
	size_t	diff2;

	if (ct->lcnt[COL_TRACK] > ct->lcnt[COL_POS])
		diff1 = ct->lcnt[COL_TRACK] - ct->lcnt[COL_POS];
	else
		diff1 = ct->lcnt[COL_POS] - ct->lcnt[COL_TRACK];
	if (ct->lcnt[ROW_TRACK] > ct->lcnt[ROW_POS])
		diff2 = ct->lcnt[ROW_TRACK] - ct->lcnt[ROW_POS];
	else
		diff2 = ct->lcnt[ROW_POS] - ct->lcnt[ROW_TRACK];
	return (diff1 < DIST && diff2 < DIST);
}

void	jump(t_context *ct)
{
	t_coord	cn;

	if (bomb_close_to_player(ct))
	{
		cn = get_coord(ct->lcnt[COL_TRACK], ct->lcnt[ROW_TRACK]);
		sval(ct, &cn, '0');
		track_init(ct);
		put_image(ct, SPACE, &cn);
	}
}

void	check_bomb_pos(t_context *ct)
{
	t_coord	cn;
	int		act;
	int		ind;

	act = ct->lcnt[IMG_TRACK];
	if (act)
	{
		if (bomb_close_to_player(ct) && ct->lcnt[IMG_TRACK])
		{
			if (act == BOMB)
			{
				if (ct->lcnt[GIFT_MEM] == 1)
					ind = BOMB;
				else
					ind = SPACE;
				cn.col = ct->lcnt[COL_TRACK];
				cn.row = ct->lcnt[ROW_TRACK];
				put_image(ct, ind, &cn);
			}
			else
				put_image(ct, act, &cn);
		}
		else
			put_image(ct, act, &cn);
	}
}
