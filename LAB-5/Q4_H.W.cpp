#include <iostream>
using namespace std;

class Blend {
    public:
        void blendJuice(string fruit) {
            cout << "Selected Fruit: " << fruit << endl;
            for (int i = 0; i < 5; i++) {
                cout << "Blending " << fruit << " juice..." << endl;
            }
        }
};

class Grind {
    public:
        void grindJuice(string fruit) {
            cout << "Grinding "<< fruit << " juice..." << endl;
            for (int i = 0; i < 5; i++) {  
                cout << ".";  
            }
            cout << "\nGrinding complete!" << endl;
        }
};

class JuiceMaker {
    private:
        Blend blend;
        Grind grind;
    public:
        void makeJuice(string fruit) {
            blend.blendJuice(fruit);
            grind.grindJuice(fruit);
        }
};

int main() {
    string fruit;
    cout << "Enter the fruit you want the Juice of: ";
    cin >> fruit;
    JuiceMaker maker;
    maker.makeJuice(fruit);
    return 0;
}
