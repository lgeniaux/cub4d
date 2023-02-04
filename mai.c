#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

char *get_next_line(int fd);

int main(int argc, char *argv[])
{
	int fd = open(argv[1], O_RDONLY);
	char *line;

	while (1)
	{
		line = get_next_line(fd);
		printf("Line: %s\n", line);
		if (!line)
			break ;
	}
}
