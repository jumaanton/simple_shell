#include "main.h"
#include "shell.h"

/**
 * _clear - clears the terminal screen
 * @params: parameters
 *
 * Return: 0
 */
void _clear(param_t *params)
{
	(void)params;
	_printf("\033[2J\033[1;1H");
}

