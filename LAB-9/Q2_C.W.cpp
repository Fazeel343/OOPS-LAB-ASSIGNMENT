#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Logger {
private:
    vector<string> logs;
    const int maxLogs = 1000;

    void storeLog(const string& level, const string& message) {
        if (logs.size() >= maxLogs) {
            logs.erase(logs.begin()); // remove oldest
        }
        logs.push_back(level + ": " + message);
    }

public:
    void logInfo(const string& msg) { storeLog("INFO", msg); }
    void logWarning(const string& msg) { storeLog("WARNING", msg); }
    void logError(const string& msg) { storeLog("ERROR", msg); }

    vector<string> getLogs(const string& authToken) const {
        if (authToken == "audit123") {
            return logs;
        } else {
            return {}; // Unauthorized
        }
    }
};

int main() {
    Logger logger;
    logger.logInfo("Network module initialized");
    logger.logWarning("Database latency detected");
    logger.logError("Connection timeout");

    vector<string> auditLogs = logger.getLogs("audit123");
    for (const string& log : auditLogs) {
        cout << log << endl;
    }

    return 0;
}
