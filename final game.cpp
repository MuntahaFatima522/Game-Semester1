#include <iostream>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);
void setColor(int color);
void hideCursor();

void printShootingMario();
int Menu();
int Rules();
int Instructions();

void level1();
void level2();
void level3();

void printHeadings();
void printMaze();

void printPlayer();
void erasePlayer();

void movePlayerRight();
void movePlayerLeft();
void movePlayerDown();
void movePlayerUp();

void fire();
void printBullet(int x, int y);
void eraseBullet(int x, int y);
void MoveBullet();
void FireBullet();
void makeBulletInActive(int index);

void printEnemy1();
void eraseEnemy1();
void moveEnemy1();

void printEnemy2();
void eraseEnemy2();
void moveEnemy2();

void printEnemy3();
void eraseEnemy3();
void moveEnemy3();

void addScore();
void minusScore();
void printScore();
void printLives();
void printEnemyScore();
void printShieldNumber();

void gameOver();
void Win();

void updateEnemy1Bullet();
void updateEnemy2Bullet();
void updateEnemy3Bullet();

void fireEnemy3();
void fireEnemy2();
void fireEnemy1();

void eraseEnemy1Bullet(int x, int y);
void printEnemy1Bulet(int x, int y);
void eraseEnemy2Bullet(int x, int y);
void printEnemy2Bulet(int x, int y);
void eraseEnemy3Bullet(int x, int y);
void printEnemy3Bullet(int x, int y);

void printBonus();
void eraseBonus();
void checkBonusCollection();
void generateNewBonus();
void checkEnemyBonusCollision();

void drawShield();
void eraseShield();
void handleShield();

int Px = 2, Py = 37;

int Ex1 = 190, Ey1 = 29;
int Ex2 = 75, Ey2 = 45;
int Ex3 = 192, Ey3 = 11;

char player[10][14] = {
    {' ', ' ', ' ', ' ', ' ', ' ', '_', '_', '_'},
    {' ', ' ', ' ', ' ', '_', '|', ' ', ' ', ' ', '|', '_', '_'},
    {' ', ' ', ' ', '|', '_', '_', '_', '_', '_', '_', '_', '_', '|'},
    {' ', ' ', ' ', '|', '_', ' ', ' ', ' ', ' ', '.', '_', '|'},
    {' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', '_'},
    {' ', ' ', ' ', '(', '_', '_', '_', '_', '_', '_', '_', '|'},
    {' ', ' ', '/', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\\'},
    {' ', '/', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '\\'},
    {' ', ' ', '|', '|', '_', '_', '_', '_', '_', '_', '_', '|', '|'},
    {' ', ' ', '|', ')', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ')'}};

char Enemy1[5][11] = {
    {' ', ' ', ' ', ' ', '_', '_', '_'},
    {' ', ' ', ' ', '(', '.', ' ', '.', ')'},
    {' ', ' ', '(', '_', '_', '_', '_', '_', ')'},
    {' ', ' ', ' ', ' ', '(', '_', ')'},
    {' ', ' ', ' ', ' ', '|', ' ', '|'}};

char Enemy2[3][9] = {
    {' ', ' ', '\\', '_', '_', '_', '/'},
    {' ', '-', '(', '_', '_', '_', ')', '-'},
    {' ', ' ', '/', ' ', ' ', ' ', '\\'}};

char Enemy3[4][11] = {
    {' ', ' ', ' ', '_', '_', '_'},
    {' ', ' ', '/', '.', ' ', '.', '\\'},
    {' ', '/', '_', '_', '_', '_', '_', '\\'},
    {' ', '|', '|', ' ', ' ', ' ', '|', '|'}};

int score = 0;
int lives = 5;
int enemy1Score = 0;
int enemy2Score = 0;
int enemy3Score = 0;

int bulletX[5000];
int bulletY[5000];
bool isBulletActive[5000] = {false};
int bulletCount = 0;

int E1BulletX[5] = {-1, -1, -1, -1, -1};
int E1BulletY[5] = {-1, -1, -1, -1, -1};
int E2BulletX[5] = {-1, -1, -1, -1, -1};
int E2BulletY[5] = {-1, -1, -1, -1, -1};
int E3BulletX[5] = {-1, -1, -1, -1, -1};
int E3BulletY[5] = {-1, -1, -1, -1, -1};

int fireCooldown1 = 0, fireCooldown2 = 0, fireCooldown3 = 0;

int E1bulletSpeedMultiplier = 5;
int E2bulletSpeedMultiplier = 2;
int E3bulletSpeedMultiplier = 2;

bool bonusCollected = false;
int bonusX = 23, bonusY = 20;
const int TotalPositions = 15;
int possibleBonusX[TotalPositions] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 110, 125, 150, 176, 114, 131};
int possibleBonusY[TotalPositions] = {40, 29, 15, 20, 25, 7, 34, 17, 22, 27, 23, 13, 39, 41, 19};

