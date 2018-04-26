#include "HR.h"
HR::HR(string name, int year, int size):
     _size(size),_year_of_birth(year), _name(name){}
bool HR::receive(AF *af){
     if(tray.size() >= _size)
          return false;
     tray.push(af);
     return true;
}
int HR::count() const {
     return tray.size();
}
void HR::remove(){
     // for(auto i  = 0; i < tray.size(); i++){
     //      auto k = (tray.top() - i) -> calculateScore();
     //
     //      if(k <= 66){
     //           // tray.remove(tray.top() - i);
     //      }
     // }
     stack<AF*> tmp;
     // while(tray.top() != nullptr){
     int n = tray.size();
     for(auto i = 0; i < n; i++){
          float score = tray.top() -> calculateScore();
          if(score > 66){
               tmp.push(tray.top());
          }
          tray.pop();
     }
     // while(tmp.top() != nullptr){ // not available
     n = tmp.size();// must use n because tmp.size() is changeable
     for(auto i = 0; i < n; i++){
          tray.push(tmp.top());
          tmp.pop();
     }
     cout << tray.size() << endl;
}
