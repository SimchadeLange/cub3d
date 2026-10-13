#include "header_raycast.h"

int	main(int argc, char **argv)
{
	t_config	cfg;

	if (argc != 2 || parse_cub(argv[1], &cfg))
		return (1);
	run_game(&cfg);
	free_config(&cfg);      /* main allocated it, main frees it */
	return (0);
}
