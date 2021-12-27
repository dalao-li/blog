#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Item {
   private:
    string id;
    int price;
    int count;

   public:
    Item(string id,int price,int count)
        : id(id),count(count),price(price) {}
    int getCount() const { 
        return count; 
    }
    string getId() const { 
        return id; 
    }
    int getPrice() const { 
        return price;
    }

    bool operator == (const Item &obj2) const {
        return this->getId().compare(obj2.getId()) == 0;
    }
};

bool complePrice(Item& obj,int y) {
    return obj.getPrice() == y;
}

vector<Item> getList() {
    vector<Item> v;
    v.push_back(Item("D121",100,2));
    v.push_back(Item("D122",12,5));
    v.push_back(Item("D123",28,6));
    v.push_back(Item("D124",8,10));
    v.push_back(Item("D125",99,3));
    return v;
}

int main() {
    vector<Item> v = getList();

    vector<Item>::iterator it;
    int num;
    cin >> num;
    it = find_if(v.begin(),v.end(),bind(complePrice,placeholders::_1,num));
    if (it != v.end()){
        cout << "Item Price :" << it->getPrice()<< " Count : " << it->getCount() << endl;
    }
    else{
        cout << "Item not Found" << endl;
    }
    return 0;
}
