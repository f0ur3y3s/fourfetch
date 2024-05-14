#include "../include/common.h"

// rewrite with regex to parse per line because bug
// VERSION_ID="22.04"
// ID=ubuntu
// gets caught on the first line
int common_read_after_seq (const char * p_str,
                    size_t       str_len,
                    const char * p_seq,
                    size_t       seq_len,
                    char *       p_out,
                    size_t       out_len)
{
    int    status  = -1;
    char * p_start = NULL;
    char * p_end   = NULL;

    if ((NULL == p_str) || (0 == str_len) || (NULL == p_seq) || (0 == seq_len)
        || (NULL == p_out) || (0 == out_len))
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

    size_t len = p_end - p_start;

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

int common_read_file (const char * p_filename, char * p_out, size_t out_len)
{
    int    status  = -1;
    FILE * fp_file = NULL;
    size_t len     = 0;

    if ((NULL == p_filename) || (NULL == p_out) || (0 == out_len))
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

int common_strip_char (char * p_str, char c)
{
    int    status = -1;
    size_t len    = 0;

    if ((NULL == p_str) || ('\0' == c))
    {
        goto EXIT;
    }

    len = strlen(p_str);

    for (size_t i = 0; i < len; i++)
    {
        if (c == p_str[i])
        {
            for (size_t j = i; j < len; j++)
            {
                p_str[j] = p_str[j + 1];
            }

            len--;
            i--;
        }
    }

    status = 0;

EXIT:
    return (status);
}