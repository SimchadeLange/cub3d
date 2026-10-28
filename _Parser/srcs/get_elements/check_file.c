#include "header.h"

static int	CheckMapEmpty(t_parser *P, int x, int y)
{
	if (P->map[y][x] != ' ' && P->map[y][x] != '\n' && P->map[y][x] != '\0')
		P->map_not_empty = true;
	return (RETURN_SUCCES);	
}

static void GetMaxWidth(t_parser *P)
{
	int	x;
	int y;
	int	start;
	int	width;

	y = 0;
	start = P->map_start;
	while (y < P->map_height)
	{
		x = 0;
		width = ft_strlen(P->file[start + y]);
		while (x < width)
			x++;
		if (P->max_width < x)
			P->max_width = x;
		y++;
	}
}

//check of t n file is en dat ie bestaat
int	CheckNameValid(char *file_name, t_parser *p_data)
{
	char	*end_of_str;
	int		length;
	int		index;

	index = 0;
	if (!file_name)
		return (PrintErrors(INVFILE));
	length = ft_strlen(file_name);
	end_of_str = ft_substr(file_name, length - 4, 4);
	if (ft_strncmp(".cub", end_of_str, 4) != 0)
	{
		free(end_of_str);
		return (PrintErrors(INVFILE));
	}
	free(end_of_str);
	p_data->fd = open(file_name, O_RDONLY);
	if (p_data->fd < 3)
		return (PrintErrors(INVFILE));
	return (RETURN_SUCCES);
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
	if (index > 0 && line[index - 1] != '\n')
        counter++;
	return (counter);
}

int	CopyFileToText(t_parser *p_data)
{
	char		*line;
	static char	buffer[2024 + 1];
	char		*temp;
	int			read_return;

	line = ft_strdup("");
	if (!line)
		return (PrintErrors(MEMFAIL));
	while ((read_return = read(p_data->fd, buffer, 2024)) > 0)
	{
		buffer[read_return] = '\0';
		temp = line;
		line = ft_strjoin(line, buffer);
		free(temp);
		if (!line)
			return (PrintErrors(MEMFAIL));
	}
	if (read_return == -1)
		return (PrintErrors(READFAIL));
	p_data->file_height = CountNewLines(line);
	p_data->file = MakeArrayFromString(line, p_data->file_height);
	if (p_data->file == NULL)
		return (PrintErrors(MEMFAIL));
	free(line);
	return (RETURN_SUCCES);
}

int	FindMap(t_parser *P)
{
	int	index;

	index = 0;
	while (index < P->file_height && P->file[index] &&
			(!ft_strncmp(P->file[index], "NO ", 3) ||
			!ft_strncmp(P->file[index], "WE ", 3) ||
			!ft_strncmp(P->file[index], "SO ", 3) ||
			!ft_strncmp(P->file[index], "EA ", 3) ||
			!ft_strncmp(P->file[index], "F ", 2)  ||
			!ft_strncmp(P->file[index], "C ", 2)  ||
			P->file[index][0] == '\n'))
		{
			index++;
		}
	P->map_start = index;
	P->map_height = P->file_height - P->map_start;
	GetMaxWidth(P);
	MakeMap(P, P->map_height, P->max_width, P->map_start);
	RemoveNewlines(P);
	P->map_not_empty = false;
	if (LoopThroughArr(P, &CheckMapEmpty) && P->map_not_empty == false)
		return (RETURN_FAIL);
	if ((P->map_copy = CopyArray(P->map, P->map_height)) == NULL)
		return (PrintErrors(MEMFAIL));
	//PrintArray(P->map_copy, P->map_height);
	return (RETURN_SUCCES);
}

int		MakeMap(t_parser *P, int height, int max_width, int start)
{
	int		x;
	int		y;
	int		line_width;
	char	**new;

	y = 0;
	new = malloc(sizeof(char *) * (height + 1));
	if (!new)
		return (PrintErrors(MEMFAIL));
	while (y < height)
	{
		x = 0;
		line_width = ft_strlen(P->file[start + y]);
		new[y] = malloc(sizeof(char) * (max_width + 1));
		if (!new[y])
			return (PrintErrors(MEMFAIL));
		while (x < line_width && x < line_width)
		{
			new[y][x] = P->file[start + y][x];
			x++;
		}
		while (x < max_width)
			new[y][x++] = ' ';
		new[y][x] = '\0';
		y++;
	}
	new[y] = NULL;
	P->map = new;
	return (RETURN_SUCCES);
}
