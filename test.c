#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

static char *extract_line(char **storage)
{
    char *line;
    char *newline_pos;
    char *remaining;

    newline_pos = ft_strchr(*storage, '\n');
    if (!newline_pos)
        return (NULL);
    line = ft_substr(*storage, 0, newline_pos - *storage + 1); // Include '\n'
    remaining = ft_strdup(newline_pos + 1); // Copy after '\n'
    free(*storage);
    *storage = remaining;
    return (line);
}

static char *finalize(char **storage)
{
    char *line;

    if (!*storage || !**storage) // Empty storage or nothing left
    {
        free(*storage);
        *storage = NULL;
        return (NULL);
    }
    line = ft_strdup(*storage); // Final leftover as line
    free(*storage);
    *storage = NULL;
    return (line);
}

char *get_next_line(int fd)
{
    static char *storage;
    char buffer[BUFFER_SIZE + 1];
    ssize_t bytes_read;
    char *temp;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while (!ft_strchr(storage, '\n'))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0) // Error or EOF
            return (bytes_read == 0 ? finalize(&storage) : NULL);
        buffer[bytes_read] = '\0'; // Null-terminate buffer
        temp = storage ? ft_strjoin(storage, buffer) : ft_strdup(buffer);
        free(storage);
        storage = temp;
    }
    return (extract_line(&storage));
}