bool shieldActive = false;
int shieldDuration = 200;
int shieldCooldown = 0;
int shieldX, shieldY;
int shieldUses = 3;

main()
{
    hideCursor();
    int option;
    system("cls");
    printShootingMario();
    option = Menu();
    system("cls");
    if (option == 1)
    {
        printShootingMario();
        setColor(13);
        cout << "LEVELS >>" << endl;
        cout << "----------" << endl;
        cout << endl;
        int op;
        setColor(7);
        setColor(11);

        cout << "Choose the level.." << endl
             << endl;
        setColor(7);
        setColor(14);
        cout << "1. Easy.." << endl;
        cout << "2. Normal.." << endl;
        cout << "3. Hard.." << endl;
        cout << "4. Exit.." << endl;
        cout << "5. Go back.." << endl;
        cout << endl;
        setColor(7);
        setColor(11);
        cout << "Your option: ";
        cin >> op;
        setColor(7);

        if (op == 1)
        {
            level1();
        }
        else if (op == 2)
        {
            level2();
        }
        else if (op == 3)
        {
            level3();
        }
        else if (op == 4)
        {
            return 0;
        }
        else if (op == 5)
        {
            main();
        }
        else
        {
            cout << "Wrong option.." << endl;
        }
    }
    else if (option == 2)
    {
        printShootingMario();
        Rules();
    }
    else if (option == 3)
    {
        printShootingMario();
        Instructions();
    }
    else if (option == 4)
    {
        return 0;
    }
    else
    {
        cout << "Wrong option.." << endl;
    }
}

void printShootingMario()
{
    setColor(12);
    cout << endl
         << endl
         << endl;
    cout << "  _____ _                 _    _                 _    _             _                        " << endl;
    cout << " / ____| |               | |  (_)               | \\  / |           (_)                      " << endl;
    cout << "| (___ | |               | |___   _  _   ____   |  \\/  | __ _ _  __ _                       " << endl;
    setColor(7);
    setColor(9);
    cout << " \\___ \\  |___  ____  ____|  __)| | |/ \\ //  \\\\  |      |/ _` | |/_/| |   ____           " << endl;
    cout << " ____) |  _  |//  \\\\//  \\\\ |_| |_|  __ |\\\\__//  | |\\/| | (_| | |   | |_ //  \\\\      " << endl;
    cout << "|_____/|_| |_|\\\\__//\\\\__//___)___)_| |_|   ||   |_|  |_|\\__,_|_|   |___)\\\\__//        " << endl;
    cout << "                                         __||                                                " << endl;
    cout << endl
         << endl
         << endl;
    setColor(7);
}

int Menu()
{
    setColor(13);
    cout << "MENU >>" << endl;
    cout << "----------" << endl;
    cout << endl;
    setColor(7);
    setColor(11);
    int option;
    cout << "Choose one of the following: " << endl
         << endl;
    setColor(7);
    setColor(14);
    cout << "1. Start Playing.." << endl;
    cout << "2. Rules.." << endl;
    cout << "3. Instructions.." << endl;
    cout << "4. Exit.." << endl;
    cout << endl;
    setColor(7);
    setColor(11);
    cout << "Your option: ";
    cin >> option;
    return option;
    setColor(7);
}
void level1()
{
    system("cls");
    printMaze();
    printHeadings();
    printBonus();
    printEnemy1();
    printPlayer();
    printScore();
    while (true)
    {
        if (lives <= 0)
        {
            break;
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            movePlayerRight();
        }

        if (GetAsyncKeyState(VK_UP))
        {
            movePlayerUp();
        }
        if (GetAsyncKeyState(VK_LEFT))
        {
            movePlayerLeft();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            movePlayerDown();
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            FireBullet();
        }
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            gameOver();
            break;
        }
        handleShield();
        MoveBullet();
        moveEnemy1();
        checkBonusCollection();
        checkEnemyBonusCollision();
        Sleep(50);
    }
    if (score <= enemy1Score)
    {
        gameOver();
    }
    if (score > enemy1Score)
    {
        Win();
    }
}

