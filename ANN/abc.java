import java.lang.Math;

class Neuron
{
	double weightVector[];
	int cntInEdges;


	double bias;
	double y, z;
	double delta;
	
	public Neuron(int cntInputEdges)
	{
		cntInEdges = cntInputEdges; //for bias value

		weightVector = new double[cntInEdges]; 
		
		double randomValue = 0.001; //random weight value

		for(int i=0; i<weightVector.length; i++)
		{
			weightVector[i] = randomValue;
		}

		bias = randomValue;
	}
}

class NeuronLayer
{
	int cntNeurons;
	Neuron neurons[];
	
	public NeuronLayer(int cntNeuronInThisLayer)
	{
		cntNeurons = cntNeuronInThisLayer;
		neurons = new Neuron[cntNeuronInThisLayer];
	}
}

class NeuralNetwork
{
	int cntInputUnit;
	int cntOutputUnit;

	int cntHiddenLayer;
	int cntNeuronPerHiddenLayer;

	int cntTotalLayer;

	int cntNeuronLayer;

	NeuronLayer neuronlayer[];


	public void init(int _inputUnit, int _outputUnit, int _hiddenLayer, int _neuronPerHiddenLayer)
	{
		cntInputUnit = _inputUnit;
		cntOutputUnit = _outputUnit;

		cntHiddenLayer = _hiddenLayer;
		cntNeuronPerHiddenLayer = _neuronPerHiddenLayer;

		cntTotalLayer = 2 + cntHiddenLayer;

		neuronlayer = new NeuronLayer[ cntTotalLayer ];


		neuronlayer[0] = new NeuronLayer(cntInputUnit);
		neuronlayer[cntTotalLayer-1] = new NeuronLayer(cntOutputUnit);

		for(int i=1; i<cntTotalLayer-1; i++)
		{
			neuronlayer[i] = new NeuronLayer(cntNeuronPerHiddenLayer);
		}


		for(int i=0; i<cntTotalLayer; i++)
		{
			for(int j=0; j<neuronlayer[i].cntNeurons; j++)
			{
				if(i == 0)
				{
					neuronlayer[i].neurons[j] = new Neuron(0);
				}
				else
				{
					neuronlayer[i].neurons[j] = new Neuron( neuronlayer[i-1].cntNeurons );
				}
			}
		}


	}

	public void feedForward(double x[])
	{
		for(int i=0; i<neuronlayer[0].cntNeurons; i++)
		{
			neuronlayer[0].neurons[i].y = x[i];
		}


		for(int i=1; i<cntTotalLayer; i++)
		{
			int cntNeuronInPreviousLayer = neuronlayer[i-1].cntNeurons;

			//System.out.println(cntNeuronInPreviousLayer);


			for(int j=0; j<neuronlayer[i].cntNeurons; j++)
			{
				
				neuronlayer[i].neurons[j].z = neuronlayer[i].neurons[j].bias;

				//System.out.println(" neuronlayer[i].neurons[j].z = " + neuronlayer[i].neurons[j].z);

				for(int k=0; k<cntNeuronInPreviousLayer; k++)
				{
					neuronlayer[i].neurons[j].z += (neuronlayer[i].neurons[j].weightVector[k] * neuronlayer[i-1].neurons[k].y  );
					//System.out.println("ager dhaper man = " +neuronlayer[i-1].neurons[k].y);
				}

				//System.out.println(neuronlayer[i].neurons[j].z);


				neuronlayer[i].neurons[j].y = sigmoid(neuronlayer[i].neurons[j].z);

			}
		}
	}


	public void BackPropagate(double x[], double t[], double learningRate)
	{
		for(int i=0; i<neuronlayer[0].cntNeurons; i++)
		{
			neuronlayer[0].neurons[i].y = x[i];
		}

		feedForward(x);

		int layerId = cntTotalLayer - 1; //last layer

		for(int i=0; i<neuronlayer[layerId].cntNeurons; i++)
		{
			neuronlayer[layerId].neurons[i].delta = neuronlayer[layerId].neurons[i].y*(1 - neuronlayer[layerId].neurons[i].y)*(t[i] - neuronlayer[layerId].neurons[i].y); ///y or z...
		}

		for(int layer=layerId-1; layer>0; layer--)
		{
			for(int h=0; h<neuronlayer[layer].cntNeurons; h++)
			{
				double sum = 0;
				layerId = layer + 1; //next Layer


				for(int k=0; k<neuronlayer[layerId].cntNeurons; k++)
				{
					sum += neuronlayer[layerId].neurons[k].delta * (neuronlayer[layerId].neurons[k].weightVector[h]);
				}


				neuronlayer[layer].neurons[h].delta = neuronlayer[layer].neurons[h].y * (1.0 - neuronlayer[layer].neurons[h].y)*sum;
			}
		}

		for(int layer= cntTotalLayer-1; layer > 0; layer--)
		{
			for(int h = 0; h<neuronlayer[layer].cntNeurons; h++)
			{
				for(int k=0; k<neuronlayer[layer].neurons[h].cntInEdges; k++)
				{
					neuronlayer[layer].neurons[h].weightVector[k] += learningRate * neuronlayer[layer].neurons[h].delta * neuronlayer[layer-1].neurons[k].y; ///changed here 
				}


				neuronlayer[layer].neurons[h].bias += learningRate * neuronlayer[layer].neurons[h].delta * 1;


			}
		}


	}



	public double sigmoid(double num)
	{
		return 1.0/(1.0 + Math.exp(-num));
	}


}

class abc
{
	public static void main(String args[])
	{
		double x[] = new double[3];
		x[0] = 100;
		x[1] = 100;
		x[2] = 100;

		double t[] = new double[1];
		t[0] = 0;



		NeuralNetwork nn = new NeuralNetwork();
		nn.init(3, 1, 1, 2);

		for(int tt=0; tt<1000000; tt++)
		{
			nn.BackPropagate(x, t, 0.1);
		}

		nn.feedForward(x);
		System.out.println(nn.neuronlayer[2].neurons[0].y);
		System.out.println(nn.neuronlayer[2].neurons[0].weightVector[0]);


	}
	
}

