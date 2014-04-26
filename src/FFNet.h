#include "NNetwork.h"

// Feed-forward Neural Network
// Currently only supports 1 hidden layer
// May expand to general case FF Network in future
class FFNet : public NNetwork
{
    public:
        // constructor for a 3-layer FF Network
        FFNet(nInput, nHidden, nOutput);
        setWeight(const NodeAddr &a, const NodeAddr &b);
        getWeight(const NodeAddr &a, const NodeAddr &b);
        struct NodeAddr
        {
            NodeAddr(int tnid, tlayer, tlayerPos)
                : nid(tnid), layer(tlayer), layerPos(tlayerPos) {}
            int nid;
            int layer;
            int layerPos;
        }
    private:
        FFNet();
};
