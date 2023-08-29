/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemur <atemur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 02:38:45 by atemur            #+#    #+#             */
/*   Updated: 2023/08/29 21:10:02 by atemur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>//denemek icin koyuldu pushlamadan once sil.
# include <fcntl.h>

char	*get_next_line(int fd);
char	*read_to_fd(int fd, char *str);
int	    n_control(char *str);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_updated_str(char *str);
char	*ft_last_str(char *str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10//opsiyonel
# endif
#endif