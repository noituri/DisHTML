#include <iostream>

#include "third_party/tinyxml2/tinyxml2.h"
#include "client.h"

using namespace tinyxml2;

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Provide path to html file." << std::endl;
        return 1;
    }

    std::cout << "Loading html file: " << argv[1] << std::endl;

    XMLDocument doc;
    doc.LoadFile(argv[1]);

    auto bot = doc.FirstChildElement("html")->FirstChildElement("bot");
    std::string token(bot->FindAttribute("token")->Value());

    Client client(token);
    client.prefix = bot->FindAttribute("prefix")->Value();

    auto cmd = bot->FirstChildElement("command");

    while (true) {
        std::string name(cmd->FindAttribute("name")->Value());
        std::string reply(cmd->GetText());
        reply.erase(0, reply.find_first_not_of("\t\n\v\f\r "));
        reply.erase(reply.find_last_not_of("\t\n\v\f\r ") + 1);

        std::cout << "Found command: " << name << std::endl;

        Command tmp(name, reply);
        client.commands.push_back(tmp);
        if (!(cmd = cmd->NextSiblingElement()))
            break;
    }

    client.run();
    return 0;
}
