#ifndef COLORS_H
#define COLORS_H
#include <stdio.h>
#include <stdlib.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_BLUE_BACKGROUND "\x1b[44m"
#define ANSI_COLOR_RED_BACKGROUND "\x1b[41m"
#define ANSI_COLOR_GREEN_BACKGROUND "\x1b[42m"

#define blue_fg(string) ANSI_COLOR_BLUE string ANSI_COLOR_RESET
#define blue_bg(string) ANSI_COLOR_BLUE_BACKGROUND string ANSI_COLOR_RESET

#define red_fg(string) ANSI_COLOR_RED string ANSI_COLOR_RESET
#define red_bg(string) ANSI_COLOR_RED_BACKGROUND string ANSI_COLOR_RESET

#define green_fg(string) ANSI_COLOR_GREEN string ANSI_COLOR_RESET
#define green_bg(string) ANSI_COLOR_GREEN_BACKGROUND string ANSI_COLOR_RESET

#define yellow_fg(string) ANSI_COLOR_YELLOW string ANSI_COLOR_RESET
#define cyan_fg(string) ANSI_COLOR_CYAN string ANSI_COLOR_RESET
#define magenta_fg(string) ANSI_COLOR_MAGENTA string ANSI_COLOR_RESET

#endif
