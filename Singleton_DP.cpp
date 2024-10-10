#include<bits/stdc++.h>
using namespace std;

class Logger
{
private:
    static int i;
    Logger();
    static unique_ptr<Logger> obj;
    // ~Logger()
    // {
    //     cout<<"In DTR"<<endl;
    // }
public:
    static Logger* LoggerInstance();
    void viewLog(string str);
    // static void deleteInstance();
};

Logger* Logger::LoggerInstance()
{
    if(obj == nullptr){
        obj = unique_ptr<Logger>(new Logger());
    }
    return obj.get();
}

// void Logger::deleteInstance()
// {
//     if(obj != nullptr){
//         delete obj;
//         obj = nullptr;
//     }
// }

//Logger* Logger::obj = nullptr;
unique_ptr<Logger> Logger::obj = nullptr;

int Logger::i = 0;

Logger::Logger(){
    i++;
    cout<<"Logger Instance Count = "<<i<<endl;
}

void Logger::viewLog(string str){
    cout<<str<<endl;
}

int main()
{
    Logger* logger1 = Logger::LoggerInstance();
    Logger* logger2 = Logger::LoggerInstance();

    logger1->viewLog("Log1 msg");
    logger2->viewLog("Log2 msg");

    //Logger::deleteInstance();

    return 0;
}
