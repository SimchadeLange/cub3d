#include "../../header_parser.h"

//loopt door de text line per line en vind de paths van alle elementen
int	ParseLines(t_config *D, t_parser *P)
{
	int index;

	index = 0;
	while (index < (P->file_height - P->map_height) && P->elements < 7)
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
	while (line[end] != ' ' && line[end] != '\0' && line[end] != '\n')
		end++;
	check = ft_substr(line, index, end - index);
	if (!check)
	{
		D->tex_path[type] = NULL;	
		return (PrintErrors(LIBFTFAIL));
	}
	P->elements++;
	D->tex_path[type] = check;
	return (RETURN_SUCCES);
}

static int	GetNextNum(char *line, t_rgbvalues *rgbv)
{
	int	commacheck;
	int	num;

	commacheck = 0;
	while (line[rgbv->index] == ' ')
		rgbv->index++;
	while (ft_isdigit(line[rgbv->index]) == true && line[rgbv->index] != '\0')
		rgbv->index++;
	while ((line[rgbv->index] == ' ' || line[rgbv->index] == ',' ) && line[rgbv->index] != '\0')
	{
		if (line[rgbv->index] == ',')
			commacheck++;
		rgbv->index++;
	}
	//wat als '\0 in isdigit komt?
	if (ft_isdigit(line[rgbv->index]) == false || commacheck != 1)
		return (-1);
	if ((num = ft_atoi(line + rgbv->index)) < 0)
		return (-1);
	return (num);
}

//vind de rgb van de vloer en t plafond
int	PutRGB(uint32_t *rgb, t_parser *P, char *line)
{
	t_rgbvalues rgbv;

	rgbv.index = 0;
	P->elements++;
	ft_bzero(&rgbv, sizeof(rgbv));
	if (line[0] == '\0')
		return (PrintErrors(INVCLR));
	rgbv.alpha = 0xFF;
	if ((rgbv.red = ft_atoi(line)) < 0)
		return (ft_bzero(&rgbv, sizeof(rgbv)), PrintErrors(INVCLR));
	if ((rgbv.green = GetNextNum(line, &rgbv)) == -1)
		return (ft_bzero(&rgbv, sizeof(rgbv)), PrintErrors(INVCLR));
	if ((rgbv.blue = GetNextNum(line, &rgbv)) == -1)
		return (ft_bzero(&rgbv, sizeof(rgbv)), PrintErrors(INVCLR));
	if (rgbv.alpha < 0 || rgbv.alpha > 255
		|| rgbv.red < 0 || rgbv.red > 255
		|| rgbv.green < 0 || rgbv.green > 255
		|| rgbv.blue < 0 || rgbv.blue > 255)
		return (PrintErrors(INVCLR));
	*rgb = 	((uint32_t)(unsigned char)rgbv.red << 24)
         | ((uint32_t)(unsigned char)rgbv.green << 16)
         | ((uint32_t)(unsigned char)rgbv.blue << 8)
         | ((uint32_t)(unsigned char)rgbv.alpha);
	ft_bzero(&rgbv, sizeof(rgbv));
	return (RETURN_SUCCES);
}
