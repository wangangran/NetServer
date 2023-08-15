//
// Created by Administrator on 2023/8/15.
//
#include <iostream>
#include <optional>
#include <string>
#include <vector>

struct student {
    int id;
    std::string name;
};

int main(int argc, char *argv[]) {
    std::vector<student> sts;
    sts.push_back({001, "xiaoming"});
    sts.push_back({002, "zhangsan"});
    auto getStudentInfo = [&sts] () -> std::optional<student> {
        if (sts.empty()) {
            return std::nullopt;
        }
        student t = sts.back();
        sts.pop_back();
        return t;
    };

    if (auto ret = getStudentInfo(); ret.has_value()) {
        std::cout << ret->id << " " << ret->name << std::endl;
    }
    return 0;
}
