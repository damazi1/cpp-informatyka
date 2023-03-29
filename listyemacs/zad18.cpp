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
    tab[j]='\0';
    return tab;
}

void wstaw(char *cel,const char* src,char symbol){
    size_t n=strlen(src)+strlen(src)/3+2,j=0,i=0;
    for(i=0;i<n&&src[j];i++){
        if(i%4==0){
            cel[i]=symbol;
        }
        else{
            cel[i]=src[j];
            j++;
        }
    }
    cel[i]='\0';
}

void wstaw1(char*& cel,const char* src,char symbol){
    size_t n=strlen(src)+strlen(src)/3+2,j=0,i=0;
    cel=new char [n];
    for(i=0;i<n&&src[j];i++){
        if(i%4==0){
            cel[i]=symbol;
        }
        else{
            cel[i]=src[j];
            j++;
        }
    }
    cel[i]='\0';
}

void usun(char*tab){
    if(tab){
        delete []tab;
        tab=0;
    }
}

int szukaj(char*src,const char s){
    int liczba=0;
    size_t n=strlen(src);
    for(size_t i=0;i<n;i++){
        if(src[i]==s){
            liczba++;
        }
    }

    return liczba;
}

char*kopiuj(const char*src){
    size_t n=strlen(src),i=0;
    char *tab=new char [n+1];
    for(;i<n;i++){
        tab[i]=toupper(src[i]);
    }
    tab[i]='\0';
    return tab;
}

int main(int argc,char*argv[]){
    if(argc!=3){
        cerr<<"Podana ilosc argumentow jest bledna(3)"<<endl;
        cout<<"Poprawny zapis to ./nazwa zdanie"<<endl;
        return 1;
    }
    // argv[1]="Ala ma kota";
    // argv[2][0]='S';  
    size_t n1=strlen(argv[1])+strlen(argv[1])/3+2;


    char *tab=wstaw(argv[1],argv[2][0]);
    char*cel=new char[n1];
    char*cel1;
    wstaw(cel,argv[1],argv[2][0]);
    wstaw1(cel1,argv[1],argv[2][0]);
    
    cout<<tab<<endl;
    
    cout<<endl;
    
    cout<<cel;
    
    cout<<endl;
    
    cout<<cel1;
    
    cout<<endl;
    
    cout<<"Znak "<<argv[2][0]<<" Wystepuje "<<szukaj(cel,argv[2][0])<<" razy. "<<endl;

    char*kopia=kopiuj(tab);

    cout<<kopia;
    
    cout<<endl;
    

    usun(tab);
    usun(cel);
    usun(cel1);
    usun(kopia);
    return 0;
}