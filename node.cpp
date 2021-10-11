#include "node.h"
#pragma once
void node::transmit(string message, int seq_num, string dest_mac_address)
{
    dataframe data(message, seq_num, mac_address, dest_mac_address);
    cout << "device " << device_id << " sending " << message << " to " << dest_mac_address << endl;
    for (int i = 0; i < num_links; i++)
    {
        cout << "Sending data to link" << endl;
        links[i].transmit(data);
    }
}