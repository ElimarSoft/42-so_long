/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala-ba <jsala-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 07:15:31 by jsala-ba          #+#    #+#             */
/*   Updated: 2023/11/03 10:10:18 by jsala-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#define CUADRADO 0

int	last_char(char *buf, size_t size, size_t *lcnt)
{
	lcnt[LAST_NOT_LF] = (lcnt[0] == (size - 1)) && (buf[size] != '\n');
	return (lcnt[LAST_NOT_LF]);
}

int	get_line_size(char *buf, size_t size, size_t *lcnt)
{
	lcnt[0] = 4;
	while (--lcnt[0])
		lcnt[lcnt[0]] = 0;
	while (lcnt[0] < size)
	{
		if (buf[lcnt[0]] == '\n' || last_char(buf, size, lcnt))
		{
			if (!lcnt[COLC])
				lcnt[COLC] = lcnt[1];
			else
			{
				if (lcnt[COLC] != lcnt[1] + lcnt[LAST_NOT_LF])
					return (show_error(MESS_LINES_NOT_EQUAL));
			}
			lcnt[1] = 0;
			lcnt[ROWC]++;
		}
		else
			lcnt[1]++;
		lcnt[0]++;
	}
	if (lcnt[COLC] != lcnt[ROWC] && CUADRADO)
		return (show_message(MESS_MAPA_CUADRADO));
	return (lcnt[ROWC]);
}

void	init_vars(size_t *lcnt)
{
	int	n;

	n = 0;
	while (n < LCNT_MAX)
	{
		lcnt[n] = 0;
		n++;
	}
}

int	check_map(char *buf, size_t fsize, size_t *lcnt)
{
	char	*mess;

	if (!get_line_size(buf, fsize, lcnt))
		return (0);
	mess = check_walls(buf, lcnt);
	if (mess)
		return (show_error(mess));
	mess = check_elements(buf, lcnt);
	if (mess)
		return (show_error(mess));
	mess = check_solution(buf, fsize, lcnt);
	if (mess)
		return (show_error(mess));
	return (1);
}

int	main(int argc, char *argv[])
{
	t_context	context_inst;
	size_t		lcnt[LCNT_MAX];
	void		*img[IMG_SIZE];
	t_coord		track[TRACK_SIZE + 1];

	context_inst.lcnt = lcnt;
	context_inst.img = img;
	context_inst.track = track;
	init_vars(lcnt);
	if (argc == 2)
		context_inst.filename = argv[1];
	else
		context_inst.filename = DEFAULT_FILE;
	context_inst.buf = read_file(&context_inst);
	if (context_inst.buf == NULL)
		return (show_error2(MESS_FILE_NOT_FOUND, context_inst.filename));
	if (context_inst.fsize == 0)
		return (show_error(MESS_EMPTY_FILE));
	if (!check_map(context_inst.buf, context_inst.fsize, context_inst.lcnt))
		return (0);
	display_graphics(&context_inst);
	return (0);
}
