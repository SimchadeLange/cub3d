#ifndef HEADER_PARSER_H
# define HEADER_PARSER_H

# include "../header.h"
# include "get_next_line/get_next_line.h"

typedef struct s_parser
{
	int		map_height;
	int		file_height; 	//*
	int 	fd;				//*
	int		elements;		//*
	char	**file;			//*
	char	**map_copy;
	char	**map;
}				t_parser;

//map handling and floodfill


//init and free structs
void	FreeParseStruct(t_parser *p_data);
void	FreeMainStruct(t_config *data);
void	free_structs(t_parser *p_data, t_config *data);
void	FreeArray(char **array, int height);

//main
int		parse_main(char *argv[]);
bool	CheckInput(t_config *data, t_parser *p_data, char *filename);

//check textpaths and colors
void	FillTextPaths(t_config *D, t_parser *P, char *line, int type);
bool	ParseLines(t_config *D, t_parser *P);
bool	CheckValidElement(t_config *D, t_parser *P, char *line);
bool	PutRGB(t_config *D, t_parser *P, char type);

//bool	PutRGB(t_config *D, t_parser *P, char type);

//check cub file
bool	CopyFileToText(t_parser *p_data);
bool	CheckNameValid(char *file_name, t_parser *p_data);
int		CountNewLines(char *line);
char	**MakeArrayFromString(char *line, int height);

//testfuncs
void	PrintArray(char **array, int height);

#endif