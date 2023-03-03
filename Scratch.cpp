#include <iostream>

#include "LinkedList.h"

using namespace std;

int main(int argc, char* argv[]) {
    cout << "Part 1" << endl;
    LinkedList<int> link;
    link.push_front(1);
    link.push_front(2);
    link.push_front(3);
    link.push_back(0);
    cout << "size: " << link.size() << endl;
    cout << link.toString() << endl;

    cout << "\nPart 2" << endl;
    cout << "List size: " << link.size() << endl;

    cout << "\nPart 3" << endl;
    link.insert(99, 2);
    link.insert(99, 0);
    link.insert(99, link.size());
    cout << "size: " << link.size() << endl;
    cout << link.toString() << endl;
    cout << "List size: " << link.size() << endl;

    cout << "\nPart 4" << endl;
    cout << "Size: " << link.size() << endl;
    for (int i = 0; i < link.size(); i++) {
        cout << "Link at " << i << ": " << link.at(i) << endl;
    }
    cout << "First element: " << link.front() << endl;
    cout << "Last element: " << link.back() << endl;

    cout << "\nPart 4" << endl;
    cout << "Link size: " << link.size() << endl;
    cout << link.toString() << endl;
    cout << "Contains 99: " << boolalpha << link.contains(99) << endl;
    cout << "Contains 8: " << boolalpha << link.contains(8) << endl;
    link.push_back(20);
    cout << "size: " << link.size() << endl;
    cout << link.toString() << endl;
    cout << "Contains 20: " << boolalpha << link.contains(20) << endl;

    cout << "\nPart 5" << endl;
    cout << "size: " << link.size() << endl;
    cout << link.toString() << endl;
    link.remove(4);
    cout << link.toString() << endl;
    cout << "size: " << link.size() << endl;
    link.remove(5);
    cout << link.toString() << endl;

    cout << "\nPush_back: " << endl;
    LinkedList<int> list;
    list.push_back(1);
    cout << list.toString() << endl;
    list.push_back(2);
    cout << list.toString() <<  " Size: " << list.size() << endl;
    list.push_back(3);
    cout << list.toString() <<  " Size: " << list.size() << endl;
    list.push_back(4);
    cout << list.toString() <<  " Size: " << list.size() << endl;
    list.push_back(5);
    cout << list.toString() <<  " Size: " << list.size() << endl;
    list.push_back(6);
    cout << list.toString() <<  " Size: " << list.size() << endl;
    list.push_back(7);
    cout << list.toString() <<  " Size: " << list.size() << endl;
    list.push_back(8);
    cout << list.toString() <<  " Size: " << list.size() << endl;
    list.insert(0, 4);
    cout << list.toString() <<  " Size: " << list.size() << endl;
    list.push_front(0);
    cout << list.toString() <<  " Size: " << list.size() << endl;
    list.push_back(20);
    cout << list.toString() <<  " Size: " << list.size() << endl;

    cout << "\nPart 6" << endl;
    list.remove(4);
    cout << list.toString() <<  " Size: " << list.size() << endl;
    list.remove(list.size() - 1);
    cout << list.toString() <<  " Size: " << list.size() << endl;
    list.pop_front();
    cout << list.toString() <<  " Size: " << list.size() << endl;
    list.pop_back();
    cout << list.toString() <<  " Size: " << list.size() << endl;
    list.pop_back();
    cout << list.toString() <<  " Size: " << list.size() << endl;

    list.clear();
    cout << list.toString() <<  " Size: " << list.size() << endl;
}
