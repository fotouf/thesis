// to read and write xml files.
 
#include "Parsing_functions.hpp"
//#include <vector>
//#include <string>
//#include <fstream>
#include <locale>
//#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/foreach.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>
 
 /*
typedef boost::gregorian::date Date;

struct Flight
{
  std::string carrier;
  unsigned number;
  Date date;
  bool cancelled;
};
 
typedef std::vector<Flight> Sked;
*/
/*
class DateTranslator
{
  typedef boost::date_time::date_facet<Date, char> tOFacet;
  typedef boost::date_time::date_input_facet<Date, char> tIFacet;
  std::locale locale_;
   
  static std::locale isoDateLocale() {
    std::locale loc;
    loc = std::locale( loc, new tIFacet("%Y-%m-%d") );
    loc = std::locale( loc, new tOFacet("%Y-%m-%d") );
    return loc;
  }
   
public:
  typedef std::string internal_type;
  typedef Date external_type;
   
  DateTranslator( ) : locale_( isoDateLocale() ) {}
   
  boost::optional<external_type> get_value(internal_type const& v)
  {
    std::istringstream stream(v);
    stream.imbue(locale_);
    external_type vAns;
    if( stream >> vAns ) {
      return vAns;
    }
    else {
      return boost::none;
    }
  }
   
  boost::optional<internal_type> put_value(external_type const& v)
  {
    std::ostringstream ans;
    ans.imbue(locale_);
    ans << v;
    return ans.str();
  }
};*/
 
namespace boost{ namespace property_tree{
 
  //template<> struct translator_between<std::string, Date> {
   // typedef DateTranslator type;
  //};
}}

 
void read(Sked *sked, std::istream & is )
{

  // populate tree structure pt
  using boost::property_tree::ptree;
  ptree pt;

  read_xml(is, pt);

  // traverse pt
  //Sked *ans;
  RobotMessage f;

// get length of file:
 /*   is.seekg (0, is.end);
    int length = is.tellg();
    is.seekg (0, is.beg);

    char * buffer = new char [length];

 //   std::cout << "Reading " << length << " data\n\n" ;
    // read data as a block:
   is.read (buffer,length);
   int cnt =0;*/
 /* BOOST_FOREACH(ptree::value_type &v,pt.get_child("RobotMessage"))
	{
		std::cout<<cnt;
		cnt+=1;
		std::string lala =  v.first;
		std::cout <<lala;
	}*/
  f.Type = pt.get<unsigned int>("RobotMessage.Type");
  f.Status = pt.get<std::string>("RobotMessage.Status");
     f.Mode = pt.get<std::string>("RobotMessage.Mode");	
      f.Time = pt.get<float>("RobotMessage.Time");
      
     f.Frame.push_back(pt.get<std::string>("RobotMessage.Frame.<xmlattr>.X"));
      f.Frame.push_back(pt.get<std::string>("RobotMessage.Frame.<xmlattr>.Y"));
      f.Frame.push_back(pt.get<std::string>("RobotMessage.Frame.<xmlattr>.Z"));
      f.Frame.push_back(pt.get<std::string>("RobotMessage.Frame.<xmlattr>.Rx"));
      f.Frame.push_back(pt.get<std::string>("RobotMessage.Frame.<xmlattr>.Ry"));
      f.Frame.push_back(pt.get<std::string>("RobotMessage.Frame.<xmlattr>.Rz"));
      
      f.Joints.push_back(pt.get<std::string>("RobotMessage.Joints.<xmlattr>.J1"));
      f.Joints.push_back(pt.get<std::string>("RobotMessage.Joints.<xmlattr>.J2"));
      f.Joints.push_back(pt.get<std::string>("RobotMessage.Joints.<xmlattr>.J3"));
      f.Joints.push_back(pt.get<std::string>("RobotMessage.Joints.<xmlattr>.J4"));
      f.Joints.push_back(pt.get<std::string>("RobotMessage.Joints.<xmlattr>.J5"));
      f.Joints.push_back(pt.get<std::string>("RobotMessage.Joints.<xmlattr>.J6"));

      f.FTime= pt.get<float>("RobotMessage.FTime");
  
      f.FFrame.push_back(pt.get<std::string>("RobotMessage.Frame.<xmlattr>.X"));
      f.FFrame.push_back(pt.get<std::string>("RobotMessage.FFrame.<xmlattr>.Y"));
      f.FFrame.push_back(pt.get<std::string>("RobotMessage.FFrame.<xmlattr>.Z"));
      f.FFrame.push_back(pt.get<std::string>("RobotMessage.FFrame.<xmlattr>.Rx"));
      f.FFrame.push_back(pt.get<std::string>("RobotMessage.FFrame.<xmlattr>.Ry"));
      f.FFrame.push_back(pt.get<std::string>("RobotMessage.FFrame.<xmlattr>.Rz"));

      f.FJoints.push_back(pt.get<std::string>("RobotMessage.FJoints.<xmlattr>.J1"));
      f.FJoints.push_back(pt.get<std::string>("RobotMessage.FJoints.<xmlattr>.J2"));
      f.FJoints.push_back(pt.get<std::string>("RobotMessage.FJoints.<xmlattr>.J3"));
      f.FJoints.push_back(pt.get<std::string>("RobotMessage.FJoints.<xmlattr>.J4"));
      f.FJoints.push_back(pt.get<std::string>("RobotMessage.FJoints.<xmlattr>.J5"));
      f.FJoints.push_back(pt.get<std::string>("RobotMessage.FJoints.<xmlattr>.J6"));

      f.Id = pt.get<std::string>("RobotMessage.<xmlattr>.Id");
      f.Ts = pt.get<std::string>("RobotMessage.<xmlattr>.Ts");
      (*sked).push_back(f);	
      
      
    
//  return ans;
}
 
