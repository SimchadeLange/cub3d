/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:19:48 by side-lan          #+#    #+#             */
/*   Updated: 2025/05/29 20:38:15 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		first_len;
	int		sec_len;
	char	*new_str;
	int		counter;

	first_len = ft_strlen(s1);
	sec_len = ft_strlen(s2);
	new_str = malloc((first_len + sec_len) + 1);
	if (!new_str)
		return (NULL);
	counter = 0;
	while (s1[counter] != '\0')
	{
		new_str[counter] = s1[counter];
		counter++;
	}
	counter = 0;
	while (s2[counter] != '\0')
	{
		new_str[counter + first_len] = s2[counter];
		counter++;
	}
	new_str[counter + first_len] = '\0';
	return (new_str);
}
