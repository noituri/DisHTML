#include <iostream>

#include "third_party/tinyxml2/tinyxml2.h"
#include "client.h"

using namespace tinyxml2;

int main() {
    XMLDocument doc;
    doc.LoadFile("../testing.html");
    auto bot = doc.FirstChildElement("html")->FirstChildElement("bot");
    std::string token(bot->FindAttribute("token")->Value());
    Client client(token);
    client.run();
    return 0;
}
