/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemur <atemur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 02:38:43 by atemur            #+#    #+#             */
/*   Updated: 2023/09/17 14:16:34 by atemur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_to_fd(int fd, char *str)
{
	char	*buffer;
	int		rd_bytes;

	rd_bytes = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (n_control(str) && rd_bytes != 0)
	{
		rd_bytes = read(fd, buffer, BUFFER_SIZE);
		if (rd_bytes < 0)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[rd_bytes] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*newstr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_to_fd(fd, str);
	if (!str)
		return (0);
	newstr = ft_updated_str(str);
	str = ft_last_str(str);
	return (newstr);
}
