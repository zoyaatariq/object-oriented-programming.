// 4. BMI Calculator (Body Mass Index)
#include <iostream>
using namespace std;

class BMI {
    float w, h;
public:
    BMI(float weight, float height) {
        w = weight; h = height;
    }
    float calc() {
        return w / (h * h);
    }
    void display() {
        float bmi = calc();
        cout << bmi << endl;
        if(bmi < 18.5) cout << "Underweight";
        else if(bmi < 25) cout << "Normal";
        else cout << "Overweight";
    }
};

int main() {
    BMI b(50, 1.6);
    b.display();
    return 0;
}
