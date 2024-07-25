/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:33:38 by vlibert           #+#    #+#             */
/*   Updated: 2024/07/03 12:52:43 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	replace_newline_with_null(char *line)
{
	size_t	len;

	len = 0;
	while (line[len] != '\0')
		len++;
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

static char	*new_line(char **line, int fd)
{
	*line = get_next_line(fd);
	return (*line);
}

static int	get_nb_lines(char *path)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(path, O_RDONLY);
	while (new_line(&line, fd))
	{
		free(line);
		count++;
	}
	return (count);
}

static void	assing_new_value(t_map *map, char **grid, int nb_line, int nb_col)
{
	map->grid = grid;
	map->line = nb_line;
	map->col = nb_col;
}

int	create_map(t_data *data, char *path)
{
	int		i;
	int		fd;
	int		nb_line;
	char	**grid;
	char	*line;

	i = 0;
	line = NULL;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (close_window(data), 0);
	nb_line = get_nb_lines(path);
	grid = (char **)malloc((nb_line + 1) * sizeof(char *));
	if (!grid)
		return (close_window(data), 0);
	while (new_line(&line, fd))
	{
		replace_newline_with_null(line);
		grid[i++] = line;
	}
	close(fd);
	grid[i] = NULL;
	assing_new_value(data->map, grid, nb_line, ft_strlen(grid[0]));
	return (1);
}
