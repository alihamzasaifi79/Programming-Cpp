#include <iostream>
#include <string>
using namespace std;

class Logger {
private:
    static string logs[10];
    static int count;

public:
    static void log(const string &str) {
        if (count< 10) {
            logs[count]=str;
            count++;
        } else {
            cout<<"log array is full, cannot store more messages."<<endl;
        }
    }

    static void printLogs() {
        cout<<"logged messages are:"<<endl;
        for(int i=0; i<count; i++){
            cout<<logs[i]<<endl;
        }
    }
};

string Logger::logs[10];
int Logger::count=0;

int main(){
    Logger::log("message 1");
    Logger::log("message 2");
    Logger::log("message 3");
    Logger::log("message 4");
    Logger::log("message 5");
    Logger::printLogs();
    return 0;
}

