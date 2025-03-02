#include <iostream>
#include <vector>
using namespace std;

class CoffeeShop {
private:
    string name;

    struct MenuItem {
        string name;
        double price;
        string category;
    };

    vector<MenuItem> menu;
    vector<string> orders;

public:
    CoffeeShop(string shopName) : name(shopName) {}

    void setMenu() {
        int numItems;
        cout << "Enter Number of Menu Items: ";
        cin >> numItems;

        for (int i = 0; i < numItems; i++) {
            MenuItem item;
            cout << "Enter Item Name: ";
            cin >> item.name;
            cout << "Enter Item Price: ";
            cin >> item.price;
            cout << "Enter Category (drink/food): ";
            cin >> item.category;

            menu.push_back(item);
        }
    }

    string addOrder(string item) {
        for (auto &menuItem : menu) {
            if (menuItem.name == item) {
                orders.push_back(item);
                return "Order added!";
            }
        }
        return "This item is currently unavailable!";
    }

    string fulfillOrder() {
        if (!orders.empty()) {
            string item = orders.front();
            orders.erase(orders.begin());
            return "The " + item + " is ready!";
        }
        return "All orders have been fulfilled";
    }

    void listOrders() {
        if (orders.empty()) {
            cout << "No Pending Orders." << endl;
        } else {
            cout << "Pending Orders:\n";
            for (auto &order : orders) {
                cout << "- " << order << endl;
            }
        }
    }

    double dueAmount() {
        double total = 0;
        for (auto &order : orders) {
            for (auto &menuItem : menu) {
                if (menuItem.name == order) {
                    total += menuItem.price;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (menu.empty()) return "Menu is empty!";
        
        double minPrice = menu[0].price;
        string cheapest = menu[0].name;

        for (auto &menuItem : menu) {
            if (menuItem.price < minPrice) {
                minPrice = menuItem.price;
                cheapest = menuItem.name;
            }
        }
        return cheapest;
    }

    vector<string> drinksOnly() {
        vector<string> drinks;
        for (auto &menuItem : menu) {
            if (menuItem.category == "drink") {
                drinks.push_back(menuItem.name);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() {
        vector<string> food;
        for (auto &menuItem : menu) {
            if (menuItem.category == "food") {
                food.push_back(menuItem.name);
            }
        }
        return food;
    }
};

int main() {
    string shopName;
    cout << "Enter Coffee Shop Name: ";
    cin >> shopName;

    CoffeeShop shop(shopName);
    shop.setMenu();

    int choice;
    string item;

    do {
        cout << "\n1. Add Order\n2. Fulfill Order\n3. List Orders\n4. Show Due Amount\n5. Show Cheapest Item\n6. Show Drinks Only\n7. Show Food Only\n8. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Item to Order: ";
                cin >> item;
                cout << shop.addOrder(item) << endl;
                break;
            case 2:
                cout << shop.fulfillOrder() << endl;
                break;
            case 3:
                shop.listOrders();
                break;
            case 4:
                cout << "Total Amount Due: $" << shop.dueAmount() << endl;
                break;
            case 5:
                cout << "Cheapest item: " << shop.cheapestItem() << endl;
                break;
            case 6: {
                vector<string> drinks = shop.drinksOnly();
                cout << "Drinks Available:\n";
                for (auto &drink : drinks) cout << "- " << drink << endl;
                break;
            }
            case 7: {
                vector<string> food = shop.foodOnly();
                cout << "Food Available:\n";
                for (auto &item : food) cout << "- " << item << endl;
                break;
            }
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid Choice! Try Again.\n";
        }
    } while (choice != 8);

    return 0;
}
