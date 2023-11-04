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

static int	check_cell(size_t *cd, char *buf, size_t *lcnt, int *pdone)
{
	int	val;

	val = gval(buf, cd[ROW], cd[COL], lcnt);
	if (val == 'P')
	{
		buf[cd[ROW] * ((lcnt[COLC] + 1)) + cd[COL]] = '2';
		*pdone = 0;
	}
	else if (val == '0' || val == 'C' || val == 'E')
	{
		if (gval_around(buf, cd, lcnt, '2'))
		{
			if (val == 'E' || val == 'C')
				lcnt[CAD_CHECK]++;
			if (lcnt[C_CNT] + 1 == lcnt[CAD_CHECK])
				return (1);
			if (val == 'E')
				buf[cd[ROW] * ((lcnt[COLC] + 1)) + cd[COL]] = '1';
			else
				buf[cd[ROW] * ((lcnt[COLC] + 1)) + cd[COL]] = '2';
			*pdone = 0;
		}
	}
	return (0);
}

static char	*check_buffer(char *buf, size_t *lcnt)
{
	size_t	cd[2];
	int		done;

	done = 0;
	while (!done)
	{
		done = 1;
		cd[ROW] = 1;
		while (cd[ROW] < lcnt[ROWC] - 1)
		{
			cd[COL] = 1;
			while (cd[COL] < lcnt[COLC] - 1)
			{
				if (check_cell(cd, buf, lcnt, &done))
					return (NULL);
				cd[COL]++;
			}
			cd[ROW]++;
		}
	}
	return (MESS_NO_SOLUTION);
}

char	*check_solution(char *buf, size_t fsize, size_t *lcnt)
{
	char	*testbuf;
	size_t	n;
	char	*res;

	testbuf = malloc(fsize);
	n = 0;
	while (n < fsize)
	{
		testbuf[n] = buf[n];
		n++;
	}
	res = check_buffer(testbuf, lcnt);
	free(testbuf);
	if (res == NULL)
	{
		if (lcnt[C_CNT] + 1 != lcnt[CAD_CHECK])
		{
			return (MESS_COL_BLOCKED);
		}
	}
	return (res);
}

char	*check_elements(char *buf, size_t *lcnt)
{
	size_t	r1;
	size_t	c1;
	int		val;

	r1 = 0;
	while (r1 < lcnt[ROWC])
	{
		c1 = 0;
		while (c1 < lcnt[COLC])
		{
			val = gval(buf, r1, c1, lcnt);
			if (!check_elem(val))
				return (MESS_CHARS_NOT_ALLOWED);
			count_elements(val, lcnt, r1, c1);
			c1++;
		}
		r1++;
	}
	if (lcnt[P_CNT] != 1)
		return (MESS_POS_INI);
	if (lcnt[E_CNT] != 1)
		return (MESS_SALIDAS);
	if (lcnt[C_CNT] < 1)
		return (MESS_COLECCIONABLE);
	return (NULL);
}

char	*check_walls(char *buf, size_t *lcnt)
{
	size_t	r1;
	size_t	c1;
	int		val;

	r1 = 0;
	while (r1 < lcnt[ROWC])
	{
		c1 = 0;
		while (c1 < lcnt[COLC])
		{
			val = gval(buf, r1, c1, lcnt);
			if (((r1 == 0) || (r1 == lcnt[ROWC] - 1) || (c1 == 0)
					|| (c1 == lcnt[COLC] - 1)) && (val != '1'))
			{
				return (MESS_WALLS_NOT_OK);
			}
			c1++;
		}
		r1++;
	}
	return (NULL);
}
