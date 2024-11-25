#include <iostream>

namespace boost::asio::ip {
    class server{

        int port;
        public:

        server(int port = 0) : port(port)
        int getPort()
        {
            return port;
        }
    };
}

int main()
{
    boost::asio::ip::server bckend(3400);
    std::cout<<
    return 0;
}