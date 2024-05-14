#include "../include/distro.h"

distro_t * distro_find (void)
{
    distro_t * p_distro = NULL;

    
EXIT:
    return (p_distro);
}

// const char * gp_ubuntu_art[MAX_ASCII_LINES] = {
//     ""
// };

// const distro_t g_distros[] = {
//     {.osname = "Ubuntu", .p_ascii_art = gp_ubuntu_art, .p_pkg_command =
//     "apt"},
// };

// const distro_t * find_distro(const char * p_osname)
// {
// }