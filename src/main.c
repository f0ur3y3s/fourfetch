#include "../include/main.h"

int main (void)
{
    int status = -1;

    char os_str[256] = { 0 };
    status           = common_read_file("/etc/os-release", os_str, 256);

    printf("%s\n", os_str);
    // status = read_after_seq();

EXIT:
    return (status);
}