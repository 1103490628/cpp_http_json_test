#include <iostream>
#include <jsoncpp/json/json.h>
#include <errno.h>
#include <string.h>
#include <sstream>

#include "httplib.h"

using namespace httplib;
using namespace std;

bool stop = false;
int main(void) {
    httplib::Server svr;
    svr.Post("/hi", [](const Request &req, Response &res) {
        string json = req.body;
        Json::Reader reader;
        Json::Value root;
        if (!reader.parse(json, root))
        {
            cout << "reader parse error: " << strerror(errno) << endl;
            return -1;
        }
        string name;
        int age;
        int size;

        size = root.size();
        cout << "total " << size << " elements" << endl;
        for (int i = 0; i < size; ++i){
            name = root[i]["name"].asString();
            age = root[i]["age"].asInt();

            cout << "name: " << name << ", age: " << age << endl;
        }
        res.set_content(json, "text/plain");
    });

    std::cout << "start server..." << std::endl;
    svr.listen("0.0.0.0", 8080);
}
