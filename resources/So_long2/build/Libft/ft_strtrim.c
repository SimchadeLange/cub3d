/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:20:15 by side-lan          #+#    #+#             */
/*   Updated: 2025/05/29 21:08:14 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *str, const char *set)
{
	int		start;
	int		end;
	char	*new_str;

	if (!set || !str)
		return (NULL);
	start = 0;
	end = ft_strlen(str) - 1;
	while (str[start] != '\0' && ft_strchr(set, str[start]))
		start++;
	if (start == end)
		return (ft_strdup("0"));
	while (end >= start && ft_strchr(set, str[end]))
		end--;
	new_str = ft_substr(str, start, (end - start) + 1);
	return (new_str);
}
