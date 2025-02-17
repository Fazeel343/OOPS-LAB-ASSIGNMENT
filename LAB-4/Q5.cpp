#include <iostream>
#include <string>
using namespace std;

const int MAX_MENU_ITEMS = 10;
const int MAX_ORDERS = 10;

class MenuItem {
    public:
        string name;
        string type;
        double price;

        MenuItem(string n, string t, double p) {
            name = n;
            type = t;
            price = p;
        }
};

class CoffeeShop {
    private:
        string name;
        MenuItem* menu[MAX_MENU_ITEMS];
        string orders[MAX_ORDERS];
        int menuSize;
        int orderCount;

    public:
        CoffeeShop(string shopName) {
            name = shopName;
            menuSize = 0;
            orderCount = 0;
        }

        void addMenuItem(string itemName, string itemType, double itemPrice) {
            if (menuSize < MAX_MENU_ITEMS) {
                menu[menuSize++] = new MenuItem(itemName, itemType, itemPrice);
            } else {
                cout << "Menu is Full, cannot add more Items." << endl;
            }
        }

        void addOrder(string itemName) {
            if (orderCount < MAX_ORDERS) {
                bool found = false;
                for (int i = 0; i < menuSize; i++) {
                    if (menu[i]->name == itemName) {
                        orders[orderCount++] = itemName;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "This Item is currently Unavailable." << endl;
                }
            } else {
                cout << "Order limit Reached, cannot add more Orders." << endl;
            }
        }

        string fulfillOrder() {
            if (orderCount == 0) {
                return "All Orders have been Fulfilled.";
            } else {
                string order = orders[0];
                for (int i = 1; i < orderCount; i++) {
                    orders[i - 1] = orders[i];
                }
                orderCount--;
                return "The " + order + " is Ready";
            }
        }

        void listOrders() {
            if (orderCount == 0) {
                cout << "No Orders taken." << endl;
            } else {
                cout << "Current Orders: " << endl;
                for (int i = 0; i < orderCount; i++) {
                    cout << orders[i] << endl;
                }
            }
        }

        double dueAmount() {
            double total = 0;
            for (int i = 0; i < orderCount; i++) {
                for (int j = 0; j < menuSize; j++) {
                    if (menu[j]->name == orders[i]) {
                        total += menu[j]->price;
                        break;
                    }
                }
            }
            return total;
        }

        string cheapestItem() {
            if (menuSize == 0) {
                return "Menu is Empty.";
            }

            int cheapestIndex = 0;
            for (int i = 1; i < menuSize; i++) {
                if (menu[i]->price < menu[cheapestIndex]->price) {
                    cheapestIndex = i;
                }
            }
            return menu[cheapestIndex]->name;
        }

        void drinksOnly() {
            cout << "Drinks Available: " << endl;
            bool found = false;
            for (int i = 0; i < menuSize; i++) {
                if (menu[i]->type == "Drink") {
                    cout << menu[i]->name << endl;
                    found = true;
                }
            }
            if (!found) {
                cout << "No Drinks Available." << endl;
            }
        }

        void foodOnly() {
            cout << "Food Available: " << endl;
            bool found = false;
            for (int i = 0; i < menuSize; i++) {
                if (menu[i]->type == "food") {
                    cout << menu[i]->name << endl;
                    found = true;
                }
            }
            if (!found) {
                cout << "No Food Available." << endl;
            }
        }

        ~CoffeeShop() {
            for (int i = 0; i < menuSize; i++) {
                delete menu[i];
            }
        }
};

int main() {
    CoffeeShop myCoffeeShop("Cafe Mocha");
    myCoffeeShop.addMenuItem("Espresso", "drink", 3.50);
    myCoffeeShop.addMenuItem("Cappuccino", "drink", 4.00);
    myCoffeeShop.addMenuItem("Cheese Sandwich", "food", 5.00);
    myCoffeeShop.addMenuItem("Chocolate Cake", "food", 3.75);
    myCoffeeShop.addOrder("Espresso");
    myCoffeeShop.addOrder("Cappuccino");
    myCoffeeShop.addOrder("Cheese Sandwich");
    myCoffeeShop.addOrder("Burger");
    myCoffeeShop.listOrders();
    cout << myCoffeeShop.fulfillOrder() << endl;
    myCoffeeShop.listOrders();
    cout << "Total due: $" << myCoffeeShop.dueAmount() << endl;
    cout << "Cheapest item: " << myCoffeeShop.cheapestItem() << endl;
    myCoffeeShop.drinksOnly();
    myCoffeeShop.foodOnly();

    return 0;
}
