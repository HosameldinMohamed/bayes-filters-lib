#include <BayesFilters/StateModel.h>

using namespace bfl;
using namespace Eigen;


Eigen::MatrixXd StateModel::getJacobian()
{
    throw std::runtime_error("ERROR::STATEMODEL::GETJACOBIAN\nERROR:\n\tMethod not implemented.");
}


Eigen::VectorXd StateModel::getTransitionProbability(const Ref<const MatrixXd>& prev_states, const Ref<const MatrixXd>& cur_states)
{
    throw std::runtime_error("ERROR::STATEMODEL::TRANSITIONPROBABILITY\nERROR:\n\tMethod not implemented.");
}


Eigen::MatrixXd StateModel::getNoiseCovarianceMatrix()
{
    throw std::runtime_error("ERROR::STATEMODEL::GETNOISECOVARIANCEMATRIX\nERROR:\n\tMethod not implemented.");
}


Eigen::MatrixXd StateModel::getNoiseSample(const std::size_t num)
{
    throw std::runtime_error("ERROR::STATEMODEL::GETNOISESAMPLE\nERROR:\n\tMethod not implemented.");
}
