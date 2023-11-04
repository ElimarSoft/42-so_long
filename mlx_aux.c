/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala-ba <jsala-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:14:41 by jsala-ba          #+#    #+#             */
/*   Updated: 2023/11/03 16:27:45 by jsala-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_aux.h"
#include "so_long.h"

void	clear_mlx_font(t_context *ct)
{
	t_mlx_ptr	*mlx;

	mlx = ct->img[MLX];
	if (mlx && mlx->font)
		mlx_destroy_image(mlx, mlx->font);
}
