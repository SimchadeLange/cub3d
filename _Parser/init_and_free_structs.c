#include "header_parser.h"


void	init_main_struct(t_config *data)
{
	data->tex_path[0] = NULL;
	data->tex_path[1] = NULL;
	data->tex_path[2] = NULL;
	data->tex_path[3] = NULL;
	data->floor_rgb = 0;
	data->ceil_rgb = 0;
	data->map = NULL;
	data->map_height = 0;
	data->player_x = 0;
	data->player_y = 0;
	data->player_dir = NORTH;
}

void	init_parse_struct(t_parser *p_data)
{
	p_data->fd = 0;
	p_data->map_copy = NULL;
	p_data->map = NULL;
	p_data->text = NULL;
}

void	free_pdata(t_parser *p_data)
{
	if(p_data->map_copy)
		free(p_data->map_copy);
	if (p_data->map)
		free(p_data->map);
	if(p_data->text)
		free(p_data->text);
}