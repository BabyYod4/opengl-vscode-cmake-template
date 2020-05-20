#ifndef BUS_NODE_HPP
#define BUS_NODE_HPP

#include "message_bus.hpp"

namespace ly{

    class BusNode
    {
    public:
        BusNode(MessageBus* t_messageBus){
            this->m_messageBus = t_messageBus;
            this->m_messageBus->addReceiver( [this](Message t_message){ onEvent(t_message); } );
        }

    protected:
        MessageBus* m_messageBus;

        void sendMessage(const Message& t_message) { 
            m_messageBus->sendMessage(t_message);
        }

        virtual void onEvent(Message& t_message){};
    };

}

#endif // BUS_NODE_HPP
