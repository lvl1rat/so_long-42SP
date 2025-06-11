/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiqueir <bsiqueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 03:27:17 by bsiqueir          #+#    #+#             */
/*   Updated: 2022/11/26 01:21:40 by bsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ext_check(char *file)
{
	if (!file)
		return (0);
	if (ft_strncmp(ft_strrchr(file, '.'), ".ber", 5) == 0)
		return (1);
	return (0);
}

static void	game_boot(t_game game)
{
	game_init(&game);
	gameplay(&game);
	mlx_loop(game.mlx);
}

static void	ext_error(t_game game)
{
	if (game.map)
		free_map(game.map);
	ft_printf("Invalid extention.\n");
	ft_printf("So_long needs to have a '.ber' map. <./so_long PATH/map.ber>\n");
	exit(1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		game.map = read_map(argv[1]);
		if (ext_check(argv[1]) == 0)
			ext_error(game);
		else if (map_check(&game) == 1 && is_winnable(&game, argv[1]) == 1)
			game_boot(game);
		else
		{
			if (game.map)
				free_map(game.map);
			ft_printf("Invalid map configuration.\n");
			exit (1);
		}
	}
	else
	{
		ft_printf("Syntax Error.\n");
		exit(1);
	}
	return (0);
}
