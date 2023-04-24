#ifndef TASKS_H_
#define TASKS_H_

typedef enum {
    LOW, MEDIUM, HIGH
} Priority;

typedef unsigned int task_id_t;

typedef struct {
    task_id_t id;
    Priority priority;
} Task;

const Task* choose_more_important_task(const Task* t1, const Task* t2);

const char* priority_as_str(Priority p);

void increase_priority(Priority* p);

void transform_task(Task* t, void(* f)(Priority*));

#endif
