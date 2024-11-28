/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:50:49 by hmnasfa           #+#    #+#             */
/*   Updated: 2024/11/28 14:03:58 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*new_str;

	if (!s1 && !s2)
		return (NULL);
	if (s1)
		len1 = ft_strlen(s1);
	else
		len1 = 0;
	if (s2)
		len2 = ft_strlen(s2);
	else
		len2 = 0;
	new_str = (char *) malloc(len1 + len2 + 1);
	if (!new_str)
		return (NULL);
	if (s1)
		ft_strcpy(new_str, s1);
	if (s2)
		ft_strcpy(new_str + len1, s2);
	new_str[len1 + len2] = '\0';
	return (new_str);
}

static char	*extract_line(char **bank)
{
	char	*new_line_stop;
	char	*line;
	char	*leftover;
	size_t	sub_lenght;

	if (!*bank || !**bank)
		return (free(*bank), *bank = NULL, NULL);
	new_line_stop = ft_strchr(*bank, '\n');
	if (new_line_stop)
	{
		sub_lenght = new_line_stop - *bank + 1;
		line = ft_substr(*bank, 0, sub_lenght);
		leftover = ft_strdup(new_line_stop + 1);
		free(*bank);
		*bank = leftover;
	}
	else
	{
		line = ft_strdup(*bank);
		free(*bank);
		*bank = NULL;
	}
	return (line);
}

static int	check_read_bytes(int fd, char *tmp_buffer)
{
	ssize_t	read_bytes;

	read_bytes = read (fd, tmp_buffer, BUFFER_SIZE);
	if (read_bytes <= 0)
	{
		if (read_bytes < 0)
			return (-1);
		return (0);
	}
	tmp_buffer[read_bytes] = '\0';
	return (1);
}

static int	handle_read(int fd, char **bank, char *tmp_buffer)
{
	char	*tmp;
	int		res;

	while (!ft_strchr(*bank, '\n'))
	{
		res = check_read_bytes(fd, tmp_buffer);
		if (res <= 0)
			return (res);
		tmp = ft_strjoin(*bank, tmp_buffer);
		if (!tmp)
			return (-1);
		free (*bank);
		*bank = tmp;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*bank;
	char		*tmp_buffer;
	int			res;

	if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	if (!bank)
		bank = ft_strdup("");
	tmp_buffer = malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp_buffer)
		return (free(bank), NULL);
	res = handle_read(fd, &bank, tmp_buffer);
	free(tmp_buffer);
	if (res == -1 || (res == 0 && (!bank || !*bank)))
		return (free(bank), bank = NULL, NULL);
	return (extract_line(&bank));
}
