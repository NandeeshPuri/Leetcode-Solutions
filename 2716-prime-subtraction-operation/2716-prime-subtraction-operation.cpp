class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> primes = sieveOfEratosthenes(1000);
        for (int i = nums.size(); i >= 2; i--) {
            if (nums[i - 2] >= nums[i - 1]) {
                int index = -1;
                for (int primeIndex = 0; primeIndex < primes.size(); primeIndex++) {
                    if (primes[primeIndex] >= nums[i - 2]) {
                        break;
                    }

                    if (nums[i - 2] - primes[primeIndex] < nums[i - 1]) {
                        index = primeIndex;
                        break;
                    }
                }
                if (index == -1) {
                    return false;
                }
                nums[i - 2] = nums[i - 2] - primes[index];
            }
        }
        return true;
    }

    vector<int> sieveOfEratosthenes(int count) {
        vector<int> result;
        vector<bool> primes(count + 1, true);
        for (int i = 2; i * i <= count; i++) {
            if (primes[i]) {
                for (int j = i * 2; j <= count; j += i) {
                    primes[j] = false;
                }
            }
        }
        for (int i = 2; i <= count; i++) {
            if (primes[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
};