#include <iostream>
using namespace std;

class Glass {
    public:
        int LiquidLevel;

        Glass() {
            LiquidLevel = 200;
        }

        void Drink(int mls) {
            if (mls <= LiquidLevel) {
                LiquidLevel -= mls;
                cout << "Remaining liquid: " << LiquidLevel << " ml" << endl;
                if (LiquidLevel < 100) {
                    Refill();
                }
            } else {
                cout << "Not enough liquid to drink that amount!" << endl;
            }
        }

        void Refill() {
            LiquidLevel = 200;
            cout << "Glass refilled to 200 ml." << endl;
        }
};

int main(int argc, char* argv[]) {
    Glass glass;
    int input;
    while (true) {
        cout << "Enter amount to drink (ml) or -1 to exit: ";
        cin >> input;
        if (input == -1) break;
        glass.Drink(input);
    }
    return 0;
}
