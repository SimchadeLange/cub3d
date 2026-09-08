#include "../header_parser.h"

//check of t n file is en dat ie bestaat
bool	CheckNameValid(char *file_name, t_parser *p_data)
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
	printf("%d\n", p_data->check++);
	free(end_of_str);
	p_data->fd = open(file_name, O_RDONLY);
	if (!p_data->fd)
		return (printf("invalid file3\n"), false);
	return (true);
}

//copy file to string
bool	CopyFileToText(t_parser *p_data)
{
	char	*line;
	char	*tmp;

	p_data->text = "";
	tmp = ft_strdup("");
	line = get_next_line(p_data->fd);
	if (!line)
	{
		p_data->text = NULL;
		return (printf("copy error1\n"), false);
	}
	while (line != NULL)
	{
		p_data->text = ft_strjoin(p_data->text, line);
		free(tmp);
		tmp = p_data->text;
		if (p_data->text == NULL)
			return(printf("copy error2"), false);
		free(line);
		line = get_next_line(p_data->fd);
	}
	//free(line);
	return (true);
}

//loopt door de text en vind de paths van alle directies als ze er niet allemaal zijn geeft een error
bool	FindTextPaths(t_config *D, t_parser *P)
{
	int index;

	index = 0;
	P->length = ft_strlen(P->text);
	while (P->index < P->length)
	{
		P->index++;
		if (P->text[P->index - 1] == 'N' && P->text[P->index] == 'O')
			FillTextPaths(D, P, NORTH);
		else if (P->text[P->index - 1] == 'S' && P->text[P->index] == 'O')
			FillTextPaths(D, P, SOUTH);
		else if (P->text[P->index - 1] == 'W' && P->text[P->index] == 'E')
			FillTextPaths(D, P, WEST);
		else if (P->text[P->index - 1] == 'E' && P->text[P->index] == 'A')
			FillTextPaths(D, P, EAST);
		else  if(P->text[P->index - 1] == 'F' && P->text[P->index] == ' ')
			PutRGB(D, P, 'F');
		else  if(P->text[P->index - 1] == 'C' && P->text[P->index] == ' ')
			PutRGB(D, P, 'C');
		if (D->tex_path[0] != NULL && D->tex_path[1] != NULL && D->tex_path[2] != NULL && D->tex_path[3] != NULL)
			return (true);
	}
	return (false);
}

//char	*getline(t_parser *P)
//{
//	char	*line;
//	int		end;

//	end = 0;
//	while (P->text[end + P->index] != '\n')
//		end++;
//	line = ft_substr(P->text, P->index, end);
//	if (!line)
//		return
//}

//pakt de path tussen vanaf de punt tot de eerste spatie/newline
void	FillTextPaths(t_config *D, t_parser *P, int type)
{
	int		end;
	char	*check;

	while (P->text[P->index] != '.')
		P->index++;
	end = P->index;
	while (P->text[end] != ' ' && P->text[end] != '\n')
		end++;
	check = ft_substr(P->text, P->index, end - P->index);
	if (!check)
	{
		printf("substr error\n");
		return ;
	}
	D->tex_path[type] = check;
	P->index = end;
}

//wat wille we hier checke?
//bool	CheckTextPathValid(t_config *data, t_parser *p_data)
//{

//}

//vind de rgb van de vloer en t plafond
//bool	PutRGB(t_config *D, t_parser *P, char type)
//{
//	int	end;

//	if (type == 'F')
//		D->floor_rgb = 
//	if (type == 'C')
//}