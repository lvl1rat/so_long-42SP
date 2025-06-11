/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiqueir <bsiqueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 06:13:25 by bsiqueir          #+#    #+#             */
/*   Updated: 2022/11/26 01:21:26 by bsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	is_rect_and_reg(char **map)
{
	int		i;
	size_t	len;

	i = 1;
	len = ft_strlen(map[0]);
	if (!map)
		return (0);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	if ((i - len) == 0)
		return (0);
	return (1);
}

static int	is_wall_surrounded(char **map)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	i = 0;
	while (map[i])
		i++;
	while (map[0][j] != '\0' && map[i - 1][j] != '\0')
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	component_checker(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x] == 'P')
				game->n_player++;
			else if (game->map[y][x] == 'E')
				game->n_exit++;
			else if (game->map[y][x] == 'C')
				game->n_ring++;
			else if (game->map[y][x] != 'P' && game->map[y][x] != 'E'
			&& game->map[y][x] != 'C' && game->map[y][x] != '0'
			&& game->map[y][x] != '1' && game->map[y][x] != 'F')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	map_check(t_game *game)
{
	game->n_ring = 0;
	game->n_player = 0;
	game->n_exit = 0;
	if (is_rect_and_reg(game->map) && is_wall_surrounded(game->map)
		&& component_checker(game))
	{
		if (game->n_player != 1 || game->n_exit != 1 || game->n_ring == 0)
			return (0);
		return (1);
	}
	return (0);
}
