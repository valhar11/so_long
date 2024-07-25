/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:19:41 by vlibert           #+#    #+#             */
/*   Updated: 2024/07/17 09:24:58 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_window(t_data *data)
{
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	clean_all(data);
	exit(0);
}

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		if (data->map->grid)
		{
			while (data->map->grid[i])
				free(data->map->grid[i++]);
			free(data->map->grid);
		}
		free(data->map);
	}
	if (data->assets)
		free(data->assets);
}

void	free_assets(t_data *data, t_assets *assets)
{
	if (assets->character)
		mlx_destroy_image(data->mlx_ptr, assets->character);
	if (assets->collectibles)
		mlx_destroy_image(data->mlx_ptr, assets->collectibles);
	if (assets->extract)
		mlx_destroy_image(data->mlx_ptr, assets->extract);
	if (assets->floor)
		mlx_destroy_image(data->mlx_ptr, assets->floor);
	if (assets->tree)
		mlx_destroy_image(data->mlx_ptr, assets->tree);
}

int	clean_all(t_data *data)
{
	if (data && data->assets)
		free_assets(data, data->assets);
	free_data(data);
	return (0);
}
