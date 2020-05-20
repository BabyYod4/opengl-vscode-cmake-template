#ifndef MESSAGE_BUS_HPP
#define MESSAGE_BUS_HPP

#include "../generic/data_types.hpp"

#include <functional>
#include <queue>
#include <vector>
#include <utility>

namespace ly{

    class Message{
    public:
        Message(cstring_t t_event):
            m_messageEvent(t_event)
        {}

        Message(const float_t& t_event):
            m_messageEvent( std::to_string(t_event) )
        {}

        cstring_t getEvent(){ return m_messageEvent.c_str(); }
    private:
        string_t m_messageEvent;
    };

    class MessageBus{
    public:
        MessageBus() {};
        ~MessageBus() {};

        void addReceiver(const std::function<void (Message message)>& t_messageReceiver){
            m_receivers.push_back(t_messageReceiver);
        }

        void sendMessage(const Message& t_message){
            m_messages.push(t_message);
        }

        void notify(){
            while(!m_messages.empty()) {
                for (auto iter = m_receivers.begin(); iter != m_receivers.end(); iter++) {
                    (*iter)(m_messages.front());
                }
                m_messages.pop();
            }
        }

    private:
        std::vector<std::function<void (Message)>> m_receivers;
        std::queue<Message> m_messages;
    };

}
#endif // MESSAGE_BUS_HPP
