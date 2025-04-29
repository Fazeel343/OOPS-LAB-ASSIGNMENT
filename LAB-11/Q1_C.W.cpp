#include <iostream>
#include <string>
#include <unordered_map>
#include <stdexcept>
using namespace std;

enum Type { INT, FLOAT, STRING };

class BadTypeException : public exception {
    public:
        const char* what() const noexcept override {
            return "Wrong Type Requested!";
        }
};

struct Entry {
    void* data;
    Type type;
};

class TypeSafeContainer {
    unordered_map<string, Entry> store;

    public:
        void put(string key, int value) {
            int* ptr = new int(value);
            store[key] = { ptr, INT };
        }

        void put(string key, float value) {
            float* ptr = new float(value);
            store[key] = { ptr, FLOAT };
        }

        void put(string key, string value) {
            string* ptr = new string(value);
            store[key] = { ptr, STRING };
        }

        int getInt(string key) {
            if (store[key].type != INT) throw BadTypeException();
            return *(int*)store[key].data;
        }

        float getFloat(string key) {
            if (store[key].type != FLOAT) throw BadTypeException();
            return *(float*)store[key].data;
        }

        string getString(string key) {
            if (store[key].type != STRING) throw BadTypeException();
            return *(string*)store[key].data;
        }

        ~TypeSafeContainer() {
            for (auto& p : store) {
                if (p.second.type == INT) delete (int*)p.second.data;
                else if (p.second.type == FLOAT) delete (float*)p.second.data;
                else if (p.second.type == STRING) delete (string*)p.second.data;
            }
        }
};

int main() {
    TypeSafeContainer container;

    container.put("age", 23);
    container.put("pi", 3.14f);
    container.put("name", "Faizan");

    try {
        cout << "Name: " << container.getString("name") << endl;
        cout << "Age: " << container.getInt("age") << endl;
        cout << "PI: " << container.getFloat("pi") << endl;

        cout << container.getFloat("name") << endl;
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
