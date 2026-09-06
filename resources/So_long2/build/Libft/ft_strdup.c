/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:19:37 by side-lan          #+#    #+#             */
/*   Updated: 2025/10/06 16:21:01 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	int		counter;
	char	*str;
	int		length;

	if (!s1)
		return (NULL);
	counter = 0;
	length = str_search(s1, '\0');
	str = malloc((length * sizeof(char)) + 1);
	if (!str)
		return (NULL);
	while (s1[counter] != '\0')
	{
		str[counter] = s1[counter];
		counter++;
	}
	str[counter] = '\0';
	return (str);
}
