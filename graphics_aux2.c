/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_aux2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: jsala-ba <jsala-ba@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/10/19 12:41:55 by jsala-ba          #+#    #+#             */
/*   Updated: 2023/10/19 12:41:55 by jsala-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int	resize_event(void *param)
{
	redraw(param);
	return (0);
}

int	close_event(t_context *cn)
{
	clean_memory(cn);
	exit(0);
	return (0);
}

int	check_game_end(t_context *ct, int val)
{
	if (val == 'E')
	{
		if (!ct->lcnt[CAD_DONE])
			return (1);
		else
		{
			ct->lcnt[GAME_END] = 1;
			show_message(GREEN MESS_GAME_OVER DEFAULT);
			wshow_message(MESS_GAME_OVER, ct, CL_LIME);
			fill_message(ct, GIFT1);
		}
	}
	return (0);
}
