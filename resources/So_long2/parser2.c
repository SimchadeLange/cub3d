/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:17:50 by side-lan          #+#    #+#             */
/*   Updated: 2025/11/26 16:07:36 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_valid_symbols(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] != 'E' && str[index] != 'C' && str[index] != 'P' \
&& str[index] != '1' && str[index] != '0' && str[index] != '\n')
			return (0);
		index++;
	}
	return (1);
}
