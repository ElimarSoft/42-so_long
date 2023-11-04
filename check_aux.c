/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: jsala-ba <jsala-ba@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/10/01 06:59:41 by jsala-ba          #+#    #+#             */
/*   Updated: 2023/10/01 06:59:41 by jsala-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_elements(int val, size_t *lcnt, size_t r1, size_t c1)
{
	if (val == 'P')
	{
		lcnt[P_CNT]++;
		lcnt[COL_ORG] = c1;
		lcnt[ROW_ORG] = r1;
		lcnt[COL_POS] = c1;
		lcnt[ROW_POS] = r1;
	}
	else if (val == 'E')
		lcnt[E_CNT]++;
	else if (val == 'C')
		lcnt[C_CNT]++;
}

int	gval_around(char *buf, size_t *cd, size_t *lcnt, char schar)
{
	int	left;
	int	right;
	int	up;
	int	down;

	up = gval(buf, cd[ROW] - 1, cd[COL], lcnt) == schar;
	down = gval(buf, cd[ROW] + 1, cd[COL], lcnt) == schar;
	left = gval(buf, cd[ROW], cd[COL] - 1, lcnt) == schar;
	right = gval(buf, cd[ROW], cd[COL] + 1, lcnt) == schar;
	return (left || right || up || down);
}

int	gval(char *buf, size_t r1, size_t c1, size_t *lcnt)
{
	return (buf[r1 * ((lcnt[COLC] + 1)) + c1]);
}

void	sval(t_context *context, t_coord *coord, char val)
{
	context->buf[coord->row * ((context->lcnt[COLC] + 1)) + coord->col] = val;
}

int	check_elem(char a)
{
	return (a == 'P' || a == 'E' || a == 'C' || a == '0' || a == '1');
}
