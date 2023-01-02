class Solution {
public:
    void SieveOfEratosthenes(vector<bool>& prime) {

        for (int p = 2 ; p * p <= 1000000 ; p++) {
            if (prime[p] == true) {
                for (int i = p * p ; i <= 1000000 ; i += p) {
                    prime[i] = false;
                }
            }
        }
    }

    vector<int> closestPrimes(int left, int right) {
        
        if(right <= 2) return { -1, -1 };
        
        vector<bool> prime(1000001, true);
        prime[0] = false;
        prime[1] = false;
        SieveOfEratosthenes(prime);
        
        int minDiff = INT_MAX;
        int nums1 = -1, nums2 = -1;
        vector<int> primes;
        
        for(int i=left ; i<=right ; i++) {
            if(prime[i]) primes.push_back(i);
        }
        
        for(int i=0 ; i<primes.size()-1 ; i++) {
            if(primes[i+1]-primes[i] < minDiff) {
                minDiff = primes[i+1] - primes[i];
                nums1 = primes[i];
                nums2 = primes[i+1];
            }
        }
        
        return { nums1, nums2 };
    }
};