/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiqueir <bsiqueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:52:02 by bsiqueir          #+#    #+#             */
/*   Updated: 2022/11/14 14:22:23 by bsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	game_events(int keycode, t_game *game)
{
	if (keycode == W || keycode == UP_ARROW)
	{
		game->y_player -= 1;
		player_w(game);
	}
	else if (keycode == S || keycode == DOWN_ARROW)
	{
		game->y_player += 1;
		player_s(game);
	}
	else if (keycode == D || keycode == RIGHT_ARROW)
	{
		game->x_player += 1;
		player_d(game);
	}
	else if (keycode == A || keycode == LEFT_ARROW)
	{
		game->x_player -= 1;
		player_a(game);
	}
}

static int	keypress(int keycode, t_game *game)
{
	if (keycode == ESC || keycode == Q)
		exit_game(game);
	else if (!game->endgame)
	{
		game_events(keycode, game);
		ft_printf("Moves: %d\r", game->n_moves);
	}
	return (0);
}

void	gameplay(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, keypress, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_expose_hook(game->win, &map_draw, game);
}
