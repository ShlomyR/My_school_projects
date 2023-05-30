#include <thread>
#include <vector>
#include <iostream>
#include <atomic>
#include <numeric>
#include <algorithm>


#define TIME 100000

double sum(std::vector<double> const& v,int n)
{
    using It = std::vector<double>::const_iterator;
    std::atomic<double> total_amount = 0.0;

    auto sum_it = [&total_amount](It it,It end){
        double result = 0.0;
        while (it != end) {
            result += *it;
            ++it;
        }
        total_amount = total_amount + result;
        // total_amount.fetch_add(result);
        
    };

    std::vector<std::thread> threads;
    auto segment = v.size() / n;
    auto from = v.begin();
    auto to = from + segment;

    for (int i = 0; i < n-1; i++) {
        threads.push_back(std::thread(sum_it,from,to));
        from = to;
        to = from + segment;
    }

    threads.push_back(std::thread(sum_it,from,v.end()));

    for (auto &t: threads) {
        t.join();
    }

    return total_amount;
    
}

int main()
{
    std::vector<double> vec(10'000);

    std::iota(vec.begin(),vec.end(),1.0);

    auto s = std::accumulate(vec.begin(),vec.end(),0.0);
    auto r = sum(vec,8);

    std::cout << s << "\n";
    std::cout << r << "\n";

    return 0;
}