//Lateefah Camacho
//210-Lab-27

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

// accessing data
    for (auto& pair : villagers) {
        auto[friendship, species, phrase] = pair.second;
        std::cout <<pair.first <<" [ "<< get<0>(pair.second) << ","<<get<1>(pair.second) <<","<<get<2>(pair.second) <<"]" <<
        endl;
        
    }

    // access the map using iterators
    std::cout << "\nVillagers detail:" << endl;
    for (auto it = villagers.begin(); it != villagers.end(); it++ ) {
         auto[friendship, species, phrase] = it->second;
       std::cout<< it->first << ":Level: "<< friendship <<" " << species <<" says" <<phrase <<" " <<endl;
    }

     //std::cout << endl;

    // delete an element
    villagers.erase("Raymond");

    
    string searchName;
     cout << "Enter villager name to search: ";
     cin >> searchName;

      auto it = villagers.find(searchName); // search for an element using .find() to avoid errors

    if (it != villagers.end()) {
    auto [f, s, p] = it->second;
    cout << "Found: " << it->first << " [Level " << f << ", " << s << ", '" << p << "']" << endl;
    
   } else {
    cout << searchName << " not found." << endl;
}

    // report size, clear, report size again to confirm map operations
   cout << "\nSize before clear: " << villagers.size() << endl;
    villagers.clear();
    cout << "Size after clear: " << villagers.size() << endl;

    return 0;

}


