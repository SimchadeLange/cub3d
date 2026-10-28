/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-roo <ede-roo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:49:08 by ede-roo           #+#    #+#             */
/*   Updated: 2025/05/07 23:14:54 by ede-roo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	lenght;
	char	*ptr;

	i = 0;
	lenght = 0;
	while (s[lenght] != '\0')
		lenght++;
	ptr = (char *)malloc((lenght + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (i < lenght)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
