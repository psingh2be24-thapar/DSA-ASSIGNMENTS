#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imaginary;

public:
    // Function to set values of real and imaginary parts
    void set() {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imaginary;
    }

    // Function to display complex number
    void display() {
        cout << real;
        if (imaginary >= 0)
            cout << " + " << imaginary << "i" << endl;
        else
            cout << " - " << -imaginary << "i" << endl;
    }

    // Function to add two complex numbers and return result
    Complex sum(Complex c) {
        Complex result;
        result.real = real + c.real;             // No 'this->'
        result.imaginary = imaginary + c.imaginary;
        return result;
    }
};

int main() {
    Complex c1, c2, result;

    cout << "Enter first complex number:\n";
    c1.set();

    cout << "\nEnter second complex number:\n";
    c2.set();

    result = c1.sum(c2);   // sum of c1 and c2 stored in result

    cout << "\nFirst Complex Number: ";
    c1.display();

    cout << "Second Complex Number: ";
    c2.display();

    cout << "Sum of Complex Numbers: ";
    result.display();

    return 0;
}
