/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:45:46 by vlibert           #+#    #+#             */
/*   Updated: 2024/07/03 13:06:33 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	mlx_put_image_but_short(t_data *d, void *image, int pos_x, int pos_y)
{
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, image,
		pos_x * d->assets->pixels, pos_y * d->assets->pixels);
}

int	main(int argc, char **argv)
{
	t_data		data;

	if (argc != 2 || !is_valid_path(argv[1]))
		return (write(2, "Error\n", 6), 1);
	data = initialize_data(&data);
	create_map(&data, argv[1]);
	if (!verify_map(data.map))
	{
		write(2, "Error\n", 6);
		return (free_data(&data), 1);
	}
	load_assets(&data, data.assets);
	data.win_ptr = mlx_new_window(data.mlx_ptr, (data.map->col) * 32,
			(data.map->line) * 32, "So Long");
	if (!data.win_ptr)
	{
		write(2, "Error\n", 6);
		return (close_window(&data), 1);
	}
	read_image_to_game(&data, data.assets);
	all_hooks(&data);
	mlx_loop(data.mlx_ptr);
	free_data(&data);
	return (0);
}
