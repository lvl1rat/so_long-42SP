/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiqueir <bsiqueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 01:53:18 by bsiqueir          #+#    #+#             */
/*   Updated: 2022/11/26 01:21:10 by bsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*xpm_to_struc(t_game *game, char *path_to_xml)
{
	void	*sprite;

	sprite = mlx_xpm_file_to_image(game->mlx, path_to_xml,
			&game->img_w, &game->img_h);
	return (sprite);
}

static void	img_init(t_game *game)
{
	game->sonic = xpm_to_struc(game, SONIC_STATIC);
	game->ring = xpm_to_struc(game, RING);
	game->wall = xpm_to_struc(game, WALL);
	game->floor = xpm_to_struc(game, FLOOR);
	game->exit = xpm_to_struc(game, EXIT_CLOSE);
	game->enemy = xpm_to_struc(game, ENEMY);
}

static void	window_size_setup(t_game *game)
{
	int	i;

	i = 0;
	game->map_w = ft_strlen(game->map[i]) * PX_SIZE;
	game->map_h = 0;
	while (game->map[i])
	{
		game->map_h++;
		i++;
	}
	game->map_h *= PX_SIZE;
}

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	window_size_setup(game);
	game->win = mlx_new_window(game->mlx, game->map_w, game->map_h, "So_Long");
	game->n_moves = 0;
	game->endgame = 0;
	img_init(game);
	map_draw(game);
}