void level2()
{
    system("cls");
    printMaze();
    printHeadings();
    printBonus();
    printEnemy1();
    printEnemy3();
    printPlayer();
    printScore();
    while (true)
    {
        if (lives <= 0)
        {
            break;
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            movePlayerRight();
        }

        if (GetAsyncKeyState(VK_UP))
        {
            movePlayerUp();
        }
        if (GetAsyncKeyState(VK_LEFT))
        {
            movePlayerLeft();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            movePlayerDown();
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            FireBullet();
        }
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            gameOver();
            break;
        }
        handleShield();
        MoveBullet();
        moveEnemy1();
        moveEnemy3();
        checkBonusCollection();
        checkEnemyBonusCollision();
        Sleep(50);
    }
    if (score <= enemy1Score && score <= enemy3Score)
    {
        gameOver();
    }
    if (score > enemy1Score && score > enemy3Score)
    {
        Win();
    }
}
void level3()
{
    system("cls");
    printMaze();
    printHeadings();
    printBonus();
    printEnemy1();
    printEnemy2();
    printEnemy3();
    printPlayer();
    printScore();
    while (true)
    {
        if (lives <= 0)
        {
            break;
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            movePlayerRight();
        }

        if (GetAsyncKeyState(VK_UP))
        {
            movePlayerUp();
        }
        if (GetAsyncKeyState(VK_LEFT))
        {
            movePlayerLeft();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            movePlayerDown();
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            FireBullet();
        }
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            gameOver();
            break;
        }
        handleShield();
        MoveBullet();
        moveEnemy1();
        moveEnemy2();
        moveEnemy3();
        checkBonusCollection();
        checkEnemyBonusCollision();
        Sleep(50);
    }
    if (score <= enemy1Score && score <= enemy2Score && score <= enemy3Score)
    {
        gameOver();
    }
    if (score > enemy1Score && score > enemy2Score && score > enemy3Score)
    {
        Win();
    }
}
int Rules()
{
    setColor(13);
    cout << "RULES>>" << endl;
    cout << "----------" << endl;
    cout << endl
         << endl;
    setColor(7);
    setColor(11);
    cout << "About Score Of Player >" << endl;
    cout << "--------------------------" << endl;
    setColor(7);
    setColor(14);
    cout << "1. Initially the Score(of player) will be zero. " << endl;
    cout << "2. Score will increase if player collects bonus pill or fires an enemy. " << endl;
    cout << "3. Score will decrease if any enemy fires at player." << endl
         << endl;
    setColor(7);
    setColor(11);
    cout << "About Lives Of Player >" << endl;
    cout << "--------------------------" << endl;
    setColor(7);
    setColor(14);
    cout << "1. Initially the Lives(of player) will be 5. " << endl;
    cout << "2. Lives of player will decrease if it touches an enemy." << endl
         << endl;
    setColor(7);
    setColor(11);
    cout << "About Health Of Enemies >" << endl;
    cout << "--------------------------" << endl;
    setColor(7);
    setColor(14);
    cout << "1. Initially the Health(of all enemies) will be zero. " << endl;
    cout << "2. Enemies health will increase if they fire at the player." << endl
         << endl;
    setColor(7);
    setColor(11);
    cout << "About Security of Player >" << endl;
    cout << "--------------------------" << endl;
    setColor(7);
    setColor(14);
    cout << "1. Lives and score do not decrease if the shield is activeted. " << endl
         << endl;
    setColor(7);
    setColor(11);
    cout << "About Win Or Loss >" << endl;
    cout << "--------------------------" << endl;
    setColor(7);
    setColor(14);
    cout << "1. Player will win the game if the lives become zero and his score is greater than the health of all enemies." << endl;
    cout << "2. Game will be over if the lives become zero and  the score of player is less than health of all enemies." << endl;
    cout << "3. If the player quits the game by pressing ESCAPE key, the game will be over.";
    cout << endl
         << endl
         << endl;
    setColor(7);
    setColor(9);
    int op;
    cout << "Do you want to play game?" << endl;
    setColor(7);
    setColor(12);
    cout << "1. Yes.." << endl;
    cout << "2. No.." << endl;
    setColor(7);
    setColor(9);
    cout << "Your option: ";
    cin >> op;
    if (op == 1)
    {
        main();
    }
    else
    {
        return 0;
    }
    setColor(7);
}

