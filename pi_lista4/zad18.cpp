#include <iostream>

using namespace std;
// int main(){
//     int n=6;
//     int silnia=1;
//     for (int i=1;i<n;i++){
//         silnia=silnia*i;
//     }
//     cout<<silnia<<endl;
//     return 0;
// }
long silnia(int n){
    if(n<2){
        return 1;
    }
    return n*silnia(n-1);
}
int main(){
    int n=6;
    cout<<silnia(n)<<endl;
    return 0;
}