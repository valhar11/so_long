/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:57:18 by vlibert           #+#    #+#             */
/*   Updated: 2024/07/03 12:02:49 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	on_keypress(int keycode, t_data *data)
{
	if (keycode == ESC)
		close_window(data);
	else
		make_it_move(data, keycode);
	return (0);
}

void	all_hooks(t_data *data)
{
	mlx_hook(data->win_ptr, 2, (1L << 0), on_keypress, data);
	mlx_hook(data->win_ptr, 17, (1L << 17), close_window, data);
}
