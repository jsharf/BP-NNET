#include "FFNet.h"

#include <vector>

FFNet::FFNet(int nInput, int nHidden, int nOutput)
{
    
}

void FFNet::setWeight(const NodeAddr &a, const NodeAddr &b, fptype w)
{
    //NNetwork::setWeight(a. 
}

fptype FFNet::getWeight(const NodeAddr &a, const NodeAddr &b)
{
    NNetwork::getWeight(a.nid, b.nid);
}
