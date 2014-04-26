#include "NNetwork.h"

int NNetwork::addNode()
{
    // get new node id
    int nid = mNet.size();
    // push new node on back of vector
    mNet.push_back(Neuron(nid));
    return nid;
}

NNetwork::~NNetwork()
{
    /*int len = mNet.size();
    for (int i=0; i<len; i++)
    {
        delete mNet[i];
    }*/
}

void NNetwork::connect(int a, int b, fptype w)
{
    // if there's no connection between a and b,
    // connect a and b
    // (connect does not change existing connections)
    if (getWeight(a, b, w))
        setWeight(a, b, w);
}

fptype NNetwork::getWeight(int a, int b) const;
{
    // weight between a node and itself is 0
    if (a == b)
        return 0;
    int len = mNet[b]->inputs.size();
    for (int i=0; i<len; i++)
    {
        if (mNet[b].inputs[i]->id == a)
        {
            return mNet[b].weights[i];
        }
    }
    // 0 means no connection
    return 0;
}

void NNetwork::setWeight(int a, int b, fptype w)
{
    // weight between a node and itself is invalid
    if (a == b)
        return;
    int len = mNet[b].inputs.size();
    for (int i=0; i<len; i++)
    {
        if (mNet[b].inputs[i]->id == a)
        {
            mNet[b].weights[i] = w;
            return;
        }
    }
    // if a and b are not connected,
    // create a new connection between them
    mNet[b].inputs.push_back(&mNet[a]);
    mNet[b].weights.push_back(w);
}

fptype NNetwork::read(int a) const
{
    return mNet[a].getOutput();
}

void NNetwork::setOutputNode(int a)
{
    mOutputNode = a;
}

fptype NNetwork::getOutput() const
{
    return read(mOutputNode);
}
