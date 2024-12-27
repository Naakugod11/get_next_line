/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgulec <dgulec@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:19:51 by dgulec            #+#    #+#             */
/*   Updated: 2024/12/20 19:26:15 by dgulec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*(s))
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*alloc;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + 1;
	alloc = (char *)malloc(len * sizeof(char));
	if (!alloc)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		alloc[i] = s1[i];
		i++;
	}
	alloc[i] = '\0';
	return (alloc);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	subs = (char *)malloc(sizeof(char) * (len +1));
	if (!subs)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*news;
	size_t	i;
	size_t	j;

	if (!s1)
		return (ft_strdup(s2));
	news = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!news)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		news[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		news[i + j] = s2[j];
		j++;
	}
	news [i + j] = '\0';
	return (news);
}
