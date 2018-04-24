#ifndef MAP_H
#define MAP_H
#include "SortedList.h"
template <typename Tkey, typename Tval,
    int (*keyComp)(const Tkey& a, const Tkey& b) = defaultComp>
class Map {
private:
    /* data */
    struct KVP{
        Tkey _key;
        Tval _value;
        //TODO:
        KVP(Tkey key):_key(key){}
        KVP(Tkey key, Tval value): _key(key), _value(value){}
        // static int comp(const KVP& a, const KVP& b){return keyComp(a._key, b._key);}
        static int comp(KVP* const& a, KVP* const& b){return keyComp(a -> _key, b -> _key);}//??
    };
    SortedList<KVP*, KVP::comp> base;

    int locate(Tkey key) const{
        KVP dummy(key);//??
        return base.indexOf(&dummy);
    }
public:
    Map ();

    void insert(Tkey key, Tval value){
        int idx = locate(key);
        if(idx == -1) base.add(new KVP(key, value));
        else base.get(idx)->val = value;
    }
    Tval* get(const Tkey& key){
        auto pos = locate(key);
        if(pos == -1) return nullptr;
        return &base.get(pos)._value;
    }
    bool remove(Tkey key){
        auto pos = locate(key);
        if(pos == -1) return false;
        delete base.get(pos);
        return base.removeAt(pos);
    }
    virtual ~Map (){
        for(int i = 0; i < base.count(); i++){
            delete base.get(i);
        }
    }
};
#endif
