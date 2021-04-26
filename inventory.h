#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

//create a data structure for storing the info of the inventory of what he owns and what he mounted
struct inventory_item{
    int id, type;
    string name;
    double effect;
    bool mounted;
    bool owned;
};

vector <inventory_item> items;
inventory_item input;
//depends on whether printmode is 1 or 0 (0 for owned and 1 for mounted)
void printinventory(int printMode){
    vector<inventory_item>::iterator iter;
    if (printMode == 0){
        cout << "Your owned items: " << endl;
        int ownedcounter = 0;
        //use for loop to read the inventory item he owned
        for (iter = items.begin(); iter != items.end(); iter++){
            //if he own the item
            if (iter->owned == 1){
                ownedcounter += 1;
                string type_name;
                //read the type of the the item
                if (iter->type == 0){
                    type_name = "Attack";
                }
                else if (iter->type == 1){
                    type_name = "Shield";
                }
                else if (iter->type == 2){
                    type_name = "HP armor";
                }
                //display the item he owned with the basic information
                cout << iter->id << ' ' << iter->name << " Type: " << type_name << endl;
            }
        }
        //in case he have no owned item
        if (ownedcounter == 0){
            cout << "No owned items! " <<endl;
        }
    }
    //display mounted item
    else if (printMode == 1){
        cout << "Your mounted items: " << endl;
        int mountedcounter = 0;
        //use for loop to read the item he mounted
        for (iter = items.begin(); iter != items.end(); iter++){
            if (iter->mounted == 1){
                mountedcounter += 1;
                string type_name;
                //read the type of item
                if (iter->type == 0){
                    type_name = "Attack";
                }
                else if (iter->type == 1){
                    type_name = "Shield";
                }
                else if (iter->type == 2){
                    type_name = "HP armor";
                }
                //display the basic info of each item he mounted
                cout << iter->id << ' ' << iter->name << " Type: " << type_name << endl;
            }
        }
        //in case he have n mounted item
        if (mountedcounter == 0){
            cout << "No mounted items! " <<endl;
        }
    }
    cout << "" << endl;
    
}

void readInventory(){
    ifstream inventories;
    //open the text file inventory.txt
    inventories.open ("inventory.txt");
//output error if cant read the inventory txt
    if (inventories.fail()){
        cout << "Error in file opening!" << endl;
        exit(1);
    }
//use while loop to read until the end of the file
    while (inventories.eof() != 1){
        //read the line in the order of id,type of item, effect, whether or not it is mounted or owned
        inventories >> input.id >> input.type >> input.name >> input.effect >> input.mounted >> input.owned;
        items.push_back(input);
    }
    //close the inventory file
    inventories.close();
    items.pop_back();

}
//use to update item status to the inventory txt to record the updated inventory list of the player
void writeInventory(){
    ofstream inventories;
    //open the file inventory.txt
    inventories.open("inventory.txt");
    //clear all existed data
    inventories.clear();

    //output error message in case cannot read the file

    if (inventories.fail()){
        cout << "Error in file opening!" << endl;
        exit(1);
    }
    //initialize vector to store the item info
    vector<inventory_item>::iterator iter;   
    //updated the inventory status and write into inventory.txt
    for ( iter = items.begin(); iter != items.end(); iter++)   {
        inventories << iter->id << "    " << iter->type << "    " << iter->name << "    " << iter->effect << "    " << iter->mounted << "    " << iter->owned <<"\n";
    } 
    inventories.close();

}

// this is used to unmount a item from the player status
void unmount(int unmountID){
    vector<inventory_item>::iterator iter;     
    //use for loop to search through the inventory to locate the item to be unmounted
    for ( iter = items.begin(); iter != items.end(); iter++){
        //use if...else to check whether the item has been mounted or not
        if ( iter->id == unmountID && iter->mounted == 1){
            iter->mounted = 0;
            cout << "Item" << iter->id << ' ' << iter->name << " has been unmounted" << endl;
        }
        else if ( iter->id == unmountID && iter->mounted == 0){
            cout << "Item has not been mounted!" << endl;
        }
    } 
    //call this function to update the inventory status for unmount of a specific item
    writeInventory();
}

