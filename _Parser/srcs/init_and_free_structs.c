#include "../header_parser.h"

void	FreeParseStruct(t_parser *p_data)
{
	if (p_data->map_copy != NULL)
		free(p_data->map_copy);
	if (p_data->map != NULL)
		free(p_data->map);
	if (p_data->file != NULL)
		FreeArray(p_data->file, p_data->file_height);
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


void	FreeArray(char **array, int height)
{
	int index;

	if (!array)
		return ;
	index = 0;
	while (index < height)
	{
		if (array)
			free(array[index]);
		index++;
	}
	free(array);
}
