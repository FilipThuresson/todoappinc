//
// Created by filip on 2023-11-25.
//
#include "ui.h"
#include "io.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CMD_LEN 10
/*
 * PRIVATE
 */

static void ui_invalid_option() {
    printf("INFO> Invalid command \n\tType help to see possible commands\n");
}

static void ui_exit() {
    printf("INFO> Bye!\n");
}

static char *ui_get_cmd(char *buf, int n) {
    printf("input> ");
    return read_line(buf, n) ? buf : 0;
}

static void ui_line(char c, int n) {
    while(n-- > 0) {
        putchar(c);
    }
    printf("\n");
}

static void ui_menu_options(const char *opt[], int n) {
    for (int i = 0; i < n ; ++i) {
        printf("Command> %s\n", opt[i]);
    }
}

static void ui_menu() {
    const char *menu_list[] = {
            "help",
            "exit | stop",
            "clear | cls\n",
            "new",

    };
    ui_menu_options(menu_list, sizeof (menu_list) / sizeof (char *));
    ui_line('-', MENU_WIDTH);
}

static void ui_center_string(char *str, int n) {
    int strl = strlen(str);

    int start_at = (n/2) - (strl / 2);
    while(start_at-- > 0) {
        putchar(' ');
    }
    printf("%s\n", str);
}

static void ui_header() {
    ui_line('-', MENU_WIDTH);
    ui_center_string("TODO APP", MENU_WIDTH);
    ui_line('-', MENU_WIDTH);
}

/*
 * Public
 */

void ui_run() {
    bool is_running = true;
    bool show_menu = true;
    bool was_invalid = false;
    char cmd[MAX_CMD_LEN];

    while (is_running) {
        system("clear");
        ui_header();
        if(was_invalid) {
            ui_invalid_option();
            was_invalid = false;
        }

        if(show_menu) {
            ui_menu();
            show_menu = false;
        }

        ui_get_cmd(cmd, MAX_CMD_LEN);

        if(strcmp(cmd, "help") == 0) {
            show_menu = true;
        } else if(strcmp(cmd, "exit") == 0 ||strcmp(cmd, "stop") == 0) {
            ui_exit();
            is_running = false;
        } else if(strcmp(cmd, "clear") == 0 ||strcmp(cmd, "cls") == 0) {
            system("clear");
        } else {
            was_invalid = true;
        }
    }
}