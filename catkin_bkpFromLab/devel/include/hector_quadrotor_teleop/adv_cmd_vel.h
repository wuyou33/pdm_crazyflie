// Generated by gencpp from file hector_quadrotor_teleop/adv_cmd_vel.msg
// DO NOT EDIT!


#ifndef HECTOR_QUADROTOR_TELEOP_MESSAGE_ADV_CMD_VEL_H
#define HECTOR_QUADROTOR_TELEOP_MESSAGE_ADV_CMD_VEL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Vector3.h>

namespace hector_quadrotor_teleop
{
template <class ContainerAllocator>
struct adv_cmd_vel_
{
  typedef adv_cmd_vel_<ContainerAllocator> Type;

  adv_cmd_vel_()
    : header()
    , linear()
    , angular()  {
    }
  adv_cmd_vel_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , linear(_alloc)
    , angular(_alloc)  {
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _linear_type;
  _linear_type linear;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _angular_type;
  _angular_type angular;




  typedef boost::shared_ptr< ::hector_quadrotor_teleop::adv_cmd_vel_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::hector_quadrotor_teleop::adv_cmd_vel_<ContainerAllocator> const> ConstPtr;

}; // struct adv_cmd_vel_

typedef ::hector_quadrotor_teleop::adv_cmd_vel_<std::allocator<void> > adv_cmd_vel;

typedef boost::shared_ptr< ::hector_quadrotor_teleop::adv_cmd_vel > adv_cmd_velPtr;
typedef boost::shared_ptr< ::hector_quadrotor_teleop::adv_cmd_vel const> adv_cmd_velConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::hector_quadrotor_teleop::adv_cmd_vel_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::hector_quadrotor_teleop::adv_cmd_vel_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace hector_quadrotor_teleop

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'hector_quadrotor_teleop': ['/home/formation/catkin_ws/src/hector_quadrotor/hector_quadrotor_teleop/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::hector_quadrotor_teleop::adv_cmd_vel_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::hector_quadrotor_teleop::adv_cmd_vel_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::hector_quadrotor_teleop::adv_cmd_vel_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::hector_quadrotor_teleop::adv_cmd_vel_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::hector_quadrotor_teleop::adv_cmd_vel_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::hector_quadrotor_teleop::adv_cmd_vel_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::hector_quadrotor_teleop::adv_cmd_vel_<ContainerAllocator> >
{
  static const char* value()
  {
    return "09119d3b0067bd05b1a6696c168cebb3";
  }

  static const char* value(const ::hector_quadrotor_teleop::adv_cmd_vel_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x09119d3b0067bd05ULL;
  static const uint64_t static_value2 = 0xb1a6696c168cebb3ULL;
};

template<class ContainerAllocator>
struct DataType< ::hector_quadrotor_teleop::adv_cmd_vel_<ContainerAllocator> >
{
  static const char* value()
  {
    return "hector_quadrotor_teleop/adv_cmd_vel";
  }

  static const char* value(const ::hector_quadrotor_teleop::adv_cmd_vel_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::hector_quadrotor_teleop::adv_cmd_vel_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/Header header\n\
geometry_msgs/Vector3 linear\n\
geometry_msgs/Vector3 angular\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Vector3\n\
# This represents a vector in free space. \n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
";
  }

  static const char* value(const ::hector_quadrotor_teleop::adv_cmd_vel_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::hector_quadrotor_teleop::adv_cmd_vel_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.linear);
      stream.next(m.angular);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct adv_cmd_vel_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::hector_quadrotor_teleop::adv_cmd_vel_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::hector_quadrotor_teleop::adv_cmd_vel_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "linear: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.linear);
    s << indent << "angular: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.angular);
  }
};

} // namespace message_operations
} // namespace ros

#endif // HECTOR_QUADROTOR_TELEOP_MESSAGE_ADV_CMD_VEL_H
