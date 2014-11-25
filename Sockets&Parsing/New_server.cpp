/*
sockets, TCP/IP.
*/

#include <iostream>
#include <sstream>
#include <cstring>      // Needed for memset
#include <sys/socket.h> // Needed for the socket functions
#include <netdb.h>      // Needed for the socket functions
#include "Parsing_functions.hpp"

/*void myReplace(std::string& str,  std::string oldStr, std::string newStr)
{
  size_t pos = 0;
  while((pos = str.find(oldStr, pos)) != std::string::npos)
  {
     str.replace(pos, oldStr.length(), newStr);
     pos += newStr.length();
  }
}*/

int main()
{
    int status;
    struct addrinfo host_info;       // The struct that getaddrinfo() fills up with data.
    struct addrinfo *host_info_list; // Pointer to the to the linked list of host_info's.
    host_info_list = &host_info;       //  <-----											check
    std::stringstream DataBuffer;   // stream for received data, used for converting data buffer(vector) in a stream which is used by read_xml() 
    std::stringstream OutputBuffer;
    Sked sked;
    //std::ofstream odata_buffer("data_buffer.xml");
    std::fstream  data_buffer;
    std::string mynewstring;
    int length;
    ssize_t bytes_recieved;
    char incomming_data_buffer[1000];
    RobotMessage *p;
// allocate memory:
    char * buffer = new char [150];
    size_t pos;
    size_t ppos;
//allocate memory 
std::string mynewnewstring;
char *cstr = new char[150]; 
char *msg = new char[100];;
int len;
ssize_t bytes_sent;



    memset(&host_info, 0, sizeof host_info);

    std::cout << "Setting up the structs..."  << std::endl;

    host_info.ai_family = AF_UNSPEC;     // IP version not specified. Can be both.		//AF_INET or PF_INET			check
    host_info.ai_socktype = SOCK_STREAM; // Use SOCK_STREAM for TCP or SOCK_DGRAM for UDP.						check
    //host_info.ai_protocol = IPPROTO_TCP; //The Transmission Control Protocol (TCP) (possibly redundant setting)				check
    host_info.ai_flags = AI_PASSIVE;     // IP Wildcard	(The socket address will be used in a call to the bind function.)										


    // FILL IN PORT NUMBER HERE!!!!!!
    status = getaddrinfo(NULL, "5151", &host_info, &host_info_list);					//5151 supports TCP - 5555 supports udp
    // getaddrinfo returns 0 on succes, or some other value when an error occured.			//both produce the same communication error though
    // (translated into human readable text by the gai_gai_strerror function).
    if (status != 0)  std::cout << "getaddrinfo error" << gai_strerror(status) ;


    std::cout << "Creating a socket..."  << std::endl;
    

/* 
struct sockaddr_in listenAddr;
memset(&listenAddr, 0, sizeof(listenAddr));
// IPv4 address 
listenAddr.sin_family = AF_INET;
// your port number 
listenAddr.sin_port = htons(5555);
// listen on all interfaces 
listenAddr.sin_addr.s_addr = htonl(INADDR_ANY);
listenAddr.sin_socktype = SOCK_STREAM;

// TCP socket 
int socketfd ; // The socket descripter
socketfd = socket(PF_INET, SOCK_STREAM, 0);

// your error code, omitted here 

status = bind(socketfd,(struct sockaddr *) &listenAddr, sizeof(listenAddr));
*/


    int socketfd ; // The socket descripter
    socketfd = socket(host_info_list->ai_family, host_info_list->ai_socktype,
                      host_info_list->ai_protocol);

    if (socketfd == -1)  std::cout << "socket error " ;

    std::cout << "Binding socket..."  << std::endl;
    // we use to make the setsockopt() function to make sure the port is not in use
    // by a previous execution of our code. (see man page for more information)
    int yes = 1;
    status = setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
    status = bind(socketfd, host_info_list->ai_addr, host_info_list->ai_addrlen);
    if (status == -1)  std::cout << "bind error" << std::endl ;

    std::cout << "Listen()ing for connections..."  << std::endl;
    status =  listen(socketfd, 5);
    if (status == -1)  std::cout << "listen error" << std::endl ;


    int new_sd;
    struct sockaddr_storage their_addr;
    socklen_t addr_size = sizeof(their_addr);
    new_sd = accept(socketfd, (struct sockaddr *)&their_addr, &addr_size);
    if (new_sd == -1)
    {
        std::cout << "listen error" << std::endl ;
    }
    else
    {
        std::cout << "Connection accepted. Using new socketfd : "  <<  new_sd << std::endl;
    }

// RECEIVING............
//......................

	

    for(int k=1;k<200;k++) 
    {

    if( remove( "data_buffer.xml" ) != 0 )
       perror( "\nError deleting file" );
    else
       puts( "\nFile successfully deleted" );

    //open .xml file to store the received message
    data_buffer.open("data_buffer.xml", std::fstream::in | std::fstream::out | std::fstream::app);
    data_buffer.flush();
    
    data_buffer.seekg (0, data_buffer.end);
    length = data_buffer.tellg();			//int
    data_buffer.seekg (0, data_buffer.beg);
    std::cout<< "\nalready in "<<length<<" data\n";

    std::cout << "Waiting to recieve data..."  << std::endl;
    		//ssize_t bytes_recieved;
    		//char incomming_data_buffer[1000];
    bytes_recieved = recv(new_sd, incomming_data_buffer,1000, 0);
    // If no data arrives, the program will just wait here until some data arrives.
    if (bytes_recieved == 0) std::cout << "host shut down." << std::endl ;
    if (bytes_recieved == -1)std::cout << "recieve error!" << std::endl ;
    std::cout << bytes_recieved << " bytes recieved :" << std::endl ;
    incomming_data_buffer[bytes_recieved] = '\0';
    std::cout << incomming_data_buffer << std::endl;
    
    //---from char buffer to string (works!!)
    //std::string mystring = std::string(incomming_data_buffer);
   
   
    //---------------------------------------------------------------------------------------------------------------------------
    //---put char buffer into a stringstream
    for(int i=0;i<(bytes_recieved);i++){
    DataBuffer.put(incomming_data_buffer[i]);
    }
 
/*------------ Storing received data in an xml file and read it in a struct ---------------*/
    //--put char buffer into a stream;
    data_buffer<< incomming_data_buffer;
    data_buffer.close();
  
    //---take istream for the read() function (puts data in a struct)
    std::ifstream input("data_buffer.xml");
    if ((bytes_recieved != 0)&(bytes_recieved != -1))
    {
	sked = read(DataBuffer);
    }
    input.close();

    
/*------------- Create the ReplyMessage -----------------*/



/*    //---modify received data and put it in a .xml file 
    std::ofstream output("output.xml");
    p = sked.data();			//RobotMessage *
    (*p).Type = k+10;    
    write(sked,output);

    
    output.close();

    //---read .xml file in a ifstream and put it in a string
    std::ifstream reply("output.xml");
    		//std::string mynewstring;
    reply.seekg (0, reply.end);
    std::streamsize llength = reply.tellg();
    reply.seekg (0, reply.beg);


    		// allocate memory:
    		//char * buffer = new char [llength];

    // read data as a block:
    reply.read (buffer,llength);
buffer[llength]='\0';					//
    reply.close();*/

// --------------------------------------------------------------------------------- USE A STRINGSTREAM ---//
OutputBuffer.str("");
    p = sked.data();			//RobotMessage *
    (*p).Type = k+10;
    write(sked,OutputBuffer);

OutputBuffer.seekg (0, OutputBuffer.end);
    std::streamsize llength = OutputBuffer.tellg();
    OutputBuffer.seekg (0, OutputBuffer.beg);

std::cout<<"\nlength of buffer = "<<llength<<"\n";
    		// allocate memory:
    		//char * buffer = new char [llength];

    // read data as a block:
    OutputBuffer.read (buffer,llength);

OutputBuffer.flush();

buffer[llength]='\0';					//
 
//-----------------------------------------------------------------------------------------------------------//

    mynewstring = std::string(buffer);
//std::cout<<llength<<" length\n";
//std::cout<<buffer<<"  buffer\n";
//std::cout<<mynewstring<<"  string\n";

   /*pos = 0;					//size_t 
    while((pos = mynewstring.find("RobotMessage", pos)) != std::string::npos)
    {
      mynewstring.replace(pos, std::string("RobotMessage").length(), "ReplyMessage");
      pos += std::string("ReplyMessage").length();
    }*/

//delete the first line (the line about the xml version...)
ppos = mynewstring.find("\n");
ppos = +ppos;
mynewnewstring = mynewstring.substr(ppos);		//std::string 

strcpy(cstr, mynewnewstring.c_str());
cstr[mynewnewstring.length()]='\0';
    //TRIAL string to char
    //char *cstr = new char[mynewnewstring.length() + 1]; 
    //strcpy(cstr, mynewnewstring.c_str());

//-----------------------------------------------------------------------------------------------------------------------------

/*mynewnewstring = "<ReplyMessage><Type>10</Type></ReplyMessage>"; 
strcpy(cstr, mynewnewstring.c_str());
cstr[mynewnewstring.length()]='\0';
msg = cstr;
*/
    std::cout << "\nsend()ing back a message..."  << std::endl;
msg = cstr;
    
    len = strlen(msg);
//    std::cout<<"\n"<<len<<"\n";
    bytes_sent = send(new_sd, cstr, len, 0);

    std::cout << "\n"<< bytes_sent << "\n";
    std::cout << "\n"<< msg << "\n";
 
   }

//END OF LOOP ---------------------------

    std::cout << "Stopping server..." << std::endl;
    freeaddrinfo(host_info_list);
    close(new_sd);
    close(socketfd);


return 0 ;


}


