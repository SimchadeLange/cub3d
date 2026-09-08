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
	
	InitParseStruct(&p_data);
	InitMainStruct(&data);
	printf("%d\n", p_data.check++);
	if (CheckInput(&data, &p_data, argv[1]))
		return (free_structs(&p_data, &data), 1);
	printf("%s\n", p_data.text);
	FreeParseStruct(&p_data);
	return(0);
}

bool	CheckInput(t_config *data, t_parser *p_data, char *filename)
{
	if (CheckNameValid(filename, &p_data) == false)
		return (FreeParseStruct(&p_data), false);
	if (CopyFileToText(&p_data) == false)
		return (FreeParseStruct(&p_data), false);
	if (FindTextPaths(&data, &p_data) == false)
		return (free_structs(&p_data, &data), false);
	return (true);
}