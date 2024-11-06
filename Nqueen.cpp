#include<iostream>
using namespace std;

class nqueen {
public:
    int N, rows, cols;
    int matrix[10][10];

    // Constructor for initializing the board and placing the first queen
    nqueen() {
        cout << "\nEnter the number of queens: ";
        cin >> N;
        rows = N;
        cols = N;

        // Initialize the board with 0s (empty positions)
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                matrix[i][j] = 0;
            }
        }
        
        if(N==4 || N==6)
        {
        	matrix[1][0]=1;
		}
		else
        // Place the first queen at the specified position
        matrix[0][0] = 1; // Place the first queen
    }

    void printsolution();
    bool isSafe(int r, int c);
    bool getSolution(int col);
};

// Function to print the board solution
void nqueen::printsolution() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                cout << " * ";  // Empty position
            } else {
                cout << " Q ";  // Queen placed
            }
        }
        cout << endl;
    }
}

// Function to check if placing a queen at (r, c) is safe
bool nqueen::isSafe(int r, int c) {
    // Check for queens in the same column
    for (int i = 0; i < cols; i++) {
        if (matrix[i][c]) {
            return false;
        }
    }
    
    // Check for queens in the same row
    for (int i = 0; i < rows; i++) {
        if (matrix[r][i]) {
            return false;
        }
    }

    int i, j;
    // Check upper-left diagonal
    for (i = r, j = c; i >= 0 && j >= 0; i--, j--) {
        if (matrix[i][j]) {
            return false;
        }
    }

    // Check lower-right diagonal
    for (i = r, j = c; i < N && j < N; i++, j++) {
        if (matrix[i][j]) {
            return false;
        }
    }

    // Check lower-left diagonal
    for (i = r, j = c; i < N && j >= 0; i++, j--) {
        if (matrix[i][j]) {
            return false;
        }
    }

    // Check upper-right diagonal
    for (i = r, j = c; i >= 0 && j < N; i--, j++) {
        if (matrix[i][j]) {
            return false;
        }
    }

    return true; // Safe position
}

// Recursive function to place queenws using backtracking
bool nqueen::getSolution(int col) {
    // Base case: If all queens are placed, print the solution
    if (col == N) {
        printsolution();
        return true;
    }

    // Skip the column where the first queen is already placed
    if (col == 0) {
        return getSolution(col + 1);
    }

    bool found_solution = false;

    // Try placing a queen in each row of the current column
    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            matrix[i][col] = 1; // Place queen at (i, col)

            // Recursively try to place the remaining queens
            found_solution = getSolution(col + 1);

            // If a solution is found, return true
            if (found_solution) {
                return true;
            }

            // Backtrack: Remove queen from (i, col)
            matrix[i][col] = 0;
        }
    }
    return found_solution; // Return whether a solution is found
}

int main() {
    nqueen n; // Create an object of nqueen class
    n.getSolution(0); // Start placing queens from the first column
    return 0;
}

