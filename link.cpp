#include "link.h"

void link::transmit(dataframe data)
{
    bool broadcast = false;
    if(data.get_dest_mac_address() == "FF:FF:FF:FF:FF:FF")
    {
        broadcast = true;
        //if destination mac address is the broadcast adress (FF:FF:FF:FF:FF:FF), 
        //then we make the broadcast flag true.
    }

    int i = 0;
    if(dir == unidirectional)
    {
        //if the link is unidirectional, only nodes that are defined after the source nodes will get the message.
        //ie - direction of transmission is in increasing order of node list index.
        while(nodes[i].get_mac_address() != data.get_src_mac_address() && i < num_nodes)
        {
            i++;
        }
        i++;
    }

    for(; i < num_nodes; i++)
    {
        if((data.get_dest_mac_address() == nodes[i].get_mac_address() || broadcast) && data.get_src_mac_address() != nodes[i].get_mac_address())
        {
            nodes[i].recieve(data);
        }
    }
}