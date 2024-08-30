#include "capt.h"

int	cfd;

void	__attribute__((constructor))open_file()
{
	cfd = open(FILE_N, O_RDONLY);
	if (cfd == -1)
		exit(0);
}

int main()
{
	int	in =  dup(0);
	dup2(cfd, 0);
	char	*line;

	while ((line = readline(NULL)) != NULL)
	{
		dprintf(STDOUT_FILENO, "%s\n", line);
		free(line);
	}
	dup2(0, in);
	close(in);
}
void	__attribute__((destructor))clean()
{
	close(cfd);
	exit(0);
}