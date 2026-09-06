#ifndef HEADER_parser_H
# define HEADER_parser_H

# include "../header.h"
# include "get_next_line/get_next_line.h"

typedef struct s_parser
{
	int 	fd;
	char	*text;
	char	**map_copy;
	char	**map;
	
}				t_parser;

//init structs
void	init_main_struct(t_config *data);
void	init_parse_struct(t_parser *p_data);
void	free_pdata(t_parser *p_data);

//main
int		parse_main(char *argv[]);
bool	copy_file_to_text(t_parser *p_data);
bool	check_name_valid(char *file_name, t_parser *p_data);




#endif