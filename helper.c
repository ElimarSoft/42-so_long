/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala-ba <jsala-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 07:29:28 by jsala-ba          #+#    #+#             */
/*   Updated: 2023/11/01 18:24:13 by jsala-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int	show_message(char *message)
{
	ft_putendl_fd(message, 1);
	return (0);
}

int	show_error(char *message)
{
	ft_putstr_fd(RED "Error : " YELLOW, 1);
	ft_putstr_fd(message, 1);
	ft_putstr_fd(DEFAULT "\n", 1);
	return (0);
}

int	show_error2(char *message1, char *message2)
{
	ft_putstr_fd(RED "Error : " YELLOW, 1);
	ft_putstr_fd(message1, 1);
	ft_putstr_fd(GREEN, 1);
	ft_putstr_fd(message2, 1);
	ft_putstr_fd(DEFAULT "\n", 1);
	return (0);
}

int	show_counters(size_t *lcnt)
{
	ft_putstr_fd(BLUE "Pasos : " DEFAULT, 1);
	ft_putnbr_fd(lcnt[MOV_CNT], 1);
	ft_putstr_fd("\n", 1);
	return (0);
}

int	show_key_code(int keycode)
{
	int	debug;

	debug = 1;
	if (debug)
	{
		ft_putstr_fd(GRAY "Keycode ", 1);
		ft_putnbr_fd(keycode, 1);
		ft_putstr_fd("\n", 1);
	}
	return (0);
}
