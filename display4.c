/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:34:42 by zhasni            #+#    #+#             */
/*   Updated: 2014/12/28 18:44:36 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_size_fc(t_env *env)
{
	if (env->size_fc == 1)
	{
		env->floortexx = (int)(env->currentfloorx * TEX_WIDTH / 2) % TEX_WIDTH;
		env->floortexy = (int)(env->currentfloory * TEX_HEIGHT / 2)
		% TEX_HEIGHT;
	}
	else if (env->size_fc == 2)
	{
		env->floortexx = (int)(env->currentfloorx * TEX_WIDTH / 4) % TEX_WIDTH;
		env->floortexy = (int)(env->currentfloory * TEX_HEIGHT / 4)
		% TEX_HEIGHT;
	}
	else
	{
		env->floortexx = (int)(env->currentfloorx * TEX_WIDTH) % TEX_WIDTH;
		env->floortexy = (int)(env->currentfloory * TEX_HEIGHT) % TEX_HEIGHT;
	}
}

void	ft_mod_floor(t_env *env)
{
	if (env->mod_floor == 1)
		env->checkerboardpattern = (int)(env->currentfloorx +
				env->currentfloory) % 2;
	else if (env->mod_floor == 2)
		env->checkerboardpattern = (int)((env->currentfloorx +
					(int)env->currentfloory)) % 2;
	else
		env->checkerboardpattern = (int)(env->currentfloorx) +
			(int)(env->currentfloory) % 2;
	if (env->checkerboardpattern == 0)
		env->floortexture = 0;
	else
		env->floortexture = 4;
}

void	ft_calc_sprite_bis(t_env *env)
{
	if (env->drawstarty < 0)
		env->drawstarty = 0;
	env->drawendy = env->spriteheight / 2 + SCREEN_HEIGHT / 2
		+ env->vmovescreen;
	if (env->drawendy >= SCREEN_HEIGHT)
		env->drawendy = SCREEN_HEIGHT - 1;
	env->spritewidth = abs((int)(SCREEN_HEIGHT / (env->transformy)))
		/ env->udiv;
	env->drawstartx = -env->spritewidth / 2 + env->spritescreenx;
	if (env->drawstartx < 0)
		env->drawstartx = 0;
	env->drawendx = env->spritewidth / 2 + env->spritescreenx;
	if (env->drawendx >= SCREEN_WIDTH)
		env->drawendx = SCREEN_WIDTH - 1;
}

void	ft_store_sprite_bis(t_env *env, int stripe, int i)
{
	int		d;
	int		y;

	env->texx = (int)(256 * (stripe - (-env->spritewidth / 2 + env->
					spritescreenx)) * TEX_WIDTH / env->spritewidth) / 256;
	y = env->drawstarty;
	if (env->transformy > 0 && stripe > 0 && stripe < SCREEN_WIDTH &&
			env->transformy < env->zbuffer[stripe])
	{
		while (y < env->drawendy)
		{
			d = (y - env->vmovescreen) * 256 - SCREEN_HEIGHT * 128 +
				env->spriteheight * 128;
			env->texy = ((d * TEX_HEIGHT) / env->spriteheight) / 256;
			env->color = env->texture
				[env->sprite[env->spriteorder[i]].texture]
				[TEX_WIDTH * env->texy + env->texx];
			if ((env->color & 0x00FFFFFF) != 0)
				env->buffer[stripe][y] = env->color;
			y++;
		}
	}
}
