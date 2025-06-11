/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiqueir <bsiqueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:49:02 by bsiqueir          #+#    #+#             */
/*   Updated: 2022/11/14 13:55:12 by bsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*next_line(char *buff)
{
	int		i;
	int		j;
	char	*new_line_ret;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	new_line_ret = malloc(sizeof(char) * (ft_strlen(buff) - i + 1));
	if (!new_line_ret)
	{
		free(new_line_ret);
		return (NULL);
	}
	i++;
	j = 0;
	while (buff[i])
		new_line_ret[j++] = buff[i++];
	new_line_ret[j] = '\0';
	free(buff);
	return (new_line_ret);
}

char	*line_thrower(char *buff)
{
	char	*line_ret;
	int		i;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	line_ret = ft_gnl_substr(buff, 0, i + needs_null(buff));
	if (!line_ret)
	{
		free(line_ret);
		return (NULL);
	}
	return (line_ret);
}

char	*fd_read(int fd, char *buff)
{
	char		*buff_string;
	int			read_bytes;

	buff_string = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff_string)
		return (NULL);
	read_bytes = 1;
	while (!ft_gnl_strchr(buff, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff_string, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(buff_string);
			return (NULL);
		}
		buff_string[read_bytes] = '\0';
		buff = ft_gnl_strjoin(buff, buff_string);
	}
	free(buff_string);
	return (buff);
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = fd_read(fd, buffer);
	if (!buffer)
		return (NULL);
	ret = line_thrower(buffer);
	buffer = next_line(buffer);
	return (ret);
}
