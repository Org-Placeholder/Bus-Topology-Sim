#include "node.h"
#pragma once
void node::transmit(string message, int seq_num, string dest_mac_address)
{
    dataframe data(message, seq_num, mac_address, dest_mac_address);
    if (dest_mac_address == "FF:FF:FF:FF:FF:FF")
    {
        //FF:FF:FF:FF:FF:FF is the broadcast address.
        cout << "Device " << device_id << " broadcasting '" << message << "'" << endl;
    }
    else
    {
        cout << "Device " << device_id << " sending '" << message << "' to " << dest_mac_address << endl;
    }
    for (int i = 0; i < num_links; i++)
    {
        cout << "Device " << device_id << " sending data to link" << endl;
        links[i].transmit(data);
    }
}

void node::recieve(dataframe data)
{
    cout << data.get_message() << " recieved at device " << device_id << endl;
}

void node::set_links(link *l, int n)
{
    links = l;
    num_links = n;
}

string node::get_mac_address()
{
    return mac_address;
}