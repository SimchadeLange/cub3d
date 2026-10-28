#include "includes/header.h"

int	main(int argc, char **argv)
{
	t_config	cfg;
	int			ret;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nusage: ./cub3D <map.cub>\n", 2);
		return (1);
	}
	if (parse_main(argv[1], &cfg))
		return (1);
	ret = run_game(&cfg);
	free_config(&cfg);
	return (ret);
}
