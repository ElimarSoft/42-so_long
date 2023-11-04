/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_aux.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala-ba <jsala-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:52:14 by jsala-ba          #+#    #+#             */
/*   Updated: 2023/10/30 08:15:49 by jsala-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_AUX_H
# define MLX_AUX_H

typedef struct s_mlx_img_list
{
	int						width;
	int						height;
	char					*buffer;
	float					vertexes[8];
	struct mlx_img_list		*next;
}							t_mlx_img_list;

typedef struct s_mlx_img_ctx
{
	unsigned int			texture;
	unsigned int			vbuffer;
	t_mlx_img_list			*img;
	struct s_mlx_img_ctx	*next;
}							t_mlx_img_ctx;

typedef struct s_mlx_win_list
{
	void					*winid;
	t_mlx_img_ctx			*img_list;
	int						nb_flush;
	int						pixmgt;
	struct s_mlx_win_list	*next;
}							t_mlx_win_list;

typedef struct s_mlx_ptr
{
	void					*appid;
	t_mlx_win_list			*win_list;
	t_mlx_img_list			*img_list;
	void					(*loop_hook)(void *);
	void					*loop_hook_data;
	void					*loop_timer;
	t_mlx_img_list			*font;
	int						main_loop_active;
}							t_mlx_ptr;
#endif
