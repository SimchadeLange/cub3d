#include "../header_parser.h"

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

char	**CopyArray(char **old, int start, int height)
{
	char	**new;
	int		index;

	index = 0;
	new = malloc(sizeof(char *) * (height + 1));
	if (!new)
		return (NULL);
	while (index < height)
	{
		new[index] = ft_strdup(old[index + start]);
		if (!new[index])
			return (FreeArray(new, index), NULL);
		index++;
	}
	new[index] = NULL;
	return (new);
}