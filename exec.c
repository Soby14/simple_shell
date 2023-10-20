#include "shell.h"

/**
 * exec - Execute a command from a specified path in a child process.
 *
 * @args: An array of  arguments for the command.
 *
 * Return: The exist status of execute command.
 */

int exec(char **args)
{
	int id = fork(), status;

	if (id == 0)
	{
		if (execve(args[0], args, environ) == -1)
			perror("Error");
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
	}

	return (status);
}
