#include "includes/header.h"

//check walls

static void init_player(t_parser *P, int x, int y)
{
 	if (P->map[y][x] == 'N')
		P->Data->player_dir = NORTH;
 	else if (P->map[y][x] == 'S')
		P->Data->player_dir = SOUTH;
 	else if (P->map[y][x] == 'W')
		P->Data->player_dir = WEST;
	else
		P->Data->player_dir = EAST;
	P->Data->player_x = x + 0.5;
	P->Data->player_y = y + 0.5;
	P->player_counter++;
}

static int CheckWallsEnclosed(t_parser *P)
{
	int x;
	int y;
	int	width;

	width = ft_strlen(P->map[0]);
	y = 0;
	x = 0;
	while (y < P->map_height && (P->map[y][0] == ' ' || P->map[y][0] == '1'))
		y++;
	while (x < width && (P->map[0][x] == ' ' || P->map[0][x] == '1'))
		x++;
	if (y != P->map_height || x != width)
		return (PrintErrors(INVMAPWALL));
	x = 0;
	width = ft_strlen(P->map[P->map_height - 1]);
	while (x < width && (P->map[P->map_height - 1][x] == ' ' || P->map[P->map_height - 1][x] == '1'))
		x++;	
	if (x != width)
		return (PrintErrors(INVMAPWALL));
	return (RETURN_SUCCES);
}

static bool	FloodFill(t_parser *P, int y, int x)
{
	if (y < 0 || y >= P->map_height || x < 0 || !P->map_copy[y] || x >= (int)ft_strlen(P->map_copy[y]))
		return (false);
	if (P->map_copy[y][x] == ' ')
		return (false);
	if (P->map_copy[y][x] == '1')
		return (true);
	if (P->map_copy[y][x] == 'X')
		return (true);
	P->map_copy[y][x] = 'X';
	return (FloodFill(P, y + 1, x)
		&& FloodFill(P, y - 1, x)
		&& FloodFill(P, y, x + 1)
		&& FloodFill(P, y, x - 1));
}

int	ParseMapChars(t_parser *P, int x, int y)
{
	if (P->map[y][x] != '1' && \
		P->map[y][x] != '0' && \
		P->map[y][x] != ' ' && \
		P->map[y][x] != 'N' && \
		P->map[y][x] != 'E' && \
		P->map[y][x] != 'W' && \
		P->map[y][x] != 'S')
			return (PrintErrors(INVMAPCHAR));
	if (P->map[y][x] == 'N' || \
		P->map[y][x] == 'E' || \
		P->map[y][x] == 'W' || \
		P->map[y][x] == 'S')
			init_player(P, x, y);
	//if (P->map[y][x] != '\n' || P->map[y][x] != '\0')
	//	P->map_height = y;
	return (RETURN_SUCCES);
}

int	ParseMap(t_parser *P)
{
	if (LoopThroughArr(P, &ParseMapChars) == RETURN_FAIL)
		return (RETURN_FAIL);
	if (P->player_counter == 0)
		return (PrintErrors(NOPLAY));
	if (P->player_counter > 1)
		return (PrintErrors(MULTPLAY));
	if (FloodFill(P, (int)P->Data->player_y, (int)P->Data->player_x) == false)
		return (PrintErrors(INVMAPWALL));
	if (CheckWallsEnclosed(P) == RETURN_FAIL)
		return (RETURN_FAIL);
	if (LoopThroughArr(P, InvalidVoids) == RETURN_FAIL)
		return (RETURN_FAIL);
	return (RETURN_SUCCES);
}

int	InvalidVoids(t_parser *P, int x, int y)
{
	int	width;

	if (!P->map[y])
		return (PrintErrors(INVMAPWALL));
	width = ft_strlen(P->map[y]);
	if (P->map[y][x] != '0')
		return (RETURN_SUCCES);
	if (y < P->map_height - 1 && P->map[y + 1][x] == ' ')
		return (PrintErrors(INVMAPWALL));
	if (y > 0 && P->map[y - 1][x] == ' ')
		return (PrintErrors(INVMAPWALL));
	if (x < width - 1 && P->map[y][x + 1] == ' ')
		return (PrintErrors(INVMAPWALL));
	if (x > 0 && P->map[y][x - 1] == ' ')
		return (PrintErrors(INVMAPWALL));
	return (RETURN_SUCCES);
}
