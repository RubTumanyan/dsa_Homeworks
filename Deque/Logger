#include <iostream>
#include <deque>
#include <string>

class Logger {
private:
    std::deque<std::string> messages;
    size_t capacity;

public:
    Logger(size_t N) : capacity(N) {}

    void add(const std::string& msg) {
        if (messages.size() == capacity) {
            messages.pop_front();
        }
        messages.push_back(msg); 
    }

    void show() const {
        for (const auto& msg : messages) {
            std::cout << msg << std::endl;
        }
    }
};

int main() {
    Logger log(3);

    log.add("start");
    log.add("init");
    log.add("run");
    log.add("stop");

    log.show();
    return 0;
}
