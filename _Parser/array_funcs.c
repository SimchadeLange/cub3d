#include "includes/header.h"

//behoud alle newlines die in de file zate
char	**MakeArrayFromString(char *line, int height)
{
	int		height_index;
	char	**array;
	int		width;
	int		start;

	start = 0;
	height_index = 0;
	array = malloc(sizeof(char *) * (height + 1));
	if (!array)
		return (PrintErrors(MEMFAIL), NULL);
	while (height_index < height)
	{
		width = 0;
		while (line[start + width] != '\0')
        {
        	    if (line[start + width] == '\n')
        	    {
        	        width++;
        	        break ;
        	    }
        	    width++;
    	}
		array[height_index] = ft_substr(line, start, width);
		if (!array[height_index])
			return (FreeArray(array, height_index), NULL);
		height_index++;
		start = start + width;
	}
	array[height_index] = NULL;
	return (array);
}

char	**CopyArray(char **old, int height)
{
	char	**new;
	int		index;

	index = 0;
	new = malloc(sizeof(char *) * (height + 1));
	if (!new)
		return (NULL);
	while (index < height)
	{
		new[index] = ft_strdup(old[index]);
		if (!new[index])
			return (FreeArray(new, index), NULL);
		index++;
	}
	new[index] = NULL;
	return (new);
}

int	RemoveNewlines(t_parser *P)
{
	char	*newline;
	int		y;

	y = 0;
	newline = NULL;
	while (y < P->map_height)
	{
		if ((newline = ft_strchr(P->map[y], '\n')) != NULL)
			*newline = ' ';
		y++;
	}
	return (RETURN_SUCCES);
}

int	LoopThroughArr(t_parser *P, int (*func)(t_parser *P, int x, int y))
{
	int	x;
	int	y;
	int	width;

	y = 0;
	while (y < P->map_height)
	{
		x = 0;
		width = ft_strlen(P->map[y]);
		while (x < width)
		{
			if (func(P, x, y) == RETURN_FAIL)
				return  (RETURN_FAIL);
			x++;
		}
		y++;
	}
	return (RETURN_SUCCES);
}