
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

void check_commands(char *command)
{
    if (ft_strcmp(command, SHA256))
    {
        ft_printf("error");
        exit(1);
    }
}

void parse_av(int ac, char **av, t_all *all)
{
    int i = 2;
    check_commands(av[1]);
    while (i != ac)
    {

        i++;
    }
}

int main(int ac, char ** av)
{
    t_all *all;
    char str;
    all = init();
    parse_av(ac, av, all);

    while (read(STDIN_FILENO , &str, 1) > 0)
    {
        all->std_in = add_symb(all->std_in, str);
    }
    ft_printf("%s", all->std_in);
    free_foo(all);
    return 0;
}
