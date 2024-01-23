/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaafkhar <kaafkhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:08:55 by kaafkhar          #+#    #+#             */
/*   Updated: 2024/01/23 21:03:27 by kaafkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *s)
{
	char	*b;
	int		i;

	i = 1;
	b = malloc (BUFFER_SIZE + 1);
	if (!b)
		return (NULL);
	while (i && ft_strchr(s, '\n') == 0)
	{
		i = read(fd, b, BUFFER_SIZE);
		if (i < 0)
			return (free(b), free(s), NULL);
		b[i] = '\0';
		s = ft_strjoin(s, b);
	}
	free (b);
	return (s);
}

char	*first_line(char *str)
{
	char	*s;
	int		i;

	i = 0;
	if (!str || !(*str))
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	s = malloc (i + 1);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		s[i++] = '\n';
	s[i] = '\0';
	return (s);
}

char	*rest_line(char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (ft_strlen(str) == i)
		return (free(str), NULL);
	s = malloc(ft_strlen(str) - i + 1);
	i++;
	while (str[i])
		s[j++] = str[i++];
	s[j] = 0;
	free (str);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*g;
	char		*s;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	g = ft_read_line(fd, g);
	if (!g)
		return (NULL);
	s = first_line(g);
	g = rest_line(g);
	return (s);
}
