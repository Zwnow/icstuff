#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

FILE *fptr;

void add_task(char *task) {
    fptr = fopen("tasks.md", "a");
    fprintf(fptr, "%s - incomplete\n", task);
    fclose(fptr);
}

int complete_task(int no) {
    int changed = 0;
    FILE *tmp;
    int count = 1;
    fptr = fopen("tasks.md", "r");
    tmp = fopen("temp.tmp", "w");

    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, fptr) != -1) {
        if (count == no) {
            changed = 1;
            for (int i = 0; line[i] != '-'; i++) {
                fputc(line[i], tmp);
            }
            fprintf(tmp, "- complete\n");
        } else {
            fprintf(tmp, "%s", line);
        }
        count++;
    }
    free(line);
    fclose(tmp);
    fclose(fptr);

    tmp = fopen("temp.tmp","r");
    fptr = fopen("tasks.md", "w");

    line = NULL;
    len = 0;

    while (getline(&line, &len, tmp) != -1) {
       fprintf(fptr, "%s", line); 
    }

    free(line);

    fclose(tmp);
    fclose(fptr);
    remove("temp.tmp");

    return changed;
}

void remove_task(int no) {
    FILE *tmp;
    int count = 1;
    fptr = fopen("tasks.md", "r");
    tmp = fopen("temp.tmp", "w");

    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, fptr) != -1) {
        if (count != no) {
            fprintf(tmp, "%s", line);
        }
        count++;
    }
    free(line);
    fclose(tmp);
    fclose(fptr);

    tmp = fopen("temp.tmp","r");
    fptr = fopen("tasks.md", "w");

    line = NULL;
    len = 0;

    while (getline(&line, &len, tmp) != -1) {
       fprintf(fptr, "%s", line); 
    }

    free(line);

    fclose(tmp);
    fclose(fptr);
    remove("temp.tmp");
}

void read_tasks() {
    int count = 1;
    fptr = fopen("tasks.md", "r");
    char line[100];
    if (fptr != NULL) {
        while (fgets(line, 100, fptr)) {
            printf("%i. %s", count++, line);
        }
    }
}

int main(int argc, char **argv) {
    if (argc == 1) {
        printf("Usage:\n\n- To add a task:\n[add] ['task']\n");
        printf("- To complete a task:\n[com] [tasknumber]\n");
        printf("- To delete a task:\n[rm] [tasknumber]\n");
        printf("- To read tasks:\n[rd]\n");
    }
    
    if (strcmp(argv[1], "add") == 0) {
        if (argv[2] != NULL) {
            add_task(argv[2]);
        }
    } else if (strcmp(argv[1], "com") == 0) {
        int line = atoi(argv[2]);
        if (complete_task(line) == 1) {
            printf("List updated!");
        } else {
            printf("Nothing to update!");
        }
    } else if (strcmp(argv[1], "rm") == 0) {
        int line = atoi(argv[2]);
        remove_task(line);
    } else if (strcmp(argv[1], "rd") == 0) {
        read_tasks();
    }
}
