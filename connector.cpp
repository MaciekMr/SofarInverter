#include "connector.h"
#include <iostream>
#include "boost/asio.hpp"
#include "boost/system/error_code.hpp"
#include "configmodel.h"

using namespace boost::asio;
using ip::tcp;
using std::string;
using std::cout;
using std::endl;



Connector *Connector::_connector;

Connector::Connector():ThreadSet()
{
    workers = new workermap();
}

const Connector * Connector::getConnector(){

    if(!_connector)
        _connector = new Connector();
    return (_connector);
}


void Connector::addWorker(Worker *_worker) const{

    workers->insert(pair(_worker->getid(), _worker));

}

void Connector::killWorker(int id){

}

void Connector::runWorker(int id){


}

/**********************************WORKER******************************************************/

Worker::Worker(int id):Thread(&Worker::comm, this){

    ConfigModel *conf = ConfigModel::getConfig();

    this->address = conf->findparameter<string>(std::to_string(id), IP);
    this->port    = conf->findparameter<string>(std::to_string(id), PORT);;

}

void Worker::update(){


}


[[ noreturn ]]
void Worker::comm(){

    while(true){

        std::cout<<"Thread id:"<<this->thread_ptr->get_id()<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
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

int Worker::getid(){

    return(worker_id);
}
