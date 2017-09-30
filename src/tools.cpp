#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
    VectorXd rmse(4);
	rmse << 0,0,0,0;

    VectorXd c(4);

	for(int i=0; i < estimations.size(); ++i){
	    c << estimations[i]-ground_truth[i];
	    for(int j=0; j < c.size(); ++j){
	        rmse[j] += c[j]*c[j]/estimations.size();
	    }
	}
    
    return rmse.array().sqrt();    
}
