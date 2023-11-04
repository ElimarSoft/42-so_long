/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala-ba <jsala-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:16:33 by jsala-ba          #+#    #+#             */
/*   Updated: 2023/11/03 16:16:33 by jsala-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	track_init(t_context *ct)
{
	ct = ct;
}

int	track(t_coord *coord, t_context *ct)
{
	ct->lcnt[COL_POS] = coord->col;
	ct->lcnt[ROW_POS] = coord->row;
	return (0);
}
