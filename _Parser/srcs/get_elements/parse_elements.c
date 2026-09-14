#include "../../header_parser.h"

//loopt door de text line per line en vind de paths van alle elementen
int	ParseLines(t_config *D, t_parser *P)
{
	int index;

	index = 0;
	while (index < (P->file_height - P->map_start) && P->elements < 7)
	{
		if (CheckValidElement(D, P, P->file[index]) == RETURN_FAIL)
			return (RETURN_FAIL);
		index++;
	}
	if (P->elements != 6 || D->tex_path[0] == NULL || D->tex_path[1] == NULL || D->tex_path[2] == NULL || D->tex_path[3] == NULL)
			return (PrintErrors(INVELEMNUM));
	return (RETURN_SUCCES);
}

//checkt of t een lege line is of valid element is 
int	CheckValidElement(t_config *D, t_parser *P, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (FillTextPaths(D, P, line + 3, NORTH));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (FillTextPaths(D, P, line + 3, SOUTH));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (FillTextPaths(D, P, line + 3, WEST));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (FillTextPaths(D, P, line + 3, EAST));
	else  if (ft_strncmp(line, "F ", 2) == 0)
		return (PutRGB(&D->floor_rgb, P, line + 1));
	else  if (ft_strncmp(line, "C ", 2) == 0)
		return (PutRGB(&D->ceil_rgb, P, line + 1));
	else if (line[0] == '\n')
		return (RETURN_SUCCES);
	else
		return (PrintErrors(INVELEM));
}

//pakt de path tussen vanaf de punt tot de eerste spatie/newline
int	FillTextPaths(t_config *D, t_parser *P, char *line, t_directions type)
{
	int		end;
	char	*check;
	int		index;

	index = 0;
	while (line[index] != '\0' && line[index] != '.')
        index++;
	end = index;
	while (line[end] != ' ' && line[end] != '\0')
		end++;
	check = ft_substr(line, index, end - index);
	if (!check)
	{
		D->tex_path[type] = NULL;
		return (PrintErrors(LIBFTFAIL));
	}
	P->elements++;
	D->tex_path[type] = check;
	free(check);
	return (RETURN_SUCCES);
}

//vind de rgb van de vloer en t plafond
int	PutRGB(uint32_t *rgb, t_parser *P, char *line)
{
	int	red;
	int green;
	int	blue;
	int alpha;
	int	index;

	index = 0;
	P->elements++;
	while (line[index] == ' ')
		index++;
	if (line[index] == '\0')
		return (PrintErrors(INVELEM));
	alpha = 0xFF;
	red = ft_atoi(line + index);
	index = GetNextNum(line, index);
	green = ft_atoi(line + index);
	index = GetNextNum(line, index);
	blue = ft_atoi(line + index);
	if (alpha < 0 || alpha > 255
		|| red < 0 || red > 255
		|| green < 0 || green > 255
		|| blue < 0 || blue > 255)
		return (PrintErrors(INVCLR));
*rgb = 	((uint32_t)(unsigned char)red << 24)
         | ((uint32_t)(unsigned char)green << 16)
         | ((uint32_t)(unsigned char)blue << 8)
         | ((uint32_t)(unsigned char)alpha);
	return (RETURN_SUCCES);
}

int	GetNextNum(char *line, int index)
{
	while (ft_isdigit(line[index]) == 1 && line[index] != '\0')
		index++;
	while (ft_isdigit(line[index]) == 0 && line[index] != '\0')
		index++;
	return (index);
}
