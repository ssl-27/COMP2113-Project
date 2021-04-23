#include <vector>
#include <string>

struct inventory_item{
    int id, type;
    string name;
    double effect;
    bool mounted;
};

vector <inventory_item> items;
inventory_item mounted_items[3];

void printinventory(int printMode){
    vector<inventory_item>::iterator iter;
    if (printMode == 0){
        cout << "Your items: " << endl;
        for (iter = items.begin(); iter != items.end(); iter++){
            cout << items.id << endl;
        }  
    }
    else if (printMode == 1){
        cout << "Your mounted items: " << endl;
        for (iter = items.begin(); iter != items.end(); iter++){
            if (items.mounted == 1){
                cout << items.id << ' ' << items.name << endl;
            }
        }
    }
    
}

void equipitems(){
    cout << "These are your mounted items. You can mount 3 items at most." << endl;
    printinventory(1);
    
}

void inventory(){
    int choice;
    cout << "1. See all items" << endl;
    cout << "2. See mounted items" << endl;
    cout << "3. Equip items" << endl;
    cin >> choice;
    while (choice != 1 || choice != 2 || choice != 3 ){
        cout << "wrong command! Input again";
        cin >> choice; 
    }
    if (choice == 1){
        printinventory(0);
    }
    else if (choice == 2){
        printinventory(1);
    }
    else if (choice == 3){
        equipitems();
    }
}