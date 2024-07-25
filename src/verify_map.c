/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:19:47 by vlibert           #+#    #+#             */
/*   Updated: 2024/07/15 13:05:15 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	line_same_len(t_map *map)
{
	size_t	i;
	size_t	len;

	if (!map->grid || !map->grid[0])
		return (FALSE);
	len = ft_strlen(map->grid[0]);
	i = 1;
	while (map->grid[i])
	{
		if (ft_strlen(map->grid[i]) != len)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	is_in_walls(t_map *map)
{
	int		i;
	int		j;
	size_t	len;

	if (!map->grid || !map->grid[0])
		return (FALSE);
	len = ft_strlen(map->grid[0]);
	j = 0;
	while (j < (int)len)
	{
		if (map->grid[0][j] != '1' || map->grid[map->line - 1][j] != '1')
			return (FALSE);
		j++;
	}
	i = 1;
	while (i < map->line - 1)
	{
		if (map->grid[i][0] != '1' || map->grid[i][len - 1] != '1')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	not_in_expected_char(char a)
{
	if (a != '0' && a != '1' && a != 'E' && a != 'C' && a != 'P')
		return (TRUE);
	return (FALSE);
}

static int	expected_char(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->grid[i])
	{
		while (map->grid[i][j])
		{
			if (not_in_expected_char(map->grid[i][j]))
				return (FALSE);
			j++;
		}
		j = 0;
		i++;
	}
	return (TRUE);
}

int	verify_map(t_map *map)
{
	if (!line_same_len(map) || !is_in_walls(map)
		|| !check_map_contents(map) || !expected_char(map) || !valid_road(map))
		return (FALSE);
	return (TRUE);
}
