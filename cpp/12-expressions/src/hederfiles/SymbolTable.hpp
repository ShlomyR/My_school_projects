#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

class SymbolTable
{
public:
    static std::unique_ptr<SymbolTable>& getInstance()
    {
        static std::unique_ptr<SymbolTable> instance(new SymbolTable);
        return instance;
    }
public:
    std::unordered_map<std::string, double> creatDataBaseMap();
    std::unordered_map<std::string, double> data_base;
private:
    SymbolTable();
    //static std::unique_ptr<SymbolTable> instance;
private:
    template <typename K, typename V>
    void printMap(std::unordered_map<K, V> const &m);
};