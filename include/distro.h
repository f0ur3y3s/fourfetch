#ifndef DISTRO_H
#define DISTRO_H

#include <stdlib.h>

typedef enum distro_constants_t
{
    MAX_OSNAME_LEN  = 64,
    MAX_ASCII_LINES = 16,
} distro_constants_t;

// typedef struct info_t
// {
//     char
// } info_t;

typedef struct distro_t
{
    char         osname[MAX_OSNAME_LEN];
    const char * p_ascii_art[MAX_ASCII_LINES];
    const char * p_pkg_command;
} distro_t;

// const distro_t * find_distro(const char * p_osname);

distro_t * distro_find (void);
int        distro_destroy (distro_t * p_distro);

#endif // DISTRO_H