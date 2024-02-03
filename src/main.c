/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:27:44 by eros-gir          #+#    #+#             */
/*   Updated: 2022/05/19 12:07:18 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"utilslib.h"

//sprites are	0 = background, 1 = player, 2 = walls
//				3 = collectibles, 4 = exit, 5 = enemies.
void	set_sprites(t_vars *vars)
{
	int	img_height;
	int	img_width;

	vars->spr[0] = mlx_png_file_to_image(vars->mlx, "./sprites/BGrock.png",
			&img_width, &img_height);
	vars->spr[1] = mlx_png_file_to_image(vars->mlx, "./sprites/up_00.png",
			&img_width, &img_height);
	vars->spr[2] = mlx_png_file_to_image(vars->mlx, "./sprites/FGrock.png",
			&img_width, &img_height);
	vars->spr[3] = mlx_png_file_to_image(vars->mlx, "./sprites/coin_0.png",
			&img_width, &img_height);
	vars->spr[4] = mlx_png_file_to_image(vars->mlx, "./sprites/Ehole.png",
			&img_width, &img_height);
	vars->spr[5] = mlx_png_file_to_image(vars->mlx, "./sprites/mine_0.png",
			&img_width, &img_height);
}

int	set_vars(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->spr)
		return (0);
	set_sprites(vars);
	vars->win = mlx_new_window(vars->mlx, (vars->mapw * 63),
			(vars->maph * 63), "so_long");
	vars->img = mlx_new_image(vars->mlx, (vars->mapw * 63), (vars->maph * 63));
	vars->addr = mlx_get_data_addr(vars->img, &vars->bpp,
			&vars->linelen, &vars->endian);
	vars->movcount = 0;
	vars->score = 0;
	vars->frame = 0;
	vars->fps = 8;
	vars->pdir = "up_0";
	vars->eframe = 401;
	vars->pdup = 0;
	return (1);
}

int	check_filename(char *str)
{
	char	*chks;
	char	*cmps;
	int		len;

	cmps = ".ber";
	len = ft_strlen(str);
	chks = ft_substr(str, len -4, len);
	if (ft_strncmp(chks, cmps, 5))
	{	
		free(chks);
		return (-5);
	}
	free(chks);
	return (0);
}

int	main(int ac, char **av)
{
	int		errorno;
	t_vars	vars;

	if (ac < 2)
	{
		error_handle(-5);
		return (1);
	}
	else
		errorno = check_filename(av[1]);
	if (errorno == 0)
		errorno = check_map(av[1], &vars);
	if (errorno < 0)
	{
		error_handle(errorno);
		exit(0);
	}
	if (!set_vars(&vars))
		exit(0);
	mlx_loop_hook(vars.mlx, render_frame, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_inputs, &vars);
	mlx_hook(vars.win, 17, 0, destroy_mlx, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
