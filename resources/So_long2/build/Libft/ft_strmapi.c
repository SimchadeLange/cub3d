/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:19:56 by side-lan          #+#    #+#             */
/*   Updated: 2025/05/29 20:38:54 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	int		counter;
	char	*new_str;

	if (!str || !f)
		return (0);
	new_str = malloc(ft_strlen(str) + 1);
	if (!new_str)
		return (NULL);
	counter = 0;
	while (str[counter] != '\0')
	{
		new_str[counter] = f(counter, str[counter]);
		counter++;
	}
	new_str[counter] = '\0';
	return (new_str);
}
