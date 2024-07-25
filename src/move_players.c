/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:38:39 by vlibert           #+#    #+#             */
/*   Updated: 2024/07/17 08:44:11 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	increase_move(t_data *data)
{
	ft_putnbr_fd(++(data->move), 1);
	write(1, "\n", 1);
}

static void	collect(t_map *map, int y, int x)
{
	map->collected++;
	map->grid[y][x] = 0;
	if (map->collected == map->collectibles)
		map->exit_opened = TRUE;
}

static void	exit_map(t_data *d)
{
	if (d->map->collected == d->map->collectibles)
		close_window(d);
}

static void	move(t_data *d, t_assets *a, char axis, int direction)
{
	int	new_x;
	int	new_y;

	new_x = d->map->x_p;
	new_y = d->map->y_p;
	if (axis == 'x')
		new_x += direction;
	else if (axis == 'y')
		new_y += direction;
	if (d->map->grid[new_y][new_x] == '1')
		return ;
	else if (d->map->grid[new_y][new_x] == 'C')
		collect(d->map, new_y, new_x);
	else if (d->map->grid[new_y][new_x] == 'E')
		exit_map(d);
	if (new_x < 1 || new_x < 1)
		return ;
	if (d->map->grid[d->map->y_p][d->map->x_p] == 'E')
		mlx_put_image_but_short(d, a->extract, d->map->x_p, d->map->y_p);
	else
		mlx_put_image_but_short(d, a->floor, d->map->x_p, d->map->y_p);
	d->map->y_p = new_y;
	d->map->x_p = new_x;
	mlx_put_image_but_short(d, d->assets->character, new_x, new_y);
	increase_move(d);
}

void	make_it_move(t_data *data, int keycode)
{
	if (keycode == S_KEY || keycode == DOWN_KEY)
		move(data, data->assets, 'y', 1);
	if (keycode == W_KEY || keycode == UP_KEY)
		move(data, data->assets, 'y', -1);
	if (keycode == A_KEY || keycode == LEFT_KEY)
		move(data, data->assets, 'x', -1);
	if (keycode == D_KEY || keycode == RIGHT_KEY)
		move(data, data->assets, 'x', 1);
}
