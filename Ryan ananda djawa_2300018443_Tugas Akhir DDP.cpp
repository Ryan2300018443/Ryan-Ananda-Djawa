#include <iostream>

using namespace std;

// Fungsi untuk menampilkan papan permainan
void displayBoard(char board[3][3]) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

// Fungsi untuk mengecek apakah ada pemenang atau seri
char checkWinner(char board[3][3]) {
    // Cek baris dan kolom
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return board[0][i];
        }
    }

    // Cek diagonal
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }

    // Cek apakah ada celah kosong
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return ' ';
            }
        }
    }

    // Jika tidak ada pemenang dan tidak ada celah kosong, maka seri
    return 'T';
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char currentPlayer = 'X';
    int row, col;

    do {
        // Tampilkan papan permainan
        displayBoard(board);

        // Input posisi
        cout << "Player " << currentPlayer << ", masukkan baris (0-2) dan kolom (0-2) dipisahkan spasi: ";
        cin >> row >> col;

        // Periksa apakah posisi sudah terisi atau tidak valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Posisi tidak valid. Coba lagi." << endl;
            continue;
        }

        // Isi posisi dengan simbol pemain
        board[row][col] = currentPlayer;

        // Ganti giliran pemain
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

        // Periksa apakah ada pemenang atau seri
        char winner = checkWinner(board);
        if (winner != ' ') {
            // Tampilkan papan permainan terakhir kali
            displayBoard(board);

            // Tampilkan hasil permainan
            if (winner == 'T') {
                cout << "Permainan seri!" << endl;
            } else {
                cout << "Player " << winner << " menang!" << endl;
            }

            break;
        }

    } while (true);

    return 0;
}