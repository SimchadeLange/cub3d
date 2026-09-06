/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-roo <ede-roo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:25:45 by ede-roo           #+#    #+#             */
/*   Updated: 2025/05/07 23:15:13 by ede-roo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	i = ft_strlen(s);
	j = 0;
	str = malloc (sizeof (char) * (i + 1));
	if (!str)
		return (NULL);
	while (j < i)
	{
		str[j] = f(j, s[j]);
		j++;
	}
	str[j] = '\0';
	return (str);
}
