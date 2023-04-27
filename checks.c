#include "shell.h"
/**
 *checks- checks to see weather its a built in function
 *@cmd: tokenized user input
 *@buf: line drived fromgetline function
 *Return: 1 if cmd excuted 0 if cmd is not executed
 */
int checker(char **cmd, char *buf)
{
	/**
	 * The code checks to see if the user input is a built in function.
	 * If it is, then execution of that command will be done and return 1.
	 * Otherwise, if the user input contains '/', then the command will be executed and return 1.
	 * The code checks for the existence of a function called handle_builtin and if it exists, executes it.
	 * If not, then execution is passed to the next command in the string.
	 * 
	 * **/
	if (handle_builtin(cmd, buf))
		return (1);
	else if (**cmd == '/')
	{
		execution(cmd[0], cmd);
		return (1);
	}
	return (0);
}
