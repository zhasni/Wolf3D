/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 16:02:19 by zhasni            #+#    #+#             */
/*   Updated: 2015/01/28 15:55:57 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_init_dda(int x, t_env *env)
{
	env->camerax = 2 * x / (double)SCREEN_WIDTH - 1;
	env->rayposx = env->posx;
	env->rayposy = env->posy;
	env->raydirx = env->dirx + env->planex * env->camerax;
	env->raydiry = env->diry + env->planey * env->camerax;
	env->mapx = (int)env->rayposx;
	env->mapy = (int)env->rayposy;
	env->deltadistx = sqrt(1 + (env->raydiry * env->raydiry)
			/ (env->raydirx * env->raydirx));
	env->deltadisty = sqrt(1 + (env->raydirx * env->raydirx)
			/ (env->raydiry * env->raydiry));
}

void	ft_side_ray_dist(t_env *env)
{
	if (env->raydirx < 0)
	{
		env->stepx = -1;
		env->sidedistx = (env->rayposx - env->mapx) * env->deltadistx;
	}
	else
	{
		env->stepx = 1;
		env->sidedistx = (env->mapx + 1.0 - env->rayposx) * env->deltadistx;
	}
	if (env->raydiry < 0)
	{
		env->stepy = -1;
		env->sidedisty = (env->rayposy - env->mapy) * env->deltadisty;
	}
	else
	{
		env->stepy = 1;
		env->sidedisty = (env->mapy + 1.0 - env->rayposy) * env->deltadisty;
	}
}

void	ft_dist_wallx4(t_env *env)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (env->sidedistx < env->sidedisty)
		{
			env->sidedistx += env->deltadistx;
			env->mapx += env->stepx;
			env->side = 0;
			if (env->stepx == -1)
				env->side = 2;
		}
		else
		{
			env->sidedisty += env->deltadisty;
			env->mapy += env->stepy;
			env->side = 1;
			if (env->stepy == -1)
				env->side = 3;
		}
		if (env->worldmap[env->mapx][env->mapy] > 0)
			hit = 1;
	}
}

void	ft_dist_wall(t_env *env)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (env->sidedistx < env->sidedisty)
		{
			env->sidedistx += env->deltadistx;
			env->mapx += env->stepx;
			env->side = 0;
		}
		else
		{
			env->sidedisty += env->deltadisty;
			env->mapy += env->stepy;
			env->side = 1;
		}
		if (env->worldmap[env->mapx][env->mapy] > 0)
			hit = 1;
	}
}

void	ft_draw_map(t_env *env)
{
	int		x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		ft_init_dda(x, env);
		ft_side_ray_dist(env);
		ft_dist_wall(env);
		ft_start_end_line(env);
		ft_text_calc(env);
		ft_store_text(x, env);
		ft_calc_floor(env);
		ft_store_ceiling(x, env);
		x++;
	}
	ft_ord_tab_sprite(env);
	ft_store_sprite(env);
	ft_draw_buffer(env);
}
