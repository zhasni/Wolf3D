/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 15:56:34 by zhasni            #+#    #+#             */
/*   Updated: 2015/01/29 16:04:39 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_move_right(t_env *env)
{
	if (env->worldmap[(int)(env->posx - env->planex)][(int)env->posy] == 0)
		env->posx -= env->planex * 0.15;
	if (env->worldmap[(int)env->posx][(int)(env->posy - env->planey)] == 0)
		env->posy -= env->planey * 0.15;
}
