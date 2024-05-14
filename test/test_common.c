#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "unity/unity.h"
#include "../include/common.h"

void setUp (void)
{
    char * p_test_str = "ID=Ubuntu";
    FILE * fp         = fopen("/tmp/os-release", "w");
    fwrite(p_test_str, 1, strlen(p_test_str), fp);
    fclose(fp);
}

void tearDown (void)
{
    remove("/tmp/os-release");
}

void test_read_file (void)
{
    // touch test file
    // echo "ID=Ubuntu" > /tmp/os-release

    char os_str[256] = { 0 };
    int  status      = common_read_file("/tmp/os-release", os_str, 256);

    TEST_ASSERT_EQUAL_INT(0, status);
    TEST_ASSERT_EQUAL_STRING("ID=Ubuntu", os_str);

    return;
}

void test_read_after_seq (void)
{
    char * p_filename = "/etc/os-release";
    char   out[256]   = { 0 };
    int    status     = common_read_file(p_filename, out, 256);

    TEST_ASSERT_EQUAL_INT(0, status);

    char   seq_out[256] = { 0 };
    char * p_seq        = "PRETTY_NAME=";
    status = common_read_after_seq(out, strlen(out), p_seq, strlen(p_seq), seq_out, 256);

    TEST_ASSERT_EQUAL_INT(0, status);
    TEST_ASSERT_EQUAL_STRING("\"Ubuntu 22.04.3 LTS\"", seq_out);

    // TEST_ASSERT_EQUAL_INT(0, status);
    // TEST_ASSERT_EQUAL_STRING("Ubuntu", out);

    return;
}

int main (void)
{
    UNITY_BEGIN();

    RUN_TEST(test_read_after_seq);
    RUN_TEST(test_read_file);

    return UNITY_END();
}