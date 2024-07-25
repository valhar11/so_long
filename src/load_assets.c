/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:05:34 by vlibert           #+#    #+#             */
/*   Updated: 2024/07/03 12:08:20 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	initialize(t_assets *assets)
{
	assets->character = NULL;
	assets->collectibles = NULL;
	assets->extract = NULL;
	assets->floor = NULL;
	assets->tree = NULL;
}

void	load_assets(t_data *d, t_assets *a)
{
	initialize(a);
	if (!a->character)
		a->character = mlx_xpm_file_to_image(d->mlx_ptr,
				"assets/character.xpm", &(a->pixels), &(a->pixels));
	if (!a->collectibles)
		a->collectibles = mlx_xpm_file_to_image(d->mlx_ptr,
				"assets/collectibles.xpm", &(a->pixels), &(a->pixels));
	if (!a->extract)
		a->extract = mlx_xpm_file_to_image(d->mlx_ptr,
				"assets/extract.xpm", &(a->pixels), &(a->pixels));
	if (!a->floor)
		a->floor = mlx_xpm_file_to_image(d->mlx_ptr,
				"assets/floor.xpm", &(a->pixels), &(a->pixels));
	if (!a->tree)
		a->tree = mlx_xpm_file_to_image(d->mlx_ptr,
				"assets/tree.xpm", &(a->pixels), &(a->pixels));
	if (!a->character || !a->collectibles || !a->extract
		|| !a->floor || !a->tree)
	{
		write(2, "Error\n", 6);
		close_window(d);
	}
}
