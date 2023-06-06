#include <fcntl.h>  // open()
#include <stdio.h>

#include "get_next_line.h"

int main(void)
{
	int fd1, fd2, fd3, fd4;
	char *line;

	fd1 = open("fichier1", O_RDONLY);
	fd2 = open("fichier2", O_RDONLY);
	fd3 = open("fichier_vide", O_RDONLY);
	fd4 = open("fichier_tres_longue_ligne", O_RDONLY);
	line = get_next_line(fd1);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd1);
	}
	close(fd1);
	
	line = get_next_line(fd2);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd2);
	}
	close (fd2);

	line = get_next_line(fd3);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd3);
	}
	close (fd3);

	line = get_next_line(fd4);
	while (line)
	{
		printf("%s", line);
		free(line);
		get_next_line(fd4);
	}
	close (fd4);

	return (0);
}
