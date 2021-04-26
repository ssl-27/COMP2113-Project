#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <fstream>
using namespace std;


struct inventory_item{
    int id, type;
    string name;
    double effect;
    bool mounted;
    bool owned;
};

vector <inventory_item> items;
inventory_item input;

void printinventory(int printMode){
    vector<inventory_item>::iterator iter;
    if (printMode == 0){
        cout << "Your owned items: " << endl;
        int ownedcounter = 0;
        for (iter = items.begin(); iter != items.end(); iter++){
            if (iter->owned == 1){
                ownedcounter += 1;
                string type_name;
                if (iter->type == 0){
                    type_name = "Attack";
                }
                else if (iter->type == 1){
                    type_name = "Shield";
                }
                else if (iter->type == 2){
                    type_name = "HP armor";
                }
                cout << iter->id << ' ' << iter->name << " Type: " << type_name << endl;
            }
        }
        if (ownedcounter == 0){
            cout << "No owned items! " <<endl;
        }
    }
    else if (printMode == 1){
        cout << "Your mounted items: " << endl;
        int mountedcounter = 0;
        for (iter = items.begin(); iter != items.end(); iter++){
            if (iter->mounted == 1){
                mountedcounter += 1;
                string type_name;
                if (iter->type == 0){
                    type_name = "Attack";
                }
                else if (iter->type == 1){
                    type_name = "Shield";
                }
                else if (iter->type == 2){
                    type_name = "HP armor";
                }
                cout << iter->id << ' ' << iter->name << " Type: " << type_name << endl;
            }
        }
        if (mountedcounter == 0){
            cout << "No mounted items! " <<endl;
        }
    }
    cout << "" << endl;
    
}

void readInventory(){
    ifstream inventories;
    inventories.open ("inventory.txt");

    if (inventories.fail()){
        cout << "Error in file opening!" << endl;
        exit(1);
    }

    while (inventories.eof() != 1){
        inventories >> input.id >> input.type >> input.name >> input.effect >> input.mounted >> input.owned;
        items.push_back(input);
    }
    
    inventories.close();
    items.pop_back();

}

void writeInventory(){
    ofstream inventories;
    inventories.open("inventory.txt");
    inventories.clear();
    if (inventories.fail()){
        cout << "Error in file opening!" << endl;
        exit(1);
    }
    vector<inventory_item>::iterator iter;     
    for ( iter = items.begin(); iter != items.end(); iter++)   {
        inventories << iter->id << "    " << iter->type << "    " << iter->name << "    " << iter->effect << "    " << iter->mounted << "    " << iter->owned <<"\n";
    } 
    inventories.close();

}


void unmount(int unmountID){
    vector<inventory_item>::iterator iter;     
    for ( iter = items.begin(); iter != items.end(); iter++){
        if ( iter->id == unmountID && iter->mounted == 1){
            iter->mounted = 0;
            cout << "Item" << iter->id << ' ' << iter->name << " has been unmounted" << endl;
        }
        else if ( iter->id == unmountID && iter->mounted == 0){
            cout << "Item has not been mounted!" << endl;
        }
    } 
    writeInventory();
}

void unmountItems(){
    int unmountID;
    cout << "These are your mounted items: " << endl;
    printinventory(1);
    cout << "Enter the item ID to be unmounted: " << endl;
    cin >> unmountID;
    unmount(unmountID);
}

void equipitems(){
    cout << "These are your mounted items. You can mount 3 items at most." << endl;
    printinventory(1);
    int choice;
    cout << "1. Mount an item" << endl;   
    cout << "0. Exit" << endl;
    cin >> choice;
    while (choice != 0){
        if (choice == 1){
            int numMounted = 0;
            vector<inventory_item>::iterator iter;     
            for ( iter = items.begin(); iter != items.end(); iter++){
                if (iter->mounted == 1){
                    numMounted +=1;
                }
            }            
            cout << "You have mounted " << numMounted << " items" << endl;
            printinventory(1);

            if (numMounted == 3) {
                cout << "Max items mounted! Would you like to unmount some? 1. Yes/2. No" << endl;
                int yesNo;
                cin >> yesNo;
                while (yesNo != 2){
                    int unmountID;
                    cout << "Please input the item id to be unmounted" << endl;
                    cin >> unmountID;
                    unmount(unmountID);
                    cout << "Continue unmounting? 1. Yes/2. No" << endl;
                    cin >> yesNo;
                }
                choice = 0;
            }
            else
            {
                int toMountId;
                cout << "Select inventory to be mouted: " << endl;
                printinventory(0); 
                cin >> toMountId;
                vector<inventory_item>::iterator iter;     
                for ( iter = items.begin(); iter != items.end(); iter++){
                    if (iter->id == toMountId){
                        iter->mounted = 1;
                        cout << "Item mounted: " << iter->name << endl;
                    }
                }
                writeInventory();
                choice = 0;
            }
            
        }
        else if (choice == 0 ){

            break;
        }     
        else {
            cout << "Wrong command!" <<endl;
        }    
    }

}

void dropinventory(){
    srand(time(NULL));
    int inventoryid = rand()%6 + 1;
    vector <inventory_item>:: iterator dropiter;
    for (dropiter = items.begin(); dropiter != items.end(); dropiter++){
        if (inventoryid == dropiter->id){
            dropiter->owned = 1;
            cout << "You are awarded with " << dropiter->name <<"! " << endl;
            cout << "It is added into your inventory! " <<endl;            
        }
    }
    writeInventory();
}


void inventory(){
    int choice;
    readInventory();
    cout << "1. See all owned items" << endl;
    cout << "2. See mounted items" << endl;
    cout << "3. Equip items" << endl;
    cout << "4. Unmount items" << endl;
    cout << "0. Quit" << endl;
    cin >> choice;
    while (choice != 0 ){
        if (choice == 1){
            printinventory(0);
        }
        else if (choice == 2){
            printinventory(1);
        }
        else if (choice == 3){
            equipitems();
        }
        else if (choice == 4){
            unmountItems();
        }
        else {
            cout << "Wrong Command!" << endl;
        }
        cout << "1. See all items" << endl;
        cout << "2. See mounted items" << endl;
        cout << "3. Equip items" << endl;
        cout << "4. Unmount items" << endl;
        cout << "0. Quit" << endl;
        cin >> choice;    
    }

}