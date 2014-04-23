#include <cmath>
#include <limits>
typedef float fptype;

class NNetwork
{
    public:
        NNetwork(int n) : mNet(n) {}
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
        void read(int a) const;
        struct Neuron
        {
            Neuron(int nid) : id(nid) {}
            int getOutput()
            {
                int sum = 0;
                int len = inputs.size();
                for (int i=0; i<len; i++)
                    sum += inputs[i]->getOutput()*weights[i];
            }
            vector <Neuron *> inputs;
            vector <fptype> weights;
            int id;
            private:
                // no default constructor!
                Neuron() {};
        };
    private:
        vector <Neuron> mNet;
};
