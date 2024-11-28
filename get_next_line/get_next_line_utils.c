/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:44:02 by hmnasfa           #+#    #+#             */
/*   Updated: 2024/11/27 15:43:56 by hmnasfa          ###   ########.fr       */
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

	if (!s)
		return (NULL);
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

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
