#include <iostream>
#include <fstream>
#include <string>
#include <cstdio> 
using namespace std;

class Logger {
    string baseFile = "log.txt";
    int maxSize;

    int getFileSize(const string& filename) {
        ifstream in(filename, ios::binary | ios::ate);
        if (in) {
            return in.tellg();  
        } else {
            return 0;  
        }
    }

    void rotateLogs() {
        int count = 1;
        string newName;
        do {
            newName = "log" + to_string(count) + ".txt";
            ifstream f(newName);
            if (!f) break;
            count++;
        } while (true);

        rename(baseFile.c_str(), newName.c_str()); 
    }

    public:
        Logger(int sizeLimit = 1024) : maxSize(sizeLimit) {}

        void log(const string& message) {
            if (getFileSize(baseFile) >= maxSize) {
                rotateLogs();
            }

            ofstream fout(baseFile, ios::app);
            fout << message << endl;
            fout.close();
        }
};

int main() {
    Logger logger(300); 
    for (int i = 0; i < 20; ++i) {
        logger.log("Log Entry Number " + to_string(i + 1));
    }
    cout << "Logging Complete.\n";
    return 0;
}
