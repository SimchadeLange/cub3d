#include "header.h"
#include "_Parser/header_parser.h"

int	main(int argc, char *argv[])
{
	int		returnval;

	if (argc != 2)
		return (PrintErrors(ARGINV));
	returnval = parse_main(argv);
	printf("returnval = %d\n", returnval);
	return (0);
}
