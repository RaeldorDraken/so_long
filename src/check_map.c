/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:22:07 by eros-gir          #+#    #+#             */
/*   Updated: 2022/05/19 12:22:18 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"utilslib.h"

char	**map_buffer(char *filename, int height)
{
	int		i;
	char	**map;
	int		fd;

	i = 0;
	map = ft_calloc(sizeof(char *), height);
	fd = open(filename, O_RDONLY);
	if (!map)
		return (NULL);
	while (i < height)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
		{
			free(map);
			return (NULL);
		}
		i ++;
	}
	close(fd);
	return (map);
}

//Error formatting:
//	 0 everything fine.
//	-1 error in check_size.
//	-2 error in side walls.
//	-3 error in player/exit/collectible count.
int	check_map(char *filename, t_vars *vars)
{
	int		fd;
	int		errorno;

	fd = open(filename, O_RDONLY);
	errorno = 0;
	if (fd < 0)
	{
		close(fd);
		return (-4);
	}
	vars->maph = check_size(fd);
	close(fd);
	if (vars->maph < 0)
		return (-1);
	vars->level = map_buffer(filename, vars->maph);
	if (!vars->level)
		return (-4);
	errorno = check_walls(vars->level, vars->maph);
	if (errorno < 0)
		return (errorno);
	errorno = check_conditions(vars->level, vars->maph);
	if (errorno < 0)
		return (errorno);
	vars->mapw = ft_strlen(vars->level[0]) - 1;
	return (0);
}

int	ft_strchk(char *s, int c)
{
	int	l;
	int	i;
	int	result;

	l = ft_strlen(s) - 1;
	i = 0;
	result = 0;
	while (i < l)
	{
		if (s[i] == c)
			result ++;
		i ++;
	}
	return (result);
}
