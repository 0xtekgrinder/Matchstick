# Matchstick

An Epitech Project to recreate the nim game with a number of lines changeable as well as a maximum number of sticks you can take each turn.

# Usage:
Compile it with `make` and launch the programm with:
```bash
./matchstick NB_LINES MAX_STICKS
```

# Example:
    $> ./matchstick 2 10
    *****
    * | *
    *|||*
    *****

    Your turn:
    Line: 1
    Matches: 1
    Player removed 1 match(es) from line 1
    *****
    *   *
    *|||*
    *****

    AI's turn...
    AI removed 2 match(es) from line 2
    *****
    *   *
    *|  *
    *****

    Your turn:
    Line: 2
    Matches: 1
    Player removed 1 match(es) from line 2
    *****
    *   *
    *   *
    *****
    You lost, too bad...

# Tests
You can execute functional tests with `./tests/functional-test.sh` and you can run unit tests with `make tests_run`. Use `make coverage` to see the number of lines covered by the unit tests and `make branches` to see the number of branches covered by the unit tests

# Bonus

## The bonuses
There are two types of bonuses:
- AI
- Network

With regard to AI bonuses, you can battle an AI against another AI with four different levels of AI. On top of that, the AI can play as the first player and the user as the second player.

Regarding the Network bonus, you can play against another player coming from another program instance with a binary named server.

## Usage
Compile it with `make bonus`. Run the server with `./server` and then run the binary with:
```bash
 ./matchstick_bonus nb_lines max_sticks -g GAMEMODE [-i1 FIRST_AI] [-i2 SECOND_AI] [-p PLAYER]

OPTIONS
 -g     1: player vs player
        2: player vs AI
        3: AI vs player
        4: AI vs AI

-i1/i2  1: strong AI
        2: medium AI
        3: low AI
        4: very low AI
```

# Author:
- **Matéo VIEL**