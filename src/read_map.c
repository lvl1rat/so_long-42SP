/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiqueir <bsiqueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 00:07:55 by bsiqueir          #+#    #+#             */
/*   Updated: 2022/11/12 04:56:17 by bsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *path)
{
	int		fd;
	char	*line;
	char	*full_str_map;
	char	*save_point;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	full_str_map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		save_point = full_str_map;
		full_str_map = ft_strjoin(save_point, line);
		free(line);
		free(save_point);
	}
	map = ft_split(full_str_map, '\n');
	free(full_str_map);
	close(fd);
	return (map);
}
