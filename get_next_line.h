/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmunoz-p <pmunoz-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:55:51 by pmunoz-p          #+#    #+#             */
/*   Updated: 2024/10/09 12:39:42 by pmunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <string.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
char	*readbuff(int fd, char *depot);
char	*new_line(char *depot);
char	*ft_strchar(char *depot, int c);
char	*ft_free(char **str);
char	*ft_strjoin(char *depot, char *buf);
char	*ft_substr(char *depot, unsigned int start, size_t len);
size_t	ft_strlen(char *str);
char	*clean_depot(char *depot);

#endif
