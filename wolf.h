/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 19:20:15 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/19 09:39:47 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include </usr/X11/include/X11/X.h>

# include "get_next_line.h"
# include "libft.h"

# define SCREEN_WIDTH	640
# define SCREEN_HEIGHT	480
# define TEX_WIDTH		64
# define TEX_HEIGHT		64
# define MAP_WIDTH		24
# define MAP_HEIGHT		24
# define NUM_SPRITES 	7
# define T_ESC			65307
# define T_UP			65362
# define T_DOWN			65364
# define T_LEFT			65361
# define T_RIGHT		65363
# define T_SEVEN		65463
# define T_FOUR			65460
# define T_ONE			65457
# define T_Z			122
# define T_C 			99
# define T_Q			113
# define T_W 			119
# define T_E 			101
# define T_R  			114
# define T_T  			116
# define T_Y 			121
# define T_U 			117
# define T_I 			105
# define T_O 			111
# define T_P 			112
# define T_L 			108

typedef	struct			s_sprite
{
	double				x;
	double				y;
	int					texture;
}						t_sprite;

typedef struct			s_xpm
{
	void				*tex;
	char				*ptr;
	int					bpp;
	int					sline;
	int					endian;
	int					height;
	int					width;
}						t_xpm;

typedef	struct			s_env
{
	unsigned int		buffer[SCREEN_WIDTH][SCREEN_HEIGHT];
	int					tex[TEX_HEIGHT][TEX_WIDTH];
	int					texture[15][TEX_WIDTH * TEX_HEIGHT];
	int					spriteorder[NUM_SPRITES];
	void				*mlx;
	void				*win;
	void				*img;
	t_xpm				xpm[15];
	t_sprite			sprite[NUM_SPRITES];
	void				*text;
	char				*str;
	char				*ptr;
	int					bpp;
	int					sline;
	int					endian;
	int					bppx;
	int					slinex;
	int					endianx;
	int					worldmap[MAP_HEIGHT][MAP_WIDTH];
	int					height;
	int					width;
	double				posx;
	double				posy;
	double				dirx;
	double				diry;
	double				planex;
	double				planey;
	double				camerax;
	double				rayposx;
	double				rayposy;
	double				raydirx;
	double				raydiry;
	double				sidedistx;
	double				sidedisty;
	double				deltadistx;
	double				deltadisty;
	double				perpwalldist;
	double				wallx;
	double				floorxwall;
	double				floorywall;
	double				distwall;
	double				distplayer;
	double				currentdist;
	double				weight;
	double				currentfloorx;
	double				currentfloory;
	double				zbuffer[SCREEN_WIDTH];
	double				spritedistance[NUM_SPRITES];
	double				transformx;
	double				transformy;
	double				olddirx;
	double				oldplanex;
	double				spritex;
	double				spritey;
	double				invdet;
	int					r;
	int					g;
	int					b;
	int					floortexx;
	int					floortexy;
	int					checkerboardpattern;
	int					floortexture;
	int					stepx;
	int					stepy;
	int					mapx;
	int					mapy;
	int					lineheight;
	int					drawstart;
	int					drawend;
	unsigned int		color;
	int					side;
	int					texnum;
	int					texx;
	int					texy;
	int					drawstartx;
	int					drawendx;
	int					drawstarty;
	int					drawendy;
	int					spritewidth;
	int					spritescreenx;
	int					vmovescreen;
	int					spriteheight;
	float				view;
	int					mod_floor;
	int					size_fc;
	int					udiv;
	int					vdiv;
	int					vmove;
}						t_env;

typedef struct			s_line
{
	int					*line;
	int					len;
	int					x;
	struct s_line		*next;
}						t_line;

int						ft_wolf(t_env *env);
void					ft_draw_map(t_env *env);
void					ft_move_forward(t_env *env);
void					ft_move_backward(t_env *env);
void					ft_rotate_right(t_env *env);
void					ft_rotate_left(t_env *env);
void					ft_move_left(t_env *env);
void					ft_move_right(t_env *env);
void					ft_color(t_env *enc);
void					ft_draw_ground(int x, t_env *env);
void					ft_verline(int x, t_env *env);
void					ft_draw_sky(int	x, t_env *env);
void					ft_put_pix_image(t_env *env, int x, int y, int color);
void					ft_init_dda(int x, t_env *env);
void					ft_init_texture(t_env *env);
void					ft_xpm_to_img(t_env *env);
void					ft_texture_to_int(t_env *env);
int						toi(unsigned char r, unsigned char g, unsigned char b);
int						ft_rgb_to_int(int r, int g, int b);
void					ft_side_ray_dist(t_env *env);
void					ft_dist_wall(t_env *env);
void					ft_dist_wallx4(t_env *env);
void					ft_start_end_line(t_env *env);
void					ft_init_env(t_env *env);
void					ft_init_sprite(t_env *env);
void					ft_init_texture(t_env *env);
void					ft_xpm_to_img(t_env *env);
void					ft_texture_to_int(t_env *env);
int						ft_tablen(char **tab);
void					ft_destroy_block(t_env *env, int x, int y);
void					ft_add_block(t_env *env, int y);
int						expose_hook(t_env *env);
int						mouse_hook(int button, int x, int y, t_env *env);
int						key_hook(int keycode, t_env *env);
void					ft_text_calc(t_env *env);
void					ft_store_text(int x, t_env *env);
void					ft_calc_floor(t_env *env);
void					ft_store_ceiling(int x, t_env *env);
void					ft_sprite_sort(int *order, double *dist, int nb);
void					ft_draw_buffer(t_env *env);
void					ft_size_fc(t_env *env);
void					ft_mod_floor(t_env *env);
void					ft_calc_sprite_bis(t_env *env);
void					ft_store_sprite_bis(t_env *env, int stripe, int i);
void					ft_ord_tab_sprite(t_env *env);
void					ft_calc_sprite(t_env *env, int i);
void					ft_store_sprite(t_env *env);
void					ft_init_texture_bis(t_env *env);
void					ft_xpm_to_img_bis(t_env *env);
void					ft_get_color(t_env *env, int x, int y, int z);

#endif
