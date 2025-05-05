#include <mqtt/client.h>

int main() {
    const std::string SERVER_ADDRESS = "tcp://localhost:1883";
    const std::string CLIENT_ID = "simple_publisher";
    const std::string TOPIC = "test/topic";

    mqtt::client client(SERVER_ADDRESS, CLIENT_ID);
    client.connect();
    client.publish(TOPIC, "Hello from C++ bitch", 256, 0, false);
    client.disconnect();
    
    return 0;
}