#include "includes/header.h"

void	PrintArray(char **array, int height)
{
	int	index;

	index = 0;
	while (index < height)
	{
		printf("%s\n", array[index]);
		index++;
	}
}

void	PrintStruct(t_config *D, t_parser *P)
{
	P->file_height = P->file_height;
	//PrintArray(P->file, P->file_height);
	printf("%u\n", D->floor_rgb);
	printf("%u\n", D->ceil_rgb);
	printf("%s\n", D->tex_path[0]);
	printf("%s\n", D->tex_path[1]);
	printf("%s\n", D->tex_path[2]);
	printf("%s\n", D->tex_path[3]);
	printf("%d\n", D->player_dir);
	printf("%f\n", D->player_x);
	printf("%f\n", D->player_y);
	printf("%d\n", D->map_height);
	PrintArray(P->map, P->map_height);
}
