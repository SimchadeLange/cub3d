#ifndef HEADER_H
# define HEADER_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "Resources/libft/libft.h"
# include <math.h>
# include "header_structs.h"

/* parser contract (real parser or stub_parser.c) */
int		parse_cub(char *path, t_config *cfg);
void	free_config(t_config *cfg);

/* raycaster */
int		run_game(t_config *cfg);
void	destroy_game(t_game *game);
void	init_player_raycast(t_game *g);
void	game_loop(void *param);
void	render_frame(t_game *g);
void	draw_column(t_game *g, t_ray *ray, int x);

/*load config*/
int	parse_cub(char *path, t_config *cfg);

//parser
int		parse_main(char *argv, t_config *data);
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