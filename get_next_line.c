/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idumenil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:58:18 by idumenil          #+#    #+#             */
/*   Updated: 2023/05/03 15:54:14 by idumenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *stash)
{
	char	*temp;

	temp = ft_strjoin(buffer, stash);
	free(buffer);
	free(stash);
	return (temp);
}

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	ft_read_file(int fd, char **stash)
{
	char	*buffer;
	ssize_t	nbytes_read;

	if (!(*stash))
		*stash = ft_calloc(1, sizeof(char));
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	nbytes_read = 1;
    while (nbytes_read > 0)
    {
        nbytes_read = read(fd, buffer, BUFFER_SIZE);
        if (nbytes_read == -1)
            {
                free(buffer);
                return (-1); // Error reading file
            }
	buffer[nbytes_read] = '\0'; // Add null terminator
	*stash = ft_free(buffer, *stash);
	if (ft_strchr(*stash, '\n'))
		break;
    }
    free(buffer);
    if (nbytes_read == 0 && !(*stash)[0])
    {
        free(*stash);
        *stash = NULL;
    }
    return (nbytes_read);
}

char	*get_next_line(int fd)
{
	static char *stash;
	char 		*line;
	int 	read_result;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL); // Invalid file descriptor or buffer size
	read_result = ft_read_file(fd, &stash);
	if (read_result == -1)
		return (NULL); // Error reading file

	if (read_result == 0 && !stash)
		return (NULL); // End of file
	line = ft_line(stash);
	stash = ft_next(stash);
	return (line);
}

#include <fcntl.h>  // open()
#include <stdio.h>
int main(void)
{
	int fd1;
	char *line;
	
	fd1 = open("fichier1", O_RDONLY);
	line = get_next_line(fd1);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd1);
	}
	close(fd1);

	return (0);
}