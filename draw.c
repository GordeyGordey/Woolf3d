/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 18:30:50 by wendell           #+#    #+#             */
/*   Updated: 2020/10/30 16:03:10 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_floor(t_wolf *wlf, int pixel, char c)
{
	wlf->s[pixel] = c;
	wlf->s[++pixel] = c;
	wlf->s[++pixel] = c;
}

void	draw_skybox(t_wolf *wlf)
{
	int i;
	int j;
	int pixel;
	int px1;

	i = -1;
	while (++i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT / 2)
		{
			pixel = (i * wlf->pixb / 8) + (j * wlf->strb);
			px1 = ((i % wlf->sk_h) * wlf->sk_pixb / 8) +
			((j % wlf->sk_h) * wlf->sk_strb);
			wlf->s[pixel] = wlf->sk_s[px1];
			wlf->s[++pixel] = wlf->sk_s[++px1];
			wlf->s[++pixel] = wlf->sk_s[++px1];
			j++;
		}
	}
}

void	draw_wall(t_wolf *wlf, int pixel, int y)
{
	int px1;

	px1 = (wlf->tex_x * wlf->wl_pixb[wlf->ntex] / 8)
	+ (y * wlf->wl_strb[wlf->ntex]);
	wlf->s[pixel] = wlf->wl_s[wlf->ntex][px1];
	wlf->s[++pixel] = wlf->wl_s[wlf->ntex][++px1];
	wlf->s[++pixel] = wlf->wl_s[wlf->ntex][++px1];
}

void	draw(t_wolf *wlf)
{
	int		i;
	int		j;
	int		pixel;
	double	l;
	double	step;

	draw_skybox(wlf);
	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		l = (int)(HEIGHT / calc_d(i, wlf));
		step = 1.0 * wlf->wl_h[wlf->ntex] / l;
		while (++j < HEIGHT)
		{
			pixel = (i * wlf->pixb / 8) + (j * wlf->strb);
			if (j >= (l + HEIGHT) / 2)
				draw_floor(wlf, pixel, 80);
			else if (j > (HEIGHT - l) / 2)
				draw_wall(wlf, pixel, (int)((j - HEIGHT / 2.0 + l / 2) * step));
		}
	}
	draw_hud(wlf);
	mlx_put_image_to_window(wlf->init, wlf->win, wlf->img, 0, 0);
}

int		ext1(t_wolf *wlf)
{
	if (wlf)
		free(wlf);
	exit(0);
	return (0);
}
