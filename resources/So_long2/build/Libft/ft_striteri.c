/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:19:42 by side-lan          #+#    #+#             */
/*   Updated: 2025/10/03 16:30:04 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	unsigned int	index;

	if (!str || !f)
		return ;
	index = 0;
	while (str[index])
	{
		f(index, &str[index]);
		index++;
	}
}
