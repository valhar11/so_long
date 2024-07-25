/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:54:30 by vlibert           #+#    #+#             */
/*   Updated: 2024/07/17 09:02:26 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define ESC 53
# define TRUE 1
# define FALSE 0
# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2
# define UP_KEY 126
# define DOWN_KEY 125
# define LEFT_KEY 123
# define RIGHT_KEY 124

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char		**grid;
	int			line;
	int			col;
	int			x_p;
	int			y_p;
	int			collected;
	int			collectibles;
	int			exit_opened;
}				t_map;

typedef struct s_assets
{
	void		*character;
	void		*collectibles;
	void		*extract;
	void		*floor;
	void		*tree;
	int			pixels;
}				t_assets;

typedef struct s_data
{
	t_map		*map;
	t_assets	*assets;
	void		*mlx_ptr;
	void		*win_ptr;
	int			x;
	int			y;
	int			keycode;
	int			move;
}				t_data;

int				create_map(t_data *data, char *path);
void			load_assets(t_data *data, t_assets *assets);
void			load_map(t_data *data, t_assets *assets);
void			read_image_to_game(t_data *data, t_assets *assets);
int				verify_line_lengths(char **grid);
void			free_assets(t_data *data, t_assets *assets);
void			free_data(t_data *data);
int				close_window(t_data *data);
void			all_hooks(t_data *data);
void			make_it_move(t_data *data, int keycode);
int				clean_all(t_data *data);
t_data			initialize_data(t_data *data);
int				verify_map(t_map *map);
int				valid_road(t_map *map);
void			free_visited(int **visited, int line);
int				**initialize_visited(t_map *map);
int				find_player_position(t_map *map);
void			initialize_directions(int directions[4][2]);
int				is_valid_position(int x, int y, t_map *map, int **visited);
int				is_valid_path(const char *path);
int				check_map_contents(t_map *map);
void			mlx_put_image_but_short(t_data *d, void *image, int pos_x,
					int pos_y);

#endif