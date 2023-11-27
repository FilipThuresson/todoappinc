//
// Created by filip on 2023-11-25.
//

#ifndef TODO_APP_TODO_H
#define TODO_APP_TODO_H

#include <stdbool.h>

struct todo {
        int id;
        char *name;
        char *desc;
        bool is_done;
};

typedef struct todo todo_t;

typedef struct todo_l{
    todo_t todo;
    todo_l *next;
    todo_l *prev;

} todo_l;

bool create_todo(char *name, char *desc);
bool remove_todo(char id);

todo_l* all();
todo_l* get(int id);
todo_l* set(int id, todo_l *new);

#endif //TODO_APP_TODO_H
