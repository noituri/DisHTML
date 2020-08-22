#ifndef DISHTML_CLIENT_H
#define DISHTML_CLIENT_H

#include <sleepy_discord/websocketpp_websocket.h>
#include "command.h"

class Client : public SleepyDiscord::DiscordClient {
private:
    std::vector<std::unique_ptr<Command>> commands;
public:
    using SleepyDiscord::DiscordClient::WebsocketppDiscordClient;
    std::string prefix;
    void onMessage(SleepyDiscord::Message message) override;
};


#endif //DISHTML_CLIENT_H
