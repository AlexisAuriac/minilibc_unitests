/*
** EPITECH PROJECT, 2017
** minilibc
** File description:
** Tests strchr.
*/

#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <criterion/criterion.h>

Test(test_strchr, base)
{
    void *lib = dlopen(LIB, RTLD_LAZY);
    char *(*my_strchr)(const char *, int) = dlsym(lib, "strchr");
    const char *str = "Hello, World!";

    cr_assert_neq(my_strchr, NULL);
    cr_assert_eq(my_strchr(str, 'l'), str + 2);
    cr_assert_eq(my_strchr(str, 'H'), str);
    cr_assert_eq(my_strchr(str, '!'), str + 12);
    cr_assert_eq(my_strchr(str, 'z'), NULL);
    dlclose(lib);
}
