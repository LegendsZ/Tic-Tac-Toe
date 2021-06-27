#include <iostream>

#define MAX 9
#define ROW 3
#define COLUMN 3

void drawGame(const char data[]);
int formulaGame(int x, int y);

char check(const char* data);
char logicGame(const char* data);
void changeLogicGame(const char* data, int toChange, int change);
int makeMove(char* data, int startH, const int* randomized);
int makeMove_2(char* data, int start, int end, int increment);
void randomized_array(int* randomized);

int countX = 0;
int countO = 0;
int eight[8];

int main()
{
    system("title TripleTs / Made By LegendsZ#1526 @ Discord");
    while (true) {
        srand(time(0));
        std::cout << "[CONSOLE]: Format: '[x][y]' - Example: '12'\n";

        char gameData[MAX];
        const bool botFirst = false;
        int* randomArray = new int[8];

        for (int i = 0; i < MAX; i++) { //can also get max by sizeof(gameData)/sizeof(decltype (gameData[0]))
            gameData[i] = ' ';
            if (i != MAX - 1) {
                eight[i] = 0;
            }
        }

        if (botFirst == true) {
            randomized_array(randomArray);
            int changed = makeMove(gameData, 0, randomArray);
            changeLogicGame(gameData, changed, -1);
        }
        while (true) {
            drawGame(gameData);
            std::cout << "[CONSOLE]: Your turn > ";
            std::string cmd;
            std::cin >> cmd;

            if (cmd.length() > 2 || cmd.length() < 1 || atoi(cmd.c_str()) > 33 || atoi(cmd.c_str()) < 0) {
                std::cout << "[CONSOLE]: Error: Invalid Input - Follow format!\n\n";
                system("pause");
                system("cls");
                std::cout << "[CONSOLE]: Format: '[x][y]' - Example: '12'\n";
            }
            else {
                int x = cmd[0] - 48;
                int y = cmd[1] - 48;

                int pos = formulaGame(x, y);
                if (gameData[pos] == ' ') {
                    gameData[pos] = 'X';

                    system("cls");
                    std::cout << "[CONSOLE]: Format: '[x][y]' - Example: '12'\n";

                    drawGame(gameData);
                    changeLogicGame(gameData, formulaGame(x, y), 1);
                    if (check(gameData) != ' ') {
                        break;
                    }

                    randomized_array(randomArray);
                    int changed = makeMove(gameData, 0, randomArray);

                    //std::cout << changed << "\n";
                    //system("pause");

                    system("cls");
                    std::cout << "[CONSOLE]: Format: '[x][y]' - Example: '12'\n";

                    changeLogicGame(gameData, changed, -1);
                    if (check(gameData) != ' ') {
                        break;
                    }
                }
                else {
                    std::cout << "[CONSOLE]: Error: Invalid Input - Don't put the same coordinate!\n\n";
                    system("pause");
                    system("cls");
                    std::cout << "[CONSOLE]: Format: '[x][y]' - Example: '12'\n";
                }
            }
        }
        system("pause");
        system("cls");
    }
}

void drawGame(const char data[]) {
    std::cout << "\n\n   1 2 3\n  -------\n1 |" << data[0] << "|" << data[1] << "|" << data[2] << "|\n  -------\n2 |" << data[3] << "|" << data[4] << "|" << data[5] << "|\n  -------\n3 |" << data[6] << "|" << data[7] << "|" << data[8] << "|\n  -------\n\n";
}

void changeLogicGame(const char* data, int toChange, int change) {

    if (data[toChange] == 'X') {
        countX++;
    }
    else if (data[toChange] == 'O') {
        countO++;
    }
    if (toChange == 0 || toChange == 3 || toChange == 6) {
        eight[3] += change;
        if (toChange == 0) {
            eight[0] += change;
            eight[6] += change;
        }
        else if (toChange == 3) {
            eight[1] += change;
        }
        else if (toChange == 6) {
            eight[2] += change;
            eight[7] += change;
        }
    }
    else if (toChange == 1 || toChange == 4 || toChange == 7) {
        eight[4] += change;
        if (toChange == 1) {
            eight[0] += change;
        }
        else if (toChange == 4) {
            eight[7] += change;
            eight[6] += change;
            eight[1] += change;
        }
        else if (toChange == 7) {
            eight[2] += change;
        }
    }
    else if (toChange == 2 || toChange == 5 || toChange == 8) {
        eight[5] += change;
        if (toChange == 2) {
            eight[0] += change;
            eight[7] += change;
        }
        else if (toChange == 5) {
            eight[1] += change;
        }
        else if (toChange == 8) {
            eight[2] += change;
            eight[6] += change;
        }
    }
}

char logicGame(const char* data) {
    if (countX < 3 && countO < 3) {
        return ' ';
    }

    for (int i = 0; i < 8; i++) {
        if (eight[i] == 3) {
            return 'W';
        }
        else if (eight[i] == -3) {
            return 'L';
        }
    }
    for (int i = 0; i < ROW * COLUMN; i++) {
        if (data[i] == ' ') {
            return ' ';
        }
    }
    return 'T';
}

