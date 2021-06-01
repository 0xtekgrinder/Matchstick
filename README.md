# Matchstick

An Epitech Project to recreate the nim game with an amount of lines changeable as well as a maximum amount of sticks you can take each turn.

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
You can execute the fonctionnall tests with `./tests/functionnal-test.sh` and you can run the unit tests with `make tests_run`. Use `make coverage` to see the amount of lines covered by the unit tests and `make branches` to see the amount of branches covered by the unit tests

# Bonus

## The bonuses
There is two kind of bonuses:
- AI
- Network

On the AI bonuses, you can battle an ai against another ai with four differents levels of AI. On top of that, the ai can play as the first playeyer and the user as the second player.

On the Network bonuses, you can play against another player from another instance of the program with a server binary.

## The Usage
Compile it with `make bonus`. Run the server with `./server` and then run the binary with:
```bash
 ./matchstick_bonus nb_lines max_sticks -g GAMEMODE [-i1 FIRST_IA] [-i2 SECOND_IA] [-p PLAYER]

OPTIONS
 -g     1: player vs player
        2: player vs IA
        3: IA vs player
        4: IA vs IA

-i1/i2  1: strong IA
        2: medium IA
        3: low IA
        4: very low IA
```

# Autor:
- **Matéo VIEL**