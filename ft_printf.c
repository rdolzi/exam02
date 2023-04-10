// Assignment name  : ft_printf
// Expected files   : ft_printf.c
// Allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end
// --------------------------------------------------------------------------------

// Write a function named `ft_printf` that will mimic the real printf but
// it will manage only the following conversions: s,d and x.

// Your function must be declared as follows:

// int ft_printf(const char *, ... );

// Before you start we advise you to read the `man 3 printf` and the `man va_arg`.
// To test your program compare your results with the true printf.

// Exemples of the function output:

// call: ft_printf("%s\n", "toto");
// out: toto$

// call: ft_printf("Magic %s is %d", "number", 42);
// out: Magic number is 42%

// call: ft_printf("Hexadecimal for %d is %x\n", 42, 42);
// out: Hexadecimal for 42 is 2a$

// Obs: Your function must not have memory leaks. Moulinette will test that.

#include <stdarg.h>
#include <unistd.h>

void ft_printchar(char c, int *sum)
{
    write(1, &c, 1);
    (*sum)++;
}

void ft_printstr(char *str, int *sum)
{
    int i;

    i = 0;
    while (str[i])
    {
        ft_printchar(str[i++], sum);
    }
}

void ft_printnbr(int nbr, int *sum)
{
    if (nbr == -2147483648)
    {
        ft_printstr("-2147483648", sum);
        return;
    }
    if (nbr < 0)
    {
        ft_printchar('-', sum);
        nbr *= -1;
    }
    if (nbr > 9)
        ft_printnbr(nbr / 10, sum);
    ft_printchar((nbr % 10) + '0', sum);
}

void ft_printhex(unsigned int nbr, int *sum)
{
    char *base;
    base = "0123456789abcdef";
    if (nbr > 15)
        ft_printhex(nbr / 16, sum);
    ft_printchar(base[nbr % 16], sum);
}

void ft_checker(char c, va_list *va, int *sum)
{
    if (c == 's')
    {
        ft_printstr(va_arg(*va, char *), sum);
    }
    else if (c == 'd')
    {
        ft_printnbr(va_arg(*va, int), sum);
    }
    else if (c == 'x')
    {
        ft_printhex(va_arg(*va, unsigned int), sum);
    }
}

int ft_printf(const char *str, ...)
{
    int i;
    int sum;
    va_list va;

    i = 0;
    sum = 0;
    va_start(va, str);
    while (str[i])
    {
        if (str[i] == '%')
        {
            ft_checker(str[++i], &va, &sum);
            i++;
        }
        else
            ft_printchar(str[i++], &sum);
    }
    va_end(va);
    return (sum);
}

int main()
{
    // ft_printf("%s\n", "toto");
    // ft_printf("Magic %s is %d", "number", 42);
    ft_printf("Hexadecimal for %d is %x\n", 42, 42);
}