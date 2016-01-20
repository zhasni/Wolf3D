/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 19:15:44 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/05 18:53:37 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_init_texture_bis(t_env *env)
{
	env->xpm[12].ptr = mlx_get_data_addr(env->xpm[12].tex, &env->xpm[12].bpp,
			&env->xpm[12].sline, &env->xpm[12].endian);
}

void	ft_xpm_to_img_bis(t_env *env)
{
	env->xpm[12].tex = mlx_xpm_file_to_image(env->mlx, "pics/greystone.xpm",
			&env->xpm[12].width, &env->xpm[12].height);
}

void	ft_get_color(t_env *env, int x, int y, int z)
{
	env->r = *(env->xpm[z].ptr + y * env->xpm[z].sline +
			(env->xpm[z].bpp / 8) * x);
	env->g = *(env->xpm[z].ptr + y * env->xpm[z].sline +
			(env->xpm[z].bpp / 8) * x + 1);
	env->b = *(env->xpm[z].ptr + y * env->xpm[z].sline +
			(env->xpm[z].bpp / 8) * x + 2);
}

int		ft_wolf(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "WOLF3D");
	if (!(env->img = mlx_new_image(env->mlx, SCREEN_WIDTH, SCREEN_HEIGHT)))
		return (-1);
	if (!(env->str = mlx_get_data_addr(env->img, &(env->bpp), &(env->sline),
					&(env->endian))))
		return (-1);
	ft_xpm_to_img(env);
	ft_init_texture(env);
	ft_texture_to_int(env);
	mlx_do_key_autorepeaton(env->mlx);
	mlx_hook(env->win, 2, 3, key_hook, env);
	mlx_mouse_hook(env->win, mouse_hook, env);
	mlx_expose_hook(env->win, expose_hook, env);
	mlx_loop(env->mlx);
	return (0);
}
