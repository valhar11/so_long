/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:06:02 by vlibert           #+#    #+#             */
/*   Updated: 2024/07/17 09:21:52 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	set_to_null(t_data *data, t_assets *assets, t_map *map)
{
	assets->character = NULL;
	assets->collectibles = NULL;
	assets->extract = NULL;
	assets->floor = NULL;
	assets->tree = NULL;
	assets->pixels = 32;
	data->assets = assets;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->x = 0;
	data->y = 0;
	data->keycode = 0;
	data->move = 0;
	map->line = 0;
	map->collected = 0;
	map->collectibles = 0;
	map->exit_opened = 0;
}

t_data	initialize_data(t_data *data)
{
	data->assets = (t_assets *)malloc(sizeof(t_assets));
	data->map = (t_map *)malloc(sizeof(t_map));
	if (!(data->assets) || !(data->map))
	{
		write(2, "Error\n", 6);
		close_window(data);
	}
	set_to_null(data, data->assets, data->map);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		write(2, "Error\n", 6);
		close_window(data);
	}
	return (*data);
}
