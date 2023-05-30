#include <vector>
#include <string>
#include <unordered_map>

class Store
{
public:
    static int dataBaseMaps();
    static  std::vector<std::unordered_map<std::string,std::string>>& getStrMapDB();
    static  std::vector<std::unordered_map<std::string,double>>& getDoubleMapDB();
private:
    static std::vector<std::unordered_map<std::string,std::string>> m_str_map_data_base;
    static std::vector<std::unordered_map<std::string,double>> m_double_map_data_base;
    template<typename K, typename V>
    static void printMap(std::vector<std::unordered_map<K, V>> const& m);
};