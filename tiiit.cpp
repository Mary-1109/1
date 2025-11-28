#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Функция: f(x) = 2x^4 - 2
double f(double x) {
    return 2 * pow(x,4) - 2;
}

// Производная: f'(x) = 8x^3
double df(double x) {
    return 8 * pow(x,3);
}

int main() {
    double x = -1.5;  // Начальное приближение1
    double x2 = 0.5; // Начальное приближение2
    double eps = 0.01;

    cout << "Newton method for 2x^4 - 2 = 0" << endl;
    cout << "Starting -x0 = " << x << ", accuracy = " << eps << endl;

    for (int i = 1; i <= 10; i++) {
        double x_new = x - f(x) / df(x);

        cout << "Step " << i << ": x = " << x_new;
        cout << ", f(x) = " << f(x_new) << endl;

        if (fabs(x_new - x) < eps) {
            cout << "\nThe first root is found: x = " << x_new << endl;
            break;
        }

        x = x_new;
    }
  
    cout << "\nStarting +x0 = " << x2 << ", accuracy = " << eps << endl;
    for (int i = 1; i <= 10; i++) {
        double x_new2 = x2 - f(x2) / df(x2);

        cout << "Step " << i << ": x = " << x_new2;
        cout << ", f(x) = " << f(x_new2) << endl;

        if (fabs(x_new2 - x2) < eps) {
            cout << "\nThe second root is found: x = " << x_new2 << endl;
            break;
        }

        x2 = x_new2;
    }

    return 0;
}