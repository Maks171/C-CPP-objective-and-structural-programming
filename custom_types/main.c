#include <stdlib.h>
#include <stdio.h>
#include "tasks.h"

int main(void) {
    Task t1 = {.id = 1, .priority = LOW};
    Task t2 = {.id = 2, .priority = MEDIUM};

    const Task* important_task = choose_more_important_task(&t1, &t2);
    printf("More important task: #%u (priority: %s)\n", important_task->id, priority_as_str(important_task->priority));

    t1.priority = HIGH;
    important_task = choose_more_important_task(&t1, &t2);
    printf("More important task: #%u (priority: %s)\n", important_task->id, priority_as_str(important_task->priority));

    transform_task(&t2, increase_priority);
    printf("Task #%u (priority: %s)\n", t2.id, priority_as_str(t2.priority));

    Task t3 = {.id = 3, .priority = LOW};
    transform_task(&t3, increase_priority);
    printf("Task #%u (priority: %s)\n", t3.id, priority_as_str(t3.priority));
    return EXIT_SUCCESS;
}
