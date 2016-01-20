/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 16:02:19 by zhasni            #+#    #+#             */
/*   Updated: 2014/12/28 18:43:44 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_start_end_line(t_env *env)
{
	if (env->side == 0)
		env->perpwalldist = fabs((env->mapx - env->rayposx + (1 - env->stepx)
					/ 2) / env->raydirx);
	else
		env->perpwalldist = fabs((env->mapy - env->rayposy + (1 - env->stepy)
					/ 2) / env->raydiry);
	env->lineheight = abs((int)(SCREEN_WIDTH / env->perpwalldist));
	env->drawstart = -env->lineheight / 2 + SCREEN_HEIGHT / 2;
	if (env->drawstart < 0)
		env->drawstart = 0;
	env->drawend = env->lineheight / 2 + SCREEN_HEIGHT / 2;
	if (env->drawend >= SCREEN_HEIGHT)
		env->drawend = SCREEN_HEIGHT - 1;
}

void	ft_text_calc(t_env *env)
{
	env->texnum = env->worldmap[env->mapx][env->mapy] - 1;
	if (env->side == 1)
		env->wallx = env->rayposx + ((env->mapy - env->rayposy +
					(1 - env->stepy) / 2) / env->raydiry) * env->raydirx;
	else
		env->wallx = env->rayposy + ((env->mapx - env->rayposx +
					(1 - env->stepx) / 2) / env->raydirx) * env->raydiry;
	env->wallx -= floor((env->wallx));
	env->texx = (int)(env->wallx * (double)TEX_WIDTH);
	if (env->side == 0 && env->raydirx > 0)
		env->texx = TEX_WIDTH - env->texx - 1;
	if (env->side == 1 && env->raydiry < 0)
		env->texx = TEX_WIDTH - env->texx - 1;
}

void	ft_store_text(int x, t_env *env)
{
	int		y;
	int		d;

	y = env->drawstart;
	while (y < env->drawend)
	{
		d = y * 256 - SCREEN_HEIGHT * 128 + env->lineheight * 128;
		env->texy = ((d * TEX_HEIGHT) / env->lineheight) / 256;
		env->color = env->texture[env->texnum][TEX_WIDTH * env->texy
			+ env->texx];
		if (env->side == 1)
			env->color = (env->color >> 1) & 8355711;
		env->buffer[x][y] = env->color;
		y++;
	}
	env->zbuffer[x] = env->perpwalldist;
}

void	ft_calc_floor(t_env *env)
{
	if (env->side == 0 && env->raydirx > 0)
	{
		env->floorxwall = env->mapx;
		env->floorywall = env->mapy + env->wallx;
	}
	else if (env->side == 0 && env->raydirx < 0)
	{
		env->floorxwall = env->mapx + 1.0;
		env->floorywall = env->mapy + env->wallx;
	}
	else if (env->side == 1 && env->raydiry > 0)
	{
		env->floorxwall = env->mapx + env->wallx;
		env->floorywall = env->mapy;
	}
	else
	{
		env->floorxwall = env->mapx + env->wallx;
		env->floorywall = env->mapy + 1.0;
	}
	env->distwall = env->perpwalldist;
	env->distplayer = 0.0;
	if (env->drawend < 0)
		env->drawend = SCREEN_HEIGHT;
}

void	ft_store_ceiling(int x, t_env *env)
{
	int		y;

	y = env->drawend + 1;
	while (y < SCREEN_HEIGHT)
	{
		env->currentdist = SCREEN_HEIGHT / (2.0 * y - SCREEN_HEIGHT);
		env->weight = (env->currentdist - env->distplayer)
			/ (env->distwall - env->distplayer);
		env->currentfloorx = env->weight * env->floorxwall +
			(1.0 - env->weight) * env->posx;
		env->currentfloory = env->weight * env->floorywall +
			(1.0 - env->weight) * env->posy;
		ft_size_fc(env);
		ft_mod_floor(env);
		env->buffer[x][y] = (env->texture[env->floortexture][TEX_WIDTH *
				env->floortexy + env->floortexx] >> 1) & 8355711;
		env->buffer[x][SCREEN_HEIGHT - y] = env->texture[6][TEX_WIDTH *
			env->floortexy + env->floortexx];
		y++;
	}
}
