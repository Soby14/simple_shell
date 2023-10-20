#include "shell.h"

/**
* _getenviron - Retrieve the values of an environment variable.
*
* @env_var: The name of the environment variable to retrieve.
*
* Return: A pointer to the content of the environment var, or NULL if not seen.
*/

char *_getenviron(char *env_var)
{
int i = 0, j;
int status;
while (environ[i])
{
status = 1;
for (j = 0; environ[i][j] != '='; j++)
{
if (environ[i][j] != env_var[j])
status = 0;
}
if (status == 1)
break;
i++;
}
return (&environ[i][j + 1]);
}
/**
* _environ - prints out environment
*/
void _environ(void)
{
int i = 0;
while (environ[i])
{
printf("%s\n", environ[i]);
i++;
}
}