char check(const char *data) {
    if (logicGame(data) == 'W') {
        system("cls");
        std::cout << "[CONSOLE]: Formats: '[x][y]' - Example: '12'\n";
        drawGame(data);
        std::cout << "[CONSOLE]: You Won!\n\n";
        return 'W';
    }
    else if (logicGame(data) == 'L') {
        system("cls");
        std::cout << "[CONSOLE]: Formats: '[x][y]' - Example: '12'\n";
        drawGame(data);
        std::cout << "[CONSOLE]: You Lost!\n\n";
        return 'L';
    }
    else if (logicGame(data) == 'T') {
        system("cls");
        std::cout << "[CONSOLE]: Formats: '[x][y]' - Example: '12'\n";
        drawGame(data);
        std::cout << "[CONSOLE]: You Tied!\n\n";
        return 'T';
    }
    return ' ';
}

int formulaGame(int x, int y) {
    return (3 * y + x - 4);
}

int makeMove(char *data, int startH, const int *randomized) {
    int highest = startH;
    int lowest = rand() % 8;
    int picked = rand() % 8;

    for (int i = startH; i < 8; i++) {
        if (eight[randomized[i]] >= eight[highest]) {
            highest = randomized[i];
        }
    }

    for (int i = 0; i < 8; i++) {
        if (eight[randomized[i]] <= eight[lowest]) {
            lowest = randomized[i];
        }
    }

    if (abs(eight[lowest]) == eight[highest]) {
        picked = lowest;
    }
    else {
        picked = highest;
    }

    int changed = 0;

    //std::cout << picked << "\n";
    //system("pause");

    if (picked >= 0 && picked <= 2) {
        switch (picked)
        {
        case 0:
            changed = makeMove_2(data, 0, 2, 1);
            if (changed == -1) {
                startH = highest+1;
                return makeMove(data, startH, randomized);
            }
            else {
                return changed;
            }
            break;
        case 1:
            changed = makeMove_2(data, 3, 5, 1);
            if (changed == -1) {
                startH = highest + 1;
                return makeMove(data, startH, randomized);
            }
            else {
                return changed;
            }
            break;
        case 2:
            changed =  makeMove_2(data, 6, 8, 1);
            if (changed == -1) {
                startH = highest + 1;
                return makeMove(data, startH, randomized);
            }
            else {
                return changed;
            }
            break;
        default:
            break;
        }
    }
    else if (picked >= 3 && picked <= 5) {
        switch (picked)
        {
        case 3:
            changed = makeMove_2(data, 0, 6, 3);
            if (changed == -1) {
                startH = highest + 1;
                return makeMove(data, startH, randomized);
            }
            else {
                return changed;
            }
            break;
        case 4:
            changed = makeMove_2(data, 1, 7, 3);
            if (changed == -1) {
                startH = highest + 1;
                return makeMove(data, startH, randomized);
            }
            else {
                return changed;
            }
            break;
        case 5:
            changed = makeMove_2(data, 2, 8, 3);
            if (changed == -1) {
                startH = highest + 1;
                return makeMove(data, startH, randomized);
            }
            else {
                return changed;
            }
            break;
        default:
            break;
        }
    }
    else if (picked >= 6) {
        switch (picked)
        {
        case 6:
            changed = makeMove_2(data, 0, 8, 4);
            if (changed == -1) {
                startH = highest + 1;
                return makeMove(data, startH, randomized);
            }
            else {
                return changed;
            }
            break;
        case 7:
            return makeMove_2(data, 2, 6, 2);
            break;
        default:
            break;
        }
    }
    return -1;
}

int makeMove_2(char *data, int start, int end, int increment) {
    int availables[3] = { -1,-1,-1 };
    int available_index = -1;

    for (int i = start; i < end + 1; i += increment) {
        if (data[i] == ' ') {
            availables[++available_index] = i;
        }
    }
    if (available_index == -1) {
        return -1;
    }
    int picked = rand() % (available_index+1);
    data[availables[picked]] = 'O';
    return availables[picked];

    /*for (int i = start; i < end + 1; i += increment) {
        if (data[i] == ' ') {
            data[i] = 'O';
            return i;
        }
    }
    return -1;*/
}

void randomized_array(int* randomized) {
    int randomized_index = 0;

    for (int i = 0; i < 8; i++) {
        randomized[i] = -1;
    }

    while (randomized_index != 8) {
        int random = rand() % 8;
        bool notThere = true;
        for (int i = 0; i <= randomized_index; i++) {
            if (randomized[i] == random) {
                notThere = false;
            }
        }
        if (notThere == true) {
            randomized[randomized_index++] = random;
            //std::cout << random << "\n";
        }
    }
    //system("pause");
}