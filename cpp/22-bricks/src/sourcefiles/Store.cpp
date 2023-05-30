#include <iostream>

// #include "Store.hpp"
// #include "SymbolVar.hpp"

#include "../hederfiles/Store.hpp"
#include "../hederfiles/SymbolVar.hpp"

std::vector<std::unordered_map<std::string,std::string>> Store::m_str_map_data_base;
std::vector<std::unordered_map<std::string,double>> Store::m_double_map_data_base;

int Store::dataBaseMaps()
{ 
    m_str_map_data_base.push_back(SymbolVar::getInstance()->map_strDB);
    m_double_map_data_base.push_back(SymbolVar::getInstance()->map_doubleDB);
    
    // printMap(m_str_map_data_base);
    // printMap(m_double_map_data_base);

    return 0;
}

std::vector<std::unordered_map<std::string,std::string>>& Store::getStrMapDB()
{
    return m_str_map_data_base;
}

std::vector<std::unordered_map<std::string,double>>& Store::getDoubleMapDB()
{
    return m_double_map_data_base;
}

template <typename K, typename V>
void Store::printMap(std::vector<std::unordered_map<K, V>> const &m)
{
    for (size_t i = 0; i < m.size(); i++)
    {
        for (auto  &pair : m[i]) {
            std::cout << "{" << pair.first << ": " << pair.second << "}\n";
        }
    }
    

}