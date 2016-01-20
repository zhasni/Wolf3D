/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 15:26:07 by zhasni            #+#    #+#             */
/*   Updated: 2015/01/08 21:52:39 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_tablen(char **tab)
{
	int i;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		toi(unsigned char r, unsigned char g, unsigned char b)
{
	unsigned int		new;

	new = 0;
	new += ((b << 16) + (g << 8) + r);
	return (new);
}

int		ft_rgb_to_int(int r, int g, int b)
{
	int		new;

	new = 0;
	new += ((r << 16) + (g << 8) + b);
	return (new);
}

void	ft_color(t_env *env)
{
	if (env->side == 1)
		env->color = 0x0000FF;
	else if (env->side == 2)
		env->color = 0x00FF00;
	else if (env->side == 3)
		env->color = 0xFF0000;
	else
		env->color = 0xFFFFFF;
}
