/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:20:05 by side-lan          #+#    #+#             */
/*   Updated: 2025/05/29 19:47:47 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	counter;
	size_t	index;

	counter = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (counter < len && haystack[counter] != '\0')
	{
		index = 0;
		while ((counter + index) < len && \
		haystack[counter + index] == needle[index] && needle[index] != '\0')
		{
			if (needle[index + 1] == '\0')
				return ((char *)(haystack + counter));
			index++;
		}
		counter++;
	}
	return (NULL);
}
