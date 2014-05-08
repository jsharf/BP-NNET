#include <cmath>
#include <limits>
typedef float fptype;

/*
     tanh is used as the activation function
     It is differentiable, which is important for backwards propagation.
     Since tanh is centered around y=0, it doesn't introduce any
     bias in the learning algorithm (unlike the logistical sigmoid)
     tanh is a kind of sigmoidal function
*/
fptype sigmoid(fptype x)
{
    return tanh(x); 
}

class NNetwork
{
    public:
        NNetwork() {}
        virtual ~NNetwork();
        // add a new node. returns node ID
        int addNode();
        // Connect output of a to input of b with weight w
        // equivalent to setWeight except if a and b are already
        // connected, don't overwrite that value
        void connect(int a, int b, fptype w);
        // get the weight between two nodes (node a output -> node b input)
        fptype getWeight(int a, int b) const;
        // set the weight between two nodes (node a output -> node b input)
        void setWeight(int a, int b, fptype w);
        // read the current output of node a
        fptype read(int a) const;
        void setOutputNode(int a);
        fptype getOutput() const;
        int mOutputNode;
        struct Neuron
        {
            Neuron(int nid) : id(nid), mIsInput(0) {}
            void setInput(int val)
            {
                mVal = val;
                mIsInput = 1;
            }
            fptype getOutput()
            {
                if (mIsInput)
                    return mVal;
                float sum = 0;
                int len = inputs.size();
                for (int i=0; i<len; i++)
                    sum += inputs[i]->getOutput()*weights[i];
                return sigmoid(sum);
            }
            vector <Neuron *> inputs;
            vector <fptype> weights;
            int id;
            int mVal;
            char mIsInput;
            private:
                // no default constructor!
                Neuron() {};
        };
    private:
        vector <Neuron> mNet;
};
