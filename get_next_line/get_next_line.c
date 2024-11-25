/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:50:49 by hmnasfa           #+#    #+#             */
/*   Updated: 2024/11/25 16:46:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *extract_line(char **bank)
{
	char *new_line_stop;
	char *line;
	char *leftover;
	size_t sub_lenght;

	if (!bank || !*bank || !**bank)
		return (NULL);
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
	return(line);
}

char	*get_next_line(int fd)
{
	char *tmp_buffer;
	static char *bank;
	ssize_t read_bytes;
	char *tmp;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!bank)
    	bank = ft_strdup("");
	tmp_buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp_buffer)
		return (NULL);
	while (!ft_strchr(bank, '\n'))
	{
		read_bytes = read(fd, tmp_buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			if (read_bytes < 0)
			{
				free(tmp_buffer);
				return (NULL);
			}
			if (read_bytes == 0)
				break;
		}
		tmp_buffer[read_bytes] = '\0';
		tmp = ft_strjoin(bank, tmp_buffer);
		if (!tmp)
		{
			free(tmp_buffer);
			return(NULL);
		}
		free (bank);
		bank = tmp;
	}
	free(tmp_buffer);
	return(extract_line(&bank));
}
#include <fcntl.h>
int main(void)
{
	
	int fd = open("test.txt" , O_RDONLY);
	if (fd == -1)
		return (1);
	
	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s" , line);
		free(line);
	}
	return(0);
}