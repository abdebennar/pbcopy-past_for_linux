#include "capt.h"

int cfd;


void	__attribute__((constructor))creat_file_and_check_space()
{
		cfd = open(FILE_N, O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (cfd == -1)
			dprintf(2,"%s\n", strerror(errno));
		// exit(1);  
}

int main()
{
	char *line;
	int		offset;

	while ((line = readline(NULL)) != NULL)
	{
		if (dprintf (cfd, "%s\n", line) == -1)
			perror("write");
		free(line);
	}
	exit(0);
}

void	__attribute__((destructor))close_and_clean()
{
	close(cfd);
}