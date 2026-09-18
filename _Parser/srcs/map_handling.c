#include "../header_parser.h"

int	FindMap(t_parser *P)
{
	int	index;

	//PrintArray(P->file, P->file_height);
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
	//PrintArray(P->file + index, P->file_height - index);
	P->map_start = index;
	P->map_height = P->file_height - P->map_start;
	P->map = CopyArray(P->file, P->map_start, P->map_height);
	return (RETURN_SUCCES);
}
int	CheckValidChars(t_parser *P)
{
	int y;
	int	x;
	int	max_x;

	y = 0;
	while (y < P->map_height)
	{
		x = 0;
		while (P->map[y][x] != '\0')
		{
			if (P->map[y][x] != '1' || \
				P->map[y][x] != '0' || \
				P->map[y][x] != ' ' || \
				P->map[y][x] != 'N' || \
				P->map[y][x] != 'E' || \
				P->map[y][x] != 'W' || \
				P->map[y][x] != 'S')
			x++;
		}
		if (x > max_x)
			max_x = x;
	}
}
//int	PrepareFloodFill(t_config *D, t_parser *P)
//{
//
//}

//bool	flood_fill(t_parser *P, int y, int x)
//{
//	if (x < 0 || x >= (int)P->x_max || y < 0 || y >= (int)P->map_height)
//		return (false);
//	if (P->map_copy == 'X')
//		return (true);
//	if (get_type(P->map_copy[y][x]) == ' ')
//		return (false);
//	if (get_type(P->map_copy[y][x]) == '1')
//		return (true);
//	return (flood_fill(P, y + 1, x)
//		&& flood_fill(P, y - 1, x)
//		&& flood_fill(P, y, x + 1)
//		&& flood_fill(P, y, x - 1));
//}