#include <iostream>
#include<cmath>
#include<limits.h>
using namespace std;

int g=9;

void print(int puzzle[]){
    for(int i=0;i<9;i++){
        if(i%3==0) cout<<"\n";
        if(puzzle[i] == 1) cout<<" - ";
        else cout<<puzzle[i]<<" ";
    }
    cout<<"\n\n";
}

void moveLeft(int start[],int position){
    swap(start[position],start[position - 1]);
}

void moveRight(int start[],int position){
    swap(start[position],start[position + 1]);
}
void moveUp(int start[],int position){
    swap(start[position],start[position - 3]);
}
void moveDown(int start[],int position){
    swap(start[position],start[position + 3]);
}

void copy(int temp[],int real[]){
    for(int i=0;i<9;i++){
        temp[i]=real[i];
    }
}



void main(){
    int goal[9],start[9];

    cout<<"Enter start state: ";
    for(int i=0;i<9;i++){
       cin>> start[i];
    }

    cout<<"Enter Goal state: ";
    for(int i=0;i<9;i++){
        cin>>goal[i];
    }
}
