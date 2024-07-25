/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_road.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:37:47 by vlibert           #+#    #+#             */
/*   Updated: 2024/07/15 13:07:48 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	dfs(int x, int y, t_map *map, int **visited)
{
	int	directions[4][2];
	int	i;
	int	new_x;
	int	new_y;

	if (!is_valid_position(x, y, map, visited))
		return ;
	visited[x][y] = 1;
	initialize_directions(directions);
	i = 0;
	while (i < 4)
	{
		new_x = x + directions[i][0];
		new_y = y + directions[i][1];
		dfs(new_x, new_y, map, visited);
		i++;
	}
}

static int	check_collectibles_and_exit(t_map *map, int **visited)
{
	int	i;
	int	j;
	int	all_collectibles_reachable;
	int	exit_reachable;

	all_collectibles_reachable = TRUE;
	exit_reachable = FALSE;
	i = 0;
	while (i < map->line)
	{
		j = 0;
		while (j < map->col)
		{
			if (map->grid[i][j] == 'C' && visited[i][j] == 0)
				all_collectibles_reachable = FALSE;
			if (map->grid[i][j] == 'E' && visited[i][j] == 1)
				exit_reachable = TRUE;
			j++;
		}
		i++;
	}
	return (all_collectibles_reachable && exit_reachable);
}

int	valid_road(t_map *map)
{
	int	**visited;
	int	result;

	if (!find_player_position(map))
		return (FALSE);
	visited = initialize_visited(map);
	dfs(map->x_p, map->y_p, map, visited);
	result = check_collectibles_and_exit(map, visited);
	free_visited(visited, map->line);
	return (result);
}
