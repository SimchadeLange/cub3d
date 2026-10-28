#ifndef HEADER_PARSER_H
# define HEADER_PARSER_H

typedef enum e_returnval
{
	RETURN_SUCCES = 0,
	RETURN_FAIL,
}	t_returnval;

typedef enum e_error_type
{
	SUCCESS = 0,	// No Errors.
	MLXFAIL,		// MLX42 function has failed.
	LIBFTFAIL,		// Libft function has failed.
	MEMFAIL,		// Dynamic memory allocation has failed.
	INVFILE,		// The provided file was invalid or does not exist.
	INVELEM,		// Element has invalid type identifier.
	INVELEMNUM,		// Invalid number of elements in file
	INVCLR,			// Colour is invalid.
	INVTEXPATH,		// Texture path was invalid or does not exist.
	NOTEX,			// Texture is missing.
	NOMAP,			// Map is missing.
	INVMAPCHAR,		// Map has invalid character.
	INVMAPWALL,		// Map not closed/surrounded by walls.
	NOPLAY,			// Map has no player position.
	MULTPLAY,		// Map has multiple player positions.
	READFAIL,		// Reading the file failed.
	ARGINV,			//invalid amount of args
	ERRMAX,			// Error count
}	t_error_type;

typedef struct s_rgbvalues
{
	int			index;
	int			red;
	int			green;
	int			blue;
	int			alpha;
	uint32_t	color;
}	t_rgbvalues;

typedef struct s_parser
{
	bool		map_not_empty;
	int			map_start;
	int			map_height;
	int			file_height; 	//*
	int 		fd;				//*
	int			elements;		//*
	char		**file;			//*
	char		**map_copy;
	char		**map;
	int			max_width;
	int			player_counter;
	t_config	*Data;
}				t_parser;

//main
int		parse_main(char *argv[]);
int		CheckInput(t_config *data, t_parser *p_data, char *filename);

//map handling and floodfill
int		FindMap(t_parser *P);
int		ParseMapChars(t_parser *P, int x, int y);
int		ParseMap(t_parser *P);
int		InvalidVoids(t_parser *P, int x, int y);

//init and free structs
void	FreeParseStruct(t_parser *p_data);
void	FreeMainStruct(t_config *data);
void	free_structs(t_parser *p_data, t_config *data);
void	FreeArray(char **array, int height);

//check textpaths and colors
int		FillTextPaths(t_config *D, t_parser *P, char *line, t_directions type);
int		ParseLines(t_config *D, t_parser *P);
int		CheckValidElement(t_config *D, t_parser *P, char *line);
int		PutRGB(uint32_t *rgb, t_parser *P, char *line);

//check cub file
int		CopyFileToText(t_parser *p_data);
int		CheckNameValid(char *file_name, t_parser *p_data);
int		CountNewLines(char *line);

//array helpers
char	**CopyArray(char **old, int height);
char	**MakeArrayFromString(char *line, int height);
int		RemoveNewlines(t_parser *P);
int		LoopThroughArr(t_parser *P, int (*func)(t_parser *P, int x, int y));

//testfuncs
void	PrintArray(char **array, int height);
void	PrintStruct(t_config *D, t_parser *P);

//errors
int		PrintErrors(t_error_type type);

#endif