/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-roo <ede-roo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 18:12:11 by ede-roo           #+#    #+#             */
/*   Updated: 2026/10/28 18:27:32 by ede-roo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	strip_newlines(t_config *cfg)
{
	char	*nl;
	int		i;

	i = 0;
	while (i < 4)
	{
		nl = ft_strchr(cfg->tex_path[i], '\n');
		if (nl)
			*nl = '\0';
		i++;
	}
}
int	parse_cub(char *path, t_config *cfg)
{
	t_parser	p;

	ft_bzero(&p, sizeof(p));
	ft_bzero(cfg, sizeof(*cfg));
	p.Data = cfg;
	if (CheckInput(cfg, &p, path) == RETURN_FAIL)
		return (free_structs(&p, cfg), RETURN_FAIL);
	strip_newlines(cfg);
	cfg->map = p.map;
	cfg->map_height = p.map_height;
	p.map = NULL;
	FreeParseStruct(&p);
	return (RETURN_SUCCES);
}
