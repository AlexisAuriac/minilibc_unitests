/*
** EPITECH PROJECT, 2017
** minilibc
** File description:
** Tests strstr.
*/

#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <criterion/criterion.h>

Test(test_strstr, base)
{
    void *lib = dlopen(LIB, RTLD_LAZY);
    char *(*my_strstr)(const char *, const char *) =
    dlsym(lib, "strstr");
    const char *str = "Hello, World!";

    cr_assert_neq(my_strstr, NULL);
    cr_assert_eq(my_strstr(str, "ll"), str + 2);
    cr_assert_eq(my_strstr(str, "rl"), str + 9);
    cr_assert_eq(my_strstr(str, "Hl"), NULL);
    cr_assert_eq(my_strstr(str, ""), str);
    cr_assert_eq(my_strstr(str, "ld!l"), NULL);
    cr_assert_eq(my_strstr(str, "lal"), NULL);
    cr_assert_eq(my_strstr(str, str), str);
    cr_assert_eq(my_strstr(str, str + 1), str + 1);
    cr_assert_eq(my_strstr(str + 1, str), NULL);
    dlclose(lib);
}
