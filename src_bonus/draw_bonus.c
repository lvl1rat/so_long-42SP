/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiqueir <bsiqueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:21:35 by bsiqueir          #+#    #+#             */
/*   Updated: 2022/11/26 23:52:30 by bsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	img_draw(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window
		(game->mlx, game->win, img, x * PX_SIZE, y * PX_SIZE);
}

static void	player_draw(t_game *game, void *img, int x, int y)
{
	game->x_player = x;
	game->y_player = y;
	img_draw(game, img, x, y);
}

static void	exit_draw(t_game *game, int x, int y)
{
	if (game->n_ring == 0)
	{
		mlx_destroy_image(game->mlx, game->exit);
		game->exit = xpm_to_struc(game, EXIT_OPEN);
	}
	img_draw(game, game->exit, x, y);
}

int	map_draw(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '1')
				img_draw(game, game->wall, x, y);
			else if (game->map[y][x] == '0')
				img_draw(game, game->floor, x, y);
			else if (game->map[y][x] == 'P')
				player_draw(game, game->sonic, x, y);
			else if (game->map[y][x] == 'C')
				img_draw(game, game->ring, x, y);
			else if (game->map[y][x] == 'E')
				exit_draw(game, x, y);
			else if (game->map[y][x] == 'F')
				img_draw(game, game->enemy, x, y);
		}
	}
	score_to_screen(game);
	return (0);
}

void	ran_into_enemy(t_game *game)
{
	mlx_destroy_image(game->mlx, game->sonic);
	mlx_clear_window(game->mlx, game->win);
	game->sonic = xpm_to_struc(game, DEATH);
	game->endgame = 1;
	map_draw(game);
}
