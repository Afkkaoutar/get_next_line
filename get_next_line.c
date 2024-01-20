/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geet_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaafkhar <kaafkhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 03:22:43 by kaafkhar          #+#    #+#             */
/*   Updated: 2024/01/20 03:49:31 by kaafkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*check(char *str)
{
	char	*c;
	int		i;

	i = 0;
	if (!str || !(*str))
		return (NULL);
	while (str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	c = malloc (i + 1);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		c[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		c[i++] = '\n';
	c[i] = '\0';
	return (c);
}

char	*del(char *str)
{
	int		i;
	int		j;
	char	*c;

	i = 0;
	j = 0;
	while (str[i] != '\n')
		i++;
	if (ft_strlen(str) == i)
		return (free(str), NULL);
	c = malloc(ft_strlen(str) - i + 1);
	i++;
	while (str[i])
		c[j++] = str[i++];
	c[j] = 0;
	free (str);
	return (c);
}

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

char	*get_next_line(int fd)
{
	static char	*g;
	char		*s;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    g = ft_read_line(fd, s);
    if (!g)
        return (NULL);

    s = check(g);
    g = del(g);
        
  
}