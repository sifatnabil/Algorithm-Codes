#include <bits/stdc++.h>
using namespace std;
vector <int> primes;
vector <int> factors;

void sieve(int n){
    bool isPrime[n];
//    cout << "Root Square of n is: " << n << endl;
    for(int i = 0; i < n; i++) isPrime[i] = true;
    for(int i = 3; i * i <= n; i += 2){
        if(isPrime[i])
            for(int j = i * i; j <= n; j += i + i) isPrime[i] = false;
    }
    primes.push_back(2);
    for(int i = 3; i <= n; i += 2)
        if(isPrime[i]) primes.push_back(i);

//    cout << "The array of Primes: ";
//    for(int i = 0; i < primes.size(); i++) cout << primes[i] << " ";
}

void primeFactorization(int n){
    sieve(sqrt(n) + 1);
    for(int i = 0; primes[i] * primes[i] <= n && i < primes.size(); i++){
       // cout << "prime divisor: " << primes[i] << endl;
        if(n % primes[i] == 0){
            while(n % primes[i] == 0){
                n /= primes[i];
                //cout << "n is: " << n << endl;
                factors.push_back(primes[i]);
            }
        }
    }

    if(n > 1){
        factors.push_back(n);
    }

    for(int i = 0; i < factors.size(); i++) cout << factors[i] << " " ;
    cout << endl;

}


int main(){
    int num = 35;
    primeFactorization(num);

    return 0;
}