#include "header_parser.h"

int	main(int argc, char *argv[])
{
	argc = 0;
	printf("returnval = %d\n", parse_main(argv));
	return (0);
}

int	parse_main(char *argv[])
{
	t_parser p_data;
	t_config data;

	init_parse_struct(&p_data);
	init_main_struct(&data);
	if (check_name_valid(argv[1], &p_data) == false)
		return (free_pdata(&p_data), 1);
	if (copy_file_to_text(&p_data) == false)
		return (free_pdata(&p_data), 1);
	printf("%s\n", p_data.text);
	free_pdata(&p_data);
	return(0);
}
