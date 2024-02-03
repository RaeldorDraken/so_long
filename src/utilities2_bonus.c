/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:33:24 by eros-gir          #+#    #+#             */
/*   Updated: 2022/05/13 11:28:31 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"utilslib.h"

void	frame_cycle(t_vars *vars)
{
	if (vars->fps > 0)
		vars->fps --;
	else
	{
		vars->fps = 8;
		vars->frame ++;
		if (vars->frame > 7)
			vars->frame = 0;
	}
	change_edir(vars, 0);
	if (vars->eframe > 0)
		vars->eframe --;
	else
		vars->eframe = 401;
}

void	change_edir(t_vars *vars, int mode)
{
	if (mode == 0)
	{
		if (vars->frame == 5)
			vars->edir = -1;
		else if (vars->frame == 0)
			vars->edir = 1;
		else if (vars->frame == 3)
			vars->edir = -2;
		else if (vars->frame == 4)
			vars->edir = 2;
	}
	else
	{
		if (vars->frame == 3)
			vars->edir = -1;
		else if (vars->frame == 4)
			vars->edir = 1;
		else if (vars->frame == 0)
			vars->edir = -2;
		else if (vars->frame == 5)
			vars->edir = 2;
	}
}

int	swap_tiles2(t_vars *vars, int y, int x)
{
	if (vars->edir == -1)
	{
		if (vars->level[y][x - 1] == '0')
		{
			vars->level[y][x - 1] = 'M';
			vars->level[y][x] = '0';
			return (-1);
		}
		else
			change_edir(vars, 0);
	}
	else if (vars->edir == 1)
	{
		if (vars->level[y][x + 1] == '0')
		{
			vars->level[y][x + 1] = 'M';
			vars->level[y][x] = '0';
			return (1);
		}
		else
			change_edir(vars, 1);
	}
	else
		return (swap_tiles3(vars, y, x));
	return (0);
}

int	swap_tiles3(t_vars *vars, int y, int x)
{
	if (vars->edir == -2)
	{
		if (vars->level[y - 1][x] == '0')
		{
			vars->level[y - 1][x] = 'M';
			vars->level[y][x] = '0';
			return (-2);
		}
		else
			change_edir(vars, 1);
	}
	else if (vars->edir == 2)
	{
		if (vars->level[y + 1][x] == '0')
		{
			vars->level[y + 1][x] = 'M';
			vars->level[y][x] = '0';
			return (2);
		}
		else
			change_edir(vars, 0);
	}
	return (0);
}

void	enemymove(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	if (vars->eframe == 0)
	{
		while (y < vars->maph)
		{
			x = 0;
			while (x < vars->mapw)
			{
				if (check_tile(vars->level[y][x]) == 5)
				{
					if (swap_tiles2(vars, y, x) != 0)
					{
						x ++;
						y ++;
						change_edir(vars, 1);
					}
				}
				x ++;
			}
			y ++;
		}
	}
}
