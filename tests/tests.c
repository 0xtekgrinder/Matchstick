/*
** EPITECH PROJECT, 2021
** tests.c
** File description:
** this is the file for the tests
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include "matchstick.h"
#include "my.h"

Test(matchstick, load_map_normal)
{
    char **map = load_map(5);
    char *result[] = {"***********",
                     "*    |    *",
                     "*   |||   *",
                     "*  |||||  *",
                     "* ||||||| *",
                     "*|||||||||*",
                     NULL};

    for (int i = 0; result[i]; i++)
        cr_assert_str_eq(map[i], result[i]);
    my_free("2", map);
}

Test(matchstick, get_sticks_normal)
{
    char *result[] = {"***********",
                     "*    |    *",
                     "*   |||   *",
                     "*  |||||  *",
                     "* ||||||| *",
                     "*|||||||||*",
                     NULL};

    cr_assert_eq(1, get_sticks(result[1]));
}

Test(matchstick, remove_sticks_normal)
{
    char **result = load_map(5);

    remove_sticks(result, 1, 1);
    cr_assert_str_eq(result[1], "*         *");
    my_free("2", result);
}

Test(matchstick, check_win_it_isnt)
{
    char *result[] = {"***********",
                     "*    |    *",
                     "*   |||   *",
                     "*  |||||  *",
                     "* ||||||| *",
                     "*|||||||||*",
                     NULL};

    cr_assert_eq(is_it_a_win(result), false);
}

Test(matchstick, check_win_it_is)
{
    char *result[] = {"***********",
                     "*         *",
                     "*         *",
                     "*         *",
                     "*         *",
                     "*         *",
                     NULL};

    cr_assert_eq(is_it_a_win(result), true);
}

Test(matchstick, check_line_no_char)
{
    char *line = "";

    cr_assert_eq(is_line_ok(line, 5), false);
}

Test(matchstick, check_line_no_nb)
{
    char *line = "fgrg";

    cr_assert_eq(is_line_ok(line, 5), false);
}

Test(matchstick, check_line_out_of_range)
{
    char *line = "6";

    cr_assert_eq(is_line_ok(line, 5), false);
}

Test(matchstick, check_line_zero)
{
    char *line = "0";

    cr_assert_eq(is_line_ok(line, 5), false);
}

Test(matchstick, check_line_normal)
{
    char *line = "3";

    cr_assert_eq(is_line_ok(line, 5), true);
}

Test(matchstick, check_matches_no_char)
{
    char *matches = "";
    char *line = "*  |||  *";

    cr_assert_eq(is_matches_ok(matches, line, 5), false);
}

Test(matchstick, check_matches_no_nb)
{
    char *matches = "zeiugr";
    char *line = "*  |||  *";

    cr_assert_eq(is_matches_ok(matches, line, 5), false);
}

Test(matchstick, check_matches_too_much_matches)
{
    char *matches = "6";
    char *line = "*  |||  *";

    cr_assert_eq(is_matches_ok(matches, line, 5), false);
}

Test(matchstick, check_matches_zero)
{
    char *matches = "0";
    char *line = "*  |||  *";

    cr_assert_eq(is_matches_ok(matches, line, 5), false);
}

Test(matchstick, check_matches_too_many)
{
    char *matches = "5";
    char *line = "*  |||  *";

    cr_assert_eq(is_matches_ok(matches, line, 5), false);
}

Test(matchstick, check_matches_normal)
{
    char *matches = "3";
    char *line = "*  |||  *";

    cr_assert_eq(is_matches_ok(matches, line, 5), true);
}

Test(matchstick, check_wrong_number_of_arguments)
{
    char *tab[] = {"test", "amazing", "test", NULL};

    cr_assert_eq(error_handling(5, tab), EXIT_FAILURE);
}

Test(matchstick, check_wrong_not_nb_1)
{
    char *tab[] = {"test", "amazing", "1", NULL};

    cr_assert_eq(error_handling(3, tab), EXIT_FAILURE);
}

Test(matchstick, check_wrong_wrong_nb_1)
{
    char *tab[] = {"test", "0", "3", NULL};

    cr_assert_eq(error_handling(3, tab), EXIT_FAILURE);
}

Test(matchstick, check_wrong_wrong_nb_2)
{
    char *tab[] = {"test", "2000", "3", NULL};

    cr_assert_eq(error_handling(3, tab), EXIT_FAILURE);
}

Test(matchstick, check_wrong_wrong_nb_3)
{
    char *tab[] = {"test", "7", "0", NULL};

    cr_assert_eq(error_handling(3, tab), EXIT_FAILURE);
}

Test(matchstick, all_good_error_handling)
{
    char *tab[] = {"test", "7", "3", NULL};

    cr_assert_eq(error_handling(3, tab), EXIT_SUCCESS);
}

Test(matchstick, get_input_failure)
{
    FILE *stream = fopen("./tests/expected_outputs/temp", "w");
    char buff[512];

    fprintf(stream, "%d", EOF);
    cr_assert_eq(get_input(stream, buff), EXIT_FAILURE);
    fclose(stream);
}

Test(matchstick, create_game_tools_test)
{
    game_tools_t game_tools;
    char *tab[] = {"test", "5", "3", NULL};
    char *result[] = {"***********",
                     "*    |    *",
                     "*   |||   *",
                     "*  |||||  *",
                     "* ||||||| *",
                     "*|||||||||*",
                     "***********",
                     NULL};

    create_game_tools(&game_tools, tab);
    for (int i = 0; result[i]; i++)
        cr_assert_str_eq(game_tools.map[i], result[i]);
    cr_assert_eq(game_tools.max_sticks, 3);
    my_free("2", game_tools.map);
}