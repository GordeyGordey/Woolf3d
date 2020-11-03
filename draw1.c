/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 18:57:16 by wendell           #+#    #+#             */
/*   Updated: 2020/10/12 20:11:31 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	tics(t_wolf *wlf)
{
	if (wlf->bool_tic)
		wlf->tic--;
	else
		wlf->tic++;
	if (wlf->tic == 0 || wlf->tic == 10)
		wlf->bool_tic = !wlf->bool_tic;
}

void	draw_map(t_wolf *wlf)
{
	int i;
	int j;
	int pixel;

	i = -1;
	while (++i < wlf->maph * MAP)
	{
		j = -1;
		while (++j < wlf->mapw * MAP)
		{
			pixel = (i * wlf->pixb / 8) + (j * wlf->strb);
			if (i / MAP == (int)wlf->ppos_x && j / MAP == (int)wlf->ppos_y)
			{
				wlf->s[pixel] = (char)(120);
				wlf->s[++pixel] = (char)(200);
				wlf->s[++pixel] = (char)(30);
			}
			else if (wlf->map[i / MAP][j / MAP] == 1)
				draw_floor(wlf, pixel, 80);
			else
				draw_floor(wlf, pixel, 120);
		}
	}
}

void	draw_w(t_wolf *wlf, int i)
{
	int wdth;
	int j;
	int pixel;
	int px1;

	wdth = WIDTH / 2 + HUD * wlf->h_w[0] / 2 - 1;
	while (++i < wdth)
	{
		j = HEIGHT - HUD * wlf->h_h[0] + wlf->tic - 1;
		while (++j < HEIGHT)
		{
			pixel = (i * wlf->pixb / 8) + (j * wlf->strb);
			px1 = ((i - (WIDTH / 2 - HUD * wlf->h_w[0] / 2 - 1)) / HUD *
			wlf->h_pixb[0] / 8) + ((j - wlf->tic - (HEIGHT - HUD * wlf->h_h[0]))
			/ HUD * wlf->h_strb[0]);
			if (wlf->h_s[0][px1] != -120 || wlf->h_s[0][px1 + 2] != -104)
			{
				wlf->s[pixel] = wlf->h_s[0][px1];
				wlf->s[++pixel] = wlf->h_s[0][++px1];
				wlf->s[++pixel] = wlf->h_s[0][++px1];
			}
		}
	}
}

void	draw_wf(t_wolf *wlf, int i)
{
	int wdth;
	int j;
	int pixel;
	int px1;

	wdth = WIDTH / 2 + HUD * wlf->h_w[1 + wlf->tic % 2] / 2 - 1;
	while (++i < wdth)
	{
		j = HEIGHT - HUD * wlf->h_h[1 + wlf->tic % 2] + wlf->tic - 1;
		while (++j < HEIGHT)
		{
			pixel = (i * wlf->pixb / 8) + (j * wlf->strb);
			px1 = ((i - (WIDTH / 2 - HUD * wlf->h_w[1 + wlf->tic % 2] / 2 -
			1)) / HUD * wlf->h_pixb[1 + wlf->tic % 2] / 8) + ((j - wlf->tic -
			(HEIGHT - HUD * wlf->h_h[1 + wlf->tic % 2])) / HUD * wlf->h_strb[1
			+ wlf->tic % 2]);
			if (wlf->h_s[1 + wlf->tic % 2][px1] != -120 || wlf->h_s[1 + wlf->tic
			% 2][px1 + 1] != 0 || wlf->h_s[1 + wlf->tic % 2][px1 + 2] != -104)
			{
				wlf->s[pixel] = wlf->h_s[1 + wlf->tic % 2][px1];
				wlf->s[++pixel] = wlf->h_s[1 + wlf->tic % 2][++px1];
				wlf->s[++pixel] = wlf->h_s[1 + wlf->tic % 2][++px1];
			}
		}
	}
}

void	draw_hud(t_wolf *wlf)
{
	int i;

	i = WIDTH / 2 - HUD * wlf->h_w[0] / 2 - 1;
	if (!wlf->f)
		draw_w(wlf, i);
	else
		draw_wf(wlf, i);
	if (wlf->mp)
		draw_map(wlf);
}
