// Assignment name  : inter
// Expected files   : inter.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes two strings and displays, without doubles, the
// characters that appear in both strings, in the order they appear in the first
// one.

// The display will be followed by a \n.

// If the number of arguments is not 2, the program displays \n.

// Examples:

// $>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// padinto$
// $>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6ewg4$
// $>./inter "rien" "cette phrase ne cache rien" | cat -e
// rien$
// $>./inter | cat -e
// $

#include <unistd.h>

int there_is(char c, char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int is_first(char c, char *str, int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        if (str[i] == c)
            return (0);
        i++;
    }
    return (1);
}

int main(int argc, char **argv)
{
    char *a;
    char *b;
    int i;

    if (argc != 3)
        return (write(1, "\n", 1) * 0);
    i = 0;
    a = argv[1];
    b = argv[2];
    while (a[i])
    {
        if (there_is(a[i], b) && is_first(a[i], a, i))
            write(1, &a[i], 1);
        i++;
    }
    write(1, "\n", 1);
    return (0);
}