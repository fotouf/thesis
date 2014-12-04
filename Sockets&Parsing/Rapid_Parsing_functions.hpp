#include <iostream>
#include <fstream>
#include <vector>
#include <string> 
#include <sstream>

//#define RAPIDXML_NO_EXCEPTIONS 

#include "rapidxml.hpp"
#include "rapidxml_print.hpp"
#include <list>
//#include <iostream>
//#include <sstream>
#include <cstring>      // Needed for memset



//#define RAPIDXML_NO_EXCEPTIONS


struct RobotMessage
{
  unsigned int Type;
  std::string Status;
  std::string Mode;
  float Time;
  std::list<std::string> Frame;
  
  std::list<std::string> Joints;
  
  float FTime;
  std::list<std::string> FFrame;
  std::list	<std::string> FJoints;
  
  std::string Id;
  std::string Ts;
};
 
typedef std::vector<RobotMessage> Sked;

void rxml_read(Sked *sked, std::istream & is );
void rxml_write( Sked *sked, std::stringstream & os );


