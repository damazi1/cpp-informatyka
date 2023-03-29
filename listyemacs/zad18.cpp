#include <iostream>
#include <cstring>


using namespace std;

char* wstaw(const char*src,char symbol){
    size_t n=strlen(src)+strlen(src)/3+2,j=0,i=0;
    char*tab=new char [n];
    for(;j<n&&src[i];j++){
        if(j%4==0){
            tab[j]=symbol;
        }
        else{
            tab[j]=src[i];
            i++;
        }
    }
    return tab;
}

void wstaw(char *cel,const char* src,char symbol){
    size_t n=strlen(src)+strlen(src)/3+2,j=0,i=0;
    for(i=0;i<n&&src[i];i++){
        if(i%4==0){
            cel[i]=symbol;
        }
        else{
            cel[i]=src[j];
            j++;
        }
    }
}

int main(int argc,char*argv[]){
    if(argc!=3){
        cerr<<"Podana ilosc argumentow jest bledna(3)"<<endl;
        cout<<"Poprawny zapis to ./nazwa zdanie"<<endl;
        return 1;
    }

    return 0;
}