#include <iostream>
#include <iomanip>

#define BOARD_SIZE 20
using namespace std;



enum square {
    none,
    white,
    black,
    omok,
};

enum square board[BOARD_SIZE][BOARD_SIZE];

struct storage {
    int a;
    int b;
};

storage ee[5];

int omokCount = 1;

// False 오목 아님
// True 오목
bool check(int x, int y) {
    int tempX;
    int tempY;

    // 상
    omokCount = 1;

    tempX = x;
    tempY = y;
    for (int i = 0; i < 4; i++) {
        tempY++;

        if (tempY >= BOARD_SIZE || tempY < 0) {
            break;
        }

        if (board[x][y] == board[tempX][tempY]) {
            ee[omokCount - 1].a = tempX;
            ee[omokCount - 1].b = tempY;
            omokCount++;
        }
        else {
            break;
        }
    }

    // 하
    tempX = x;
    tempY = y;

    for (int i = 0; i < 4; i++) {
        tempY--;

        if (tempY >= BOARD_SIZE || tempY < 0) {
            break;
        }

        if (omokCount == 5) {
            break;
        }

        if (board[x][y] == board[tempX][tempY]) {
            ee[omokCount - 1].a = tempX;
            ee[omokCount - 1].b = tempY;
            omokCount++;
        }
        else {
            omokCount = 1;
            break;
        }
    }

    // 오목 확인
    if (omokCount >= 5) {

        for (int l = 0; l < 4; l++) {
            board[ee[l].a][ee[l].b] = omok;
        }

        board[x][y] = omok;

        cout << "히 히 너 오목" << endl;
        return true;
    }

    // 좌
    omokCount = 1;

    tempX = x;
    tempY = y;
    for (int i = 0; i < 4; i++) {
        tempX--;

        if (tempX >= BOARD_SIZE || tempX < 0) {
            break;
        }

        if (board[x][y] == board[tempX][tempY]) {
            ee[omokCount - 1].a = tempX;
            ee[omokCount - 1].b = tempY;
            omokCount++;
        }
        else {
            break;
        }
    }

    //우
    tempX = x;
    tempY = y;
    for (int i = 0; i < 4; i++) {
        tempX++;

        if (tempX >= BOARD_SIZE || tempX < 0) {
            break;
        }

        if (omokCount == 5) {
            break;
        }

        if (board[x][y] == board[tempX][tempY]) {
            ee[omokCount - 1].a = tempX;
            ee[omokCount - 1].b = tempY;
            omokCount++;
        }
        else {
            omokCount = 1;
            break;
        }
    }

    // 오목 확인
    if (omokCount >= 5) {

        for (int l = 0; l < 4; l++) {

            board[ee[l].a][ee[l].b] = omok;

        }

        board[x][y] = omok;

        cout << "히 히 너 오목" << endl;
        return true;
    }

    // 상좌
    omokCount = 1;
    tempX = x;
    tempY = y;
    for (int i = 0; i < 4; i++) {
        tempX--;
        tempY++;

        if (tempX >= BOARD_SIZE || tempX < 0) {
            break;
        }

        if (tempY >= BOARD_SIZE || tempY < 0) {
            break;
        }

        if (board[x][y] == board[tempX][tempY]) {
            ee[omokCount - 1].a = tempX;
            ee[omokCount - 1].b = tempY;
            omokCount++;

            if (omokCount >= 5) {
                for (int l = 0; l < 4; l++) {
                    board[ee[l].a][ee[l].b] = omok;
                }
                board[x][y] = omok;

                cout << "오목이ㅣ당" << endl;
                return true;
            }
        }
        else {
            break;
        }
    }

    // How
    tempX = x;
    tempY = y;
    for (int i = 0; i < 4; i++) {
        tempX++;
        tempY--;

        if (tempX >= BOARD_SIZE || tempX < 0) {
            break;
        }

        if (tempY >= BOARD_SIZE || tempY < 0) {
            break;
        }

        if (board[x][y] == board[tempX][tempY]) {
            ee[omokCount - 1].a = tempX;
            ee[omokCount - 1].b = tempY;
            omokCount++;

            if (omokCount >= 5) {
                for (int l = 0; l < 4; l++) {
                    board[ee[l].a][ee[l].b] = omok;
                }
                board[x][y] = omok;

                cout << "오목이ㅣ당" << endl;
                return true;
            }
        }
        else {
            omokCount = 1;
            break;
        }
    }

    // 상우
    omokCount = 1;
    tempX = x;
    tempY = y;
    for (int i = 0; i < 4; i++) {
        tempX++;
        tempY++;

        if (tempX >= BOARD_SIZE || tempX < 0) {
            break;
        }

        if (tempY >= BOARD_SIZE || tempY < 0) {
            break;
        }

        if (board[x][y] == board[tempX][tempY]) {
            ee[omokCount - 1].a = tempX;
            ee[omokCount - 1].b = tempY;
            omokCount++;

            if (omokCount >= 5) {
                for (int l = 0; l < 4; l++) {
                    board[ee[l].a][ee[l].b] = omok;
                }

                board[x][y] = omok;

                cout << "오목이얌" << endl;
                return true;
            }
        }
        else {
            break;
        }
    }


    // 하좌
    tempX = x;
    tempY = y;
    for (int i = 0; i < 4; i++) {
        tempX--;
        tempY--;

        if (tempX >= BOARD_SIZE || tempX < 0) {
            break;
        }

        if (tempY >= BOARD_SIZE || tempY < 0) {
            break;
        }

        if (board[x][y] == board[tempX][tempY]) {
            ee[omokCount - 1].a = tempX;
            ee[omokCount - 1].b = tempY;

            omokCount++;

            if (omokCount >= 5) {
                for (int l = 0; l < 4; l++) {
                    board[ee[l].a][ee[l].b] = omok;
                }
                board[x][y] = omok;

                cout << "오목이얌" << endl;
                return true;
            }
        }
        else {
            omokCount = 1;
            break;
        }
    }

    return false;
}

