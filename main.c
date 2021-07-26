
#include "ft_ssl.h"

char * add_symb(char *string, int c)
{
    int i = 0;
    char *str;
    str = malloc(sizeof(char) + strlen(string) + 1);
    while (string[i] != '\0')
    {
        str[i] = string[i];
        i++;
    }
    str[i] = c;
    str[i + 1] = '\0';
    free(string);
    string = ft_strdup(str);
    free(str);
    return string;
}

t_all * init()
{
    t_all *all;
    all = malloc(sizeof(t_all));

    all->flags = (t_flags *)ft_memalloc(sizeof(t_flags));
    all->commands = (t_commands *)ft_memalloc(sizeof(t_commands));
    all->std_in = ft_strdup("");
    all->file = ft_strdup("");
    all->test_string_for_output = "codeTextXXXXXXXXXXX";
    return all;
}

void free_foo(t_all *all)
{
    free(all->std_in);
    free(all->file);
    free(all->commands);
    free(all->flags);
    free(all);
}

void check_commands(char *command, t_all *all)
{
    if (ft_strcmp(command, SHA256) != 0 && ft_strcmp(command, MD5) != 0)
    {
        ft_printf("error");
        exit(1);
    }
	ft_strcmp(command, SHA256) == 0 ? (all->commands->sha256 = 1) : (all->commands->md5 = 1);
}

int flag_foo(char param, t_all *all)
{
	if (param == 'p')
	{
		all->flags->p = 1;
		return 1;
	}
	if (param == 'q')
	{
		all->flags->q = 1;
		return 1;
	}
	if (param == 'r')
	{
		all->flags->r = 1;
		return 1;
	}
	if (param == 's')
	{
		all->flags->s = 1;
		return 1;
	}
	return 0;
}

int get_flags(char *str_flag, t_all *all)
{
	if (ft_strlen(str_flag) != 2)
		return 0;
	if (str_flag[0] != '-')
		return 0;
	return flag_foo(str_flag[1], all);
}

void parse_av(int ac, char **av, t_all *all)
{
    int i = 2;
    int flags = 1;
    check_commands(av[1], all);
//	printf("%d %d\n", all->commands->sha256, all->commands->md5);
    while (i != ac)
    {
		if (flags == 1)
		{
			flags = get_flags(av[i], all);
		}
        i++;
    }
}

int main(int ac, char ** av)
{
    t_all *all;
    char str;
    all = init();
    parse_av(ac, av, all);

//    while (read(STDIN_FILENO , &str, 1) > 0)
//    {
//        all->std_in = add_symb(all->std_in, str);
//    }
    ft_printf("%s", all->std_in);
    free_foo(all);
    return 0;
}
