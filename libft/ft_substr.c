/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-roo <ede-roo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:55:02 by ede-roo           #+#    #+#             */
/*   Updated: 2025/05/07 23:15:30 by ede-roo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substr;
	size_t			max_len;

	max_len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
	{
		substr = malloc(sizeof(char));
		if (substr != NULL)
			substr[0] = '\0';
		return (substr);
	}
	if (len > max_len)
		len = max_len;
	substr = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (substr == NULL)
		return (NULL);
	while (i < len && s[i + start] != '\0')
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
