class Solution {
public:
    int countPrimes(int n) {
        // 如果在 [2,sqrt(n)] 这个区间之内没有发现可整除因子，就可以直接断定 n 是素数了，因为在区间 [sqrt(n),n] 也一定不会发现可整除因子。
        //  Sieve of Eratosthenes O(N * loglogN)
        vector<bool> isPrime(n, true);
        for (int i = 2; i * i < n; i++) 
            if (isPrime[i]) 
                // 排除法
                for (int j = i * i; j < n; j += i) 
                    isPrime[j] = false;
        int count = 0;
        for (int i = 2; i < n; i++)
            if (isPrime[i]) count++;
        
        return count;
    }
};// https://leetcode.cn/problems/count-primes/description/