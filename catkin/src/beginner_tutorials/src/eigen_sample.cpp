#include <ros/ros.h>
#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>

int main(int argc, char* argv[])
{
  ros::init(argc, argv, "eigen_sample");
	
	double hairetsu[2][2];
	Eigen::Matrix<double,2,2> mat;

	hairetsu[0][0] = 0.0;
	hairetsu[1][0] = 0.0;
	hairetsu[0][1] = 0.0;
	hairetsu[1][1] = 0.0;

	mat << 1.0,1.0,
               1.0,1.0;

std::cout << "mat = " << mat << std::endl;

//	mat = Eigen::Map<Eigen::Matrix<double,2, 2>>(&(hairetsu[2][2]),4,4);

std::cout << "mat = " << mat << std::endl;

	return 0;
}

/*
#include <ros/ros.h>
#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>

int iii;
double rv_x;

int main(int argc, char* argv[])
{
  ros::init(argc, argv, "eigen_sample");
	
	Eigen::Matrix<double,2,2> rv;
        ros::NodeHandle params("~");

        params.param<int>("iii", iii, 0);
        params.param<double>("rv", rv_x, 1.0);

	rv << rv_x,0.0,
              0.0,0.0;

	std::cout << "iii: " << iii << std::endl;        	
	std::cout << "rv: " << rv << std::endl;
	return 0;
}
*/
