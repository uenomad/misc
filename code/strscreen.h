#ifndef MISC_STRSCREEN_H
#define MISC_STRSCREEN_H

typedef struct screen_s {
    void       *divs;
    int         divs_count;
    char       *buffer;
    char      **matrix;
    char      **lines;
    char        bckchr;
    int         height;
    int         width;
    int         fd;
} screen_t;

void wprintf_init(screen_t *screen, int height, int width, int fd, char bckchr);

void wprintf_divide(screen_t *screen, int p1[2], int p2[2], int div_index);

void wprintf(screen_t *s);

void wsprintf(screen_t *s, char *buffer, int div_index);

#endif //MISC_STRSCREEN_H
