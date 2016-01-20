/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 15:24:17 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/05 11:06:25 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_init_env(t_env *env)
{
	env->posx = 22;
	env->posy = 12;
	env->dirx = -1;
	env->diry = 0;
	env->planex = 0;
	env->planey = 0.66;
	env->view = 2;
	env->mod_floor = 0;
	env->size_fc = 0;
	env->udiv = 1;
	env->vdiv = 1;
	env->vmove = 0.0;
}

void	ft_init_sprite(t_env *env)
{
	env->sprite[0].x = 20.5;
	env->sprite[0].y = 11.5;
	env->sprite[0].texture = 10;
	env->sprite[1].x = 20.5;
	env->sprite[1].y = 12.5;
	env->sprite[1].texture = 9;
	env->sprite[2].x = 20.5;
	env->sprite[2].y = 10.5;
	env->sprite[2].texture = 8;
	env->sprite[3].x = 9.5;
	env->sprite[3].y = 9;
	env->sprite[3].texture = 7;
	env->sprite[4].x = 10.5;
	env->sprite[4].y = 9;
	env->sprite[4].texture = 7;
	env->sprite[5].x = 5.5;
	env->sprite[5].y = 3.5;
	env->sprite[5].texture = 9;
	env->sprite[6].x = 1.5;
	env->sprite[6].y = 3.5;
	env->sprite[6].texture = 9;
}

void	ft_init_texture(t_env *env)
{
	env->xpm[0].ptr = mlx_get_data_addr(env->xpm[0].tex, &env->xpm[0].bpp,
			&env->xpm[0].sline, &env->xpm[0].endian);
	env->xpm[1].ptr = mlx_get_data_addr(env->xpm[1].tex, &env->xpm[1].bpp,
			&env->xpm[1].sline, &env->xpm[1].endian);
	env->xpm[2].ptr = mlx_get_data_addr(env->xpm[2].tex, &env->xpm[2].bpp,
			&env->xpm[2].sline, &env->xpm[2].endian);
	env->xpm[3].ptr = mlx_get_data_addr(env->xpm[3].tex, &env->xpm[3].bpp,
			&env->xpm[3].sline, &env->xpm[3].endian);
	env->xpm[4].ptr = mlx_get_data_addr(env->xpm[4].tex, &env->xpm[4].bpp,
			&env->xpm[4].sline, &env->xpm[4].endian);
	env->xpm[5].ptr = mlx_get_data_addr(env->xpm[5].tex, &env->xpm[5].bpp,
			&env->xpm[5].sline, &env->xpm[5].endian);
	env->xpm[6].ptr = mlx_get_data_addr(env->xpm[6].tex, &env->xpm[6].bpp,
			&env->xpm[6].sline, &env->xpm[6].endian);
	env->xpm[7].ptr = mlx_get_data_addr(env->xpm[7].tex, &env->xpm[7].bpp,
			&env->xpm[7].sline, &env->xpm[7].endian);
	env->xpm[8].ptr = mlx_get_data_addr(env->xpm[8].tex, &env->xpm[8].bpp,
			&env->xpm[8].sline, &env->xpm[8].endian);
	env->xpm[9].ptr = mlx_get_data_addr(env->xpm[9].tex, &env->xpm[9].bpp,
			&env->xpm[9].sline, &env->xpm[9].endian);
	env->xpm[10].ptr = mlx_get_data_addr(env->xpm[10].tex, &env->xpm[10].bpp,
			&env->xpm[10].sline, &env->xpm[10].endian);
	env->xpm[11].ptr = mlx_get_data_addr(env->xpm[11].tex, &env->xpm[11].bpp,
			&env->xpm[11].sline, &env->xpm[11].endian);
	ft_init_texture_bis(env);
}

void	ft_xpm_to_img(t_env *env)
{
	env->xpm[0].tex = mlx_xpm_file_to_image(env->mlx, "pics/greystone.xpm",
			&env->xpm[0].width, &env->xpm[0].height);
	env->xpm[1].tex = mlx_xpm_file_to_image(env->mlx, "pics/colorstone.xpm",
			&env->xpm[1].width, &env->xpm[1].height);
	env->xpm[2].tex = mlx_xpm_file_to_image(env->mlx, "pics/eagle.xpm",
			&env->xpm[2].width, &env->xpm[2].height);
	env->xpm[3].tex = mlx_xpm_file_to_image(env->mlx, "pics/bluestone.xpm",
			&env->xpm[3].width, &env->xpm[3].height);
	env->xpm[4].tex = mlx_xpm_file_to_image(env->mlx, "pics/mossy.xpm",
			&env->xpm[4].width, &env->xpm[4].height);
	env->xpm[5].tex = mlx_xpm_file_to_image(env->mlx, "pics/purplestone.xpm",
			&env->xpm[5].width, &env->xpm[5].height);
	env->xpm[6].tex = mlx_xpm_file_to_image(env->mlx, "pics/wood.xpm",
			&env->xpm[6].width, &env->xpm[6].height);
	env->xpm[7].tex = mlx_xpm_file_to_image(env->mlx, "pics/redbrick.xpm",
			&env->xpm[7].width, &env->xpm[7].height);
	env->xpm[8].tex = mlx_xpm_file_to_image(env->mlx, "pics/barrel.xpm",
			&env->xpm[8].width, &env->xpm[8].height);
	env->xpm[9].tex = mlx_xpm_file_to_image(env->mlx, "pics/pillar.xpm",
			&env->xpm[9].width, &env->xpm[9].height);
	env->xpm[10].tex = mlx_xpm_file_to_image(env->mlx, "pics/greenlight.xpm",
			&env->xpm[10].width, &env->xpm[10].height);
	env->xpm[11].tex = mlx_xpm_file_to_image(env->mlx, "pics/mossy.xpm",
			&env->xpm[11].width, &env->xpm[11].height);
	ft_xpm_to_img_bis(env);
}

void	ft_texture_to_int(t_env *env)
{
	int				y;
	int				x;
	int				z;

	z = 0;
	while (z < 13)
	{
		y = 0;
		while (y < TEX_HEIGHT)
		{
			x = 0;
			while (x < TEX_WIDTH)
			{
				ft_get_color(env, x, y, z);
				env->texture[z][TEX_WIDTH * y + x] =
				toi(env->r, env->g, env->b);
				x++;
			}
			y++;
		}
		z++;
	}
}
