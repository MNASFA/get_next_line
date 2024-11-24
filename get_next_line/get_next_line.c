/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:50:49 by hmnasfa           #+#    #+#             */
/*   Updated: 2024/11/24 12:31:03 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *check_eof(char **bank)
{
	char *line;

	if (!**bank || !*bank)
		return (NULL);
	line = ft_strdup(*bank);
	free (*bank);
	*bank = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	char *tmp_buffer;
	static char *bank;
	ssize_t read_bytes;
	char *tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp_buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp_buffer)
		return (NULL);
	while (!ft_strchr(bank, '\n'))
	{
		read_bytes = read(fd, tmp_buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			if (read_bytes == 0)
				check_eof(&bank);
			else 
				return (NULL);
		}
		tmp_buffer[read_bytes] = '\0';
		if (bank)
			tmp = ft_strjoin(bank, tmp_buffer);
		else
			tmp = ft_strdup(tmp_buffer);
	}
	
}