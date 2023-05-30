#include <iostream>
#include <memory>

#include "../hederfiles/SymbolTable.hpp"

SymbolTable::SymbolTable(){}

std::unordered_map<std::string,double> SymbolTable::creatDataBaseMap()
{    
    SymbolTable::getInstance()->data_base["x"] = 5;
    SymbolTable::getInstance()->data_base["y"] = 10;
    SymbolTable::getInstance()->data_base["z"] = 1.5;

    return SymbolTable::getInstance()->data_base;    
}

template<typename K, typename V>
void SymbolTable::printMap(std::unordered_map<K, V> const &m)
{
    for (auto const &pair: m) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}