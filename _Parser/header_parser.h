#ifndef HEADER_parser_H
# define HEADER_parser_H

# include "../header.h"
# include "get_next_line/get_next_line.h"

typedef struct s_parser
{
	int		index;
	int		length;
	int		check;
	int 	fd;
	char	**text;
	char	**map_copy;
	char	**map;
	
}				t_parser;

//map handling and floodfill


//init and free structs
void	InitMainStruct(t_config *data);
void	InitParseStruct(t_parser *p_data);
void	FreeParseStruct(t_parser *p_data);
void	FreeMainStruct(t_config *data);
void	free_structs(t_parser *p_data, t_config *data);

//main
int		parse_main(char *argv[]);
bool	CheckInput(t_config *data, t_parser p_data, char *filename);

//check textpaths and colors
void	FillTextPaths(t_config *D, t_parser *P, enum directions type);
bool	FindTextPaths(t_config *D, t_parser *P);
char	*getline(t_parser *P);

//bool	PutRGB(t_config *D, t_parser *P, char type);

//check cub file
bool	CopyFileToText(t_parser *p_data);
bool	CheckNameValid(char *file_name, t_parser *p_data);


#endif