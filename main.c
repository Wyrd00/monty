#include "monty.h"

int main(int argc, char **argv)
{
    char *line;
    size_t len;
    ssize_t read;
    stack_t *head;
    unsigned int linenum;
    FILE *fd;

    if (argc != 2)
    {
        printf("USAGE: More than 2 arguments");
        exit(EXIT_FAILURE);
    }
    fd = fopen(argv[1], "r");

    if (fd == NULL)
    {
        printf("USAGE: fd NULL");
        exit(EXIT_FAILURE);
    }

    head = NULL;
    linenum = 0;
    line = NULL;
    len = 0;

    do
    {
	    ++linenum;
	    read = getline(&line, &len, fd);
	    if (read > 0)
	    {
		    perform(&head, linenum, line);
	    }
	    else
	    {
		    free(line);
	    }
    } while (read != -1);

    fclose(fd);
    free_list(head);

    return (0);
}
