/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmunoz-p <pmunoz-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:13:21 by pmunoz-p          #+#    #+#             */
/*   Updated: 2024/10/09 12:55:49 by pmunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*clean_depot(char *depot)
{
	char	*new_depot;
	char	*p;
	int		len;

	p = ft_strchar(depot, '\n');
	if (!p)
	{
		new_depot = NULL;
		return (ft_free(&depot));
	}
	else
		len = (p - depot) + 1;
	if (!depot[len])
		return (ft_free(&depot));
	new_depot = ft_substr(depot, len, ft_strlen(depot) - len);
	ft_free(&depot);
	if (!new_depot)
		return (NULL);
	return (new_depot);
}

char	*new_line(char *depot)
{
	char	*line;
	char	*p;
	int		len;

	p = ft_strchar(depot, '\n');
	len = p - depot + 1;
	line = ft_substr(depot, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*readbuff(int fd, char *depot)
{
	int		to_read;
	char	*buffer;

	if (fd < 0)
		return (NULL);
	to_read = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&depot));
	buffer[0] = '\0';
	while (to_read > 0 && !ft_strchar(buffer, '\n'))
	{
		to_read = read (fd, buffer, BUFFER_SIZE);
		if (to_read > 0)
		{
			buffer[to_read] = '\0';
			depot = ft_strjoin(depot, buffer);
		}
	}
	free(buffer);
	if (to_read == -1)
		return (ft_free(&depot));
	return (depot);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*depot = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if ((depot && !ft_strchar(depot, '\n')) || !depot)
		depot = readbuff(fd, depot);
	if (!depot)
		return (NULL);
	line = new_line(depot);
	if (!line)
		return (ft_free(&depot));
	depot = clean_depot(depot);
	return (line);
}
