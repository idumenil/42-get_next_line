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
