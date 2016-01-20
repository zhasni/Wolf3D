/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 21:51:17 by zhasni            #+#    #+#             */
/*   Updated: 2015/01/28 15:56:14 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_put_pix_image(t_env *env, int x, int y, int color)
{
	int		i;

	i = ((env->bpp / 8) * x) + ((env->sline) * y);
	if (i >= 0 && i < SCREEN_HEIGHT * env->sline && i > y * env->sline && i <
			(y * env->sline) + ((env->bpp / 8) * SCREEN_WIDTH))
	{
		env->str[i] = color;
		env->str[i + 1] = (color) >> 8;
		env->str[i + 2] = (color) >> 16;
	}
}

void	ft_verline(int x, t_env *env)
{
	while (env->drawstart < env->drawend)
	{
		ft_put_pix_image(env, x, env->drawstart, env->color);
		env->drawstart++;
	}
}

void	ft_draw_ground(int x, t_env *env)
{
	while (env->drawend < SCREEN_HEIGHT)
	{
		ft_put_pix_image(env, x, env->drawend, 0x808080);
		env->drawend++;
	}
}

void	ft_draw_sky(int x, t_env *env)
{
	int		i;

	i = 0;
	while (i < env->drawstart)
	{
		ft_put_pix_image(env, x, i, 0x99FFFF);
		i++;
	}
}

void	ft_draw_background(t_env *env)
{
	int		x;
	int		y;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			ft_put_pix_image(env, x, y, 0x808080);
			x++;
		}
		y++;
	}
}
