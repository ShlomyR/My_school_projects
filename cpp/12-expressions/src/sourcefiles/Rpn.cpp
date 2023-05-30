#include "../hederfiles/Rpn.hpp"

#include <stack>

int Rpn::prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}



std::vector<std::string> Rpn::infixToPostfix()
{
    std::string result = {};
    std::vector<std::string> vec_result = {};
    size_t i;

    for (i = 0; i < m_vec.size(); i++) {
        vec_result.push_back(result);
        result = {};
        for (size_t j = 0; j < m_vec[i].size(); j++) {

            char c = m_vec[i][j];

            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == ' ') {
                if (c != ' ' && m_vec[i][j + 1] != ' ') {
                    result += c;
                } else if (c == ' ') {
                    continue;
                } else {
                    result += c;
                    result += " ";
                }
            } else if (c == '(') {
                m_stack.push('(');
            } else if (c == ')') {
                while (m_stack.top() != '('){
                    result += m_stack.pop();
                }
                m_stack.pop();
            } else {
                while (!m_stack.is_empty() && prec(m_vec[i][j]) <= prec(m_stack.top())) {
                    result += m_stack.pop();
                    result += " ";
                }
                m_stack.push(c);
            }
        }
        while (!m_stack.is_empty()) {
            result += " ";
            result += m_stack.pop();;
            
        }
    }
    vec_result.erase(vec_result.begin());
    vec_result.push_back(result);
    return vec_result;
}
