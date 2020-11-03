/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 19:05:32 by wendell           #+#    #+#             */
/*   Updated: 2020/10/30 16:01:42 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	rotate(t_wolf *wlf, int angl)
{
	double x;
	double y;
	double rangl;

	rangl = angl * RANGL;
	x = wlf->dir_x;
	y = wlf->dir_y;
	wlf->dir_x = cos(rangl) * x - sin(rangl) * y;
	wlf->dir_y = sin(rangl) * x + cos(rangl) * y;
	x = wlf->cam_x;
	y = wlf->cam_y;
	wlf->cam_x = cos(rangl) * x - sin(rangl) * y;
	wlf->cam_y = sin(rangl) * x + cos(rangl) * y;
}

int		rkey(int key, t_wolf *wlf)
{
	if (key == 257)
		wlf->sh = 0;
	if (key == 49)
		wlf->f = 0;
	draw(wlf);
	return (0);
}

int		main(int ac, char **av)
{
	t_wolf	*wlf;
	int		k;

	if (ac != 2)
		ext(wlf, "wrong number arguments!");
	if (!(wlf = (t_wolf *)malloc(sizeof(t_wolf))))
		return (0);
	if (!init_all(wlf))
		ext(wlf, "initialization error!");
	if (!(readmap(wlf, av[1])))
		return (0);
	draw(wlf);
	mlx_hook(wlf->win, 3, 0, rkey, wlf);
	mlx_hook(wlf->win, 2, 0, pkey, wlf);
	mlx_hook(wlf->win, 17, 0, ext1, wlf);
	mlx_loop(wlf->init);
	return (0);
}
