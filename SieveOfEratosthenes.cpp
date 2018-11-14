#include <bits/stdc++.h>
#define M 100000
using namespace std;
bool marked[M];

//bool isPrime(int n){
//    if(n < 2) return false;
//    for(int i = 2; i < n; i++){
//        if(n % i == 0) return false;
//    }
//    return true;
//}

//bool isPrime(int n){
//    if(n < 2) return false;
//    for(int i = 2; i * i <= n; i++){
//        if(n % i == 0) return false;
//    }
//    return true;
//}

void sieve(int n){
    for(int i = 3; i * i <= n; i += 2){
        if(!marked[i]) {
            for(int j = i * i; j <= n; j += i + i){
                marked[j] = true;
            }
        }
    }
}

bool isPrime(int n){
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    sieve(n);
    return !marked[n];
}

int main(){
    int num = 139;
    //sieve(num);
    if(isPrime(num)) printf("The number is prime");
    else printf("The number is not prime");

    return 0;
}