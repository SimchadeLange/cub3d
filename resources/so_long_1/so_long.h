/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-roo <ede-roo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 23:08:03 by ede-roo           #+#    #+#             */
/*   Updated: 2025/11/04 23:44:26 by ede-roo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

# define MIN_WIDTH 4
# define MIN_HEIGHT 4

# define TILE_SIZE 64

typedef struct s_sl
{
	char	**map;
	size_t	height;
	size_t	width;
	size_t	x;
	size_t	y;
	size_t	start_x;
	size_t	start_y;
	int		collectibles;
	int		collected;
	int		map_fd;
	int		player;
	int		exit;
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit;
	int		img_width;
	int		img_height;
	int		moves;
	int		found_all;
}	t_sl;

int		main(int argc, char *argv[]);
void	struct_initialisation(t_sl *sl);
void	make_line(int line_count, char *line, t_sl *sl, char *argv[]);
int		map_loading(char *argv[], t_sl *sl);
void	free_map(char **map);
int		map_limits(char **map, t_sl *sl);
int		map_tiles_checking(char **map, t_sl *sl, int i, int j);
int		map_validation(char **map, t_sl *sl);
void	route_trying(char **map_copy, t_sl *sl, size_t x, size_t y);
char	**make_map_copy(char **map, t_sl *sl);
int		route_validation(char **map, t_sl *sl);
void	mlx_initialization(t_sl *sl);
void	render_map(t_sl *sl);
void	move_player(t_sl *sl, size_t dx, size_t dy);
void	cleanup(t_sl *sl);
int		close_window(t_sl *sl);
void	textures_initialisation(t_sl *sl);
void	find_player(t_sl *sl);
int		key_hook(int keycode, void *param);
void	move_collectibles(t_sl *sl, size_t nx, size_t ny, char next_tile);
void	error_exit(t_sl *sl, char *msg);

#endif
