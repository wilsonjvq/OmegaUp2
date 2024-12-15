// H. Divide and Conquer
// https://www.onlinegdb.com/online_c++_compiler

#include <iostream>
#include <vector>
#include <algorithm>

int maxSubarraySum(const std::vector<int>& arr) {
    int max_current = arr[0];
    int max_global = arr[0];

    for (size_t i = 1; i < arr.size(); ++i) {
        max_current = std::max(arr[i], max_current + arr[i]);
        max_global = std::max(max_global, max_current);
    }

    return max_global;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int max_sum = maxSubarraySum(arr);
    std::cout << max_sum << std::endl;

    return 0;
}
