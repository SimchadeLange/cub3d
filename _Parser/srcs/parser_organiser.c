#include "header.h"

int	parse_main(char *argv[])
{
	t_parser p_data;
	t_config data;

	ft_bzero(&p_data, sizeof(p_data));
	ft_bzero(&data, sizeof(data));
	p_data.Data = &data;
	if (CheckInput(&data, &p_data, argv[1]) == RETURN_FAIL)
		return (free_structs(&p_data, &data), RETURN_FAIL);
	data.map_height = p_data.map_height;
	//data.map = p_data.map;
	PrintStruct(&data, &p_data);
	FreeParseStruct(&p_data);
	return(RETURN_SUCCES);
}

int	CheckInput(t_config *data, t_parser *p_data, char *filename)
{
	if (CheckNameValid(filename, p_data) == RETURN_FAIL)
		return (RETURN_FAIL);
	if (CopyFileToText(p_data) == RETURN_FAIL)
		return (RETURN_FAIL);
	FindMap(p_data);
	if (ParseLines(data, p_data) == RETURN_FAIL)
		return (RETURN_FAIL);
	if (ParseMap(p_data) == RETURN_FAIL)
		return (RETURN_FAIL);
	return (RETURN_SUCCES);
}

