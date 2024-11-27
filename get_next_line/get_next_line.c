/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:50:49 by hmnasfa           #+#    #+#             */
/*   Updated: 2024/11/27 15:25:46 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int	ft_help(int fd, char *tmp_buffer)
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

char	*get_next_line(int fd)
{
	static char	*bank;
	char		*tmp_buffer;
	char		*tmp;
	int res;

	if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	if (!bank)
		bank = ft_strdup("");
	tmp_buffer = (char *) malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp_buffer)
		return (free(bank), NULL);
	while (!ft_strchr(bank, '\n'))
	{
		res = ft_help(fd , tmp_buffer);
		if ((res = ft_help(fd , tmp_buffer)) == -1)
			return(free(tmp_buffer), free(bank), bank = NULL, NULL);
		else if ((res = ft_help(fd , tmp_buffer)) == 0)
			break;
		tmp = ft_strjoin(bank, tmp_buffer);
		if (!tmp)
			return (free(tmp_buffer), free(bank), bank = NULL, NULL);
		free (bank);
		bank = tmp;
	}
	return (free(tmp_buffer) , extract_line(&bank));
}
