/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaafkhar <kaafkhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 03:22:43 by kaafkhar          #+#    #+#             */
/*   Updated: 2024/01/21 19:57:17 by kaafkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read_line(int fd, char *s) 
{
    char *b;
    int i;

    b = malloc(BUFFER_SIZE + 1);
    if (!b)
        return (NULL);

    while ((i = read(fd, b, BUFFER_SIZE)) > 0) {
        b[i] = '\0';
        s = ft_strjoin(s, b);
        if (!s) {
            free(b);
            return NULL;
        }
        if (ft_strchr(s, '\n'))
            break;
    }

    free(b);
    return (i < 0 || !s) ? free(s), NULL : s;
}


char *ft_first_line(char *g)
{
    char *s;
    int i;

    i = 0;
    if (!g || !g[0])
        return (NULL);
    while (g[i] && g[i] != '\n')
        i++;
        if (g[i] == '\n')
            i++;
    s = malloc(i + 1);
    if (!s)
        return (NULL);
    i = 0;
    while (g[i] && g[i] != '\n')
    {
        s[i] = g[i];
        i++;
    }
    if (g[i] == '\n')
    {
        s[i] = '\n';
        i++;
    }
    s[i] = '\0';
    return (s);
}

char *ft_rest_line(char *g)
{
    char *s;
    int i;
    int j;

    i = 0;
    j = 0;
    while (g[i] && g[i] != '\n')
        i++;
    if (!g[i])
    {
        free(g);
        g = NULL;
        return (NULL);
    }
    s = malloc(ft_strlen(g) - i + 1);
    if (!s)
        return (NULL);
    i++;
    while (g[i])
    {
        s[j] = g[i];
        i++;
        j++;
    }
    s[j] = '\0';
    free(g);
    g = NULL;
    return (s);
}

char *get_next_line(int fd)
{
    static char *g;
    char *s;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    g = ft_read_line(fd, g);
    if (!g)
        return (NULL);
    s = ft_first_line(g);
    g = ft_rest_line(g);
    return (s);
}