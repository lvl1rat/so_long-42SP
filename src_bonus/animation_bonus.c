/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiqueir <bsiqueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:53:28 by bsiqueir          #+#    #+#             */
/*   Updated: 2022/11/26 23:54:22 by bsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	frame_upd(t_game *game)
{
	if (game->frame < 4)
		game->frame++;
	else
		game->frame = 1;
}

static void	img_loop(t_game *game, int frame)
{
	mlx_destroy_image(game->mlx, game->ring);
	if (frame == 1)
		game->ring = xpm_to_struc(game, RING);
	else if (frame == 2)
		game->ring = xpm_to_struc(game, RING_FRAME2);
	else if (frame == 3)
		game->ring = xpm_to_struc(game, RING_FRAME3);
	else if (frame == 4)
		game->ring = xpm_to_struc(game, RING_FRAME4);
}

static void	animation(t_game *game)
{
	if (game->anim < ANIMATION_SPEED)
	{
		game->anim++;
		return ;
	}
	else
		game->anim = 0;
	frame_upd(game);
	img_loop(game, game->frame);
	map_draw(game);
}

int	animation_loop(t_game *game)
{
	animation(game);
	return (0);
}

void	score_to_screen(t_game *game)
{
	char	*str;

	str = ft_itoa(game->n_moves);
	mlx_string_put(game->mlx, game->win, 18, 15, 0x000000, "Moves: ");
	mlx_string_put(game->mlx, game->win, 60, 15, 0x000000, str);
	free(str);
}
