#include "holberton.h"
int main(int argc, char *argv[])
{
char header[5];
int fd, x;
if (argc != 2)
{
dprintf(STDERR_FILENO, "Usage: elf_header elf_filename");
exit (98);
}
fd = open(argv[1], O_RDONLY);
x = read(fd, header, 5);
if (x == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s", argv[1]);
exit (98);
}
if (strcmp(header, "^?ELF") == 0)
{
dprintf(STDERR_FILENO, "Error: File not ELF %s");
exit(98);
}
}
int strcmp(char a[], char *b)
{
while (*a)
{
if (*a != *b)
return (0);
else
a++;
b++;
}
return (1);
}
