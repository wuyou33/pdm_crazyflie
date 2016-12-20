#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>

/*Eigen::MatrixXd plus(Eigen::MatrixXd a,Eigen::MatrixXd b)
{
	Eigen::Matrix<double,2,2> c;
	c = a + b;
return c;
}
*/

int main(int argc, char* argv[])
{
//	Eigen::MatrixXd r(2,2), v(2,2), rv(2,2);
//	rv = Eigen::Matrix<double,2,2>::Zero();

	Eigen::Matrix<double,2,2> rv,rinv;

	rv << 1,1,
	      2,0;
        	
	rinv = rv.inverse();
	std::cout << rv << std::endl;
	std::cout << rinv << std::endl;

	return 0;
}
