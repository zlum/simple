#include <cmath>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        cout << "Wrong argc " << argc << endl;

        return 1;
    }

    string msg(argv[1]);
    std::vector<uint8_t> bytes(msg.begin(), msg.end());

    stringstream data;

    for(const auto byte : bytes)
    {
        data << hex << int(byte) << ' ';
    }

    uint8_t checksum = bytes[0];

    for(unsigned i = 1; i < bytes.size(); i++)
    {
        uint8_t byte = bytes[i];

        checksum ^= byte;
    }

    std::ostringstream os;

    os << hex << int(checksum);
    std::string digits = os.str();

    cout << "23 "
         << data.str()
         << hex << int('*') << ' '
         << int(digits[0]) << ' ' << int(digits[1])
         << " 0D 0A" << endl;

    return 0;
}
