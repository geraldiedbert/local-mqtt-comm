#include <mqtt/client.h>
#include <iostream>

int main() {
    const std::string SERVER_ADDRESS = "tcp://localhost:1883";
    const std::string CLIENT_ID = "simple_subsciber";
    const std::string TOPIC = "test/topic";

    mqtt::client client(SERVER_ADDRESS, CLIENT_ID);
    client.connect();
    client.subscribe(TOPIC, 1);

    auto msg = client.consume_message();
    if (msg) {
        std::cout << "Received: " << msg->to_string() << std::endl;
    }

    client.disconnect();
    
    return 0;
}