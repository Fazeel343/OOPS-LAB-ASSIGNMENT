#include <iostream>
#include <vector>
#include <string>
using namespace std;

class User {
    public:
        string user_id;
        string first_name;
        string last_name;
        string address;
        string email;

        User(string uid, string fname, string lname, string addr, string mail)
            : user_id(uid), first_name(fname), last_name(lname), address(addr), email(mail) {}
};

class Product {
    public:
        string product_id;
        string product_name;
        string description;
        int price;

        Product(string pid, string pname, string desc, int p)
            : product_id(pid), product_name(pname), description(desc), price(p) {}
};

class Order {
    public:
        string order_id;
        string user_id;
        string product_id;
        int total_paid;

        Order(string oid, string uid, string pid, int paid)
            : order_id(oid), user_id(uid), product_id(pid), total_paid(paid) {}
};

int main() {
    vector<User> users = {
        User("U001", "Linus", "Torvalds", "Finland", "linus@example.com"),
        User("U002", "Ada", "Lovelace", "UK", "ada@example.com")
    };

    vector<Product> products = {
        Product("P001", "Laptop", "High-end laptop", 1200),
        Product("P002", "Phone", "Latest smartphone", 800),
        Product("P003", "Keyboard", "Mechanical keyboard", 100)
    };

    vector<Order> orders = {
        Order("O001", "U001", "P001", 1200),
        Order("O002", "U001", "P003", 100),
        Order("O003", "U002", "P002", 800)
    };

    string linus_id = "";
    for (const auto& user : users) {
        if (user.first_name == "Linus") {
            linus_id = user.user_id;
            break;
        }
    }

    if (linus_id == "") {
        cout << "User Linus not found.\n";
        return 1;
    }

    cout << "Products ordered by Linus:\n";
    for (const auto& order : orders) {
        if (order.user_id == linus_id) {
            for (const auto& product : products) {
                if (product.product_id == order.product_id) {
                    cout << "- " << product.product_name << endl;
                    break;
                }
            }
        }
    }

    return 0;
}
