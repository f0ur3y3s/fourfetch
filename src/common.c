#include "../include/common.h"

int read_after_seq (const char * p_str,
                    size_t       str_len,
                    const char * p_seq,
                    size_t       seq_len,
                    char *       p_out,
                    size_t       out_len)
{
    int    status  = -1;
    char * p_start = NULL;
    char * p_end   = NULL;
    size_t len     = 0;

    if (!p_str || !p_seq || !p_out || !out_len)
    {
        goto EXIT;
    }

    p_start = strstr(p_str, p_seq);

    if (NULL == p_start)
    {
        goto EXIT;
    }

    p_start += seq_len;
    p_end = strchr(p_start, '\n');

    if (NULL == p_end)
    {
        goto EXIT;
    }

    len = p_end - p_start;

    if (len >= out_len)
    {
        goto EXIT;
    }

    strncpy(p_out, p_start, len);
    p_out[len] = '\0';

    status = 0;

EXIT:
    return (status);
}

int read_file (const char * p_filename, char * p_out, size_t out_len)
{
    int    status = -1;
    FILE * fp_file = NULL;
    size_t len    = 0;

    if (!p_filename || !p_out || !out_len)
    {
        goto EXIT;
    }

    fp_file = fopen(p_filename, "r");

    if (NULL == fp_file)
    {
        goto EXIT;
    }

    len = fread(p_out, 1, out_len - 1, fp_file);

    if (0 == len)
    {
        goto EXIT;
    }

    p_out[len] = '\0';

    status = 0;

EXIT:
    if (NULL != fp_file)
    {
        fclose(fp_file);
    }

    return (status);
}