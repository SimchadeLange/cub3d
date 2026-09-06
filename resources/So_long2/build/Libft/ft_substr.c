/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:20:21 by side-lan          #+#    #+#             */
/*   Updated: 2025/06/02 20:45:00 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			counter;
	char			*substr;
	unsigned int	str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	counter = 0;
	if (start >= str_len)
		return (ft_strdup(""));
	if (start + len > str_len)
		substr = (char *)malloc((str_len - start) + 1);
	else
		substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	while (s[counter + start] != '\0' && counter < len)
	{
		substr[counter] = s[counter + start];
		counter++;
	}
	substr[counter] = '\0';
	return (substr);
}