int state = 2;

bool input() {
    int x;
    int y;

    cin >> x;
    x--;
    cin >> y;
    y--;

    if (x <= -1 || x >= BOARD_SIZE || y <= -1 || y >= BOARD_SIZE) {
        cout << "숫자가 잘못되었다" << endl;
        return false;
    }

    if (board[x][y] != none) {
        cout << "중복" << endl;
        return false;
    }

    if (state == 2) {
        board[x][y] = black;
        cout << "흑 돌 설치 완료" << endl;
        cout << "백 차례" << endl;
        state = 1;
    }
    else if (state == 1) {
        board[x][y] = white;
        cout << "백 돌 설치 완료" << endl;
        cout << "흑 차례" << endl;
        state = 2;
    }


    return check(x, y);

}



void output() {
    for (int y = BOARD_SIZE - 1; y >= 0; y--) {
        cout << "    ";
        for (int index = 0; index < BOARD_SIZE; index++) {
            cout << "+   ";
        }
        cout << "+" << endl;

        cout << setw(3) << y + 1 << " ";
        cout << "  ";
        for (int x = 0; x < BOARD_SIZE; x++) {
            if (board[x][y] == none) {
                cout << " " << "   ";
            }
            if (board[x][y] == white) {
                cout << "○" << "   ";
            }
            if (board[x][y] == black) {
                cout << "●" << "   ";
            }
            if (board[x][y] == omok) {
                cout << "◎" << "   ";
            }
        }
        cout << endl;

    }

    cout << "    ";
    for (int index = 0; index < BOARD_SIZE; index++) {
        cout << "+   ";
    }
    cout << "+" << endl;
    cout << "   ";
    for (int i = 1; i < BOARD_SIZE + 1; i++) {
        cout << setw(4) << i;
    }
    cout << endl;
}

int main()
{
    //board[4][5] = board[4][6] = board[4][3] = board[4][2] = black;    // 상하
    //board[5][4] = board[6][4] = board[3][4] = board[2][4] = black;    // 좌우
    //board[3][5] = board[2][6] = board[5][3] = board[6][2] = black;    // 상좌 하우
    //board[2][2] = board[3][3] = board[5][5] = board[6][6] = black;    // 상우 하좌

    output();

    while (input() == false) {
        output();
    }
    output();

    //well, done!
}



