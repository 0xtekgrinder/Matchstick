#!/bin/bash
##
## EPITECH PROJECT, 2020
## test.sh
## File description:
## this is the fonctional test file
##

test () {
    echo -ne $3 | ./matchstick "$1" "$2" > result
    diff result "tests/expected_outputs/$4" &> /dev/null
    if [ $? -eq 0 ]
    then
        echo "success for $4"
    else
        echo "fail for $4"
    fi
}

test_win_loose() {
    echo -ne $3 | ./matchstick "$1" "$2" > /dev/null
    if [ $? -eq $(($4)) ]
    then
        echo "success for $5"
    else
        echo "fail for $5"
    fi
}

test "5" "4" "\n" "error_line_1"
test "5" "4" "iuth\n" "error_line_2"
test "5" "4" "0\n" "error_line_3"
test "5" "4" "6\n" "error_line_4"
test "5" "4" "3\n\n" "error_matches_1"
test "5" "4" "3\nibh\n" "error_matches_2"
test "5" "4" "3\n5\n" "error_matches_3"
test "5" "4" "3\n0\n" "error_matches_4"
test "5" "4" "1\n3\n" "error_matches_5"
test "5" "4" "1\n1\n" "normal_rm"
test_win_loose "2" "5" "1\n1\n2\n1\n" "2" "ai_win"
test_win_loose "2" "5" "2\n3\n" "1" "player_win"
rm result