int Instructions()
{
    setColor(13);
    cout << "INSTRUCTIONS>>" << endl;
    cout << "----------------" << endl;
    cout << endl
         << endl;
    setColor(7);
    setColor(11);

    cout << "For Movement Of Player >" << endl;
    cout << "--------------------------" << endl;
    setColor(7);
    setColor(14);

    cout << "1. Press "
            "UP ARROW KEY"
            " to move player upward. "
         << endl;
    cout << "2. Press "
            "DOWN ARROW KEY"
            " to move player downward. "
         << endl;
    cout << "3. Press "
            "RIGHT ARROW KEY"
            " to move player rightward. "
         << endl;
    cout << "4. Press "
            "LEFT ARROW KEY"
            " to move player leftward. "
         << endl;
    cout << "5. Press "
            "SPACE BAR"
            " to move player upward. "
         << endl;
    cout << "6. Press "
            "SHIFT KEY"
            " to activate shield. "
         << endl;
    cout << endl;
    setColor(7);
    setColor(11);

    cout << "To Quit the Game >" << endl;
    cout << "--------------------------" << endl;
    setColor(7);
    setColor(14);

    cout << "1. Press "
            "ESCAPE KEY"
            " to quit the game. "
         << endl;
    cout << endl
         << endl
         << endl;
    setColor(7);
    setColor(9);

    int op;
    cout << "Do you want to play game?" << endl;
    setColor(7);
    setColor(12);

    cout << "1. Yes.." << endl;
    cout << "2. No.." << endl;
    setColor(7);
    setColor(9);

    cout << "Your option: ";
    cin >> op;
    if (op == 1)
    {
        main();
    }
    else
    {
        return 0;
    }
    setColor(7);
}
void printHeadings()
{
    cout << endl;
    printScore();
    printLives();
    printEnemyScore();
    printShieldNumber();
    cout << endl
         << endl;
}

void printMaze()
{
    setColor(15);
    gotoxy(0,0);
    cout << "_____________________________________________________________________________________________________________________________________________________________________________________________________________" <<endl;
    cout << "|***********************************************************************************************************************************************************************************************************|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*_________________________________________________________________________________________________________________________________________________________________________________________________________*|" <<endl;
    cout << "|***********************************************************************************************************************************************************************************************************|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*                                                                                                                                                                                                         *|" <<endl;
    cout << "|*_________________________________________________________________________________________________________________________________________________________________________________________________________*|" <<endl;

    cout << endl;
    setColor(9);
    cout << "Press";
    setColor(7);
    setColor(12);
    cout << " Escape ";
    setColor(7);
    setColor(9);
    cout << "key to exit..." << endl;
    setColor(7);
}

void printPlayer()
{
    setColor(12);
    for (int i = 0; i < 10; i++)
    {
        gotoxy(Px, Py + i);
        if (i == 3)
        {
            setColor(7);
            setColor(9);
        }
        for (int j = 0; j < 14; j++)
        {
            cout << player[i][j];
        }
    }
    setColor(7);

    if (shieldActive)
    {
        drawShield();
    }
}

void erasePlayer()
{
    for (int i = 0; i < 10; i++)
    {
        gotoxy(Px, Py + i);
        for (int j = 0; j < 14; j++)
        {
            cout << " ";
        }
    }

    if (shieldActive)
    {
        eraseShield();
    }
}

void movePlayerRight()
{
    if (getCharAtxy(Px + 15, Py) == ' ')
    {
        erasePlayer();
        Px = Px + 1;
        printPlayer();
    }
}

void movePlayerUp()
{
    if (getCharAtxy(Px, Py - 1) == ' ')
    {
        erasePlayer();
        Py = Py - 1;
        printPlayer();
    }
}

void movePlayerDown()
{
    if (getCharAtxy(Px, Py + 10) == ' ')
    {
        erasePlayer();
        Py = Py + 1;
        printPlayer();
    }
}

void movePlayerLeft()
{
    if (getCharAtxy(Px - 1, Py) == ' ')
    {
        erasePlayer();
        Px = Px - 1;
        printPlayer();
    }
}

void printBullet(int x, int y)
{
    setColor(12);
    gotoxy(x, y);
    cout << "_";
    setColor(7);
}

void eraseBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}

void makeBulletInActive(int index)
{
    isBulletActive[index] = false;
}

