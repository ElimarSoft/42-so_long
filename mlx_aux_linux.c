/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_aux_linux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala-ba <jsala-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:14:41 by jsala-ba          #+#    #+#             */
/*   Updated: 2023/11/03 16:27:57 by jsala-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_aux.h"
#include "so_long.h"

void	clear_mlx_font(t_context *ct)
{
	mlx_destroy_display(ct->img[MLX]);
}
