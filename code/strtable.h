#ifndef STRTABLE_H
#define STRTABLE_H

#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <linux/limits.h>

#define STR_MAX_BUFFER		4096
#define STR_MAX_COLUMNS		20
#define STR_SIZE_BUFFER		PIPE_BUF
#define STR_SYMBOL			"||"
#define STR_SYMBOL_VIS		"|||"
#define STR_RED				"<red>"
#define STR_GRE 			"<gre>"
#define STR_YLW 			"<ylw>"
#define STR_BLU 			"<blu>"
#define STR_MGT 			"<mgt>"
#define STR_CYA 			"<cya>"
#define STR_COL_CHR			5
#define STR_MODE_DEF		0
#define STR_MODE_COL		1
#define STR_MODE_CSV		2
#define COL_RED             "\x1b[31m"
#define COL_GRE             "\x1b[32m"
#define COL_YLW             "\x1b[33m"
#define COL_BLU             "\x1b[34m"
#define COL_MGT             "\x1b[35m"
#define COL_CYA             "\x1b[36m"
#define COL_CLR             "\x1b[0m"
#define COL_CHR             5
#define CLR_CHR             4

typedef struct strtable_s {
	char buffer_raw[STR_MAX_BUFFER];
	char buffer_out[STR_MAX_BUFFER];
	unsigned int format[STR_MAX_COLUMNS];
	unsigned int columns;
	unsigned int mode;
	int fd;
} strtable_t;

#define tprintf(tr, ...) \
    { \
    snprintf((tr)->buffer_raw, STR_SIZE_BUFFER-1, __VA_ARGS__); \
    tprintf_apply(tr); \
    }

int tprintf_init(strtable_t *t, int fd, int mode, char *format);

int tprintf_apply(strtable_t *t);

#endif
