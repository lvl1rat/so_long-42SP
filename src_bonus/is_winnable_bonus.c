/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_winnable_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiqueir <bsiqueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 21:13:08 by bsiqueir          #+#    #+#             */
/*   Updated: 2022/11/26 23:54:45 by bsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	print_grd(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		ft_printf("%s\n", map[y]);
		y++;
	}
	ft_printf("\n");
}

static	int	paint_from_player_pos(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->x_player = x;
				game->y_player = y;
			}
			x++;
		}
		y++;
	}
	return (0);
}

static void	flood_fill(t_game *game, int y, int x)
{
	if (game->map[y][x] == '1' || game->map[y][x] == 'A' ||
		game->map[y][x] == 'E' || game->map[y][x] == 'F')
		return ;
	if (game->map[y][x] == '0' || game->map[y][x] == 'C' ||
		game->map[y][x] == 'P')
	{
		if (game->map[y][x] == 'C')
			game->p_ring++;
		game->map[y][x] = 'A';
		flood_fill(game, y + 1, x);
		flood_fill(game, y - 1, x);
		flood_fill(game, y, x + 1);
		flood_fill(game, y, x - 1);
		return ;
	}
}

static void	is_exitable(t_game *game, int y, int x)
{
	if (game->map[y][x] == '1' || game->map[y][x] == 'A' ||
		game->map[y][x] == 'F')
		return ;
	if (game->map[y][x] == '0' || game->map[y][x] == 'C' ||
		game->map[y][x] == 'P' || game->map[y][x] == 'E')
	{
		if (game->map[y][x] == 'E')
			game->p_exit++;
		game->map[y][x] = 'A';
		is_exitable(game, y + 1, x);
		is_exitable(game, y - 1, x);
		is_exitable(game, y, x + 1);
		is_exitable(game, y, x - 1);
		return ;
	}
}

int	is_winnable(t_game *game, char *path)
{
	game->p_ring = 0;
	game->p_exit = 0;
	paint_from_player_pos(game);
	is_exitable(game, game->y_player, game->x_player);
	if (game->n_exit - game->p_exit == 0)
	{
		free_map(game->map);
		game->map = read_map(path);
		flood_fill(game, game->y_player, game->x_player);
		if (game->n_ring - game->p_ring == 0)
		{
			ft_printf("\nMap winnability checked successfully.\n\n");
			print_grd(game->map);
			free_map(game->map);
			game->map = read_map(path);
			return (1);
		}
	}
	ft_printf("\nError.\nWinnability system tryed to paint map with 'A's.\n");
	ft_printf("Player 'P' can't reach an exit 'E' or a collectable 'C'.\n\n");
	print_grd(game->map);
	return (0);
}
