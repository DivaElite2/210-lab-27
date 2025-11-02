#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagers;// name, frienship level, species catchphrase

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagers["Audie"] = make_tuple(5, "Alligator", "see you later!");
    villagers["Raymond"] = make_tuple(1,"Parakeet ", "chirp");
    villagers["Marshal"]= make_tuple(2, "Cat", "purtastic!");

    // accessing  data
    cout << "Villagers details:" << endl;
    for (auto& pair : villagers) {
        auto[friendship, species, phrase] = pair.second;
        cout << pair.first << " : Level" << friendship << " <<endl;
        
    }

    // access the map using iterators
    cout << "\nVillagers detail:" << endl;
    for (auto it = villagers.begin(); it != villagers.end(); it++ ); 
         auto[friendship, species, phrase] = it->second;
        cout<< it->first << ":Level: "<< friendship <<" " <<species <<"says" <<phrase <<" " <<endl;
    }

     cout << endl;

    // delete an element
    villagers.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagers.find(searchKey);
    if (it != villagers.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagers.size() << endl;
    villagers.clear();
    cout << "Size after clear: " << villagers.size() << endl;

    return 0;
}
