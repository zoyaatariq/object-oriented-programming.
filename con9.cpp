// 9. Shopping Cart Total Using Dynamic Constructor
#include <iostream>
using namespace std;

class Item {
    float *price, *qty;
public:
    Item(float p, float q) {
        price = new float;
        qty = new float;
        *price = p;
        *qty = q;
    }
    float total() {
        return (*price) * (*qty);
    }
    ~Item() {
        delete price;
        delete qty;
    }
    void display() {
        cout << total();
    }
};

int main() {
    Item it(200, 3);
    it.display();
    return 0;
}
