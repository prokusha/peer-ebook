#include <iostream>
#include <vector>

static const int MAX_PAGE = 1000;
static const int MAX_USER = 1e5;

class ebook {
public:
    ebook() : users_(MAX_USER), pages_(MAX_PAGE) {}

    void AddReader(int id, int page) {
        if (!users_[id]) {
            ++all_users_;
        } else {
            --pages_[users_[id]];
        }
        users_[id] = page;
        ++pages_[page];
    }

    void PrintStat(int id) {
        std::cout << GetReadStat(id) << std::endl;
    }

private:
    std::vector<int> users_;
    std::vector<int> pages_;
    int all_users_ = 0;

    double GetReadStat(int id) {
        double result = 0.0;
        if (all_users_ == 0) {
            return result;
        }
        if (all_users_ == 1) {
            result = users_[id] != 0 ? 1 : 0;
        } else {
            for (int i = 1; i < users_[id]; ++i) {
                result += pages_[i] / static_cast<double>(all_users_ - 1);
            }
        }
        return result;
    }
};

template <typename Type>
Type Input() {
    Type in;
    std::cin >> in;
    // std::cout << in << std::endl;
    return in;
}

int main() {
    ebook book;
    int count = Input<int>();
    for (int i = 0; i < count; ++i) {
        std::string command = Input<std::string>();
        if (command == "CHEER") {
            int id = Input<int>();
            book.PrintStat(id);
        } else if (command == "READ") {
            int id = Input<int>();
            int page = Input<int>();
            book.AddReader(id, page);
        }
    }
}
