#include "header_parser.h"


//check of t n file is en dat ie bestaat
bool	check_name_valid(char *file_name, t_parser *p_data)
{
	char	*end_of_str;
	int		length;
	int		index;

	index = 0;
	if (!file_name)
		return (printf("invalid file1\n"), false);
	length = ft_strlen(file_name);
	end_of_str = ft_substr(file_name, length - 4, 4);
	if (ft_strncmp(".cub", end_of_str, 4) != 0)
	{
		free(end_of_str);
		return (printf("invalid file2\n"), false);
	}
	free(end_of_str);
	p_data->fd = open(file_name, O_RDONLY);
	if (!p_data->fd)
		return (printf("invalid file3\n"), false);
	return (true);
}

//copy file to string
bool	copy_file_to_text(t_parser *p_data)
{
	char	*line;
	char	*tmp;

	p_data->text = "";
	line = get_next_line(p_data->fd);
	if (!line)
		return (printf("copy error1\n"), false);
	while (line != NULL)
	{
		p_data->text = ft_strjoin(p_data->text, line);
		printf("%s\n", p_data->text);
		if (p_data->text == NULL)
			return(printf("copy error2"), false);
		free(tmp);
		tmp = p_data->text;
		if (p_data->text == NULL)
			return(printf("copy error2"), false);
		free(line);
		line = get_next_line(p_data->fd);
	}
	free(line);
	return (true);
}
