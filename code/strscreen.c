#include "strscreen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define Y 0
#define X 1
#define clrscr()     printf("\e[1;1H\e[2J")
#define debug(...)   printf(__VA_ARGS__)
#define buffer(y, x) s->buffer[(y)*s->width+(x)]

static void clean_buffer_background(screen_t *s)
{
    int y, x;
    for (y = 0; y < s->height; ++y) {
        for (x = 0; x < s->width; ++x) {
            buffer(y,x) = s->bckchr;
        }
        buffer(y,x-1) = '\n';
    }
    buffer(y-1,x) = '\0';
}

void wprintf_init(screen_t *s, int height, int width, int fd, char bckchr)
{
    s->buffer = calloc((width+1)*height, sizeof(char));
    s->divs   = calloc(8, sizeof(screen_t)); //8 subdivisions is fairly enough
    s->height = height;
    s->width  = width;
    s->fd     = fd;
    s->bckchr = bckchr;
    clean_buffer_background(s);
}

static void clean_matrix_background(screen_t *s)
{
    int x, y;
    for (y = 0; y < s->height; ++y)
    for (x = 0; x < s->width-1; ++x) {
        s->matrix[y][x] = s->bckchr;
    }
}

void wprintf_divide(screen_t *s, int p1[2], int p2[2], int div_index)
{
    screen_t *div = &(((screen_t *) s->divs)[div_index]);
    int y;
    // X: #######\n <- (n-2 = '#') (n-1 = '\n')
    // Y: #######\0 <- (n-1 = '#')
    if (p2[X] >= s->width ) p2[X] = s->width-3;
    if (p2[Y] >= s->height) p2[Y] = s->height-2;
    div->buffer = s->buffer;
    div->width  = p2[X] - p1[X];
    div->height = p2[Y] - p1[Y];
    div->bckchr = ' ';
    div->matrix = calloc(div->height, sizeof(char *));
    // Setting division pointers
    for (y = 0; y < div->height; ++y) {
        div->matrix[y] = &div->buffer[(p1[Y]+y)*s->width+p1[X]];
    }
    s->divs_count++;
    clean_matrix_background(div);
}

void wsprintf(screen_t *s, char *buffer, int div_index)
{
    screen_t *div = &(((screen_t *) s->divs)[div_index]);
    size_t length = strlen(buffer);
    int c, x, y;

    // Cleaning
    clean_matrix_background(div);
    // Copying characters
    for (c = y = x = 0; c < length && y < div->height; ++c) {
        debug("%d '%c' (%d %d)\n", c, buffer[c], x, div->width);
        if (x == 0) {
            div->matrix[y][x] = ' ';
            ++x;
        }
        if (x == (div->width-2)) {
            while (buffer[c] != '\n' && buffer[c] != '\0') {
                debug("%d '%c' (%d %d)\n", c, buffer[c], x, div->width);
                c++;
            }
        }
        if (buffer[c] == '\0') {
            continue;
        }
        if (buffer[c] == '\n') {
            x = -1;
            y++;
        } else {
            div->matrix[y][x] = buffer[c];
        }
        x++;
    }
}

void wprintf(screen_t *s)
{
    clrscr();
    printf("%s", s->buffer);
}

screen_t s;

int main(int argc, char *argv[])
{
    wprintf_init(&s, 35, 180, 0, '#');

    wprintf_divide(&s, (int[]) {01,   2}, (int[]) {10,  40}, 0);
    wprintf_divide(&s, (int[]) {01,  42}, (int[]) {20,  80}, 1);
    wprintf_divide(&s, (int[]) {01, 154}, (int[]) { 7, 179}, 2);

#if 1
    char *logo = "    _________    ____ \n"
                 "   / ____/   |  / __ \\\n"
                 "  / __/ / /| | / /_/ /\n"
                 " / /___/ ___ |/ _, _/ \n"
                 "/_____/_/  |_/_/ |_|  \n";
#else
    char *logo = "";
#endif
    while (1) {
    wsprintf(&s, "-- cpufreq --------------------------------------------------------------------\n", 0);
    wsprintf(&s, "-- cpufreq --------------------------------------------------------------------\n", 0);
    //wsprintf(&s, logo, 2);
    wprintf(&s);
    sleep(1);
    }
    return 0;
}