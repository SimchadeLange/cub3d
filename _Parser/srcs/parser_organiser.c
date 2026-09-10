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
	if (CheckInput(&data, &p_data, argv[1]) != true)
		return (1);
	PrintArray(p_data.file, p_data.file_height);
	FreeParseStruct(&p_data);
	return(0);
}

bool	CheckInput(t_config *data, t_parser *p_data, char *filename)
{
	data->ceil_rgb = 2;

	if (CheckNameValid(filename, p_data) == false)
		return (FreeParseStruct(p_data), false);
	if (CopyFileToText(p_data) == false)
		return (FreeParseStruct(p_data), false);
	if (ParseLines(data, p_data) == false)
		return (free_structs(p_data, data), false);
	return (true);
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