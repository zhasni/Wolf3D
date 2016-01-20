/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 15:23:59 by zhasni            #+#    #+#             */
/*   Updated: 2014/12/28 18:51:57 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_destroy_block(t_env *env, int x, int y)
{
	ft_init_dda(x, env);
	ft_side_ray_dist(env);
	ft_dist_wall(env);
	ft_start_end_line(env);
	if (env->worldmap[env->mapx][env->mapy] > 8 && y > env->drawstart &&
			y < env->drawend)
		env->worldmap[env->mapx][env->mapy] = 0;
}

void	ft_add_block(t_env *env, int y)
{
	if (env->side == 0 && (env->worldmap[env->mapx][env->mapy] > 0
				|| env->worldmap[env->mapx][env->mapy] > 0) && ((env->mapx - 1)
					!= (int)env->posx || env->mapy != (int)env->posy) &&
			(y > env->drawstart && y < env->drawend))
		env->worldmap[env->mapx - 1][env->mapy] = 9;
	if (env->side == 2 && (env->worldmap[env->mapx][env->mapy] > 0
				|| env->worldmap[env->mapx][env->mapy] > 0) && ((env->mapx + 1)
					!= (int)env->posx || env->mapy != (int)env->posy) &&
			(y > env->drawstart && y < env->drawend))
		env->worldmap[env->mapx + 1][env->mapy] = 10;
	if (env->side == 1 && (env->worldmap[env->mapx][env->mapy] > 0
				|| env->worldmap[env->mapx][env->mapy] > 0) && (env->mapx
					!= (int)env->posx || (env->mapy - 1) != (int)env->posy) &&
			(y > env->drawstart && y < env->drawend))
		env->worldmap[env->mapx][env->mapy - 1] = 11;
	if (env->side == 3 && (env->worldmap[env->mapx][env->mapy] > 0
				|| env->worldmap[env->mapx][env->mapy] > 0) && (env->mapx
					!= (int)env->posx || (env->mapy + 1) != (int)env->posy) &&
			(y > env->drawstart && y < env->drawend))
		env->worldmap[env->mapx][env->mapy + 1] = 12;
}
