/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 15:01:47 by wendell           #+#    #+#             */
/*   Updated: 2020/10/30 15:55:29 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "minilibx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define WIDTH 1024
# define HEIGHT 720
# define HUD 10
# define MAP 10
# define RANGL 0.017453292519943

typedef struct	s_wolf
{
	void				*init;
	void				*win;
	void				*img;
	char				*s;
	int					pixb;
	int					strb;
	int					**map;
	int					maph;
	int					mapw;

	double				p_angl;
	double				ppos_x;
	double				ppos_y;
	double				dir_x;
	double				dir_y;
	double				cam_x;
	double				cam_y;
	double				ray_x;
	double				ray_y;
	int					map_x;
	int					map_y;
	int					side;
	double				wall_x;
	int					tex_x;

	void				*wl_tex[4];
	char				*wl_s[4];
	int					wl_h[4];
	int					wl_w[4];
	int					wl_pixb[4];
	int					wl_strb[4];

	int					ntex;

	void				*sk_tex;
	char				*sk_s;
	int					sk_h;
	int					sk_w;
	int					sk_pixb;
	int					sk_strb;

	void				*h_tex[3];
	char				*h_s[3];
	int					h_h[3];
	int					h_w[3];
	int					h_pixb[3];
	int					h_strb[3];

	int					tic;
	int					bool_tic;
	int					f;
	int					sh;
	int					mp;
}				t_wolf;

typedef struct	s_dda
{
	int		step_x;
	int		step_y;
	double	side_x;
	double	side_y;
	int		hit;
	double	dx;
	double	dy;

}				t_dda;

int				readmap(t_wolf *wlf, char *av);
int				rndm(int a, int b);
double			calc_d(int i, t_wolf *wlf);
void			draw(t_wolf *wlf);
void			draw_hud(t_wolf *wlf);
int				ext(t_wolf *wlf, char *str);
int				pkey(int key, t_wolf *wlf);
void			rotate(t_wolf *wlf, int angl);
int				init_all(t_wolf *wlf);
void			tics(t_wolf *wlf);
void			draw_floor(t_wolf *wlf, int pixel, char c);
int				mal_map(t_wolf *wlf);
int				ext1(t_wolf *wlf);

#endif
