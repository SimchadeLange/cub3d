#include "header_parser.h"

int	main(int argc, char *argv[])
{
	argc = 0;
	printf("returnval = %c\n", parse_main(argv));
	return (0);
}

int	parse_main(char *argv[])
{
	t_parser p_data;
	t_config data;

	init_parse_struct(&p_data);
	init_main_struct(&data);
	p_data.fd = open(argv[1], O_RDONLY);
	if (!p_data.fd)
		return (0);
	if(copy_file_to_text(&p_data) == false)
		return (1);
	printf("%s\n", p_data.text);
	return(0);
}

//copy file to string
bool	copy_file_to_text(t_parser *p_data)
{
	char	*line;

	line = get_next_line(p_data->fd);
	if (!line)
		return (printf("error\n"), false);
	while (line != NULL)
	{
		p_data->text = ft_strjoin(p_data->text, line);
		if (p_data->text == NULL)
			return(printf("error"), false);
		line = get_next_line(p_data->fd);
	}
	return (true);
}

void	init_main_struct(t_config *data)
{
	data->tex_path[0] = NULL;
	data->tex_path[1] = NULL;
	data->tex_path[2] = NULL;
	data->tex_path[3] = NULL;
	data->floor_rgb = 0;
	data->ceil_rgb = 0;
	data->map = NULL;
	data->map_height = 0;
	data->player_x = 0;
	data->player_y = 0;
	data->player_dir = NORTH;
}

void	init_parse_struct(t_parser *p_data)
{
	p_data->fd = 0;
	p_data->map_copy = NULL;
	p_data->map = NULL;
	p_data->text = NULL;
}