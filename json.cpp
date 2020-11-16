#include <iostream>
#include <jsoncpp/json/json.h>
#include <errno.h>
#include <string.h>
#include <sstream>

#include "httplib.h"

using namespace httplib;
using namespace std;

void switchHandle(const Request &req, Response &res) {
    string reqJsonString = req.body;
    Json::Reader reader;
    Json::Value reqJsonValue;

    if (!reader.parse(reqJsonString, reqJsonValue))
    {
        cout << "reader parse error: " << strerror(errno) << endl;
        return -1;
    }
    string sourceLevel1, sourceLevel2, sourceLevel3;
    bool startTag;

    sourceLevel1 = reqJsonValue["sourceLevel1"].asString();
    sourceLevel2 = reqJsonValue["sourceLevel2"].asString();
    sourceLevel3 = reqJsonValue["sourceLevel3"].asString();
    startTag = reqJsonValue["startTag"].asBool();
    stop = startTag;
    
///////////////////////////
    cout << "sourceLevel1: " << sourceLevel1 << endl;
    cout << "sourceLevel1: " << sourceLevel1 << endl;
    cout << "sourceLevel1: " << sourceLevel1 << endl;
    cout << "startTag: " << startTag << endl;
///////////////////////////


    Json::FastWriter writer;
    Json::Value resJsonValue;
    resJsonValue["success"] = true;
    resJsonValue["requestId"] = "r010201";
    resJsonValue["resultCode"] = "C0001";
    resJsonValue["resultMsg"] = "操作成功";
    resJsonValue["solution"] = "";
    resJsonValue["data"] = "";
    string resJsonSring = writer.write(resJsonValue);
    cout << resJsonSring << endl;
    res.set_content(resJsonSring, "text/plain");
}

bool stop = false;
int main(void) {
    httplib::Server svr;
    svr.Post("/interface/beltConveyorStartSignal/DT0008", switchHandle);

    std::cout << "start server..." << std::endl;
    svr.listen("0.0.0.0", 8080);
}
