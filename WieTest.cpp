#include <iostream>
using namespace std;

int main(int argc, char** argv) {
   ios_base::sync_with_stdio(0); // zabieg optymalizacyjny zwiazany z potokami(według OI, na ich stronie)
   int n;

   cin >> n; // standardowe wejście
   for(int i = 0; i < n; ++i){
       for(int j = 0; j < n; ++j){
            cout << ".";
        }
       cout << "\n";
   }
    return 0;
}

