#include <bits/stdc++.h>

std::tuple<std::tuple<double, double, int>, std::tuple<double, double, int>, double> 
dist (std::tuple<double, double, int> p1, std::tuple<double, double, int> p2){
    return {p1,p2,sqrt(pow(std::get<0>(p1) - std::get<0>(p2), 2) + pow(std::get<1>(p1) - std::get<1>(p2), 2))};
}

std::tuple<std::tuple<double, double, int>, std::tuple<double, double, int>, double> 
closestPair(int l, int r, const std::vector<std::tuple<double, double, int>>& alumni) {
    // Base Case
    if (r-l == 1){
        return dist(alumni[l], alumni[r]);
    }
    if (r-l == 2){
        auto pair1 = dist(alumni[l], alumni[l+1]);
        auto pair2 = dist(alumni[l+1], alumni[r]);
        auto pair3 = dist(alumni[l], alumni[r]);

        return std::min({pair1, pair2, pair3}, [](const auto &a, const auto &b){
            return std::get<2>(a) < std::get<2>(b);
        });
    }
    // Split and recurr
    int mid = l + (r - l) / 2;
    auto resL = closestPair(l, mid, alumni);
    auto resR = closestPair(mid+1, r, alumni);

    // Merge
    auto resMin = std::min({resL, resR}, [](const auto &a, const auto &b){
        return std::get<2>(a) < std::get<2>(b);
    });
    std::vector<std::tuple<double, double, int>> strip;
    for (int i = l; i <= r; i++){
        if (std::abs(std::get<0>(alumni[mid]) - std::get<0>(alumni[i])) < std::get<2>(resMin)){
            strip.push_back(alumni[i]);
        }
    }
    int strip_size = static_cast<int>(strip.size());
    for (int i = 0; i < strip_size; i++){
        for (int j = i+1; j < std::min(i+7, strip_size); j++){
            auto newRes = dist(strip[i], strip[j]);
            if (std::get<2>(newRes) < std::get<2>(resMin)){
                resMin = newRes;
            }
        }
    }
    return resMin;
}
int main() {
    // Fast IO
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Data Input
    int N;
    std::cin >> N;
    std::vector<std::tuple<double, double, int>> alumni(N);

    for (int i = 0; i < N; i++) {
        double x, y;
        std::cin >> x >> y;
        alumni[i] = {x, y, i + 1};
    }
    // Sort data with built-in and comparator
    std::sort(alumni.begin(), alumni.end(), [](const auto& a, const auto& b){
        return (std::get<0>(a) < std::get<0>(b)) || ((std::get<0>(a) == std::get<0>(b)) && (std::get<1>(a) < std::get<1>(b)));
    });

    // Print output
    auto res = closestPair(0,N-1,alumni);
    std::cout << std::get<2>(std::get<0>(res)) << " " 
          << std::get<2>(std::get<1>(res)) << " " 
          << std::fixed << std::setprecision(6) << std::get<2>(res) << "\n";

    return 0;
}
