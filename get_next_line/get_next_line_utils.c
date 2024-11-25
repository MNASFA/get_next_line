/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:44:02 by hmnasfa           #+#    #+#             */
/*   Updated: 2024/11/25 17:11:54 by marvin           ###   ########.fr       */
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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*buffer_dest;
	unsigned char	*buffer_src;

	if (dest == src)
		return (dest);
	buffer_dest = (unsigned char *) dest;
	buffer_src = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		buffer_dest[i] = buffer_src[i];
		i++;
	}
	return (dest);
}

char *ft_strjoin(const char *s1, const char *s2)
{
    size_t len1;
    size_t len2;
    char *result;

	if (s1)
		len1 = ft_strlen(s1);
	else
		len1 = 0;
	if (s2)
		len2 = ft_strlen(s2);
	else
		len2 = 0;
    result = (char *)malloc(len1 + len2 + 1);
    if (!result)
        return (NULL);
    if (s1)
        ft_memcpy(result, s1, len1);
    if (s2)
        ft_memcpy(result + len1, s2, len2);
    result[len1 + len2] = '\0';

    return result;
}
