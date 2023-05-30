// #include "yahid_bemino.hpp"


// void print_vec(std::vector<int> vec)
// {
//     for (size_t i = 0; i < vec.size(); i++)
//     {
//         std::cout << vec[i] << "\n";
//     }
    
// }

// template<typename T>
// size_t calc_unique(T const* a,int n)
// {

//     assert(a && n);
    
//     for (size_t i = 0; i < n; i++) {
//         for (size_t j = 0; j < i; j++) {
//             if (a[i] == a[j]) {
//                 break;
//             }
//             if (i == j) {
//                 return a[i];
//             }
//         }
        
//     }
//     return 0;
    
// }


// template<typename T>
// T yahid_bemino(T const * a,int n)
// {
//     T arr = calc_unique(a,n);

//     return arr; 
// }

// int main()
// {
//     int arr[7] = {1,2,2,4,1,5,4};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     std::cout<<  yahid_bemino<int>(arr,n) << "\n";

//     double b[] = {1.5,2.3,2.3,4.1,1.5,5.4,4.1};
//     int n1 = sizeof(b)/sizeof(*b);
//     yahid_bemino(b,n1);

//     return 0;
// }


// Time complexity O(N^2) space complexity O(N)
// int first_unique_number(std::vector<int> &v)
// {
//     for (size_t i = 0; i < v.size(); i++) {
//         for (size_t j = v.size() - 1; j >= 0; j--) {
//             if (j == 0 && v[j] != v[i]) {
//                 return v[i];
//             } else if (j == i){
//                continue;
//             } else if (v[j] == v[i]){
//                 break;
//             } else if (v[j] != v[i]){
//                 continue;
//             }
//         }
//     }
//     return 0;
    
// }

// template<typename Iter,typename Test>
// Iter find(Iter start,Iter end,Test condition)
// {
//     while (start != end) {
//         if(condition(start,end)) {
//             break;
//         }
//         ++start;
//     }
//     return start;
// }


// // Time complexity O(N^2) space complexity O(N)
// template<typename T,typename Iter>
// bool first_unique_number(Iter start,Iter end)
// {
//     bool unique = false;
//     std::unordered_map<T,T> uniques_map = {};
//     std::set<T> not_uniques = {};

//     while (start != end) {
//         if (typename std::unordered_map<T, T>::iterator search = uniques_map.find(*start); search != uniques_map.end()) {
//             uniques_map.erase(*start);
//             not_uniques.insert({*start});
//             ++start;
//         } else {
//             uniques_map.insert({*start,*start});
//             ++start;
//         }
//     }

//     uniques_map.reserve(uniques_map.size());
//     typename std::unordered_map<T, T>::iterator start_map = uniques_map.begin();
//     typename std::unordered_map<T, T>::iterator end_map = uniques_map.end();
//     while (start_map != end_map) {
//         for (auto& set : not_uniques) {
//             if ( set !=  start_map->first) {
//                 if (set == not_uniques.size() - 1) {
//                     std::cout << start_map->first << "\n";
//                     unique = true;
//                     return unique;
//                 }
//             }
//         }  
//         ++start_map;
//     }
  
//     return false;
    
// }

// template<typename Container>
// void first_unique_number(Container & v)
// {
//     first_unique_number(v);
// }

//Time complexity O(N) space complexity O(N log N)
// template<typename T>
// int first_unique_number(std::vector<T> &v)
// {
//     std::unordered_map<T,T> uniques_map = {};
//     std::vector<T> not_uniques = {};
//     typename std::vector<T>::iterator start = v.begin();
//     typename std::vector<T>::iterator end = v.end();

//     while (start != end) {
//         if (typename std::unordered_map<T, T>::iterator search = uniques_map.find(*start); search != uniques_map.end()) {
//             uniques_map.erase(*start);
//             not_uniques.push_back(*start);
//             ++start;
//         } else {
//             uniques_map.insert({*start,*start});
//             ++start;
//         }
//     }
//     uniques_map.reserve(uniques_map.size());
//     typename std::unordered_map<T, T>::iterator start_map = uniques_map.begin();
//     typename std::unordered_map<T, T>::iterator end_map = uniques_map.end();
//     while (start_map != end_map) {
//         for (size_t i = 0; i < not_uniques.size(); i++) {
//             if ( not_uniques[i] !=  start_map->first) {
//                 if (i == not_uniques.size() - 1) {
//                     std::cout << start_map->first << "\n";
//                     return start_map->first;
//                 }
//             }
//         }  
//         ++start_map;
//     }
//     return start_map->first;
// }

// template<typename T>
// int first_multiple_unique_number(std::vector<T> &v)
// {
//     std::unordered_map<T,T> uniques_map = {};
//     std::vector<T> not_uniques = {};
//     typename std::vector<T>::iterator start = v.begin();
//     typename std::vector<T>::iterator end = v.end();

