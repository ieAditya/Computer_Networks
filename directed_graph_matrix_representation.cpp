#include<bits/stdc++.h>
using namespace std;

int main(){
    int size;
    cout<<"Input number of vertices : ";
    cin>>size;
    int arr[size][size]={0};
    int edges;
    cout<<"Number of edges you will input : ";
    cin>>edges;
    while(edges){
        int v1,v2;
        cout<<"Input v1,v2 : ";
        cin>>v1>>v2;
        arr[v1-1][v2-1] = 1;

        edges--;
    }
    for(int i = 0; i<size; i++){
        for(int j = 0; j < size; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}