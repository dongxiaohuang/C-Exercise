#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

/**
   - key value pair
   - difference between map and multimap is that multimap allows duplicate keys
   - sort automatically according to keys(default is less<> or <)
   - key: element.first yeild the key of the actual element(use pos->first for iterator pos)
   - value: element.second yeild the value of the actual element(use pos->second for iterator pos)
   - bear in mind key is consider const
   - to change the key value, you should delete the old key and insert new one; this is inorder to keep order of keys
 **/

int main(){
        map<string, double> coll {
                {"tim", 9.9},
                {"struppi", 11.77}
        };

        //square the value of each element
        for_each(coll.begin(), coll.end(),
                 // [](pair<const string, double>& elem){
                 [](map<const string, double>::value_type& elem){
                elem.second *= elem.second;
        });

        //print each element
        for(auto i : coll) {
                cout << "key["<<i.first <<"]: " << i.second << endl;
        }
        cout << endl <<  "====================" << endl;

        // create map/associative array
        //-keys are strings
        //- values are floats

        typedef map<string, float> StringFloatMap;
        StringFloatMap stocks;// create empty container

        //insert some elements
        stocks["BASF"] = 369.50;
        stocks.insert({"VW", 413.50});
        stocks["Daimler"] = 819.00;
        stocks["BMW"] = 834.00;
        stocks["siemens"] = 842.0;

        //print all elements
        StringFloatMap::iterator pos;
        cout << left; //left-adjust values
        for(pos = stocks.begin(); pos != stocks.end(); ++pos) {
                cout << "stocks: " << setw(12) << pos->first
                     << "price: "<< pos->second<< endl;
        }
        cout << endl;

        //boom(all prices doubled)
        for(auto& i: stocks) { // dont forget reference
                i.second *= 2;
        }
        for(pos = stocks.begin(); pos != stocks.end(); ++pos) {
                cout << "stocks: " << setw(12) << pos->first
                     << "price: "<< pos->second<< endl;
        }

        //rename key from "VW" to "Volkswagen"
        //- provided inly by exchanging element
        stocks["Volkswagen"] = stocks["VW"];
        stocks.erase("VW");

        //print all elements
        for(pos = stocks.begin(); pos != stocks.end(); ++pos) {
                cout << "stocks: " << setw(12) << pos->first
                     << "price: "<< pos->second<< endl;
        }
        cout << endl <<  "==========Using a Multimap as a Dictionary==========" << endl;
        // create multimap as string/string dictionary
        multimap<string, string> dict;

        //insert some elements in random order
        dict.insert({
                {"day","Tag"}, {"strange","fremd"},
                {"car","Auto"}, {"smart","elegant"},
                {"trait","Merkmal"}, {"strange","seltsam"},
                {"smart","raffiniert"}, {"smart","klug"},
                {"clever","raffiniert"}
        }
                    );
        //print all elements
        cout << " " << setw(10) << "english"<< "german " << endl;
        cout << setfill('-') << setw(20) << "" << setfill(' ')<< endl;
        for(const auto& elem : dict){
            cout << ' ' << setw(10) << elem.first << elem.second << endl;
        }
        cout << endl;

        //print all values for key "smart"
        string word("smart");
        cout << word << ": " << endl;
        for(auto pos = dict.lower_bound(word);//Returns the ﬁrst position where an element with key val would get inserted (the ﬁrst element with a key >= val)
            pos != dict.upper_bound(word);// Returns the last position where an element with key val would get inserted (the ﬁrst element with a key > val)
            ++pos){
                cout << "   " << pos->second << endl;
            }

        //print all keys for value "raffiniert"
        word = "raffiniert";
        cout << word << ": " << endl;
        for(const auto&elem : dict){
            if(elem.second == word){
                cout << "   "<<elem.first << endl;
            }
        }
        return 0;
}
