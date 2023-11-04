/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala-ba <jsala-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:16:23 by jsala-ba          #+#    #+#             */
/*   Updated: 2023/11/03 16:16:23 by jsala-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	track_init(t_context *ct)
{
	int	n;

	n = 0;
	while (n <= TRACK_SIZE)
	{
		ct->track[n].row = 0;
		ct->track[n].col = 0;
		n++;
	}
	ct->lcnt[IMG_TRACK] = 0;
	ct->lcnt[ROW_TRACK] = 0;
	ct->lcnt[COL_TRACK] = 0;
}

static void	set_pos(unsigned int *pos, int n)
{
	pos[0] = n;
	pos[1] = (pos[0] + 1) % TRACK_SIZE;
	pos[2] = (pos[0] + 2) % TRACK_SIZE;
}

static void	blast(t_context *ct, size_t pos)
{
	put_image(ct, BLAST, &ct->track[pos]);
	ct->lcnt[IMG_TRACK] = BLAST;
	show_message(RED MESS_EXPLODED DEFAULT);
	wshow_message(WMESS_EXPLODED, ct, CL_RED);
	fill_message(ct, BLAST);
	ct->lcnt[GAME_END] = 1;
}

static void	set_track_pos(t_coord *cd, t_context *ct)
{
	ct->lcnt[COL_TRACK] = cd->col;
	ct->lcnt[ROW_TRACK] = cd->row;
}

int	track(t_coord *coord, t_context *ct)
{
	unsigned int	pos[3];
	t_coord			cn[2];

	ct->lcnt[COL_POS] = coord->col;
	ct->lcnt[ROW_POS] = coord->row;
	set_pos(pos, ct->track[TRACK_SIZE].row);
	ct->track[pos[0]] = *coord;
	ct->track[TRACK_SIZE].row = pos[1];
	if (ct->track[pos[1]].col && ct->track[pos[1]].row)
	{
		put_image(ct, SPACE, &ct->track[pos[1]]);
		put_image(ct, BOMB, &ct->track[pos[2]]);
		ct->lcnt[IMG_TRACK] = BOMB;
		cn[0] = ct->track[pos[1]];
		cn[1] = ct->track[pos[2]];
		if (gval(ct->buf, cn[1].row, cn[1].col, ct->lcnt) == 'P')
		{
			blast(ct, pos[2]);
			return (1);
		}
		sval(ct, cn, '0');
		sval(ct, cn + 1, 'B');
		set_track_pos(cn + 1, ct);
	}
	return (0);
}
