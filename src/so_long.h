/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiqueir <bsiqueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 01:39:47 by bsiqueir          #+#    #+#             */
/*   Updated: 2022/11/12 04:55:14 by bsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/libft.h"
# include <mlx.h>

# define SONIC_W "assets/sonic-back.xpm"
# define SONIC_S "assets/sonic-front.xpm"
# define SONIC_D "assets/sonic-right.xpm"
# define SONIC_A "assets/sonic-left.xpm"
# define SONIC_STATIC "assets/sonic-stop.xpm"
# define RING "assets/ring.xpm"
# define WALL "assets/wall.xpm"
# define FLOOR "assets/floor.xpm"
# define EXIT_CLOSE "assets/exit-close.xpm"
# define EXIT_OPEN "assets/exit-open.xpm"

# define ESC 65307
# define Q 113

# define W 119
# define A 97
# define S 115
# define D 100

# define UP_ARROW 65362
# define LEFT_ARROW 65361
# define DOWN_ARROW 65364
# define RIGHT_ARROW 65363

# define PX_SIZE 32

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*floor;
	void	*wall;
	void	*sonic;
	void	*ring;
	void	*exit;
	int		map_w;
	int		map_h;
	int		img_w;
	int		img_h;
	int		n_ring;
	int		n_player;
	int		n_exit;
	int		x_player;
	int		y_player;
	int		n_moves;
	int		endgame;
	int		p_ring;
	int		p_exit;
}	t_game;

int		map_check(t_game *game);
char	**read_map(char *path);
void	game_init(t_game *game);
void	*xpm_to_struc(t_game *game, char *path_to_xml);
int		map_draw(t_game *game);
void	img_draw(t_game *game, void *img, int x, int y);
void	free_map(char **map);
int		exit_game(t_game *game);
void	gameplay(t_game *game);
void	player_w(t_game *game);
void	player_a(t_game *game);
void	player_s(t_game *game);
void	player_d(t_game *game);
int		is_winnable(t_game *game, char *path);

#endif