#include "../header_parser.h"

int	FindMap(t_parser *P)
{
	int	index;

	PrintArray(P->file, P->file_height);
	index = 0;
	while ((!ft_strncmp(P->file[index], "NO ", 3) || !ft_strncmp(P->file[index], "WE ", 3) \
		 || !ft_strncmp(P->file[index], "SO ", 3) || !ft_strncmp(P->file[index], "EA ", 3) \
		 || !ft_strncmp(P->file[index], "F ", 2) || !ft_strncmp(P->file[index], "C ", 2) \
		 || P->file[index][0] == '\n') && index < P->file_height)
			index++;
	PrintArray(P->file + index, P->file_height - index);
	P->map_start = index;
	return (RETURN_SUCCES);	
}