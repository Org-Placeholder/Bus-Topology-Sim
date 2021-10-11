#pragma once
#include <string>
using namespace std;
class dataframe
{
    string message;
    int seq_num;
    string src_mac_address;
    string dest_mac_address;

public:
    dataframe(string msg, int snum, string src, string dest)
    {
        message = msg;
        seq_num = snum;
        src_mac_address = src;
        dest_mac_address = dest;
    };

    string get_src_mac_address()
    {
        return src_mac_address;
    }

    string get_dest_mac_address()
    {
        return dest_mac_address;
    }

    string get_message()
    {
        return message;
    }
};