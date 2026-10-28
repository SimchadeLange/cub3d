/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_management.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-roo <ede-roo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:07:06 by ede-roo           #+#    #+#             */
/*   Updated: 2025/05/20 15:12:32 by ede-roo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_buffer_type	*ft_global_buffer(void)
{
	static t_buffer_type	buffer = {NULL, 0, 0};

	return (&buffer);
}

void	ft_buffer_initialize(t_buffer_type *buffer)
{
	if (buffer -> data == NULL)
	{
		buffer -> data = malloc(1024);
		if (!buffer -> data)
			return ;
		buffer -> size = 0;
		buffer -> capacity = 1024;
	}
}

void	ft_buffer_filling(char c)
{
	t_buffer_type	*buffer;
	int				new_capacity;
	char			*new_data;
	int				i;

	buffer = ft_global_buffer();
	ft_buffer_initialize(buffer);
	i = 0;
	if (buffer -> size == buffer -> capacity)
	{
		new_capacity = buffer -> capacity * 2;
		new_data = malloc(new_capacity);
		if (!new_data)
			return ;
		while (i < buffer -> size)
		{
			new_data[i] = buffer -> data[i];
			i++;
		}
		free(buffer -> data);
		buffer -> data = new_data;
		buffer -> capacity = new_capacity;
	}
	buffer -> data[buffer -> size] = c;
	buffer -> size++;
}

void	ft_buffer_write_flush(void)
{
	t_buffer_type	*buffer;

	buffer = ft_global_buffer();
	if (buffer -> data != NULL && buffer -> size > 0)
	{
		write(1, buffer -> data, buffer -> size);
	}
	if (buffer -> data != NULL)
	{
		free(buffer -> data);
		buffer -> data = NULL;
		buffer -> size = 0;
		buffer -> capacity = 0;
	}
}

int	ft_buffer_write_str(char *str)
{
	int		i;
	int		j;
	char	*null_str;

	j = 0;
	i = 0;
	null_str = "(null)";
	if (!str)
	{
		while (null_str[j])
		{
			ft_buffer_filling(null_str[j]);
			j++;
		}
		return (6);
	}
	while (str[i] != '\0')
		ft_buffer_filling(str[i++]);
	return (i);
}
