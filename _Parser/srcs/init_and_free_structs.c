#include "../header_parser.h"


void	InitMainStruct(t_config *data)
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

void	InitParseStruct(t_parser *p_data)
{
	p_data->length = 0;
	p_data->index = 0;
	p_data->check = 0;
	p_data->fd = 0;
	p_data->map_copy = NULL;
	p_data->map = NULL;
	p_data->text = NULL;
}

void	FreeParseStruct(t_parser *p_data)
{
	if (p_data->map_copy != NULL)
		free(p_data->map_copy);
	if (p_data->map != NULL)
		free(p_data->map);
	if (p_data->text != NULL)
		free(p_data->text);
}

void	FreeMainStruct(t_config *data)
{
	if (data->tex_path[0] != NULL)
		free(data->tex_path[0]);
	if (data->tex_path[1] != NULL)
		free(data->tex_path[1]);
	if (data->tex_path[2] != NULL)
		free(data->tex_path[2]);
	if (data->tex_path[3] != NULL)
		free(data->tex_path[3]);
	if (data->map != NULL)
		free(data->map);
}

void	free_structs(t_parser *p_data, t_config *data)
{
	FreeMainStruct(data);
	FreeParseStruct(p_data);
}