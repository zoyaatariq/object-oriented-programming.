// 8. Marks Percentage Calculator
#include <iostream>
using namespace std;

class Marks {
    int m[5];
public:
    void input() {
        for(int i=0; i<5; i++) cin >> m[i];
    }
    int total() {
        int sum = 0;
        for(int i=0; i<5; i++) sum += m[i];
        return sum;
    }
    float percentage() {
        return total() / 5.0;
    }
    char grade() {
        float p = percentage();
        if(p >= 90) return 'A';
        if(p >= 75) return 'B';
        if(p >= 60) return 'C';
        if(p >= 40) return 'D';
        return 'F';
    }
    void display() {
        cout << "Total: " << total() << endl;
        cout << "Percentage: " << percentage() << endl;
        cout << "Grade: " << grade();
    }
};

int main() {
    Marks m;
    m.input();
    m.display();
    return 0;
}
