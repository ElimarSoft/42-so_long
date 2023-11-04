/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala-ba <jsala-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 07:39:54 by jsala-ba          #+#    #+#             */
/*   Updated: 2023/11/01 18:17:27 by jsala-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H
# include <stddef.h>

typedef struct s_coord
{
	size_t	col;
	size_t	row;
}			t_coord;

typedef struct s_context
{
	char	*buf;
	char	*filename;
	size_t	*lcnt;
	void	**img;
	t_coord	*track;
	size_t	fsize;
}			t_context;

int			show_message(char *message);
int			show_error(char *message);
int			show_error2(char *message1, char *message2 );
int			show_counters(size_t *lcnt);
int			show_key_code(int keycode);
#endif
