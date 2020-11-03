/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 19:34:45 by wendell           #+#    #+#             */
/*   Updated: 2020/10/30 16:02:28 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		mal_map(t_wolf *wlf)
{
	int i;

	if (!(wlf->map = (int **)malloc(sizeof(int *) * wlf->maph)))
		return (0);
	i = -1;
	if (wlf->maph <= 2 || wlf->mapw <= 2)
		return (0);
	while (++i < wlf->maph)
		if (!(wlf->map[i] = (int*)malloc(wlf->mapw * sizeof(int))))
			return (0);
	return (1);
}

int		ext(t_wolf *wlf, char *str)
{
	int i;

	i = 0;
	if (str)
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
	if (wlf)
		free(wlf);
	exit(0);
	return (0);
}

void	init_tex1(t_wolf *wlf)
{
	int k;

	wlf->sk_tex = mlx_xpm_file_to_image(wlf->init, "pics/yneg_1.XPM",
	&wlf->sk_w, &wlf->sk_h);
	wlf->sk_s = mlx_get_data_addr(wlf->sk_tex, &(wlf->sk_pixb),
	&(wlf->sk_strb), &k);
	wlf->h_tex[0] = mlx_xpm_file_to_image(wlf->init, "pics/w0.XPM",
	&(wlf->h_w[0]), &(wlf->h_h[0]));
	wlf->h_s[0] = mlx_get_data_addr(wlf->h_tex[0], &(wlf->h_pixb[0]),
	&(wlf->h_strb[0]), &k);
	wlf->h_tex[1] = mlx_xpm_file_to_image(wlf->init, "pics/w1.XPM",
	&(wlf->h_w[1]), &(wlf->h_h[1]));
	wlf->h_s[1] = mlx_get_data_addr(wlf->h_tex[1], &(wlf->h_pixb[1]),
	&(wlf->h_strb[1]), &k);
	wlf->h_tex[2] = mlx_xpm_file_to_image(wlf->init, "pics/w2.XPM",
	&(wlf->h_w[2]), &(wlf->h_h[2]));
	wlf->h_s[2] = mlx_get_data_addr(wlf->h_tex[2], &(wlf->h_pixb[2]),
	&(wlf->h_strb[2]), &k);
}

void	init_tex(t_wolf *wlf)
{
	int k;

	wlf->wl_tex[0] = mlx_xpm_file_to_image(wlf->init, "pics/bluestone.XPM",
	&(wlf->wl_w[0]), &(wlf->wl_h[0]));
	wlf->wl_s[0] = mlx_get_data_addr(wlf->wl_tex[0], &(wlf->wl_pixb[0]),
	&(wlf->wl_strb[0]), &k);
	wlf->wl_tex[1] = mlx_xpm_file_to_image(wlf->init, "pics/redbrick.XPM",
	&(wlf->wl_w[1]), &(wlf->wl_h[1]));
	wlf->wl_s[1] = mlx_get_data_addr(wlf->wl_tex[1], &(wlf->wl_pixb[1]),
	&(wlf->wl_strb[1]), &k);
	wlf->wl_tex[2] = mlx_xpm_file_to_image(wlf->init, "pics/colorstone.XPM",
	&(wlf->wl_w[2]), &(wlf->wl_h[2]));
	wlf->wl_s[2] = mlx_get_data_addr(wlf->wl_tex[2], &(wlf->wl_pixb[2]),
	&(wlf->wl_strb[2]), &k);
	wlf->wl_tex[3] = mlx_xpm_file_to_image(wlf->init, "pics/greystone.XPM",
	&(wlf->wl_w[3]), &(wlf->wl_h[3]));
	wlf->wl_s[3] = mlx_get_data_addr(wlf->wl_tex[3], &(wlf->wl_pixb[3]),
	&(wlf->wl_strb[3]), &k);
	init_tex1(wlf);
}

int		init_all(t_wolf *wlf)
{
	int k;

	wlf->init = mlx_init();
	wlf->win = mlx_new_window(wlf->init, WIDTH, HEIGHT, "wolf3d");
	wlf->img = mlx_new_image(wlf->init, WIDTH, HEIGHT);
	wlf->s = mlx_get_data_addr(wlf->img, &(wlf->pixb), &(wlf->strb), &k);
	wlf->tic = 0;
	wlf->bool_tic = 0;
	wlf->sh = 0;
	wlf->dir_x = -1;
	wlf->dir_y = 0;
	wlf->cam_x = 0;
	wlf->cam_y = 0.75;
	wlf->ntex = 0;
	wlf->mp = 1;
	wlf->mapw = 0;
	wlf->maph = 0;
	init_tex(wlf);
	return (1);
}
