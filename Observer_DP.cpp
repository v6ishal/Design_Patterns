#include<bits/stdc++.h>
using namespace std;

//usecase is send notification to all the subscribers of the channel.
//or broadcasting your messgae to all the observers

class IUser
{
    public:
        virtual void notify(string msg) = 0;
        virtual bool isadmin() = 0;
};

class User:public IUser{
    private:
        int id;
    public:
        User(int userid):id(userid){}
        void notify(string msg)
        {
            cout<<"User "<<id<<" Message: "<<msg<<endl;
        }
        bool isadmin()
        {
            return false;
        }
};

class AdminUser:public IUser
{
    private:
        int id;
    public:
        AdminUser(int userid): id(userid){}

        void notify(string msg)
        {
            cout << "Admin " << id << " received ADMIN MESSAGE: " << msg << endl;
        }
        bool isadmin(){
            return true;
        }
};

class Group
{
    private:
        list<IUser*> users;
        string msg;
    public:
        void subscribe(IUser* user){
            users.push_back(user);
        }
        void unsubscribe(IUser* user){
            users.remove(user);
        }
        
        void notify()
        {
            for(auto x:users){
                x->notify(msg);
            }
        }
            // Function to allow admin to change the message
        void changeMessage(IUser* user, string newMessage) {
            if (user->isadmin()) {
                msg = newMessage;
                cout << "Message changed by Admin to: " << newMessage << endl;
            } else {
                cout << "Only Admins can change the message!" << endl;
            }
        }
};


int main()
{
    Group* group = new Group();

    // Create regular users
    User* user1 = new User(1);
    User* user2 = new User(2);
    
    // Create an admin user
    AdminUser* admin1 = new AdminUser(101);

    // Adding users to the group
    group->subscribe(user1);
    group->subscribe(user2);
    group->subscribe(admin1);  // Admin is also added as a subscriber

    // Notify with default message
    group->notify();

    // Regular user trying to change the message (should fail)
    group->changeMessage(user1, "Regular user trying to change message");

    // Admin user changing the message (should succeed)
    group->changeMessage(admin1, "Admin changed the message");

    // Notify with updated message
    group->notify();

    return 0;
}
