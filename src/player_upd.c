/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_upd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiqueir <bsiqueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 23:35:54 by bsiqueir          #+#    #+#             */
/*   Updated: 2022/11/12 04:54:53 by bsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_img_upd(char key, t_game *game)
{
	mlx_destroy_image(game->mlx, game->sonic);
	if (key == 'w')
		game->sonic = xpm_to_struc(game, SONIC_W);
	else if (key == 's')
		game->sonic = xpm_to_struc(game, SONIC_S);
	else if (key == 'd')
		game->sonic = xpm_to_struc(game, SONIC_D);
	else if (key == 'a')
		game->sonic = xpm_to_struc(game, SONIC_A);
}

void	player_w(t_game *game)
{
	player_img_upd('w', game);
	if (game->map[game->y_player][game->x_player] == 'E'
		&& game->n_ring == 0)
	{
		game->map[game->y_player + 1][game->x_player] = '0';
		game->n_moves++;
		game->endgame = 1;
		map_draw(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->y_player += 1;
	else
	{
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_ring -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player + 1][game->x_player] = '0';
		game->n_moves++;
		map_draw(game);
	}
}

void	player_s(t_game *game)
{
	player_img_upd('s', game);
	if (game->map[game->y_player][game->x_player] == 'E'
		&& game->n_ring == 0)
	{
		game->map[game->y_player - 1][game->x_player] = '0';
		game->n_moves++;
		game->endgame = 1;
		map_draw(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->y_player -= 1;
	else
	{
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_ring -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player - 1][game->x_player] = '0';
		game->n_moves++;
		map_draw(game);
	}
}

void	player_d(t_game *game)
{
	player_img_upd('d', game);
	if (game->map[game->y_player][game->x_player] == 'E'
		&& game->n_ring == 0)
	{
		game->map[game->y_player][game->x_player - 1] = '0';
		game->n_moves++;
		game->endgame = 1;
		map_draw(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->x_player -= 1;
	else
	{
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_ring -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player][game->x_player - 1] = '0';
		game->n_moves++;
		map_draw(game);
	}
}

void	player_a(t_game *game)
{
	player_img_upd('a', game);
	if (game->map[game->y_player][game->x_player] == 'E'
		&& game->n_ring == 0)
	{
		game->map[game->y_player][game->x_player + 1] = '0';
		game->n_moves++;
		game->endgame = 1;
		map_draw(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->x_player += 1;
	else
	{
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_ring -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player][game->x_player + 1] = '0';
		game->n_moves++;
		map_draw(game);
	}
}
