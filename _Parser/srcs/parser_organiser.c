#include "../header_parser.h"

int	main(int argc, char *argv[])
{
	argc = 0;
	int		returnval;

	returnval = parse_main(argv);
	printf("returnval = %d\n", returnval);
	return (0);
}

int	parse_main(char *argv[])
{
	t_parser p_data;
	t_config data;
	
	ft_bzero(&p_data, sizeof(p_data));
	ft_bzero(&data, sizeof(data));
	if (CheckInput(&data, &p_data, argv[1]) == RETURN_FAIL)
		return (FreeParseStruct(&p_data), RETURN_FAIL);
	PrintStruct(&data, &p_data);
	FreeParseStruct(&p_data);
	return(RETURN_SUCCES);
}

int	CheckInput(t_config *data, t_parser *p_data, char *filename)
{
	data->ceil_rgb = 2;

	if (CheckNameValid(filename, p_data) == RETURN_FAIL)
		return (RETURN_FAIL);
	if (CopyFileToText(p_data) == RETURN_FAIL)
		return (RETURN_FAIL);
	FindMap(p_data);
	if (ParseLines(data, p_data) == RETURN_FAIL)
		return (RETURN_FAIL);
	return (RETURN_SUCCES);
}

void	PrintArray(char **array, int height)
{
	int	index;

	index = 0;
	while (index < height)
	{
		printf("%s", array[index]);
		index++;
	}
}

void	PrintStruct(t_config *D, t_parser *P)
{
	P->file_height = P->file_height;
	//PrintArray(P->file, P->file_height);
	printf("%u\n", D->ceil_rgb);
	printf("%u\n", D->floor_rgb);
	//printf("%d\n");
	//printf("%d\n");
	//printf("%d\n");
	//printf("%d\n");
	printf("%s\n", D->tex_path[0]);
	printf("%s\n", D->tex_path[1]);
	printf("%s\n", D->tex_path[2]);
	printf("%s\n", D->tex_path[3]);

}
