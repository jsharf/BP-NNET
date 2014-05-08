#include "NNetwork.h"

// Feed-forward Neural Network
// Currently only supports 1 hidden layer
// May expand to general case FF Network in future
class FFNet : public NNetwork
{
    public:
        // constructor for a 3-layer FF Network
        FFNet(int nInput,int nHidden,int nOutput);
        void setWeight(const NodeAddr &a, const NodeAddr &b, fptype w);
        fptype getWeight(const NodeAddr &a, const NodeAddr &b);
        struct NodeAddr
        {
            NodeAddr(int tnid, tlayer, tlayerPos)
                : nid(tnid), layer(tlayer), layerPos(tlayerPos) {}
            int nid;
            int layer;
            int layerPos;
        };
        struct Layer
        {
            Layer(int n):nodes(n) 
            {
                mLayerId = mLayerCount;
                mLayerCount++;     
            }
            NodeAddr addNeuron()
            {
                int nid = addNode();
                nids.push_back(nid);
                return NodeAddr(nid, mLayerId, nids.size()-1);  
            }
            int size()
            {
                return nids.size();
            }
            vector <int> nids;
            int mLayerId;
            static int mLayerCount = 0;
        };
        vector <Layer> layers;
    private:
        FFNet();
};
