#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
	int n;
	cin >> n;
	vector<long long> x(n);
	for (int i = 0; i < n; i++){
		cin >> x[i];
	}
	ll current_sum = x[0];
	ll max_subarray_sum = x[0];
	for (int i = 1; i < n; i++){
		/*
		 * Continue the subarray sum or start a new
		 * subarray sum beginning at the current element.
		 */
		current_sum = max(current_sum + x[i], x[i]);
		// Store the maximum subarray sum at each iteration.
		max_subarray_sum = max(max_subarray_sum, current_sum);
	}
	cout << max_subarray_sum << endl;
}
// From: https://usaco.guide/silver/more-prefix-sums/#max-subarray-sum
