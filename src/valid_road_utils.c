/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_road_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:12:21 by vlibert           #+#    #+#             */
/*   Updated: 2024/07/15 13:07:56 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_valid_position(int x, int y, t_map *map, int **visited)
{
	if (x >= 0 && x < map->line && y >= 0 && y < map->col)
	{
		if (map->grid[x][y] != '1' && visited[x][y] == 0)
			return (TRUE);
	}
	return (FALSE);
}

void	initialize_directions(int directions[4][2])
{
	directions[0][0] = 0;
	directions[0][1] = 1;
	directions[1][0] = 1;
	directions[1][1] = 0;
	directions[2][0] = 0;
	directions[2][1] = -1;
	directions[3][0] = -1;
	directions[3][1] = 0;
}

int	find_player_position(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->line)
	{
		j = 0;
		while (j < map->col)
		{
			if (map->grid[i][j] == 'P')
			{
				map->x_p = i;
				map->y_p = j;
				return (TRUE);
			}
			j++;
		}
		i++;
	}
	return (FALSE);
}

int	**initialize_visited(t_map *map)
{
	int	**visited;
	int	i;

	visited = (int **)malloc(map->line * sizeof(int *));
	i = 0;
	while (i < map->line)
	{
		visited[i] = (int *)malloc(map->col * sizeof(int));
		ft_memset(visited[i], 0, map->col * sizeof(int));
		i++;
	}
	return (visited);
}

void	free_visited(int **visited, int line)
{
	int	i;

	i = 0;
	while (i < line)
		free(visited[i++]);
	free(visited);
}
