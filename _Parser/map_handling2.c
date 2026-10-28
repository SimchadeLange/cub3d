#include "includes/header.h"

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

static int	CheckMapEmpty(t_parser *P, int x, int y)
{
	if (P->map[y][x] != ' ' && P->map[y][x] != '\n' && P->map[y][x] != '\0')
		P->map_not_empty = true;
	return (RETURN_SUCCES);	
}

static int	MakeMap(t_parser *P, int height, int max_width, int start)
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
		if (!P->file[start + y] || P->file[start + y][0] == '\0' || P->file[start + y][0] == '\n')
            break;
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
	P->map_height = y;
	P->map = new;
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
	return (RETURN_SUCCES);
}
