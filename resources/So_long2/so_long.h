/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:26:01 by side-lan          #+#    #+#             */
/*   Updated: 2025/11/26 16:00:19 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdbool.h>
# include <fcntl.h>
# include "Libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "MLX42/include/MLX42/MLX42.h"

# ifndef TILE_SIZE
#  define TILE_SIZE 128
# endif

typedef struct s_constants
{
	int	height;
	int	width;
	int	e_x;
	int	e_y;
}	t_constants;

typedef struct s_updates
{
	int		check;
	int		move_counter;
	int		p_y;
	int		p_x;
	bool	exit_open;
	int		c_count;
}	t_updates;

typedef struct s_bigstruct
{
	bool			last_point_exit;
	char			*copy;
	char			*map;
	mlx_t			*mlx;
	t_constants		constants;
	mlx_image_t		*img_empty;
	mlx_image_t		*img_exit;
	mlx_image_t		*img_player;
	mlx_image_t		*img_star;
	mlx_image_t		*img_wall;
	t_updates		updates;
}	t_bigstruct;

/*error*/
void	exit_program(t_bigstruct *info, char *error);

/*map parsing*/
char	*parse_organizer(char *argv[], t_bigstruct *mapinfo);
int		check_object_count(t_bigstruct *info, int p_check, int e_check);
char	*read_file(char	*file_name, t_bigstruct *mapinfo);
int		check_walls(char *str, int y);
int		get_height(char *str);
int		check_shape(char *str);
int		check_valid_symbols(char *str);

/*flood fill*/
char	*flood_prepare(t_bigstruct	*mapinfo);
void	floodfill(int x, int y, t_constants sizes, t_bigstruct *mapinfo);
int		flood_check(char c);
int		find_indexes(char *map, int *x, int *y, int *width);
int		flood_organizer(t_bigstruct *mapinfo);

/*window rendering*/
int		visualize_map_organizer(t_bigstruct *info);
void	init_images(t_bigstruct *info);
void	put_image(int x, int y, t_constants *sizes, t_bigstruct *info);

/*struct*/
void	init_structs(t_bigstruct *info);

/*hooks*/
void	create_keyhook(mlx_key_data_t keydata, void *param);
void	move_player(t_bigstruct *info, int new_x, int new_y);

#endif