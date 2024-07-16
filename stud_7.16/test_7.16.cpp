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

// ����ģ�� -- ����ƥ��
template<class T>
bool Less(T left, T right)
{
    return left < right;
}

 //���ĳЩ���ͽ������⴦�� -- Date*
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
        // ʹ��unordered_set���洢nums1�е�����Ԫ�أ��Ӷ�������ٲ���
        std::unordered_set<int> set1(nums1.begin(), nums1.end());
        // ʹ��unordered_set���洢nums2�е�����Ԫ��
        std::unordered_set<int> set2(nums2.begin(), nums2.end());

        // ��ʼ�����������������ڼ�¼��������������ͬԪ�صĸ���
        int answer1 = 0, answer2 = 0;

        // ����nums1�е�ÿ��Ԫ��
        for (int i = 0; i < nums1.size(); ++i) {
            // �����ǰԪ����set2��Ҳ���ҵ���˵�������������鶼�е�Ԫ��
            if (set2.count(nums1[i]) > 0) {
                // ����answer1������
                ++answer1;
            }
        }

        // ����nums2�е�ÿ��Ԫ��
        for (int i = 0; i < nums2.size(); ++i) {
            // �����ǰԪ����set1��Ҳ���ҵ���˵�������������鶼�е�Ԫ��
            if (set1.count(nums2[i]) > 0) {
                // ����answer2������
                ++answer2;
            }
        }

        // ���ذ��������������Ľ������
        return { answer1, answer2 };
    }
};

void test_T()
{
	// �Ƚ��ַ���
	char str1[] = "hello";
	char str2[] = "hello";
	cout << IsEqual(str1, str2) << endl;

}

class Person//����
{
public:
    Person(const char* name)//c��ʽ���ַ���
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
        if (this != &p)//���һ���Ƿ������Ҹ�ֵ
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
    string _name;//����

};
class Student :public Person
{
public:
    Student(const char* name, int num)
        : Person(name) // ���û���Ĺ��캯����ʼ������
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
	Student s1("����", 18);
	Student s2(s1);

	Student s3("����", 20);

	s1 = s3;
}
int main()
{
	 test_T();
	 test_person();

	return 0;
}