// this function is used for user to input the specific item he want to unmount
void unmountItems(){
    int unmountID;
    cout << "These are your mounted items: " << endl;
    //this function is called for displaying the mounted item in print mode 1
    printinventory(1);
    cout << "Enter the item ID to be unmounted: " << endl;
    //read the specific id of the item to be unmount
    cin >> unmountID;
    //call to function to unmount the specific item
    unmount(unmountID);
}

void equipitems(){
    cout << "These are your mounted items. You can mount 3 items at most." << endl;
    //display the mounted item
    printinventory(1);
    int choice;
    cout << "1. Mount an item" << endl;   
    cout << "0. Exit" << endl;
    //read the instruction whether to mount or not
    cin >> choice;
    //use while loop to loop until choice =0
    while (choice != 0){
        if (choice == 1){
            int numMounted = 0;
            vector<inventory_item>::iterator iter;     
            //search the inventory item
            //use for loop to count the number of item that have been mounted
            for ( iter = items.begin(); iter != items.end(); iter++){
                if (iter->mounted == 1){
                    numMounted +=1;
                }
            }            
            cout << "You have mounted " << numMounted << " items" << endl;
            printinventory(1);
            //display the mounted item
            //in case the player has reached the maximun number of item can be mounted
            if (numMounted == 3) {
                cout << "Max items mounted! Would you like to unmount some? 1. Yes/2. No" << endl;
                int yesNo;
                cin >> yesNo;
                //use while loop to allow the player to unmount as many item as he want
                while (yesNo != 2){
                    int unmountID;
                    cout << "Please input the item id to be unmounted" << endl;
                    cin >> unmountID;
                    //call this function to unmount the specific item
                    unmount(unmountID);
                    cout << "Continue unmounting? 1. Yes/2. No" << endl;
                    //read the input again to confirm if the player would like to unmount the next item
                    cin >> yesNo;
                }
                //end the loop
                choice = 0;
            }
            else
            {
                int toMountId;
                cout << "Select inventory to be mouted: " << endl;
                //call this function to display the item he owned
                printinventory(0); 
                cin >> toMountId;
                vector<inventory_item>::iterator iter;     
                //search from the inventory item
                //use for loop to search for the item he would like to mount
                for ( iter = items.begin(); iter != items.end(); iter++){
                    if (iter->id == toMountId){
                        //change the item status he want to mount
                        iter->mounted = 1;
                        cout << "Item mounted: " << iter->name << endl;
                    }
                }
                //call this function to update the item status
                writeInventory();
                //end the loop
                choice = 0;
            }
            
        }
        else if (choice == 0 ){

            break;
        }     
        else {
            cout << "Wrong command!" <<endl;
            //verification
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
    //call this function to read the inventory txt
    readInventory();
    //display the instruction manual for player to decide the next instruction
    cout << "1. See all owned items" << endl;
    cout << "2. See mounted items" << endl;
    cout << "3. Equip items" << endl;
    cout << "4. Unmount items" << endl;
    cout << "0. Quit" << endl;
    cin >> choice;
    //read the instruction
    while (choice != 0 ){
        if (choice == 1){
            printinventory(0);
            //display the owned item
        }
        else if (choice == 2){
            printinventory(1);
            //display the mounted item
        }
        else if (choice == 3){
            equipitems();
            //call this function to mount or unmount item if he mounted 3 which is the maximum
        }
        else if (choice == 4){
            unmountItems();
            //call this function to unmount a specific item
        }
        else {
            cout << "Wrong Command!" << endl;
            //validation
        }
        //display the manual again
        cout << "1. See all items" << endl;
        cout << "2. See mounted items" << endl;
        cout << "3. Equip items" << endl;
        cout << "4. Unmount items" << endl;
        cout << "0. Quit" << endl;
        //read the player's next move
        cin >> choice;    
    }

}
