#include<iostream>
#include<omp.h>

using namespace std;

int main() {
    #pragma omp parallel 
    {
        cout<<omp_get_thread_num();
    }
}