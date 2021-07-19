#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		long long n, k;
		cin >> n >> k;
		vector<long long> a(n);	
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		auto GetMaximumSubarray = [&](vector<long long> temp) {
			long long best = LLONG_MIN;
			long long sum = 0;
			for (int i = 0; i < (int) temp.size(); i++) {
				sum = max(temp[i], sum + temp[i]);
				best = max(best, sum);
			}
			return best;
		};
		if (k == 1) {
			// if 'k' is equal to 1, then simply find the maximum subarray sum
			cout << GetMaximumSubarray(a);
		} else {
			// calculate the sum of all the elements in the sequence
			long long sum = accumulate(a.begin(), a.end(), 0LL);
			// insert all of the elements again in vector 'a' (to create two same sequences)
			for (int i = 0; i < n; i++) {
				a.emplace_back(a[i]);
			}
			// find the maximum subarray sum in this new sequence
			long long res = GetMaximumSubarray(a);
			// check if 'sum' is greater than 0
			if (sum > 0) {
				// if yes, then add the product of ('sum' and ('k' - 2)) to 'res'
				// note: we are subtracting 2 from 'k' since we have already found the
				// maximum subarray sum when we inserted all the elements again in the sequence (above)
				res += (sum * (k - 2));
			}
			cout << res;
		}
		cout << '\n';
	}
	return 0;
}
