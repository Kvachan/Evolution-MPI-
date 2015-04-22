#ifndef NEURALNETWORKS
#define NEURALNETWORKS

#include "links.h"

class Neuron;
class IThresholdFunction;

class NeuralNetwork {   // : public Cloneable {

protected:
    std::vector<Neuron *> neurons;
    Links* neuronsLinks;
    int activationIterations;

public:
    NeuralNetwork();
    NeuralNetwork(int numberOfNeurons);
    void setNeuronFunction(int neuronNumber, IThresholdFunction *function, std::vector<double> params);
    void addLink(int activatorNeuronNumber, int receiverNeuronNumber, double weight);
    void putSignalToNeuron(int neuronIndex, double signalValue);
    double getAfterActivationSignal(int neuronIndx);
    void activate();
    std::vector<double> getWeightsOfLinks();
    void setWeightsOfLinks(std::vector<double> weights);
    std::vector<Neuron *> getNeurons();         // Возвращает копии. Это нормально???
    int getNeuronsCount();
    int getActivationsIterations();
    void setNeurons(std::vector<Neuron *> newNeurons);
    void setActivationIterations(int activationIterations);
    void setNeuronalLinks(Links* newNeuronLinks);
    Links *getNeuronsLinks();
    NeuralNetwork* clone();
    std::string toString();

};


#endif // NEURALNETWORKS

/*    public static void marsall(NeuralNetwork nn, OutputStream out) throws Exception {
        // TODO refactoring
        JAXBContext context = JAXBContext.newInstance(NeuralNetwork.class);
        Marshaller marshaller = context.createMarshaller();
        marshaller.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, true);
        marshaller.marshal(nn, out);
        out.flush();
    }

    public static NeuralNetwork unmarsall(InputStream in) throws Exception {
        // TODO refactoring
        JAXBContext context = JAXBContext.newInstance(NeuralNetwork.class);
        Unmarshaller unmarshaller = context.createUnmarshaller();
        NeuralNetwork unmarshalledNn = (NeuralNetwork) unmarshaller.unmarshal(in);
        return unmarshalledNn;
    }
}
*/
