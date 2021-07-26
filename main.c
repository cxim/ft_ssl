#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

#define MD5 "md5"
#define SHA256 "sha256"


typedef struct s_flags
{
    int p;
    int q;
    int r;
    int s;

}               t_flags;

typedef struct s_commands
{
    int md5;
    int sha256;

}               t_commands;

typedef struct s_all
{
    char *test_string_for_output;
    char *std_in;
    char *file;
    t_commands  *commands;
    t_flags *flags;
}               t_all;


void	*ft_memset(void *b, int c, size_t len)
{
    unsigned char	*z;
    size_t			x;

    x = 0;
    z = b;
    while (x != len)
    {
        z[x] = c;
        x++;
    }
    return (z);
}

void	ft_bzero(void *s, size_t n)
{
    ft_memset(s, 0, n);
}

void	*ft_memalloc(size_t size)
{
    void	*cpy;

    if (size + 1 == 0)
        return (NULL);
    if (!(cpy = (void*)malloc(sizeof(void) * size)))
        return (NULL);
    ft_bzero(cpy, size);
    return (cpy);
}

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
    string = strdup(str);
    free(str);
    return string;
}

t_all * init()
{
    t_all *all;
    all = malloc(sizeof(t_all));

    all->flags = (t_flags *)ft_memalloc(sizeof(t_flags));
    all->commands = (t_commands *)ft_memalloc(sizeof(t_commands));
    all->std_in = strdup("");
    all->file = strdup("");
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
    if (strcmp(command, SHA256))
    {
        printf("eror");
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
    printf("%s", all->std_in);
    free_foo(all);
    return 0;
}

//это то, что я переполняю буффер, который ты рассчитал для конкатенации. И в тот момент, когда адрес должен вызвать ret, ты получаешь еще нагрузку на буфер и ret вызов принять не может