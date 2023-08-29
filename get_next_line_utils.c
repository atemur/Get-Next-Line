/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemur <atemur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 02:38:39 by atemur            #+#    #+#             */
/*   Updated: 2023/08/29 22:06:40 by atemur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	n_control(char *str)
{
	int	i;

	i = 0;
	// if (!str) eklenebilir
	if(!str)
		return(1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*cpy;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	cpy = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	while (s1[++i])
		cpy[i] = s1[i];
	while (s2[j])
		cpy[i++] = s2[j++];
	free(s1);
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_updated_str(char *str)
{
	char	*mystring;
	int		i;

	i = 0;
	if(!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	mystring = malloc(sizeof(char) * i + 1);
	if (!mystring)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		mystring[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		mystring[i++] = '\n';
	mystring[i] = '\0';
	return (mystring);
}

char	*ft_last_str(char *str)
{
	int		i;
	int		len;
	char	*temp;

	len = 0;
	i = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (!*str)
	{
		free(str);
		return (NULL);
	}
	if (str[len] == '\n')
		len++;
	temp = (char *)malloc(sizeof(char) * (ft_strlen(str) - len + 1));
	if (!temp)
		return (NULL);
	while (str[len])
	{
		temp[i] = str[len];
		i++;
		len++;
	}
	temp[i] = '\0';
	free(str);
	return (temp);
}
