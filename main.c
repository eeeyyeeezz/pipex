#include <stdio.h>
#include <unistd.h>

int			main(int argc, char **argv, char **envp)
{
	execve("/bin/ls", &argv[1], envp);
}