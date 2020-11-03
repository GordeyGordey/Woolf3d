/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 16:10:33 by wendell           #+#    #+#             */
/*   Updated: 2020/10/12 18:42:42 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

double	dxdy(t_wolf *wlf, int b)
{
	if (b)
	{
		if (wlf->ray_x == 0)
			return (0);
		else if (wlf->ray_y == 0)
			return (1);
		else
			return (fabs(1 / wlf->ray_y));
	}
	else
	{
		if (wlf->ray_y == 0)
			return (0);
		else if (wlf->ray_x == 0)
			return (1);
		else
			return (fabs(1 / wlf->ray_x));
	}
}

t_dda	initdda(t_wolf *wlf)
{
	t_dda dda;

	dda.dx = dxdy(wlf, 0);
	dda.dy = dxdy(wlf, 1);
	if (wlf->ray_x < 0)
	{
		dda.step_x = -1;
		dda.side_x = (wlf->ppos_x - wlf->map_x) * dda.dx;
	}
	else
	{
		dda.step_x = 1;
		dda.side_x = (wlf->map_x + 1.0 - wlf->ppos_x) * dda.dx;
	}
	if (wlf->ray_y < 0)
	{
		dda.step_y = -1;
		dda.side_y = (wlf->ppos_y - wlf->map_y) * dda.dy;
	}
	else
	{
		dda.step_y = 1;
		dda.side_y = (wlf->map_y + 1.0 - wlf->ppos_y) * dda.dy;
	}
	return (dda);
}

double	dda_ret(t_wolf *wlf, t_dda dda)
{
	if (wlf->side)
	{
		if (dda.step_y > 0)
			wlf->ntex = 3;
		else
			wlf->ntex = 2;
	}
	else
	{
		if (dda.step_x > 0)
			wlf->ntex = 1;
		else
			wlf->ntex = 0;
	}
	if (wlf->side == 0)
		return ((wlf->map_x - wlf->ppos_x +
		(1.0 - dda.step_x) / 2.0) / wlf->ray_x);
	else
		return ((wlf->map_y - wlf->ppos_y +
		(1.0 - dda.step_y) / 2.0) / wlf->ray_y);
}

double	dda(t_wolf *wlf)
{
	t_dda dda;

	dda = initdda(wlf);
	dda.hit = 0;
	while (dda.hit == 0)
	{
		if (dda.side_x < dda.side_y)
		{
			dda.side_x += dda.dx;
			wlf->map_x += dda.step_x;
			wlf->side = 0;
		}
		else
		{
			dda.side_y += dda.dy;
			wlf->map_y += dda.step_y;
			wlf->side = 1;
		}
		if (wlf->map[wlf->map_x][wlf->map_y] == 1)
			dda.hit = 1;
	}
	return (dda_ret(wlf, dda));
}

double	calc_d(int i, t_wolf *wlf)
{
	double camera_x;
	double dist;

	camera_x = 2 * i / (double)(WIDTH) - 1;
	wlf->ray_x = wlf->dir_x + wlf->cam_x * camera_x;
	wlf->ray_y = wlf->dir_y + wlf->cam_y * camera_x;
	wlf->map_x = (int)wlf->ppos_x;
	wlf->map_y = (int)wlf->ppos_y;
	dist = dda(wlf);
	if (wlf->side == 0)
		wlf->wall_x = wlf->ppos_y + dist * wlf->ray_y;
	else
		wlf->wall_x = wlf->ppos_x + dist * wlf->ray_x;
	wlf->wall_x -= floor(wlf->wall_x);
	wlf->tex_x = (int)(wlf->wall_x * (double)wlf->wl_w[wlf->ntex]);
	return (dist);
}
