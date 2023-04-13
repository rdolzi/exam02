#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char    *get_next_line(int fd)
{
    int rd = 0;
    int i = 0;
    char c;
    char *buffer = malloc(10000);

    if (BUFFER_SIZE <= 0)
    {
        free(buffer);
        return (NULL);
    }   
    while ((rd = read(fd, &c, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0)
    {
        buffer[i++] = c;
        if (c == '\n')
            break;
    }
    if (rd == -1 || (!rd && !buffer[i - 1]))
    {
        free(buffer);
        return (NULL);
    }
    buffer[i] = '\0';
    return (buffer);    
}



int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *str = get_next_line(fd);
	printf("%s", str);
	free(str);
	//close(fd);
	
	str = get_next_line(fd);
	printf("%s",str);
	free(str);
	str = get_next_line(fd);
	printf("%s",str);
	free(str);
	str = get_next_line(fd);
	printf("%s",str);
	free(str);
}