void FireBullet()
{
    bulletX[bulletCount] = Px + 15;
    bulletY[bulletCount] = Py + 7;
    isBulletActive[bulletCount] = true;
    gotoxy(Px + 15, Py + 7);
    cout << "_";
    bulletCount++;
}

void MoveBullet()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (bulletX[x] >= 195)
        {
            eraseBullet(bulletX[x], bulletY[x]);
            makeBulletInActive(x);
            continue;
        }

        if (shieldActive &&
            bulletX[x] >= shieldX && bulletX[x] <= shieldX + 2 &&
            bulletY[x] == shieldY)
        {
            eraseBullet(bulletX[x], bulletY[x]);
            makeBulletInActive(x);
            continue;
        }

        if ((Ex1 + 8 >= bulletX[x] && Ex1 <= bulletX[x]) && (Ey1 + 4 >= bulletY[x] && Ey1 <= bulletY[x]))
        {
            addScore();
            enemy1Score--;
            printEnemyScore();
            eraseBullet(bulletX[x], bulletY[x]);
            makeBulletInActive(x);
            continue;
        }
        if ((Ex2 <= bulletX[x] && Ex2 + 6 >= bulletX[x]) && (Ey2 <= bulletY[x] && Ey2 + 2 >= bulletY[x]))
        {
            addScore();
            enemy2Score--;
            printEnemyScore();
            eraseBullet(bulletX[x], bulletY[x]);
            makeBulletInActive(x);
            continue;
        }
        if ((bulletX[x] >= Ex3 && bulletX[x] <= Ex3 + 8) && (bulletY[x] >= Ey3 && bulletY[x] <= Ey3 + 3))
        {
            addScore();
            enemy3Score--;
            printEnemyScore();
            eraseBullet(bulletX[x], bulletY[x]);
            makeBulletInActive(x);
            continue;
        }

        else
        {
            eraseBullet(bulletX[x], bulletY[x]);
            bulletX[x] = bulletX[x] + 2;
            printBullet(bulletX[x], bulletY[x]);
        }
    }
}

void printEnemy1()
{
    setColor(3);
    for (int i = 0; i < 5; i++)
    {
        gotoxy(Ex1, Ey1 + i);
        for (int j = 0; j < 11; j++)
        {
            cout << Enemy1[i][j];
        }
        cout << endl;
    }
    setColor(7);
}

