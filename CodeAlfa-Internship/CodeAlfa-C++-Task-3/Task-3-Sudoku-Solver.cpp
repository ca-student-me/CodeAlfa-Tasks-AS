#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>

using namespace std;

const int N = 9;

// Set console text color
void setColor(int colorCode) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorCode);
}

// Typewriter text effect for smooth step-by-step reading
void typeText(const string& text, int delayMs = 15) {
    for (char c : text) {
        cout << c << flush;
        Sleep(delayMs);
    }
}

// Display the Sudoku board
void printBoard(int board[N][N], bool originalMask[N][N], int highlightRow = -1, int highlightCol = -1) {
    setColor(11); // Cyan border
    cout << "\n  +-------+-------+-------+\n";

    for (int row = 0; row < N; ++row) {
        setColor(11);
        cout << "  | ";

        for (int col = 0; col < N; ++col) {
            if (row == highlightRow && col == highlightCol) {
                setColor(13); // Magenta for the cell currently being altered
                cout << board[row][col] << " ";
            } else if (board[row][col] == 0) {
                setColor(8); // Dark gray for empty
                cout << ". ";
            } else if (originalMask[row][col]) {
                setColor(14); // Yellow for original clues
                cout << board[row][col] << " ";
            } else {
                setColor(10); // Green for filled numbers
                cout << board[row][col] << " ";
            }

            if ((col + 1) % 3 == 0) {
                setColor(11);
                cout << "| ";
            }
        }
        cout << "\n";

        if ((row + 1) % 3 == 0) {
            setColor(11);
            cout << "  +-------+-------+-------+\n";
        }
    }
    setColor(7); // Reset to standard white/gray
}

// Check row, column, and 3x3 subgrid constraints
bool isValid(int board[N][N], int row, int col, int num) {
    for (int i = 0; i < N; ++i) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    int startRow = row - (row % 3);
    int startCol = col - (col % 3);

    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            if (board[startRow + r][startCol + c] == num) {
                return false;
            }
        }
    }
    return true;
}

// Interactive backtracking with step explanation and pauses
bool solveSudokuStepByStep(int board[N][N], bool originalMask[N][N], long long& stepCount) {
    int row = -1;
    int col = -1;
    bool isEmpty = false;

    // Locate the first empty cell
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (board[r][c] == 0) {
                row = r;
                col = c;
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) break;
    }

    // No empty cells remaining: solved
    if (!isEmpty) {
        return true;
    }

    for (int num = 1; num <= 9; ++num) {
        stepCount++;

        if (isValid(board, row, col, num)) {
            board[row][col] = num;

            // Log step details
            setColor(14);
            cout << "\n[Step " << stepCount << "] ";
            setColor(11);
            typeText("Action: Placing ");
            setColor(10);
            cout << num;
            setColor(11);
            typeText(" at cell (Row " + to_string(row + 1) + ", Col " + to_string(col + 1) + "). Constraints satisfied.\n");
            
            printBoard(board, originalMask, row, col);

            setColor(8);
            typeText("--> Press any key to continue to the next step...", 5);
            _getch();
            cout << "\n";

            if (solveSudokuStepByStep(board, originalMask, stepCount)) {
                return true;
            }

            // Backtracking trigger
            stepCount++;
            setColor(14);
            cout << "\n[Step " << stepCount << "] ";
            setColor(12);
            typeText("Backtracking: Value ");
            cout << num;
            typeText(" at (Row " + to_string(row + 1) + ", Col " + to_string(col + 1) + ") caused conflicts ahead. Resetting cell.\n");

            board[row][col] = 0;
            printBoard(board, originalMask, row, col);

            setColor(8);
            typeText("--> Press any key to continue...", 5);
            _getch();
            cout << "\n";
        }
    }

    return false;
}

int main() {
    setColor(11);
    cout << "===============================================================\n";
    cout << "           INTERACTIVE STEP-BY-STEP SUDOKU SOLVER              \n";
    cout << "===============================================================\n";

    setColor(14);
    cout << "1. Run sample near-complete puzzle (Recommended for quick demo)\n";
    cout << "2. Run standard sample puzzle\n";
    setColor(11);
    cout << "Select mode (1-2): ";
    setColor(15);

    int mode;
    if (!(cin >> mode) || (mode != 1 && mode != 2)) {
        mode = 1;
    }

    int board[N][N];
    bool originalMask[N][N] = {false};

    // A near-complete board so stepping through with getch() is practical and demonstrates backtracking quickly
    int demoPuzzle[N][N] = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 0, 0}
    };

    int standardPuzzle[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            board[r][c] = (mode == 1) ? demoPuzzle[r][c] : standardPuzzle[r][c];
            if (board[r][c] != 0) {
                originalMask[r][c] = true;
            }
        }
    }

    setColor(13);
    cout << "\n[INITIAL BOARD STATE]";
    printBoard(board, originalMask);

    setColor(14);
    typeText("\nStarting interactive solver. Press any key to begin stepping through...\n", 10);
    _getch();

    long long stepCount = 0;
    if (solveSudokuStepByStep(board, originalMask, stepCount)) {
        setColor(10);
        cout << "\n===============================================================\n";
        typeText("               Sudoku solved completely!\n", 15);
        cout << "===============================================================\n";
        printBoard(board, originalMask);
    } else {
        setColor(12);
        cout << "\n[ERROR] No valid configuration exists for this puzzle.\n";
    }

    setColor(7);
    return 0;
}