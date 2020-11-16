#include <iostream>
#include <jsoncpp/json/json.h>
#include <errno.h>
#include <string.h>
#include <sstream>

#include "httplib.h"

using namespace httplib;
using namespace std;

int main(void) {
    string json = R"[=======]({"sourceLevel1": "PL0001","sourceLevel2": "BF0001","sourceLevel3": "BC0001","startTag": true})[=======]";
    cout << json << endl;
    Json::Reader reader;
    Json::Value root;
    if (!reader.parse(json, root))
    {
        cout << "reader parse error: " << strerror(errno) << endl;
        return -1;
    }
    string sourceLevel1, sourceLevel2, sourceLevel3;
    bool startTag;

    sourceLevel1 = root["sourceLevel1"].asString();
    sourceLevel2 = root["sourceLevel2"].asString();
    sourceLevel3 = root["sourceLevel3"].asString();
    startTag = root["startTag"].asBool();

    cout << "sourceLevel1: " << sourceLevel1 << endl;
    cout << "sourceLevel1: " << sourceLevel1 << endl;
    cout << "sourceLevel1: " << sourceLevel1 << endl;
    cout << "startTag: " << startTag << endl;
}

// bool stop = false;
// int main(void) {
//     httplib::Server svr;
//     svr.Post("/hi", [](const Request &req, Response &res) {
//         string json = R"[=======]({
//         "sourceLevel1": "PL0001",
//         "sourceLevel2": "BF0001",
//         "sourceLevel3": "BC0001",
//         "startTag": true})[=======]";
//         Json::Reader reader;
//         Json::Value root;
//         if (!reader.parse(json, root))
//         {
//             cout << "reader parse error: " << strerror(errno) << endl;
//             return -1;
//         }
//         string sourceLevel1, sourceLevel2, sourceLevel3;
//         bool startTag;

//         sourceLevel1 = root["sourceLevel1"].asString();
//         sourceLevel2 = root["sourceLevel2"].asString();
//         sourceLevel3 = root["sourceLevel3"].asString();
//         startTag = root["startTag"].asBool();

//         cout << "sourceLevel1: " << sourceLevel1 << endl;
//         cout << "sourceLevel1: " << sourceLevel1 << endl;
//         cout << "sourceLevel1: " << sourceLevel1 << endl;
//         cout << "startTag: " << startTag << endl;
//         res.set_content(json, "text/plain");
//     });

//     std::cout << "start server..." << std::endl;
//     svr.listen("0.0.0.0", 8080);
// }
