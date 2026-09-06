#ifndef HEADER_RAYCAST_H
# define HEADER_RAYCAST_H
#include "../header.h"

typedef struct s_img
{
	void	*ptr;       /* from mlx_new_image / mlx_xpm_file_to_image */
	char	*addr;      /* from mlx_get_data_addr */
	int		bpp;
	int		line_len;
	int		endian;
	int		w;
	int		h;
}	t_img;

typedef struct s_player
{
	double	x;          /* position, in tile units */
	double	y;
	double	dir_x;      /* direction vector, length 1 */
	double	dir_y;
	double	plane_x;    /* camera plane, perpendicular to dir */
	double	plane_y;
	int		keys[6];    /* W A S D LEFT RIGHT held? */
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		screen;
	t_img		tex[4];     /* NO SO WE EA, loaded from cfg->tex_path */
	t_config	*cfg;       /* map + colours live here, don't copy them */
	t_player	player;
}	t_game;

#endif