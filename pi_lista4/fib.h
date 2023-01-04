int fib(int*tab,int n){
    for (int i=2;i<n;i++){
        tab[i]=tab[i-1]+tab[i-2];
    }
    return tab[n];
}
