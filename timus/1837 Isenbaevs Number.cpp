#include "../euler/undirected_graph.hpp"
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <set>

int main() {
    undirected_graph<std::string> g;
    std::set<std::string> all_names;
    int n;
    std::cin >> n;
    while (n--) {
        std::string tmp[3];
        for (int i = 0; i < 3; ++i) {
            std::cin >> tmp[i];
            all_names.insert(tmp[i]);
        }
        for (int i = 0; i < 3; ++i)
            for (int j = i + 1; j < 3; ++j)
                g.connect(tmp[i], tmp[j]);
    }

    std::map<std::string, int> recorded;
    std::queue<Edge<std::string>> q;
    auto level1 = g["Isenbaev"];
    recorded["Isenbaev"] = 0;
    for (auto i : level1)
        q.push(i);
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        if (recorded.find(t.to_) == recorded.end())
            recorded[t.to_] = recorded[t.from_] + 1;
        for (auto i : g[t.to_]) {
            if (recorded.find(i.to_) == recorded.end())
                q.push(i);
        }
    }

    for (auto i : all_names) {
        std::cout << i << " ";
        if (recorded.find(i) == recorded.end())
            std::cout << "undefined";
        else
            std::cout << recorded[i];
        std::cout << std::endl;
    }
}
