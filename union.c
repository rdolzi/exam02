// Assignment name  : union
// Expected files   : union.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes two strings and displays, without doubles, the
// characters that appear in either one of the strings.

// The display will be in the order characters appear in the command line, and
// will be followed by a \n.

// If the number of arguments is not 2, the program displays \n.

// Example:

// $>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// zpadintoqefwjy$
// $>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6vewg4thras$
// $>./union "rien" "cette phrase ne cache rien" | cat -e
// rienct phas$
// $>./union | cat -e
// $
// $>
// $>./union "rien" | cat -e
// $
// $>

#include <unistd.h>

int is_first(char c, char *a, int i, char *b, int j)
{
    int m;
    int n;

    m = 0;
    n = 0;
    while (a && m < i)
    {
        if (a[m] == c)
            return (0);
        m++;
    }
    while (b && n < j)
    {
        if (b[n] == c)
            return (0);
        n++;
    }
    return (1);
}

int main(int argc, char **argv)
{
    int i;
    int j;
    char *a;
    char *b;
    if (argc != 3)
    {
        return (write(1, "\n", 1) * 0);
    }
    i = 0;
    j = 0;
    a = argv[1];
    b = argv[2];
    while (a[i])
    {
        if (is_first(a[i], a, i, NULL, j))
            write(1, &a[i], 1);
        i++;
    }
    while (b[j])
    {
        if (is_first(b[j], a, i, b, j))
            write(1, &b[j], 1);
        j++;
    }
    return (write(1, "\n", 1) * 0);
}