void eraseEnemy1()
{
    for (int i = 0; i < 5; i++)
    {
        gotoxy(Ex1, Ey1 + i);
        for (int j = 0; j < 11; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void moveEnemy1()
{
    gotoxy(Ex1, Ey1);
    eraseEnemy1();
    Ex1--;
    if (Ex1 < 2)
    {
        Ex1 = 190;
    }
    if ((Ex1 + 8 >= Px && Ex1 <= Px + 14) && (Ey1 + 4 >= Py && Ey1 <= Py + 9))
    {
        Ex1 = 190;
        if (!shieldActive)
        {
            lives--;
            printLives();
        }
        printEnemyScore();
    }
    if (fireCooldown1 == 0)
    {
        fireEnemy1();
        fireCooldown1 = 15;
    }
    else
    {
        fireCooldown1--;
    }
    for (int i = 0; i < E1bulletSpeedMultiplier; i++)
    {
        updateEnemy1Bullet();
    }

    gotoxy(Ex1, Ey1);
    printEnemy1();
}

void printEnemy1Bullet(int x, int y)
{
    setColor(3);
    gotoxy(x, y);
    cout << "...";
    setColor(7);
}

void eraseEnemy1Bullet(int x, int y)
{
    gotoxy(x, y);
    cout << "   ";
}

void fireEnemy1()
{
    for (int i = 0; i < 5; i++)
    {
        if (E1BulletX[i] == -1 && E1BulletY[i] == -1)
        {
            E1BulletX[i] = Ex1 - 3;
            E1BulletY[i] = Ey1 + 2;
            break;
        }
    }
}

void updateEnemy1Bullet()
{
    for (int i = 0; i < 5; i++)
    {
        if (E1BulletX[i] != -1 && E1BulletY[i] != -1)
        {
            eraseEnemy1Bullet(E1BulletX[i], E1BulletY[i]);
            E1BulletX[i]--;

            if (E1BulletX[i] < 4 || (E1BulletX[i] >= Px && E1BulletX[i] <= Px + 14 && E1BulletY[i] >= Py && E1BulletY[i] <= Py + 9))
            {
                if (E1BulletX[i] >= Px && E1BulletX[i] <= Px + 14 && E1BulletY[i] >= Py && E1BulletY[i] <= Py + 9)
                {
                    if (!shieldActive)
                    {
                        minusScore();
                        enemy1Score++;
                        printEnemyScore();
                    }
                }
                E1BulletX[i] = -1;
                E1BulletY[i] = -1;
            }
            else
            {
                printEnemy1Bullet(E1BulletX[i], E1BulletY[i]);
            }
        }
    }
}

void printEnemy2()
{
    setColor(14);
    for (int i = 0; i < 3; i++)
    {
        gotoxy(Ex2, Ey2 + i);
        for (int j = 0; j < 9; j++)
        {
            cout << Enemy2[i][j];
        }
        cout << endl;
    }

    setColor(7);
}

void eraseEnemy2()
{
    for (int i = 0; i < 3; i++)
    {
        gotoxy(Ex2, Ey2 + i);
        for (int j = 0; j < 9; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void moveEnemy2()
{
    gotoxy(Ex2, Ey2);
    eraseEnemy2();
    Ey2--;
    if (Ey2 < 11)
    {
        Ey2 = 45;
    }
    if (Ex2 <= Px + 14 && Ex2 + 6 >= Px && Ey2 <= Py + 9 && Ey2 + 2 >= Py)
    {
        Ey2 = 45;
        if (!shieldActive)
        {
            lives--;
            printLives();
        }
        printEnemyScore();
    }
    if (fireCooldown2 == 0)
    {
        fireEnemy2();
        fireCooldown2 = 25;
    }
    else
    {
        fireCooldown2--;
    }
    for (int i = 0; i < E2bulletSpeedMultiplier; i++)
    {
        updateEnemy2Bullet();
    }
    gotoxy(Ex2, Ey2);
    printEnemy2();
}

void printEnemy2Bullet(int x, int y)
{
    setColor(14);
    gotoxy(x, y);
    cout << "<<";
    setColor(7);
}

void eraseEnemy2Bullet(int x, int y)
{
    gotoxy(x, y);
    cout << "  ";
}

void fireEnemy2()
{
    for (int i = 0; i < 5; i++)
    {
        if (E2BulletX[i] == -1 && E2BulletY[i] == -1)
        {
            E2BulletX[i] = Ex2;
            E2BulletY[i] = Ey2 + 1;
            break;
        }
    }
}

void updateEnemy2Bullet()
{
    for (int i = 0; i < 5; i++)
    {
        if (E2BulletX[i] != -1 && E2BulletY[i] != -1)
        {
            eraseEnemy2Bullet(E2BulletX[i], E2BulletY[i]);
            E2BulletX[i]--;

            if (E2BulletX[i] < 2 || (E2BulletX[i] >= Px && E2BulletX[i] <= Px + 14 && E2BulletY[i] >= Py && E2BulletY[i] <= Py + 9))
            {
                if (E2BulletX[i] >= Px && E2BulletX[i] <= Px + 14 && E2BulletY[i] >= Py && E2BulletY[i] <= Py + 9)
                {
                    if (!shieldActive)
                    {
                        minusScore();
                        enemy2Score++;
                        printEnemyScore();
                    }
                }
                E2BulletX[i] = -1;
                E2BulletY[i] = -1;
            }
            else
            {
                printEnemy2Bullet(E2BulletX[i], E2BulletY[i]);
            }
        }
    }
}

void printEnemy3()
{
    setColor(13);

    for (int i = 0; i < 4; i++)
    {
        gotoxy(Ex3, Ey3 + i);
        for (int j = 0; j < 11; j++)
        {
            cout << Enemy3[i][j];
        }
        cout << endl;
    }
    setColor(7);
}

void eraseEnemy3()
{
    for (int i = 0; i < 4; i++)
    {
        gotoxy(Ex3, Ey3 + i);
        for (int j = 0; j < 11; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void moveEnemy3()
{
    gotoxy(Ex3, Ey3);
    eraseEnemy3();
    Ey3++;
    if (Ey3 >= 45)
    {
        Ey3 = 11;
    }
    if ((Px + 14 >= Ex3 && Px <= Ex3 + 8) && (Py + 9 >= Ey3 && Py <= Ey3 + 3))
    {
        Ey3 = 11;
        if (!shieldActive)
        {
            lives--;
            printLives();
        }
        printEnemyScore();
    }
    if (fireCooldown3 == 0)
    {
        fireEnemy3();
        fireCooldown3 = 25;
    }
    else
    {
        fireCooldown3--;
    }
    for (int i = 0; i < E3bulletSpeedMultiplier; i++)
    {
        updateEnemy3Bullet();
    }
    gotoxy(Ex3, Ey3);
    printEnemy3();
}

void printEnemy3Bullet(int x, int y)
{
    setColor(13);
    gotoxy(x, y);
    cout << "oo";
    setColor(7);
}

void eraseEnemy3Bullet(int x, int y)
{
    gotoxy(x, y);
    cout << "  ";
}

void fireEnemy3()
{
    for (int i = 0; i < 5; i++)
    {
        if (E3BulletX[i] == -1 && E3BulletY[i] == -1)
        {
            E3BulletX[i] = Ex3;
            E3BulletY[i] = Ey3 + 3;
            break;
        }
    }
}

void updateEnemy3Bullet()
{
    for (int i = 0; i < 5; i++)
    {
        if (E3BulletX[i] != -1 && E3BulletY[i] != -1)
        {
            eraseEnemy3Bullet(E3BulletX[i], E3BulletY[i]);
            E3BulletX[i]--;

            if (E3BulletX[i] < 2 || (E3BulletX[i] >= Px && E3BulletX[i] <= Px + 14 && E3BulletY[i] >= Py && E3BulletY[i] <= Py + 9))
            {
                if (E3BulletX[i] >= Px && E3BulletX[i] <= Px + 14 && E3BulletY[i] >= Py && E3BulletY[i] <= Py + 9)
                {
                    if (!shieldActive)
                    {
                        minusScore();
                        enemy3Score++;
                        printEnemyScore();
                    }
                }
                E3BulletX[i] = -1;
                E3BulletY[i] = -1;
            }
            else
            {
                printEnemy3Bullet(E3BulletX[i], E3BulletY[i]);
            }
        }
    }
}

void printBonus()
{
    setColor(2);
    gotoxy(bonusX, bonusY);
    cout << "**";
    setColor(7);
}

void eraseBonus()
{
    gotoxy(bonusX, bonusY);
    cout << "  ";
}

void checkBonusCollection()
{
    if (!bonusCollected &&
        Px <= bonusX &&
        Px + 15 >= bonusX &&
        Py <= bonusY &&
        Py + 10 >= bonusY)
    {
        bonusCollected = true;
        eraseBonus();
        generateNewBonus();
        printBonus();
        addScore();
    }
}

void generateNewBonus()
{
    int index;
    do
    {
        index = rand() % TotalPositions;
        bonusX = possibleBonusX[index];
        bonusY = possibleBonusY[index];
    } while ((bonusX >= Px && bonusX <= Px + 14 && bonusY >= Py && bonusY <= Py + 9) ||
             (bonusX >= Ex1 && bonusX <= Ex1 + 8 && bonusY >= Ey1 && bonusY <= Ey1 + 4) ||
             (bonusX >= Ex2 && bonusX <= Ex2 + 3 && bonusY >= Ey2 && bonusY <= Ey2 + 2) ||
             (bonusX >= Ex3 && bonusX <= Ex3 + 8 && bonusY >= Ey3 && bonusY <= Ey3 + 3));
    bonusCollected = false;
}

void checkEnemyBonusCollision()
{
    if ((Ex1 + 8 >= bonusX && Ex1 <= bonusX) && (Ey1 + 4 >= bonusY && Ey1 <= bonusY))
    {
        return;
    }

    if (Ex2 <= bonusX && Ex2 + 6 >= bonusX && Ey2 <= bonusY && Ey2 + 2 >= bonusY)
    {
        return;
    }

    if ((bonusX >= Ex3 && bonusX <= Ex3 + 8) && (bonusY >= Ey3 && bonusY <= Ey3 + 3))
    {
        return;
    }
}
void drawShield()
{
    if (shieldActive)
    {
        setColor(2);
        for (int i = 0; i < 10; i++)
        {
            gotoxy(Px + 16, Py + i);
            cout << "|";
        }
        setColor(7);
    }
}

void eraseShield()
{
    for (int i = 0; i < 10; i++)
    {
        gotoxy(Px + 16, Py + i);
        cout << " ";
    }
}

void handleShield()
{
    if (GetAsyncKeyState(VK_SHIFT) && shieldCooldown == 0 && shieldUses > 0)
    {
        shieldActive = true;
        shieldCooldown = 300;
        shieldUses--;
        printShieldNumber();
        shieldDuration = 150;
    }

    if (shieldActive)
    {
        shieldX = Px + 16;
        shieldY = Py;
        drawShield();
        shieldDuration--;
        if (shieldDuration <= 0)
        {
            shieldActive = false;
            shieldDuration = 150;
            eraseShield();
        }
    }

    if (shieldCooldown > 0)
    {
        shieldCooldown--;
    }
}

void addScore()
{
    score++;
    printScore();
}

void minusScore()
{
    score--;
    printScore();
}
void printScore()
{
    setColor(9);
    gotoxy(2, 3);
    cout << "     SCORE: " << score << endl;
    setColor(7);
}

void printLives()
{
    setColor(12);
    gotoxy(2, 4);
    cout << "     LIVES: " << lives << endl;
    setColor(7);
}

void printEnemyScore()
{
    setColor(3);
    gotoxy(2, 5);
    cout << "     ENEMY1 HEALTH: " << enemy1Score << endl;
    setColor(7);
    setColor(14);
    gotoxy(2, 6);
    cout << "     ENEMY2 HEALTH: " << enemy2Score << endl;
    setColor(7);
    setColor(13);
    gotoxy(2, 7);
    cout << "     ENEMY3 HEALTH: " << enemy3Score << endl;
    setColor(7);
}
void printShieldNumber()
{
    setColor(2);
    gotoxy(2, 8);
    cout << "     SHIELDS REMAINING: " << shieldUses << endl;
    setColor(7);
}
void gameOver()
{
    int x = 90, y = 20;
    system("cls");
    gotoxy(x, y);
    setColor(12);
    cout << "--------------------------------" << endl;
    gotoxy(x, y + 1);
    cout << "|        GAME OVER!!!!         |" << endl;
    gotoxy(x, y + 2);
    cout << "--------------------------------" << endl;
    setColor(7);
    gotoxy(x, y + 3);
    cout << endl
         << endl;
    gotoxy(x, y + 4);
    setColor(9);
    cout << "   SCORE: " << score << endl;
    gotoxy(x, y + 5);
    cout << "   LIVES: " << lives << endl;
    gotoxy(x, y + 6);
    cout << "   ENEMY1 HEALTH: " << enemy1Score << endl;
    gotoxy(x, y + 7);
    cout << "   ENEMY2 HEALTH: " << enemy2Score << endl;
    gotoxy(x, y + 8);
    cout << "   ENEMY3 HEALTH: " << enemy3Score << endl;
    gotoxy(x, y + 9);
    cout << "   SHIELDS REMAINING: " << shieldUses << endl;
    setColor(7);
    gotoxy(x, y + 10);
    cout << endl
         << endl;
    gotoxy(x, y + 11);
    setColor(12);
    cout << "--------------------------------" << endl;
    setColor(7);
    gotoxy(0, 40);
}

void Win()
{
    int x = 90, y = 20;
    system("cls");
    gotoxy(x, y);
    setColor(9);
    cout << "--------------------------------" << endl;
    gotoxy(x, y + 1);
    cout << "|          YOU WIN!!!!         |" << endl;
    gotoxy(x, y + 2);
    cout << "--------------------------------" << endl;
    gotoxy(x, y + 3);
    setColor(7);
    cout << endl
         << endl;
    gotoxy(x, y + 4);
    setColor(12);
    cout << "   SCORE: " << score << endl;
    gotoxy(x, y + 5);
    cout << "   LIVES: " << lives << endl;
    gotoxy(x, y + 6);
    cout << "   ENEMY1 HEALTH: " << enemy1Score << endl;
    gotoxy(x, y + 7);
    cout << "   ENEMY2 HEALTH: " << enemy2Score << endl;
    gotoxy(x, y + 8);
    cout << "   ENEMY3 HEALTH: " << enemy3Score << endl;
    gotoxy(x, y + 9);
    cout << "   SHIELDS REMAINING: " << shieldUses << endl;
    setColor(7);
    gotoxy(x, y + 10);
    cout << endl
         << endl;
    gotoxy(x, y + 11);
    setColor(9);
    cout << "--------------------------------" << endl;
    setColor(7);
    gotoxy(0, 40);
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufsize;
    coordBufsize.X = 1;
    coordBufsize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufsize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void hideCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE; 
    SetConsoleCursorInfo(consoleHandle, &info);
}
