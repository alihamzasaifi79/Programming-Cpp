#include <iostream>
#include <string>
using namespace std;

int main() {
    string* ptr= new string[5];
    ptr[0] = "Read";
    ptr[1] = "Bear";
    ptr[2] = "Hat";
    ptr[3] = "beat";
    ptr[4] = " ";
    
    for (int i=0; i<5; i+=2) { 
    if(ptr[i].length()>0 && ptr[i+1].length()>0) {
        char temp = ptr[i][0];
        ptr[i][0] = ptr[i+1][0];
        ptr[i+1][0] = temp;
    }
}
    int t=0;
    for(int i=0;i<5;i++) {
        t+=ptr[i].length();
    }
    
    cout<<"after swapping: "<<endl;
    for(int i=0;i<5;i++) {
        cout<<ptr[i]<<endl;
    }

    cout<<"total number of characters:"<<t<<endl;

    delete[] ptr;
    ptr = NULL;

    return 0;
}

