#include "FFNet.h"

#include <vector>

FFNet::FFNet(int nInput, int nHidden, int nOutput)
{
    layers.push_back(Layer(nInput));
    layers.push_back(Layer(nHidden));
    layers.push_back(Layer(nOutput));   
}

FFNet::FFNet(int nInput, int nOutput)

void FFNet::setWeight(const NodeAddr &a, const NodeAddr &b, fptype w)
{
    NNetwork::setWeight(a.nid, b.nid);
}

fptype FFNet::getWeight(const NodeAddr &a, const NodeAddr &b)
{
    NNetwork::getWeight(a.nid, b.nid);
}
