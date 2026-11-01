#include<iostream>
#include<set>
#include<map>
#include<string>
#include<vector>

class Employee
{
    int m_ID;
    std::string m_name;
public:
    explicit Employee(int ival, const std::string strName) noexcept : m_ID(ival), m_name(strName) 
    {
        
    }
    ~Employee() = default;
    void Display() const
    {
        std::cout<<"ID = "<<m_ID<<'\n';
        std::cout<<"Name = "<<m_name<<'\n';
    }
};

template<typename T>
using myset = std::set<T>;

template<typename T1, typename T2>
using mymap = std::map<T1,T2>;

template<typename T>
using myvect = std::vector<T>;

int main()
{
    myset<int> set1;
    set1.insert(10);
    set1.insert(20);
    set1.insert(30);
    set1.insert(40);
    set1.insert(50);
    for(const int& elem : set1)
    {
        std::cout<<"elem = "<<elem<<'\n';
    }
    myset<int>::iterator it1 = set1.lower_bound(25);
    std::cout<<"set.lower_bound(25) = "<< *it1<<'\n';
    myset<int>::iterator it2 = set1.lower_bound(30);
    std::cout<<"set.lower_bound(30) = "<< *it2<<'\n';
    myset<int>::iterator it3 = set1.lower_bound(35);
    std::cout<<"set.lower_bound(35) = "<< *it3<<'\n';
    myset<int>::iterator it4 = set1.lower_bound(40);
    std::cout<<"set.lower_bound(40) = "<< *it4<<'\n';
    myset<int>::iterator it5 = set1.lower_bound(50);
    std::cout<<"set.lower_bound(50) = "<< *it5<<'\n';
    myset<int>::iterator it6 = set1.lower_bound(100);
    std::cout<<"set.lower_bound(100) = "<< *it6<<'\n';

    myset<int>::iterator it7 = set1.upper_bound(25);
    std::cout<<"set.upper_bound(25) = "<< *it7<<'\n';
    myset<int>::iterator it8 = set1.upper_bound(30);
    std::cout<<"set.upper_bound(30) = "<< *it8<<'\n';
    myset<int>::iterator it9 = set1.upper_bound(35);
    std::cout<<"set.upper_bound(35) = "<< *it9<<'\n';
    myset<int>::iterator it10 = set1.upper_bound(40);
    std::cout<<"set.upper_bound(40) = "<< *it10<<'\n';
    myset<int>::iterator it11 = set1.upper_bound(50);
    std::cout<<"set.upper_bound(50) = "<< *it11<<'\n';
    myset<int>::iterator it12 = set1.upper_bound(100);
    std::cout<<"set.upper_bound(100) = "<< *it12<<'\n';

    auto it13 = set1.equal_range(30);
    std::cout<<"*(it13.first) = "<< *(it13.first)<<'\n';
    std::cout<<"*(it13.second) = "<< *(it13.second)<<'\n';
    std::pair<myset<int>::iterator, myset<int>::iterator> it14 = set1.equal_range(40);
    std::cout<<"(it.first) = "<<*(it14.first)<<'\n';
    std::cout<<"*(it.second) = "<<*(it14.second)<<'\n';

    mymap<int,std::string> map1;
    map1.insert(std::make_pair(1,"aa1"));
    map1.insert(std::make_pair(2,"aa2"));
    map1.insert(std::make_pair(3,"aa3"));
    map1.emplace(std::make_pair(4,"aa4"));
    map1.emplace(std::make_pair(5,"aa5"));
    for(const std::pair<int,std::string> elem : map1)
    {
        std::cout<<elem.first<<'\n';
        std::cout<<elem.second<<'\n';
    }
    for(const auto& [key,value] : map1)
    {
        std::cout<<key<<'\n';
        std::cout<<value<<'\n';
    }

    myvect<Employee> vect1;
    vect1.emplace_back(1,"aa1");
    vect1.emplace_back(2,"aa2");    
    vect1.emplace_back(3,"aa3");
    vect1.emplace_back(4,"aa4");
    for(const Employee& elem : vect1)
    {
        elem.Display();
    }
    return 0;
}