/*
** EPITECH PROJECT, 2017
** minilibc
** File description:
** Tests strcmp.
*/

#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <criterion/criterion.h>

Test(test_strcmp, base)
{
    void *lib = dlopen(LIB, RTLD_LAZY);
    int (*my_strcmp)(const char *, const char *) = dlsym(lib, "strcmp");

    cr_assert_neq(my_strcmp, NULL);
    cr_assert_eq(my_strcmp("a", "a"), 0);
    cr_assert_eq(my_strcmp("", ""), 0);
    cr_assert_eq(my_strcmp("abcdef", "abcdef"), 0);
    cr_assert_gt(my_strcmp("a", "A"), 0);
    cr_assert_lt(my_strcmp("A", "a"), 0);
    cr_assert_lt(my_strcmp("abcdEf", "abcdef"), 0);
    cr_assert_gt(my_strcmp("abcdef", "abcdEf"), 0);
    cr_assert_lt(my_strcmp("abcd", "abcda"), 0);
    cr_assert_gt(my_strcmp("abcda", "abcd"), 0);
    cr_assert_lt(my_strcmp("", " "), 0);
    cr_assert_gt(my_strcmp(" ", ""), 0);
    dlclose(lib);
}
