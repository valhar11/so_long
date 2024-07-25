/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:58:48 by vlibert           #+#    #+#             */
/*   Updated: 2024/07/09 22:19:27 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	push_texture_to_game(t_data *d, t_assets *a, char entity, int **table)
{
	if (!d || !a || !d->mlx_ptr || !d->win_ptr)
		return ;
	if (entity == 'C')
	{
		d->map->collectibles++;
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, a->collectibles,
			*(table[1]) * a->pixels, *(table[0]) * a->pixels);
	}
	if (entity == '0' && a && a->floor)
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, a->floor,
			*(table[1]) * a->pixels, *(table[0]) * a->pixels);
	if (entity == '1')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, a->tree,
			*(table[1]) * a->pixels, *(table[0]) * a->pixels);
	if (entity == 'E')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, a->extract,
			*(table[1]) * a->pixels, *(table[0]) * a->pixels);
	if (entity == 'P')
	{
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, a->character,
			*(table[1]) * a->pixels, *(table[0]) * a->pixels);
		d->map->x_p = *(table[1]);
		d->map->y_p = *(table[0]);
	}
}

void	read_image_to_game(t_data *data, t_assets *assets)
{
	int	i;
	int	j;
	int	*table[2];

	table[0] = &i;
	table[1] = &j;
	i = 0;
	while (i < data->map->line)
	{
		j = 0;
		while (j < data->map->col)
		{
			push_texture_to_game(data, assets, data->map->grid[i][j],
				table);
			j++;
		}
		i++;
	}
}
