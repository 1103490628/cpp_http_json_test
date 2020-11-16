#include <iostream>
#include <jsoncpp/json/json.h>
#include <errno.h>
#include <string.h>

using namespace std;

int main(void)
{

    Json::Reader reader;
    Json::Value root;
    string s = "[{"name":"姓名", "age":27}]";

    if (!reader.parse(s, false))
    {
        cout << "reader parse error: " << strerror(errno) << endl;
        return -1;
    }

    string name;
    int age;
    int size;

    size = root.size();
    cout << "total " << size << " elements" << endl;
    for (int i = 0; i < size; ++i)
    {
        name = root[i]["name"].asString();
        age = root[i]["age"].asInt();

        cout << "name: " << name << ", age: " << age << endl;
    }

    return 0;
}
