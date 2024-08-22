#include "iostream"
#include <windows.h>
#include <thread>

#include "grid.h"

using namespace std;


struct coords {
    int x, y;
};

coords convert_coords(string coordString){
    if(coordString.size() != 2) {
        return coords{0, 0};
    };
    char y_char = coordString[0];
    y_char = toupper(y_char);
    int y = y_char - 65;
    if (y > 16) {
       return coords{0, 0};
    }
    int x = coordString[1] - 48;
    if (x > 16) {
        return coords{0, 0};
    }
    return coords{x, y};
}

// void clearScreen() {
//     COORD topLeft = {0, 0};
//     HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
//     CONSOLE_SCREEN_BUFFER_INFO screen;
//     DWORD written;

//     GetConsoleScreenBufferInfo(console, &screen);
//     FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
//     FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
//     SetConsoleCursorPosition(console, topLeft);
// }

void moveCursor(int x, int y) {
    COORD position = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

// void drawInterface() {
//     clearScreen();
//     moveCursor(0, 0);
//     std::cout << "=== Economy Game ===";
//     moveCursor(0, 2);
//     std::cout << "Player 1: $1000";
//     moveCursor(0, 3);
//     std::cout << "Player 2: $800";
// }


int main(int argc, char const *argv[])
{
    string input;

    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD prevMode;

    INPUT_RECORD inputRecord;
    DWORD events;
    COORD mousePos;

    cout << "Hello World! \n";
    cin >> input;
    coords cords = convert_coords(input);
    cout << "x: " << cords.x << ", y: " << cords.y << endl;

    string grid_text = "";

    Grid grid(16, 16);
    grid.reset_field(11, 11);
    for (int y = 0; y < 16; y++) {
        for (int x = 0; x < 16; x++) {
            if (grid.get_field(y, x)) {
                grid_text += "x ";
            } else {
                grid_text += "_ ";
            }
        }
        grid_text += "\n";
    }

    cout << grid_text << endl;

    while (true) {
        ReadConsoleInput(hInput, &inputRecord, 1, &events);
        if (inputRecord.EventType == MOUSE_EVENT) {
            MOUSE_EVENT_RECORD mouseEvent = inputRecord.Event.MouseEvent;

            if (mouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
                mousePos = mouseEvent.dwMousePosition;

                // Translate console coordinates to grid coordinates
                int gridX = mousePos.X / 2; // 3 because "[ ]" is 3 characters wide
                int gridY = mousePos.Y;
                moveCursor(mousePos.X, mousePos.Y);
                std::cout << "z";

                // std::cout << "Mouse clicked at grid position: (" << gridX << ", " << gridY << ")" << std::endl;

                // Add your game logic here to process the click
                // break; // Remove this to continue listening for clicks
            }
        }
    }

    SetConsoleMode(hInput, prevMode);

    // while (true) {
    //     drawInterface();
    //     std::this_thread::sleep_for(std::chrono::seconds(1));
    // }
    /* code */
    return 0;
}
