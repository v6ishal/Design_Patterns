#include<bits/stdc++.h>
using namespace std;

//Factory - car, bike concrete classes
//Abstract factory - Lamborghini car, Ducatti Bike, family of classes, factories that will in turn create classes

class IButton
{
    public:
        virtual void press() = 0;
};

class MacButton:public IButton
{
    public:
        void press()
        {
            cout<<"Pressing Mac Button"<<endl;
        }
};

class WinButton:public IButton
{
    public:
        void press()
        {
            cout<<"Pressing Windows Button"<<endl;
        }
};

class ITextBox
{
    public:
        virtual void showText() = 0;

};

class MacTextBox:public ITextBox
{
    public:
        void showText()
        {
            cout<<"Showing Mac Text"<<endl;
        }
};

class WinTextBox:public ITextBox
{
    public:
        void showText()
        {
            cout<<"Showing Windows Text"<<endl;
        }
};

class IFactory
{
    public:
        virtual IButton* CreateButton() = 0;
        virtual ITextBox* CreateTextBox() = 0;
};

class MacFactory:public IFactory
{
    public:
        IButton* CreateButton(){
            return new MacButton();
        }

        ITextBox* CreateTextBox(){
            return new MacTextBox();
        }
};

class WinFactory:public IFactory
{
    public:
        IButton* CreateButton(){
            return new WinButton();
        }

        ITextBox* CreateTextBox(){
            return new WinTextBox();
        }
};

class GUIAbstractFactory
{
    public:
        static IFactory* CreateFactory(string ostype)
        {
            if(ostype == "Windows")
                return new WinFactory();
            else
                return new MacFactory();
        }

};  


int main()
{
    cout<<"Enter Machine OS"<<endl;
    string ostype;
    cin>>ostype;

    IFactory* fact = GUIAbstractFactory::CreateFactory(ostype);

    IButton* button = fact->CreateButton();
    button->press();

    ITextBox* textbox = fact->CreateTextBox();
    textbox->showText(); 


    return 0;
}
