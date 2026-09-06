/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-roo <ede-roo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:18:35 by ede-roo           #+#    #+#             */
/*   Updated: 2025/05/15 09:09:30 by ede-roo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			total_size;
	void			*ptr;
	unsigned char	*ptr2;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	ptr2 = (unsigned char *)ptr;
	while (total_size-- > 0)
		ptr2[total_size] = 0;
	return (ptr);
}
