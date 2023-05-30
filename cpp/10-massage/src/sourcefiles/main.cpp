#include <string>
#include <iostream>
#include <sstream>
#include <cctype>

#include "transform.hpp"
#include "Lower.hpp"
#include "Upper.hpp"


// void toCase(std::string str,std::string transform,std::ostream &os)
// { 
//     if (transform == "Lower case") {
//         for (size_t i = 0; i < str.length(); i++) {
//             str[i] = std::tolower(str[i]);
//         }
        
//     } else if (transform == "Upper case") {
//         for (size_t i = 0; i < str.length(); i++) {
//             str[i] = std::toupper(str[i]);
//         }
//     }
    

//     os << str << "\n";
// }

void toCase(std::string str,transform &transform,std::ostream &os)
{ 
    os << "From: " << str << " to - " << transform.translate(str) << "\n";
}

void test_lower_and_upper()
{
    std::string strU = "PIZZA";
    std::string strL = "pizza";
    std::ostream& os = std::cout;
    
    //transform* tU = new Upper();
    //transform* tL = new Lower();

    Upper u;
    Lower l;
    
    toCase(strU,l,os);
    toCase(strL,u,os);

    //delete tU;
    //delete tL;
}
int main()
{
    test_lower_and_upper();

    return 0;
}