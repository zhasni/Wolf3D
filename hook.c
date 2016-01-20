/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 15:41:20 by zhasni            #+#    #+#             */
/*   Updated: 2014/12/28 15:46:26 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		expose_hook(t_env *env)
{
	ft_bzero(env->str, SCREEN_HEIGHT * env->sline);
	ft_draw_map(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *env)
{
	if (button == 1)
		ft_destroy_block(env, x, y);
	if (button == 3)
	{
		ft_init_dda(x, env);
		ft_side_ray_dist(env);
		ft_dist_wallx4(env);
		ft_start_end_line(env);
		ft_add_block(env, y);
	}
	expose_hook(env);
	return (0);
}

int		key_hook_ter(int keycode, t_env *env)
{
	if (keycode == T_O)
	{
		env->udiv = 4;
		env->vdiv = 4;
	}
	if (keycode == T_P && env->vmove < 500)
		env->vmove += 10;
	if (keycode == T_L && env->vmove > 0)
		env->vmove -= 10;
	return (0);
}

int		key_hook_bis(int keycode, t_env *env)
{
	if (keycode == T_Q)
		env->mod_floor = 0;
	if (keycode == T_W)
		env->mod_floor = 1;
	if (keycode == T_E)
		env->mod_floor = 2;
	if (keycode == T_R)
		env->size_fc = 0;
	if (keycode == T_T)
		env->size_fc = 1;
	if (keycode == T_Y)
		env->size_fc = 2;
	if (keycode == T_U)
	{
		env->udiv = 1;
		env->vdiv = 1;
	}
	if (keycode == T_I)
	{
		env->udiv = 2;
		env->vdiv = 2;
	}
	else
		key_hook_ter(keycode, env);
	return (0);
}

int		key_hook(int keycode, t_env *env)
{
	if (keycode == T_ESC)
		exit (0);
	if (keycode == T_UP)
		ft_move_forward(env);
	if (keycode == T_DOWN)
		ft_move_backward(env);
	if (keycode == T_RIGHT)
		ft_rotate_right(env);
	if (keycode == T_LEFT)
		ft_rotate_left(env);
	if (keycode == T_SEVEN)
		env->view = 1.2;
	if (keycode == T_FOUR)
		env->view = 2;
	if (keycode == T_ONE)
		env->view = 10;
	if (keycode == T_C)
		ft_move_left(env);
	if (keycode == T_Z)
		ft_move_right(env);
	else
		key_hook_bis(keycode, env);
	expose_hook(env);
	return (0);
}
