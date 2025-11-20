

// 5. Volume of Box
#include <iostream>
using namespace std;

class Box {
    float length, width, height;
public:
    void input() {
        cin >> length >> width >> height;
    }
    float volume() {
        return length * width * height;
    }
    void display() {
        cout << "Volume: " << volume();
    }
};

int main() {
    Box b;
    b.input();
    b.display();
    return 0;
}
