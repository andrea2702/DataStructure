#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int n;
  cin >> n;
  
  for(int i = 0; i < n; i++){
    int min, max, num = 0;
    cin >> min >> max;
    if(min == 1){
      num= -1;
    }
    
    for(int j = min; j <= max; j++){
      int acum = 0;
      for(int k = 1; k <= sqrt(j); k++){
        if(j%k==0){
          acum++;
          if(acum>1){
            break;
          }
        }
      }
      if(acum == 1){
        num++;
      }
    }
    cout << num << '\n';
  }
}