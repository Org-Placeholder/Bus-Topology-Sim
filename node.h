#pragma once
#include<string>
#include "dataframe.h"
#include <iostream>
using namespace std;
class link;
class node
{
    int device_id;
    string mac_address;
    link* links;
    int num_links;
    public :
    node(int d_id, string m_address)
    {
        device_id = d_id;
        mac_address = m_address;
    }
    void transmit(string message, int seq_num, string dest_mac_address);
    
    void recieve(dataframe data)
    {
        cout << data.get_message() << " recieved at " << device_id << endl;
    };
    
    string get_mac_address()
    {
        return mac_address;
    }

    void set_links(link* l, int n)
    {
        links = l;
        num_links = n;
    }
};