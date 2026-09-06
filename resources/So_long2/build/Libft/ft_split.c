/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:19:30 by side-lan          #+#    #+#             */
/*   Updated: 2025/06/02 21:14:12 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_exit(char **arr, size_t word_index);
static int	count_words(const char *str, char c);

static int	count_words(const char *str, char c)
{
	int	counter;
	int	index;
	int	reset;

	counter = 0;
	index = 0;
	reset = 0;
	while (str[index])
	{
		while (str[index] == c && str[index])
		{
			index++;
			reset = 0;
		}
		while (str[index] != c && str[index])
		{
			index++;
			if (reset == 0)
				counter++;
			reset = 1;
		}
	}
	return (counter);
}

char	**ft_split(const char *s, char c)
{
	size_t	index;
	int		word_index;
	char	**arr;
	size_t	start;

	index = 0;
	word_index = 0;
	if (!s)
		return (NULL);
	arr = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (word_index < count_words(s, c))
	{
		while (s[index] == c)
			index++;
		start = index;
		while (s[index] && s[index] != c)
			index++;
		arr[word_index] = ft_substr(s, start, index - start);
		if (!arr[word_index])
			return (free_exit(arr, word_index));
		arr[word_index++][index - start] = '\0';
	}
	return (arr[word_index] = NULL, arr);
}

static char	**free_exit(char **arr, size_t word_index)
{
	if (!arr[word_index])
	{
		while (word_index-- > 0)
			free(arr[word_index]);
		free(arr);
		return (NULL);
	}
	return (arr);
}
