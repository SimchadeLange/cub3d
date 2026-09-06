/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-roo <ede-roo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:41:48 by ede-roo           #+#    #+#             */
/*   Updated: 2025/10/01 02:39:55 by ede-roo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

char	*ft_strchr(const char *s, int c);
char	*extract_line(char *leftover);
char	*ft_strjoin_and_free(char *leftover, char *buffer);
char	*ft_remove_extracted_line(char *leftover, char *line);
char	*read_and_store(char *buffer, char *leftover,
			ssize_t bytes_read, int fd);
char	*get_next_line(int fd);
char	*process_leftover(char *leftover, char *line);
size_t	ft_strlen_gnl(const char *str);

#endif