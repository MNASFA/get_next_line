/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:44:02 by hmnasfa           #+#    #+#             */
/*   Updated: 2024/11/25 13:26:35 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	d;

	i = 0;
	d = (char) c;
	while (s[i] != '\0')
	{
		if (s[i] == d)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == d)
		return ((char *) &s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	lenght;
	int		i;

	lenght = ft_strlen(s);
	i = 0;
	ptr = (char *) malloc((lenght + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	lenght;
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	lenght = ft_strlen(s);
	if (lenght <= start)
		return (ft_strdup(""));
	if (lenght < start + len)
		len = lenght - start;
	ptr = (char *) malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static void	ft_joined(char *new, char const *s1, char const *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		new[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		new[j] = s2[i];
		i++;
		j++;
	}
	new[j] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*new;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	total_len = ft_strlen(s1) + ft_strlen(s2);
	new = (char *) malloc(total_len * sizeof(char));
	if (!new)
		return (NULL);
	ft_joined (new, s1, s2);
	return (new);
}
