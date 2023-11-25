//
// Created by filip on 2023-11-25.
//

#ifndef TODO_APP_TODO_H
#define TODO_APP_TODO_H

typedef struct todo = {
        char *name;
        char *desc;
        bool is_done;
}todo_t;

typedef struct todos{
    todo_t todo,
    todos *next;
    todos *prev;

} todos;

#endif //TODO_APP_TODO_H
