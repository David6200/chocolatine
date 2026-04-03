/*
** EPITECH PROJECT, 2025
** unit_test
** File description:
** test
*/

#include "criterion/criterion.h"
#include "../SRC/my.h"
#include "criterion/redirect.h"

Test(my_strcmp, check_compare)
{
    int i = my_strcmp("papa", "papa");
    cr_assert_eq(i, 0);
}

Test(my_strcmp, check_compare_erreur)
{
    int i = my_strcmp("papa", "pap");
    cr_assert_eq(i, 0);
}

Test(output, put_nbr, .init = cr_redirect_stdout)
{
    my_put_nbr(4125);
    cr_assert_stdout_eq_str("4125");
}

Test(output, put_nbr_error, .init = cr_redirect_stdout)
{
    my_put_nbr(4125);
    cr_assert_stdout_neq_str("2008");
}

Test(output, putchar, .init = cr_redirect_stdout)
{
    my_putchar('c');
    cr_assert_stdout_eq_str("c");
}

Test(my_strlen, number)
{
    int i = my_strlen("maison");
    cr_assert_eq(i, 6);
}

Test(my_strlen, false_number)
{
    int i = my_strlen("maison");
    cr_assert_neq(i, 5);
}

Test(my_strdup, copy_string)
{
    char *string = my_strdup("pa pa paw je divageee");
    cr_assert_str_eq(string, "pa pa paw je divageee");
}

Test(my_strdup, copy_not_string)
{
    char *string = my_strdup("pa pa paw je divageee");
    cr_assert_str_neq(string, "pa pa paw je divageee, je perds la raison");
}

Test (output, mini_printf, .init = cr_redirect_stdout)
{
    int i = 625;
    mini_printf("Ah Epitech . J'ai enfin eu le tepitek");
    cr_assert_stdout_eq_str("Ah Epitech . J'ai enfin eu le tepitek");
}

Test(output, putstr, .init = cr_redirect_stdout)
{
    my_putstr("je vais a l'ecole avec ma mere");
    cr_assert_stdout_eq_str("je vais a l'ecole avec ma mere");
}

Test(output, putstr_error, .init = cr_redirect_stdout)
{
    my_putstr("je vais a l'ecole avec ma mere");
    cr_assert_stdout_neq_str("je vais a l'ecole avec ma mere demain");
}

Test(my_strtok, put_line)
{
    char str[] = "Never stop dreaming";
    char *token = my_strtok(str, " ");
    cr_assert_str_eq(token, "Never");
}

Test(my_strtok, put_line_error)
{
    char str[] = "Never stop dreaming";
    char *token = my_strtok(str, " ");
    cr_assert_str_neq(token, "azerty");
}

Test(my_strtok, put_line_more)
{
    char str[] = "Never stop dreaming";
    char *token = my_strtok(str, " ");
    char *tok = my_strtok(NULL, " ");
    char *to = my_strtok(NULL, " ");
    cr_assert_str_eq(token, "Never");
    cr_assert_str_eq(tok, "stop");
    cr_assert_str_eq(to, "dreaming");
    cr_assert_str_neq(to, "Curry");
}

Test(my_getnbr, check_number_pase)
{
    int i = my_getnbr("45");
    cr_assert_eq(45, i);
}

Test(my_getnbr, check_number_pase_error)
{
    int i = my_getnbr("45");
    cr_assert_neq(46, i);
}

Test(my_getnbr, check_number_pase_string)
{
    int i = my_getnbr("azerty");
    cr_assert_eq(-1, i);
}




