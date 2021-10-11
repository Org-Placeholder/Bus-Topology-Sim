#pragma once
#include "dataframe.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class link;
class node
{
    int device_id;
    string mac_address;
    link *links;
    int num_links;

public:
    node()
    {
    }

    node(int d_id, string m_address)
    {
        device_id = d_id;
        mac_address = m_address;
    }

    void transmit(string message, int seq_num, string dest_mac_address);

    void recieve(dataframe data);

    string get_mac_address();

    void set_links(link *l, int n);
};