/*
** EPITECH PROJECT, 2017
** minilibc
** File description:
** Tests strncmp.
*/

#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <criterion/criterion.h>

Test(test_strncmp, base)
{
    void *lib = dlopen(LIB, RTLD_LAZY);
    int (*my_strncmp)(const char *, const char *, size_t) =
    dlsym(lib, "strncmp");

    cr_assert_neq(my_strncmp, NULL);
    cr_assert_eq(my_strncmp("", "", 99), 0);
    cr_assert_eq(my_strncmp("abc", "abc", 99), 0);
    cr_assert_gt(my_strncmp("abcd", "abc", 99), 0);
    cr_assert_lt(my_strncmp("abc", "abcd", 99), 0);
    cr_assert_gt(my_strncmp("abce", "abcd", 99), 0);
    cr_assert_lt(my_strncmp("abcd", "abce", 99), 0);
    cr_assert_gt(my_strncmp("a\203", "a", 2), 0);
    cr_assert_gt(my_strncmp("a\203", "a\003", 2), 0);
    cr_assert_eq(my_strncmp("abce", "abcd", 3), 0);
    cr_assert_eq(my_strncmp("abce", "abc", 3), 0);
    cr_assert_lt(my_strncmp("abcd", "abce", 4), 0);
    cr_assert_eq(my_strncmp("abc", "def", 0), 0);
    cr_assert_gt(my_strncmp("abc", "", (size_t) -1), 0);
    cr_assert_eq(my_strncmp("abc", "abc", (size_t) -2), 0);
    dlclose(lib);
}
