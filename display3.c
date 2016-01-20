/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 16:02:19 by zhasni            #+#    #+#             */
/*   Updated: 2014/12/28 18:43:52 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_sprite_sort(int *order, double *dist, int nb)
{
	int		i;
	int		j;
	int		check;

	check = 0;
	while (check == 0)
	{
		check = 1;
		i = 0;
		j = i + 1;
		while (i < nb && j < nb)
		{
			if (dist[i] < dist[j])
			{
				ft_swap_double(&dist[j], &dist[i]);
				ft_swap_int(&order[j], &order[i]);
				check = 0;
			}
			i++;
			j++;
		}
	}
}

void	ft_ord_tab_sprite(t_env *env)
{
	int i;

	i = 0;
	while (i < NUM_SPRITES)
	{
		env->spriteorder[i] = i;
		env->spritedistance[i] = ((env->posx - env->sprite[i].x) *
				(env->posx - env->sprite[i].x) + (env->posy - env->sprite[i].y)
				* (env->posy - env->sprite[i].y));
		i++;
	}
	ft_sprite_sort(env->spriteorder, env->spritedistance, NUM_SPRITES);
}

void	ft_calc_sprite(t_env *env, int i)
{
	env->spritex = env->sprite[env->spriteorder[i]].x - env->posx;
	env->spritey = env->sprite[env->spriteorder[i]].y - env->posy;
	env->invdet = 1.0 / (env->planex * env->diry - env->dirx * env->planey);
	env->transformx = env->invdet * (env->diry * env->spritex - env->dirx *
			env->spritey);
	env->transformy = env->invdet * (-env->planey * env->spritex + env->planex *
			env->spritey);
	env->spritescreenx = (int)((SCREEN_WIDTH / 2) * (1 + env->transformx /
				env->transformy));
	env->vmovescreen = (int)(env->vmove / env->transformy);
	env->spriteheight = abs((int)(SCREEN_HEIGHT / (env->transformy))) /
		env->vdiv;
	env->drawstarty = -env->spriteheight / 2 + SCREEN_HEIGHT / 2 +
		env->vmovescreen;
	ft_calc_sprite_bis(env);
}

void	ft_store_sprite(t_env *env)
{
	int		i;
	int		stripe;

	i = 0;
	while (i < NUM_SPRITES)
	{
		ft_calc_sprite(env, i);
		stripe = env->drawstartx;
		while (stripe < env->drawendx)
		{
			ft_store_sprite_bis(env, stripe, i);
			stripe++;
		}
		i++;
	}
}

void	ft_draw_buffer(t_env *env)
{
	int y;
	int x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		y = 0;
		while (y < SCREEN_HEIGHT)
		{
			ft_put_pix_image(env, x, y, env->buffer[x][y]);
			env->buffer[x][y] = 0;
			y++;
		}
		x++;
	}
}
