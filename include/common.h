#ifndef COMMON_H
#define COMMON_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int read_after_seq (const char * p_str,
                    size_t       str_len,
                    const char * p_seq,
                    size_t       seq_len,
                    char *       p_out,
                    size_t       out_len);
int read_file (const char * p_filename, char * p_out, size_t out_len);

#endif // COMMON_H