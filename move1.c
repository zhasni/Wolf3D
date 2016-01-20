/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 17:09:59 by zhasni            #+#    #+#             */
/*   Updated: 2015/01/29 16:04:27 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_move_forward(t_env *env)
{
	if (env->worldmap[(int)(env->posx + env->dirx)][(int)env->posy] == 0)
		env->posx += env->dirx * 0.15;
	if (env->worldmap[(int)env->posx][(int)(env->posy + env->diry)] == 0)
		env->posy += env->diry * 0.15;
}

void	ft_move_backward(t_env *env)
{
	if (env->worldmap[(int)(env->posx - env->dirx)][(int)env->posy] == 0)
		env->posx -= env->dirx * 0.15;
	if (env->worldmap[(int)env->posx][(int)(env->posy - env->diry)] == 0)
		env->posy -= env->diry * 0.15;
}

void	ft_rotate_right(t_env *env)
{
	env->olddirx = env->dirx;
	env->dirx = env->dirx * cos(-0.15) - env->diry * sin(-0.15);
	env->diry = env->olddirx * sin(-0.15) + env->diry * cos(-0.15);
	env->oldplanex = env->planex;
	env->planex = env->planex * cos(-0.15) - env->planey * sin(-0.15);
	env->planey = env->oldplanex * sin(-0.15) + env->planey * cos(-0.15);
}

void	ft_rotate_left(t_env *env)
{
	env->olddirx = env->dirx;
	env->dirx = env->dirx * cos(0.15) - env->diry * sin(0.15);
	env->diry = env->olddirx * sin(0.15) + env->diry * cos(0.15);
	env->oldplanex = env->planex;
	env->planex = env->planex * cos(0.15) - env->planey * sin(0.15);
	env->planey = env->oldplanex * sin(0.15) + env->planey * cos(0.15);
}

void	ft_move_left(t_env *env)
{
	if (env->worldmap[(int)(env->posx + env->planex)][(int)env->posy] == 0)
		env->posx += env->planex * 0.15;
	if (env->worldmap[(int)env->posx][(int)(env->posy + env->planey)] == 0)
		env->posy += env->planey * 0.15;
}
