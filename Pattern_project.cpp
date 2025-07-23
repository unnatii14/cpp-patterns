#include <iostream>
using namespace std;

// set color
void setColor(const string& colorCode) {
    cout << colorCode;
}

// reset color to default
void resetColor() {
    cout << "\033[0m";
}

const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";

// 1. Square Hollow Pattern (green)
void printSquareHollow(int n) {
    setColor(GREEN);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i==0 || i==n-1 || j==0 || j==n-1)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
    resetColor();
}

// 2. Right Half Pyramid (yellow)
void printRightHalfPyramid(int n) {
    setColor(YELLOW);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++)
            cout << "* ";
        cout << endl;
    }
    resetColor();
}

// 3. Number Increasing Pyramid (blue)
void printNumberPyramid(int n) {
    setColor(BLUE);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++)
            cout << j << " ";
        cout << endl;
    }
    resetColor();
}

// 4. Butterfly Star Pattern (cyan)
void printButterfly(int n) {
    setColor(CYAN);
    // Upper half
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) cout << "* ";
        for(int j=1; j<=2*(n-i); j++) cout << "  ";
        for(int j=1; j<=i; j++) cout << "* ";
        cout << endl;
    }
    // Lower half
    for(int i=n; i>=1; i--) {
        for(int j=1; j<=i; j++) cout << "* ";
        for(int j=1; j<=2*(n-i); j++) cout << "  ";
        for(int j=1; j<=i; j++) cout << "* ";
        cout << endl;
    }
    resetColor();
}

// 5. Diamond Pattern (magenta)
void printDiamond(int n) {
    setColor(MAGENTA);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n-i; j++) cout << " ";
        for(int j=1; j<=2*i-1; j++) cout << "*";
        cout << endl;
    }
    for(int i=n-1; i>=1; i--) {
        for(int j=1; j<=n-i; j++) cout << " ";
        for(int j=1; j<=2*i-1; j++) cout << "*";
        cout << endl;
    }
    resetColor();
}

// 6. Pascal's Triangle (red)
void printPascalsTriangle(int n) {
    setColor(RED);
    for(int i=0; i<n; i++) {
        int num = 1;
        for(int j=0; j<n-i-1; j++) cout << "  ";
        for(int j=0; j<=i; j++) {
            cout << num << "   ";
            num = num * (i - j) / (j + 1);
        }
        cout << endl;
    }
    resetColor();
}

// 7. Hollow Hourglass Pattern (cyan again, looks nice)
void printHollowHourglass(int n) {
    setColor(CYAN);
    // Upper half
    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) cout << " ";
        for(int j=0; j<2*(n-i)-1; j++) {
            if(j==0 || j==2*(n-i)-2 || i==0)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    // Lower half
    for(int i=n-2; i>=0; i--) {
        for(int j=0; j<i; j++) cout << " ";
        for(int j=0; j<2*(n-i)-1; j++) {
            if(j==0 || j==2*(n-i)-2 || i==0)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    resetColor();
}

int main() {
    int choice, n;
    while(true) {
        cout << "\n === Pattern === " << endl;
        cout << "1. Square Hollow Pattern" << endl;
        cout << "2. Right Half Pyramid" << endl;
        cout << "3. Number Increasing Pyramid" << endl;
        cout << "4. Butterfly Star Pattern" << endl;
        cout << "5. Diamond Pattern" << endl;
        cout << "6. Pascal's Triangle" << endl;
        cout << "7. Hollow Hourglass Pattern" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 8) break;

        cout << "Enter size : ";
        cin >> n;

        switch(choice) {
            case 1: printSquareHollow(n); break;
            case 2: printRightHalfPyramid(n); break;
            case 3: printNumberPyramid(n); break;
            case 4: printButterfly(n); break;
            case 5: printDiamond(n); break;
            case 6: printPascalsTriangle(n); break;
            case 7: printHollowHourglass(n); break;
            default: cout << "Invalid choice!" << endl;
        }
    }
    cout << "Thank you for using Pattern! " << endl;
    return 0;
}


