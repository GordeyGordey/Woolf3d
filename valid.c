/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wendell <wendell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 20:14:36 by wendell           #+#    #+#             */
/*   Updated: 2020/10/30 16:38:33 by wendell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		mapwtowlf(t_wolf *wlf, int mapw)
{
	wlf->mapw = mapw;
	return (0);
}

int		check_size(t_wolf *wlf, char *buff)
{
	int i;
	int j;
	int mapw;

	j = 0;
	i = -1;
	mapw = 0;
	while (buff[++i] != '\0')
	{
		if (buff[i] == '2')
			j++;
		if (buff[i] == '\n')
		{
			if (wlf->maph != 0 && mapw != wlf->mapw)
				return (0);
			else
				mapw = mapwtowlf(wlf, mapw);
			wlf->maph++;
		}
		else
			mapw++;
	}
	if (j != 1 || (mapw != 0 && mapw != wlf->mapw) || buff[i - 1] != '\n')
		return (0);
	return (1);
}

void	init_pl(t_wolf *wlf, int k, int j)
{
	wlf->ppos_x = k + 0.51;
	wlf->ppos_y = j + 0.51;
	wlf->map[k][j] = 0;
}

int		cr_map(t_wolf *wlf, char *buff, int j, int k)
{
	int i;

	i = -1;
	while (buff[++i] != '\0')
		if (buff[i] != '\n')
		{
			if ((k == 0 || k == wlf->maph - 1 || j == 0 ||
			j == wlf->mapw - 1) && buff[i] != 49)
				ext(wlf, "on perimeter must be symbol \'1\'");
			if (buff[i] == 48 || buff[i] == 49)
				wlf->map[k][j] = buff[i] - 48;
			else if (buff[i] == 50)
				init_pl(wlf, k, j);
			else
				ext(wlf, "to draw map use only \'0\', \'1\', \'2\'");
			j++;
		}
		else
		{
			k++;
			j = 0;
		}
	return (1);
}

int		readmap(t_wolf *wlf, char *av)
{
	char	buff[10000];
	int		i;
	int		mapw;
	int		j;
	int		k;

	j = open(av, O_RDONLY);
	mapw = 0;
	if (j == -1)
		ext(wlf, "no file!");
	if ((k = read(j, buff, 10000)) < 1 || k > 10000)
		ext(wlf, "can not read!");
	buff[k] = '\0';
	if (!check_size(wlf, buff))
		ext(wlf, "wrong map!");
	if (!mal_map(wlf))
		ext(wlf, "memory error!");
	k = 0;
	j = 0;
	return (cr_map(wlf, buff, j, k));
}