//     while (start != end) {
//         if (typename std::unordered_map<T, T>::iterator search = uniques_map.find(*start); search != uniques_map.end()) {
//             uniques_map.erase(*start);
//             not_uniques.push_back(*start);
//             ++start;
//         } else {
//             uniques_map.insert({*start,*start});
//             ++start;
//         }
//     }
//     std::cout << not_uniques[3] << "\n";
//     return not_uniques[3];
// }



// int main()
// {
   
//     std::vector<int> vecI = {1,2,3,3,4,4,1,2,8,2,7};
//     // std::list<double> listD = {1.5,2.4,3.1,3.7,4.6,4.2,1.3,2.7,8.1,2.9,7.8};

//     std::vector<int>::iterator it = find(vecI.begin(),vecI.end(),first_unique_number<int, std::vector<int>::iterator>);
//     if (it != vecI.end()) {
//         std::cout << *it << "\n";
//     }
    
//     //first_unique_number(setI);
    
    
//     //testing_all_functions();
    
//     return 0;
// }

#include <vector>
#include <map>
#include <iostream>
#include <unordered_map>
#include <list>
#include <set>
#include <unordered_set>

#define TYPE int

// template <typename Iter, typename Test>
// Iter find(Iter start, Iter end, Test condition)
// {
//     *start = condition(start, end);

//     return start;
// }

template <typename T, typename Iter>
Iter first_unique_number(Iter start, Iter end)
{
    std::unordered_map<T, T> uniques_map;
    std::set<T> not_uniques;
    Iter copy_start = start;
    typename std::unordered_map<T, T>::iterator search;

    while (start != end) {
        if (search = uniques_map.find(*start); search != uniques_map.end()) {
            uniques_map.erase(*start);
            not_uniques.insert(*start);
            ++start;
        } else {
            uniques_map.insert({ *start, *start });
            ++start;
        }
    }

    uniques_map.reserve(uniques_map.size());
    typename std::unordered_map<T, T>::iterator start_map = uniques_map.begin();
    typename std::unordered_map<T, T>::iterator end_map = uniques_map.end();
    while (start_map != end_map) {
        for (auto& set : not_uniques) {
            if (set != start_map->first) {
                if (set == *not_uniques.rbegin()) {
                    *copy_start = start_map->first;
                    return copy_start;
                }
            } else {
                uniques_map.erase(set);
                if (uniques_map.empty()) {
                    return end;
                }
            }
        }
        ++start_map;
    }
    return end;
}

template<typename Container>
void first_unique_number(Container &v)
{
    using ValueType = typename Container::value_type;
    using Iter = typename Container::iterator;

    auto result = first_unique_number<ValueType, Iter>(v.begin(),v.end());
    if (result != v.end()) {
        std::cout << "The first unique number is: " << *result << "\n";
    } else {
        std::cout << "No unique number found\n";
    }
}

template <typename T, typename Iter>
Iter first_duplicate_number(Iter start, Iter end)
{
    std::unordered_map<T, T> uniques_map;
    std::unordered_set<T> not_uniques;
    Iter copy_start = start;
    typename std::unordered_map<T, T>::iterator search;

    while (start != end) {
        if (search = uniques_map.find(*start); search != uniques_map.end()) {
            uniques_map.erase(*start);
            not_uniques.insert(*start);
            ++start;
        } else {
            uniques_map.insert({ *start, *start });
            ++start;
        }
    }

    if (not_uniques.empty()) {
        return end;
    } else {
        auto start_set = *not_uniques.begin();
        *copy_start = start_set;
        return copy_start;
    }
    
    return end;
}



template<typename Container>
void first_duplicate_number(Container &v)
{
    using ValueType = typename Container::value_type;
    using Iter = typename Container::iterator;

    auto result = first_duplicate_number<ValueType, Iter>(v.begin(), v.end());
    if (result != v.end()) {
        std::cout << "The first unique number is: " << *result << "\n";
    } else {
        std::cout << "No unique number found\n";
    }
}


void test_for_first_unique()
{
    std::array<TYPE,11> array_numbers = {1,2,3,3,4,4,1,2,8,2,7};
    first_unique_number(array_numbers);
    std::vector<TYPE> vec_numbers = {0, 2, 3, 4, 5, 0, 2, 3};
    first_unique_number(vec_numbers);
}

void first_duplicate_number()
{
    std::array<TYPE,11> array_numbers = {1,2,3,3,4,4,8,2,2,7};
    first_duplicate_number(array_numbers);
    std::vector<TYPE> vec_numbers = {2,1,3,4,3,2};
    first_duplicate_number(vec_numbers);
}

int main()
{

    first_duplicate_number();

    return 0;
}