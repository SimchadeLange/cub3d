#include "header.h"

static const char	*ErrorMessages(t_error_type type)
{
	const char	*errors[ERRMAX] = {
		"No Errors.",
		"MLX42 function has failed.",
		"Libft function has failed.",
		"Dynamic memory allocation has failed.",
		"The provided file was invalid / does not exist.",
		"Invalid element signifier",
		"Invalid number of elements in file",
		"Colour is invalid.",
		"Texture path is invalid. (png, xpm42)",
		"Texture is missing.",
		"Map is missing.",
		"Map has an invalid character.",
		"Map is not closed/surrounded by walls and/or invalid voids.",
		"Map has no player position.",
		"Map has multiple player positions.",
		"Reading the file failed",
		"Invalid amount of arguments",
	};
	return (errors[type]);
}

	int	PrintErrors(t_error_type type)
	{
		printf("Error\n%s\n", ErrorMessages(type));
		return (RETURN_FAIL);
	}