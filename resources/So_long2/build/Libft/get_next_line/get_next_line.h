/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:08:11 by side-lan          #+#    #+#             */
/*   Updated: 2025/10/06 16:15:33 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strchr_gnl(char *str, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);
int		str_search(char *str, char c);
char	*duplicate_str(char *s1);

#endif