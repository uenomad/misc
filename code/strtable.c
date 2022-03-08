#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strtable.h"

static const char *colsymvis = STR_SYMBOL_VIS;
static const char *colsym = STR_SYMBOL;

static int tprintf_color_open(char **raw, char **out)
{
	char *praw = *raw;
	char *pout = *out;

	#define is_color(tag, color) \
	if (strncmp(praw, tag, STR_COL_CHR) == 0) \
	{ \
		sprintf(pout, "%s", color); \
		*raw = &praw[STR_COL_CHR]; \
		*out = &pout[COL_CHR]; \
		return 1; \
	}

	is_color(STR_RED, COL_RED);
	is_color(STR_GRE, COL_GRE);
	is_color(STR_YLW, COL_YLW);
	is_color(STR_BLU, COL_BLU);
	is_color(STR_MGT, COL_MGT);
	is_color(STR_CYA, COL_CYA);

	return 0;
}

static void tprintf_color_close(char **out)
{
	char *pout = *out;
	sprintf(pout, "%s", COL_CLR);
	*out = &pout[CLR_CHR];
}

int tprintf_init(strtable_t *t, int fd, int mode, char *format)
{
    char *tok;
    // There is no room in format buffer
	if (strlen(format) >= STR_SIZE_BUFFER) {
		t->columns = 0;
		return -1;
	}
	// Initialization
	t->fd      = fd;
	t->mode    = mode;
	t->columns = 0;
	// Getting the format
	strcpy(t->buffer_raw, format);
	//
	tok = strtok(t->buffer_raw, " ");
	//
	while (tok != NULL && t->columns < STR_MAX_COLUMNS) {
		t->format[t->columns++] = atoi(tok);
		tok = strtok(NULL, " ");
	}
	if (t->columns >= STR_MAX_COLUMNS) {
		t->columns = 0;
		return -1;
	}

	return 0;
}

int tprintf_apply(strtable_t *t)
{
    char *pcol = strstr(t->buffer_raw, colsym);
    char *praw = t->buffer_raw;
    char *pout = t->buffer_out;

    int len = strlen(t->buffer_raw);
	int visible = 0;
	int chr = 0;
	int col = 0;
    int i = 0;

	if ((len >= STR_SIZE_BUFFER) || (t->columns == 0)) {
		return -1;
	}
	//
    while(pcol && i < t->columns)
    {
		// If it is a visible wall
		if (visible) {
			pout[0] = '|';
            pout[1] = ' ';
            pout++;
            pout++;
			praw++;
		}
    	// If color
		if (t->mode == STR_MODE_COL) {
			col = tprintf_color_open(&praw, &pout);
		}
    	// Character copy and count
        while(praw != pcol) {
            *pout = *praw;
            ++chr;
            ++praw;
            ++pout;
		}
        // Number of characters per column
        while(chr < t->format[i]) {
            *pout = ' ';
            ++chr;
            ++pout;
        }
		//
		if (col) {
			tprintf_color_close(&pout);
			col = 0;
		}
		//
		if (pcol == &t->buffer_raw[len]) {
			break;
		}
		// Visible wall
		visible = (strncmp(praw, colsymvis, strlen(colsymvis)) == 0);

        ++i;
        pcol++;
        pcol++;
        praw = pcol;
        pcol = strstr(pcol, colsym);
		//
        if (!pcol) {
        	pcol = &t->buffer_raw[len];
        }
        chr = 0;
    }
	// Printing
	pout[0] = '\n';
	pout[1] = '\0';
    dprintf(t->fd, "%s", t->buffer_out);

	return 0;
}