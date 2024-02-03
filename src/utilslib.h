/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilslib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:14:05 by eros-gir          #+#    #+#             */
/*   Updated: 2022/05/18 13:42:51 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILSLIB_H
# define UTILSLIB_H

# include"../libft/libft.h"
# include"../minilibx/mlx.h"
# include<stdio.h>
# include<fcntl.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		plx;
	int		ply;
	int		bpp;
	int		linelen;
	int		endian;
	char	**level;
	int		mapw;
	int		maph;
	void	**spr;
	int		movcount;
	int		score;
	char	ppos;
	int		frame;
	int		fps;
	char	*pdir;
	int		pdup;
	int		edir;
	int		eframe;
}	t_vars;

int		render_frame(t_vars *vars);
char	*get_next_line(int fd);
int		ft_strchk(char *s, int c);
int		check_conditions(char **map, int height);
int		check_filename(char *str);
int		check_map(char *filename, t_vars *vars);
char	**map_buffer(char *filename, int height);
int		check_walls(char **map, int count);
int		check_size(int fd);
void	error_handle(int number);
int		key_inputs(int keycode, t_vars *vars);
int		check_tile(char c);
int		destroy_mlx(t_vars *vars);
int		move_player(t_vars *vars, int keycode);
int		move_player2(t_vars *vars, int keycode);
void	swap_tiles(t_vars *vars, int y, int x);
void	frame_cycle(t_vars *vars);
void	animate_frame(char *filename, t_vars *vars, int obj);
void	bonus_operators(t_vars *vars, char *movstr);
void	enemymove(t_vars *vars);
int		swap_tiles2(t_vars *vars, int y, int x);
int		swap_tiles3(t_vars *vars, int y, int x);
void	change_edir(t_vars *vars, int mode);

#endif
