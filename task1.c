#include "shell_header.h"

/**
 * _myexit - Exits the shell
 * @zion: Structure containing potential arguments. Used to maintain
 *         constant function prototype.
 *
 * Return: Exits with a given exit status (0) if zion->argv[0] != "exit"
 */
int _myexit(info_t *zion)
{
int exitcheck;

if (zion->argv[1])
{
exitcheck = _erratoi(zion->argv[1]);
if (exitcheck == -1)
{
zion->status = 2;
print_error(zion, "Illegal number: ");
_eputs(zion->argv[1]);
_eputchar('\n');
return (1);
}
zion->err_num = _erratoi(zion->argv[1]);
return (-2);
}
zion->err_num = -1;
return (-2);
}

/**
 * _mycd - Changes the current directory of the process
 * @zion: Structure containing potential arguments. Used to maintain
 *         constant function prototype.
 *
 * Return: Always 0
 */
int _mycd(info_t *zion)
{
char *s, *dir, buffer[1024];
int chdir_ret;

s = getcwd(buffer, 1024);
if (!s)
_puts("TODO: >>getcwd failure emsg here<<\n");
if (!zion->argv[1])
{
dir = _getenv(zion, "HOME=");
if (!dir)
chdir_ret = chdir((dir = _getenv(zion, "PWD=")) ? dir : "/");
else
chdir_ret = chdir(dir);
}
else if (_strcmp(zion->argv[1], "-") == 0)
{
if (!_getenv(zion, "OLDPWD="))
{
_puts(s);
_putchar('\n');
return (1);
}
_puts(_getenv(zion, "OLDPWD="));
_putchar('\n');
chdir_ret = chdir((dir = _getenv(zion, "OLDPWD=")) ? dir : "/");
}
else
chdir_ret = chdir(zion->argv[1]);
if (chdir_ret == -1)
{
print_error(zion, "can't cd to ");
_eputs(zion->argv[1]);
_eputchar('\n');
}
else
{
_setenv(zion, "OLDPWD", _getenv(zion, "PWD="));
_setenv(zion, "PWD", getcwd(buffer, 1024));
}
return (0);
}

/**
 * _myhelp - Provides help information
 * @zion: Structure containing potential arguments. Used to maintain
 *         constant function prototype.
 *
 * Return: Always 0
 */
int _myhelp(info_t *zion)
{
char **arg_array;

arg_array = zion->argv;
_puts("help call works. Function not implemented yet \n");
if (0)
_puts(*arg_array); /* temp att_unused workaround */
return (0);
}
