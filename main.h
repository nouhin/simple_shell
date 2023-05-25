#ifndef MAIN_H
#define MAIN_H

#define TOKEN_DELIM " \t\r\n\a"
#define PATH_DELIM ":"
#define SIZEOFCHAR sizeof(char *)

#define PROMPT "$ "
#define PROMPT_LEN 2

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

/*main*/
int main(int argc, char **argv);

/*command_handler*/
int cmd_handle(char **cmd_args, char **main_argv, int last_exit_status);
int launch_process(char **command, char *name);

/*free*/
void free_array(char **array, int size);
void free_null_terminated_array(char **array);
void free_env(void);

/*helpers.c*/
char *_get_input(void);
char **_get_tokens(char *line, const char *delimiter);
int count_tokens(char *line, const char *delimiter);
void handler_function(int signum);

/*path_helpers.c*/
char *build_cmd_path(char *dir, char *cmd);
char **get_path_directories(char *path_env);
char *get_full_path(char *cmd);
char *_getenv(char *var_name);

/*str_funcs.c*/
char *_strdup(const char *str);
size_t _strlen(const char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, const char *src);
int _strncmp(char *s1, char *s2, size_t n);
int is_valid_number(char *str);
int _strcmp(char *s1, char *s2);

/*builtins.c*/
int check_builtins(char **cmd_args, char **main_argv, int last_exit_status);
int _exit_builtin(char **cmd_args, char **main_argv, int last_exit_status);
int _env_builtin(void);

#endif
