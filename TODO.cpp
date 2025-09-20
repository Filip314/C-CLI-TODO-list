#include<iostream>
#include<vector>

using namespace std;

class Subject{
    private:
        vector<string> TODO;
        vector<string> DONE;
    public:
        Subject(){
            //empty constructor
        }
        void appendTODO(string s){
            TODO.push_back(s);
        }
        int find(string s, vector<string> * list){
            int i = 0;
            for(string e: *list){
                if(e == s){
                    return i; 
                }
                i++;
            }
            return -1;
        }
        bool check(string s){
            int i = find(s, &TODO);
            if(i > -1){
                DONE.push_back(TODO[i]);
                TODO.erase(TODO.begin() + i);
                return true;
            }else{
                return false;
            }
        }
        bool eraseTodoElement(string s){
            int i = find(s, &TODO);
            if(i > -1){
                TODO.erase(TODO.begin() + i);
                return true;
            }else{
                return false;
            }
        }
        bool eraseDoneElement(string s){
            int i = find(s, &DONE);
            if(i > -1){
                DONE.erase(DONE.begin() + i);
                return true;
            }else{
                return false;
            }
        }
        void writeTODO(){
            for(string s : TODO){
                cout << "* " << s << endl;
            }
        }
        void writeDONE(){
            for(string s: DONE){
                cout << "* " << s << endl;
            }
        }
};

bool readInput(int n, Subject & sub){
    string s;
    switch(n){
        case 1: // Add task
            cout << "Please enter the name of the task:" << endl;
            cin >> s;
            sub.appendTODO(s);
            break;       

        case 2: // Check out the task
            cout << "Please enter the task you want to check." << endl;
            cin >> s;
            sub.check(s);
            break;
        
        case 3: // Remove task from TODO
            cout << "Please enter the name of the task you want to remove." << endl;
            cin >> s;
            sub.eraseTodoElement(s);
            break;

        case 4: // Remove task from DONE
            cout << "Please enter the name of the task you want to remove." << endl;
            cin >> s;
            sub.eraseDoneElement(s);
            break;
        case 5: // Write out TODO tasks
            sub.writeTODO();
            break;
        case 6: // Write out DONE tasks
            sub.writeDONE();
            break;
    }
    return true;
} //TODO: add return statements later
void printMessage(){
    cout << "Please enter a number to select a specific option:" << endl;
    cout << "1 : Add additional task to the TODO section." << endl;
    cout << "2 : Checkout out the task. Move it to the DONE section." << endl;
    cout << "3 : Remove task from the TODO section." << endl;
    cout << "4 : Remove task from the DONE section." << endl;
    cout << "5 : Write out the whole TODO list." << endl;
    cout << "6 : Write out the whole DONE list." << endl << endl;
}


int main(){
    Subject test = Subject();
    int input;
    while(true){
        printMessage();
        cin >> input;
        readInput(input, test);
    }
    return 0;
}