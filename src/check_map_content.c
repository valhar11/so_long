/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 23:15:16 by vlibert           #+#    #+#             */
/*   Updated: 2024/07/15 13:04:34 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	count_map_elements(t_map *m, int *ct_e, int *ct_p, int *ct_c)
{
	int	i;
	int	j;

	i = 0;
	while (m->grid[i])
	{
		j = 0;
		while (m->grid[i][j])
		{
			if (m->grid[i][j] == 'E')
				(*ct_e)++;
			else if (m->grid[i][j] == 'P')
				(*ct_p)++;
			else if (m->grid[i][j] == 'C')
				(*ct_c)++;
			j++;
		}
		i++;
	}
}

int	check_map_contents(t_map *map)
{
	int	count_e;
	int	count_p;
	int	count_c;

	if (!map->grid || !map->grid[0])
		return (FALSE);
	count_e = 0;
	count_p = 0;
	count_c = 0;
	count_map_elements(map, &count_e, &count_p, &count_c);
	if (count_e != 1 || count_p != 1 || count_c < 1)
		return (FALSE);
	return (TRUE);
}
