#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>
#include< unordered_set >

using namespace std;



template <class T>
bool IsEqual(T& left,T& right)
{
	return left == right;
}
template<>
bool IsEqual<char*>(char*& left, char*& right)
{
	return strcmp(left ,right) == 0;
}
class Date
{
public:
    Date(int year = 1900, int month = 1, int day = 1)
        : _year(year)
        , _month(month)
        , _day(day)
    {}

    bool operator<(const Date& d)const
    {
        return (_year < d._year) ||
            (_year == d._year && _month < d._month) ||
            (_year == d._year && _month == d._month && _day < d._day);
    }

    bool operator>(const Date& d)const
    {
        return (_year > d._year) ||
            (_year == d._year && _month > d._month) ||
            (_year == d._year && _month == d._month && _day > d._day);
    }

    friend ostream& operator<<(ostream& _cout, const Date& d)
    {
        _cout << d._year << "-" << d._month << "-" << d._day;
        return _cout;
    }

private:
    int _year;
    int _month;
    int _day;
};

// 函数模板 -- 参数匹配
template<class T>
bool Less(T left, T right)
{
    return left < right;
}

 //针对某些类型进行特殊处理 -- Date*
template<>
bool Less<Date*>(Date* left, Date* right)
{
	return *left < *right;
}

bool Less(Date* left, Date* right)
{
    return *left < *right;
}

class Solution0 {
public:

    std::vector<int> findIntersectionValues(std::vector<int>& nums1, std::vector<int>& nums2) {
        // 使用unordered_set来存储nums1中的所有元素，从而方便快速查找
        std::unordered_set<int> set1(nums1.begin(), nums1.end());
        // 使用unordered_set来存储nums2中的所有元素
        std::unordered_set<int> set2(nums2.begin(), nums2.end());

        // 初始化两个计数器，用于记录在两个数组中相同元素的个数
        int answer1 = 0, answer2 = 0;

        // 遍历nums1中的每个元素
        for (int i = 0; i < nums1.size(); ++i) {
            // 如果当前元素在set2中也能找到，说明它是两个数组都有的元素
            if (set2.count(nums1[i]) > 0) {
                // 增加answer1计数器
                ++answer1;
            }
        }

        // 遍历nums2中的每个元素
        for (int i = 0; i < nums2.size(); ++i) {
            // 如果当前元素在set1中也能找到，说明它是两个数组都有的元素
            if (set1.count(nums2[i]) > 0) {
                // 增加answer2计数器
                ++answer2;
            }
        }

        // 返回包含两个计数器的结果向量
        return { answer1, answer2 };
    }
};

void test_T()
{
	// 比较字符串
	char str1[] = "hello";
	char str2[] = "hello";
	cout << IsEqual(str1, str2) << endl;

}

class Person//父类
{
public:
    Person(const char* name)//c形式的字符串
        :_name(name)
    {
        cout << "Person()" << endl;
    }
    Person(const Person& p)
        :_name(p._name)
    {
        cout << " Person(const Person& p)" << endl;
    }
    Person& operator=(const Person& p)

    {
        cout<< "Person& operator=(const Person& p) " << endl;
        if (this != &p)//检查一下是否是自我赋值
        {
            _name = p._name;
        }
        return *this;
    }
    ~Person()
    {
        cout << "~Person()" << endl;
    }

protected:
    string _name;//名字

};
class Student :public Person
{
public:
    Student(const char* name, int num)
        : Person(name) // 调用基类的构造函数初始化姓名
        , _num(num) 
    {

    }
    Student& operator=(const Student& s)
    {
        if (this != &s)
        {
            Person::operator=(s);
            _num - s._num;

        }
        return *this;
    }


protected:
    int _num;
};


void test_person()
{
	Student s1("张三", 18);
	Student s2(s1);

	Student s3("李四", 20);

	s1 = s3;
}
int main()
{
	 test_T();
	 test_person();

	return 0;
}
