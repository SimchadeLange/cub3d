#ifndef HEADER_parser_H
# define HEADER_parser_H
#include "../header.h"


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

//main
int		parse_main(char *argv[]);




#endif