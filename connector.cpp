#include "connector.h"
#include <iostream>
#include "boost/asio.hpp"
#include "boost/system/error_code.hpp"

using namespace boost::asio;
using ip::tcp;
using std::string;
using std::cout;
using std::endl;

Connector::Connector()
{

}

Worker::Worker(server_point *server){

    this->address = *server->second.first;
    this->port    = *server->second.second;
}

int Worker::client_connect(){

    boost::asio::io_service io_service;
    //socket creation
    tcp::socket socket(io_service);
    //connection
    socket.connect( tcp::endpoint( boost::asio::ip::address::from_string(address), std::stoi(port) ));
    // request/message from client
    const string msg = "Hello from Client!\n";
    boost::system::error_code error;
    boost::asio::write( socket, boost::asio::buffer(msg), error );
    if( !error ) {
       cout << "Client sent hello message!" << endl;
    }
    else {
       cout << "send failed: " << error.message() << endl;
    }
    // getting response from server
    boost::asio::streambuf receive_buffer;
    boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);
    if( error && error != boost::asio::error::eof ) {
        cout << "receive failed: " << error.message() << endl;
    }
    else {
        const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
        cout << data << endl;
    }
    return 0;
}
