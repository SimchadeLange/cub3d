/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:27:23 by side-lan          #+#    #+#             */
/*   Updated: 2025/11/25 15:17:29 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_program(t_bigstruct *info, char *error)
{
	if (info->map)
		free(info->map);
	if (info->copy)
		free(info->copy);
	if (info->mlx)
		mlx_terminate(info->mlx);
	write(2, error, ft_strlen(error));
	write(1, "\n", 1);
	exit(-1);
}
