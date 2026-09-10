#include "../header_parser.h"

//check of t n file is en dat ie bestaat
bool	CheckNameValid(char *file_name, t_parser *p_data)
{
	char	*end_of_str;
	int		length;
	int		index;

	index = 0;
	if (!file_name)
		return (printf("invalid file1\n"), false);
	length = ft_strlen(file_name);
	end_of_str = ft_substr(file_name, length - 4, 4);
	if (ft_strncmp(".cub", end_of_str, 4) != 0)
	{
		free(end_of_str);
		return (printf("invalid file2\n"), false);
	}
	free(end_of_str);
	p_data->fd = open(file_name, O_RDONLY);
	if (p_data->fd < 3)
		return (printf("invalid file3\n"), false);
	return (true);
}

int		CountNewLines(char *line)
{
	int		counter;
	int		index;

	index = 0;
	counter = 0;
	while (line[index] != '\0')
	{
		if (line[index] == '\n')
			counter++;
		index++;
	}
	return (counter);
}

bool	CopyFileToText(t_parser *p_data)
{
	char		*line;
	static char	buffer[2024 + 1];
	char		*temp;
	int			read_return;

	line = ft_strdup("");
	if (!line)
		return (false);
	while ((read_return = read(p_data->fd, buffer, 2024)) > 0)
	{
		buffer[read_return] = '\0';
		temp = line;
		line = ft_strjoin(line, buffer);
		free(temp);
		if (!line)
			return (false);
	}
	if (read_return == -1)
		return (false);
	p_data->file_height = CountNewLines(line);
	p_data->file = MakeArrayFromString(line, p_data->file_height);
	if (p_data->file == NULL)
		return (free(line), false);
	free(line);
	return (true);
}

//loopt door de text en vind de paths van alle directies als ze er niet allemaal zijn geeft een error
bool	ParseLines(t_config *D, t_parser *P)
{
	int index;

	index = 0;
	while (index < P->file_height)
	{
		if (CheckValidElement(D, P, P->file[index]) == false)
			break ;
		index++;
		if (P->elements > 6)
			return (printf("error dublicate elemets\n"), false);
	}
	if (D->floor_rgb != 0 && D->ceil_rgb != 0 && D->tex_path[0] != NULL && D->tex_path[1] != NULL && D->tex_path[2] != NULL && D->tex_path[3] != NULL)
			return (true);
	return (false);
}

bool	CheckValidElement(t_config *D, t_parser *P, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (FillTextPaths(D, P, line + 3, NORTH), true);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (FillTextPaths(D, P, line + 3, SOUTH), true);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (FillTextPaths(D, P, line + 3, WEST), true);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (FillTextPaths(D, P, line + 3, EAST), true);
	else  if (ft_strncmp(line, "F ", 2) == 0)
		return (PutRGB(D, P, 'F'), true);
	else  if (ft_strncmp(line, "C ", 2) == 0)
		return (PutRGB(D, P, 'C'), true);
	else if (line[0] == '\n')
		return (true);
	else
		return (false);
}

//pakt de path tussen vanaf de punt tot de eerste spatie/newline
void	FillTextPaths(t_config *D, t_parser *P, char *line, int type)
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
		printf("substr error\n");
		D->tex_path[type] = NULL;
		return ;
	}
	P->elements++;
	D->tex_path[type] = check;
}

//wat wille we hier checke?
//bool	CheckfilePathValid(t_config *data, t_parser *p_data)
//{

//}

//vind de rgb van de vloer en t plafond
bool	PutRGB(t_config *D, t_parser *P, char type)
{

	P->elements++;	
	if (type == 'F')
		D->floor_rgb = 1;
	if (type == 'C')
		D->ceil_rgb = 1;
	return (true);
}