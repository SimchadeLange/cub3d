
#include "header_raycast.h"

static char	**stub_map(void)
/* Builds the hardcoded map as a NULL-terminated char** on the HEAP.
** Heap, not just the literals, because free_config must be able to free
** it exactly like the real parser's map — same ownership rules. */
{
	static const char	*rows[] = {
		"1111111111",
		"1000000001",
		"1011000101",
		"1000000001",
		"1000000001",
		"1000000111",
		"1000001",
		"1111111",
		NULL};
	/* The map itself. Deliberately JAGGED (rows 7 and 8 are shorter) —
	** cub3D maps are not rectangles, and if your raycaster only ever sees
	** rectangular maps you'll write map[y][x] without a length check and
	** segfault at evaluation. NULL at the end marks the end, like argv.
	** Note there's no N in it — see parse_cub below for why. */
	char				**map;
	int					i;

	i = 0;
	while (rows[i])
		i++;
	/* Count the rows (i ends at 8) so we know how much to allocate. */
	map = malloc(sizeof(char *) * (i + 1));
	/* One pointer per row + 1 for the terminating NULL. */
	if (!map)
		return (NULL);
	map[i] = NULL;
	/* Set the terminator first, so if a strdup fails halfway, the partial
	** array is still NULL-terminated and free_config can walk it safely. */
	while (--i >= 0)
	{
		map[i] = ft_strdup(rows[i]);
		/* Copy each literal to the heap. --i >= 0 walks 7,6,...,0. */
		if (!map[i])
			return (map);
		/* On malloc failure return the half-built map anyway; parse_cub
		** can't easily tell, but free_config(cfg) in the error path will
		** clean whatever exists. (A stub may be this lax. The REAL parser
		** must handle this properly — person A's problem.) */
	}
	return (map);
}

int	parse_cub(char *path, t_config *cfg)
/* Same prototype as person A's real one: fills cfg, returns 0 on success,
** 1 on error. The stub ignores the path (cast to void to silence
** -Wunused-parameter, which -Werror turns fatal). */
{
	(void)path;
	ft_bzero(cfg, sizeof(t_config));
	/* Zero everything first so free_config never sees garbage pointers,
	** even if we bail out halfway through. Same trick as in run_game. */
	cfg->tex_path[0] = ft_strdup("textures/north.png");
	/* Index order is the contract from your shared header: 0=NO, 1=SO,
	** 2=WE, 3=EA. strdup'd (not literals) because free_config will
	** free() them — you can't free a string literal. */
	cfg->tex_path[1] = ft_strdup("textures/south.png");
	cfg->tex_path[2] = ft_strdup("textures/west.png");
	cfg->tex_path[3] = ft_strdup("textures/east.png");
	cfg->floor_rgb = (220 << 24) | (100 << 16) | (50 << 8) | 0xFF;
	/* "F 220,100,50" packed as 0xRRGGBBAA, exactly what the real parser's
	** PutRGB produces and what mlx_put_pixel expects: R<<24 G<<16 B<<8 A. */
	cfg->ceil_rgb = (30 << 24) | (30 << 16) | (60 << 8) | 0xFF;
	/* "C 30,30,60" -> 0x1E1E3CFF, a dark blue night sky. */
	cfg->map = stub_map();
	if (!cfg->map || !cfg->tex_path[0] || !cfg->tex_path[1]
		|| !cfg->tex_path[2] || !cfg->tex_path[3])
		return (free_config(cfg), 1);
	/* If ANY allocation failed: free whatever succeeded, return 1 like
	** the real parser would. (comma operator: runs free_config, then the
	** expression's value is 1 — a compact Norm-friendly idiom.) */
	cfg->map_height = 8;
	cfg->player_x = 5.5;
	/* Player starts in tile column 5 (0-based), and .5 puts them in the
	** CENTER of the tile, not on its corner. The real parser does the
	** same: tile (5,3) -> position (5.5, 3.5). */
	cfg->player_y = 3.5;
	cfg->player_dir = NORTH;
	/* In the map above, row 3 is "1000000001" — position (5,3) is a '0',
	** not an 'N'. The stub already "consumed" the player letter: real
	** parsers usually replace the N/S/E/W with '0' after recording it.
	** IMPORTANT: agree with person A on whether the letter is replaced!
	** If they leave it in, your walkable-check must accept N/S/E/W as
	** floor (readme_3 does, to be safe either way). */
	return (0);
}

void	free_config(t_config *cfg)
/* This one is REAL, not a stub — keep it after the merge (or agree that
** person A ships it; either way ONE of you owns it). Frees everything
** parse_cub allocated. Safe to call on a half-filled config because
** everything was bzero'd first and free(NULL) is legal C. */
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(cfg->tex_path[i]);
		/* free(NULL) does nothing, so no if needed. */
		cfg->tex_path[i] = NULL;
		/* NULL it so calling free_config twice can't double-free. */
		i++;
	}
	i = 0;
	if (cfg->map)
	{
		while (cfg->map[i])
			free(cfg->map[i++]);
		/* Free each row until the NULL terminator... */
		free(cfg->map);
		/* ...then the array of pointers itself. Always this order:
		** rows first, spine last (after freeing the spine you may not
		** touch it anymore). */
	}
	cfg->map = NULL;
}