void write( Sked *sked, std::ostream & os )
{
  using boost::property_tree::ptree;
  ptree pt;
   
  //pt.add("sked.version", 3);

  BOOST_FOREACH(RobotMessage f,(*sked)){
  ptree & node = pt.add("ReplyMessage", "");
  node.put("<xmlattr>.Id",f.Id);
  node.put("<xmlattr>.Ts",f.Ts);
  node.put("Type", f.Type);
  node.put("Status", f.Status);
  //node.put("Mode", f.Mode);
std::string myString = f.Id;
std::istringstream buffer(myString);
int value;
buffer >> value;  
  node.put("Time", value);
  
  /*int cnt=1;
  BOOST_FOREACH(std::string str, f.Frame) {
   switch (cnt)
   {
   	case 1:
      	node.put("Frame.<xmlattr>.X", str);
	break;
	case 2:
	node.put("Frame.<xmlattr>.Y", str);
	break;
	case 3:
	node.put("Frame.<xmlattr>.Z", str);
	break;
	case 4:
	node.put("Frame.<xmlattr>.Rx", str);
	break;
	case 5:
	node.put("Frame.<xmlattr>.Ry", str);
	break;
	case 6:
	node.put("Frame.<xmlattr>.Rz", str);
	break;
	default:
	break;
   }
   cnt = ++cnt;
  }
  
  cnt=1;
  BOOST_FOREACH(std::string str, f.Joints) {
   switch (cnt)
   {
   	case 1:
      	node.put("Joints.<xmlattr>.J1", str);
	break;
	case 2:
	node.put("Joints.<xmlattr>.J2", str);
	break;
	case 3:
	node.put("Joints.<xmlattr>.J3", str);
	break;
	case 4:
	node.put("Joints.<xmlattr>.J4", str);
	break;
	case 5:
	node.put("Joints.<xmlattr>.J5", str);
	break;
	case 6:
	node.put("Joints.<xmlattr>.J6", str);
	break;
	default:
	break;
   }
   cnt = ++cnt;
  }

  node.put("FTime", f.FTime);
  cnt=1;
  BOOST_FOREACH(std::string str, f.FFrame) {
   switch (cnt)
   {
   	case 1:
      	node.put("FFrame.<xmlattr>.X", str);
	break;
	case 2:
	node.put("FFrame.<xmlattr>.Y", str);
	break;
	case 3:
	node.put("FFrame.<xmlattr>.Z", str);
	break;
	case 4:
	node.put("FFrame.<xmlattr>.Rx", str);
	break;
	case 5:
	node.put("FFrame.<xmlattr>.Ry", str);
	break;
	case 6:
	node.put("FFrame.<xmlattr>.Rz", str);
	break;
	default:
	break;
   }
   cnt = ++cnt;
  }
  
  cnt=1;
  BOOST_FOREACH(std::string str, f.FJoints) {
   switch (cnt)
   {
   	case 1:
      	node.put("FJoints.<xmlattr>.J1", str);
	break;
	case 2:
	node.put("FJoints.<xmlattr>.J2", str);
	break;
	case 3:
	node.put("FJoints.<xmlattr>.J3", str);
	break;
	case 4:
	node.put("FJoints.<xmlattr>.J4", str);
	break;
	case 5:
	node.put("FJoints.<xmlattr>.J5", str);
	break;
	case 6:
	node.put("FJoints.<xmlattr>.J6", str);
	break;
	default:
	break;
   }
   cnt = ++cnt;
  }

  node.put("<xmlattr>.Id", f.Id);
  node.put("<xmlattr>.Ts", f.Ts);*/
//std::cout<<"\nId = "<<f.Id<<"\n";
  }
  write_xml(os, pt);

}
 


//void rapidxml::parse_error_handler(const char *what, void *where)
//{std::cout << "Parse error: " << what << "\n"; std::abort(); } 











