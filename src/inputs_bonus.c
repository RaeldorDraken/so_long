/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:53:23 by eros-gir          #+#    #+#             */
/*   Updated: 2022/05/18 13:06:03 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"utilslib.h"

void	bonus_operators(t_vars *vars, char *movstr)
{
	frame_cycle(vars);
	animate_frame(ft_strdup("./sprites/"), vars, 1);
	animate_frame(ft_strdup("./sprites/coin_"), vars, 3);
	animate_frame(ft_strdup("./sprites/mine_"), vars, 5);
	mlx_string_put(vars->mlx, vars->win, 31, 31, 0x00C00000, movstr);
	enemymove(vars);
}

int	key_inputs(int keycode, t_vars *vars)
{	
	if (keycode == 53)
		destroy_mlx(vars);
	else if (keycode == 0)
	{
		move_player(vars, keycode);
		vars->pdir = "left_0";
	}
	else if (keycode == 2)
	{
		move_player(vars, keycode);
		vars->pdir = "right_0";
	}
	else if (keycode == 1)
	{
		move_player(vars, keycode);
		vars->pdir = "down_0";
	}
	else if (keycode == 13)
	{
		move_player(vars, keycode);
		vars->pdir = "up_0";
	}
	return (0);
}

int	destroy_mlx(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

void	redraw_level(t_vars *vars, int tile_x, int tile_y, char *movstr)
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
	if (check_tile(vars->level[tile_y / 63][tile_x / 63]) == 5)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->spr[5],
			tile_x, tile_y);
	bonus_operators(vars, movstr);
}

int	render_frame(t_vars *vars)
{
	int		tile_x;
	int		tile_y;
	char	*movstr;

	movstr = ft_joinloc(ft_strdup("Movimientos: "), ft_itoa(vars->movcount));
	tile_y = 0;
	vars->score = 0;
	while (tile_y < (vars->maph * 63))
	{
		tile_x = 0;
		while (tile_x < (vars->mapw * 63))
		{
			redraw_level(vars, tile_x, tile_y, movstr);
			if (check_tile(vars->level[tile_y / 63][tile_x / 63]) == 3)
				vars->score ++;
			tile_x += 63;
		}
		tile_y += 63;
	}
	free(movstr);
	vars->pdup = 0;
	return (0);
}
