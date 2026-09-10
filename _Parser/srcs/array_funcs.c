#include "../header_parser.h"

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
		return (printf("malloc error\n"), NULL);
	while (height_index < height)
	{
		width = 0;
		while (line[start + width] != '\n' && line[start + width] != '\0')
			width++;
		if(line[start + width] == '\n')
			width++;
		array[height_index] = ft_substr(line, start, width);
		if (!array[height_index])
			return (FreeArray(array, height_index), NULL);
		height_index++;
		start = start + width;
	}
	array[height] = NULL;
	PrintArray(array, height);
	return (array);
}
