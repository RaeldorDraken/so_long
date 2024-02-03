/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  check_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:22:07 by eros-gir          #+#    #+#             */
/*   Updated: 2022/05/19 12:11:14 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"utilslib.h"

int	check_size(int fd)
{
	int		height;
	int		width;
	int		cwidth;
	char	*line;

	height = 0;
	line = get_next_line(fd);
	if (!line)
		return (-1);
	width = ft_strlen(line);
	while (line)
	{
		free(line);
		cwidth = ft_strlen(line);
		line = get_next_line(fd);
		if (width != cwidth)
		{
			free(line);
			return (-1);
		}
		height ++;
	}
	return (height);
}

int	check_walls(char **map, int count)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(*map) - 2;
	while (i < count && map[i])
	{
		if (i == 0 || i == (count - 1))
		{
			if ((ft_strchk(map[i], '0') > 0) || (ft_strchk(map[i], 'E') > 0)
				|| (ft_strchk(map[i], 'P') > 0) || (ft_strchk(map[i], 'C') > 0)
				|| (ft_strchk(map[i], 'M') > 0))
				return (-2);
		}
		else
		{
			if (map[i][0] != '1' || map[i][len] != '1')
				return (-2);
		}
		i ++;
	}
	return (0);
}

int	check_conditions2(char **map, int height)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < height)
	{
		while (j < ((int)ft_strlen(map[i]) - 1))
		{
			if (map[i][j] == '1' || map[i][j] == '0' || map[i][j] == 'P' ||
			map[i][j] == 'C' || map[i][j] == 'E' || map[i][j] == 'M')
				j ++;
			else
				return (0);
		}
		j = 0;
		i ++;
	}
	return (1);
}

int	check_conditions(char **map, int height)
{
	int	i;
	int	pl;
	int	co;
	int	ex;

	i = -1;
	pl = 0;
	ex = 0;
	co = 0;
	if (!check_conditions2(map, height))
		return (-3);
	while (++i < height)
	{
		pl += ft_strchk(map[i], 'P');
		ex += ft_strchk(map[i], 'E');
		co += ft_strchk(map[i], 'C');
	}
	if (pl != 1 || co == 0 || ex == 0)
		return (-3);
	return (0);
}

//Error formatting:
//	 0 everything fine.
//	-1 error in check_size.
//	-2 error in side walls.
//	-3 error in player/exit/collectible count.
void	error_handle(int number)
{
	ft_putstr_fd("Error\n", 1);
	if (number == -1)
		ft_putstr_fd("\tThe map has the incorrect format size!", 1);
	else if (number == -2)
		ft_putstr_fd("\tThere is a gap on at least one side!", 1);
	else if (number == -3)
		ft_putstr_fd("\tThe playable conditions are not met!", 1);
	else if (number == -5)
		ft_putstr_fd("\tNo map argument given!", 1);
	else
		ft_putstr_fd("\tUNDEFINED ERROR!", 1);
	ft_putstr_fd("\n", 1);
	return ;
}
