#include "includes/header.h"

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
