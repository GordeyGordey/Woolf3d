/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 19:23:34 by wendell           #+#    #+#             */
/*   Updated: 2020/10/30 15:38:42 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	rot_l(t_wolf *wlf)
{
	rotate(wlf, -10);
	tics(wlf);
}

void	rot_r(t_wolf *wlf)
{
	rotate(wlf, 10);
	tics(wlf);
}

void	move_f(t_wolf *wlf)
{
	if (wlf->map[(int)(wlf->ppos_x + wlf->dir_x /
	(10 - 3.01 * wlf->sh))][(int)wlf->ppos_y] != 1)
		wlf->ppos_x += wlf->dir_x / (10 - 3.01 * wlf->sh);
	if (wlf->map[(int)wlf->ppos_x][(int)(wlf->ppos_y + wlf->dir_y /
	(10 - 3.01 * wlf->sh))] != 1)
		wlf->ppos_y += wlf->dir_y / (10 - 3.01 * wlf->sh);
	tics(wlf);
}

void	move_b(t_wolf *wlf)
{
	if (wlf->map[(int)(wlf->ppos_x - wlf->dir_x /
	(10 - 3.01 * wlf->sh))][(int)wlf->ppos_y] != 1)
		wlf->ppos_x -= wlf->dir_x / (10 - 3.01 * wlf->sh);
	if (wlf->map[(int)wlf->ppos_x][(int)(wlf->ppos_y - wlf->dir_y /
	(10 - 3.01 * wlf->sh))] != 1)
		wlf->ppos_y -= wlf->dir_y / (10 - 3.01 * wlf->sh);
	tics(wlf);
}

int		pkey(int key, t_wolf *wlf)
{
	if (key == 257)
		wlf->sh = 1;
	if (key == 49)
	{
		wlf->f = 1;
		tics(wlf);
	}
	if (key == 46)
		wlf->mp = !wlf->mp;
	if (key == 53)
		ext(wlf, "");
	if (key == 124)
		rot_l(wlf);
	if (key == 123)
		rot_r(wlf);
	if (key == 126)
		move_f(wlf);
	if (key == 125)
		move_b(wlf);
	draw(wlf);
	wlf->f = 0;
	return (0);
}
