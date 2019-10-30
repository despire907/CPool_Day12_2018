/*
** EPITECH PROJECT, 2018
** task01
** File description:
** task01
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int my_putstr();

int my_putchar();

int no_argu(int bh, char **argv)
{
    char buffer[31];
    int tall = 1;

    while (tall != 0) {
        tall = read(0, buffer, 30);
        my_putstr(buffer);
        buffer[tall] = '\0';
    }
    tall = 1;
    my_putchar ('\n');
    close (bh);
}

int argu(int bh)
{
    char buffer[31];
    int tall = 1;

    while (tall != 0) {
        tall = read(bh, buffer, 30);
        buffer[tall] = '\0';
        my_putstr(buffer);
    }
    tall = 1;
    my_putchar ('\n');
}

int main(int argc, char **argv)
{
    int bh;
    int o = 1;

    if (argc == 1)
        no_argu(bh, argv);
    else {
        while (o < argc) {
            bh = open(argv[o], O_RDONLY);
            o = o + 1;
            if (bh == -1) {
                my_putstr("Error while opening");
                return (1);
            }
            argu(bh);
        }
    }
}
