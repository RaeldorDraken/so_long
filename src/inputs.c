/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:53:23 by eros-gir          #+#    #+#             */
/*   Updated: 2022/05/18 13:41:48 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"utilslib.h"

int	key_inputs(int keycode, t_vars *vars)
{
	if (keycode == 53)
		destroy_mlx(vars);
	else if (keycode == 0)
		move_player(vars, keycode);
	else if (keycode == 2)
		move_player(vars, keycode);
	else if (keycode == 1)
		move_player(vars, keycode);
	else if (keycode == 13)
		move_player(vars, keycode);
	return (0);
}

int	destroy_mlx(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

void	redraw_level(t_vars *vars, int tile_x, int tile_y)
{
	if (check_tile(vars->level[tile_y / 63][tile_x / 63]) == 4)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->spr[4],
			tile_x, tile_y);
	else if (check_tile(vars->level[tile_y / 63][tile_x / 63]) == 2)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->spr[2],
			tile_x, tile_y);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->spr[0],
			tile_x, tile_y);
	if (check_tile(vars->level[tile_y / 63][tile_x / 63]) == 1
		&& vars->pdup == 0)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->spr[1],
			tile_x, tile_y);
		vars->plx = tile_x / 63;
		vars->ply = tile_y / 63;
		vars->pdup = 1;
	}
	if (check_tile(vars->level[tile_y / 63][tile_x / 63]) == 3)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->spr[3],
			tile_x, tile_y);
}

int	render_frame(t_vars *vars)
{
	int		tile_x;
	int		tile_y;

	tile_y = 0;
	vars->score = 0;
	while (tile_y < (vars->maph * 63))
	{
		tile_x = 0;
		while (tile_x < (vars->mapw * 63))
		{
			redraw_level(vars, tile_x, tile_y);
			if (check_tile(vars->level[tile_y / 63][tile_x / 63]) == 3)
				vars->score ++;
			tile_x += 63;
		}
		tile_y += 63;
	}
	vars->pdup = 0;
	return (0);
}
