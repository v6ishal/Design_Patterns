#include<bits/stdc++.h>
using namespace std;

// Two incompatible objects, but we could put adpter in between, and everything works.

class XMLData{
    string xmlData;
public:
    XMLData(string pXmlData):xmlData(pXmlData){}

    string getData()
    {
        return xmlData;
    }
};

class DataAnalyticsTool
{
    string jsonData;
public:
    DataAnalyticsTool() {}
    DataAnalyticsTool(string pJsonData):jsonData(pJsonData){}

    virtual void analyseData()
    {
        cout<<"Analysing Data"<<jsonData<<endl;
    }
};

class Client
{
public:
    void ProcessData(DataAnalyticsTool* tool)
    {
        tool->analyseData();
    }
};

class Adapter:public DataAnalyticsTool
{
    XMLData* xml;
public:
    Adapter(){};
    Adapter(XMLData* xmldata)
    {
        xml = xmldata;
    }

    void analyseData(){
        cout<<"Converting xml to json: "<<xml->getData()<<endl;
    }
};

int main()
{
    XMLData* xml1 = new XMLData("Sample XML Data");
    //problem is we don't have json data but xml data
    //DataAnalyticsTool* tool1 = new DataAnalyticsTool();
    DataAnalyticsTool* tool1 = new Adapter(xml1);
    Client* client = new Client();
    client->ProcessData(tool1);


    return 0;
}
