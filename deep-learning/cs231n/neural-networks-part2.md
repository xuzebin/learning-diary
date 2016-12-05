# Neural Networks Part 2: Setting up the Data and the Loss

## Setting up the Data and the Model

### Data Prepocessing
There are 3 common forms of data prepocessing a data matrix **X**, where we assume that **X** is of size `[N x D]` (`N` is the number of data, `D` is their dimensionality).

* **Mean subtraction** 
    - subtract the mean across every individual *feature* in the data. The geometric interpretation is to center the cloud of data around the *origin* along every dimension.
    - In numpy, it is implemented as: `X -= np.mean(X, axis = 0)`.
    - For images, subtract a single value from all pixels (or to do so across the 3 color channels): `X -= np.mean(X)`.

* **Normalization**
    - normalizing the data dimensions so that they are of approximately the same scale.
    - 2 ways:
        - divide each dimension by its *standard deviation*, once it has been *zero-centered*: `X /= np.std(X, axis = 0)`
        - normalize each dimension so that the *min* and *max* along the dimension is -1 and 1 respectively. (Only make sense to apply if different input features have different scales, but they should be of approximately equal importance to the learning algorithm.

![](img/preprocessing1.jpeg)

* **PCA and Whitening** (PCA: Principal Component Analysis)
    - The data is first centered.
    - Then compute the *covariance matrix* that tells us about the correlation structure in the data.

```python
# Assume input data matrix X of size [N x D]
X -= np.mean(X, axis = 0) # zero-center the data (important)
cov = np.dot(X.T, X) / X.shape[0] # get the data covariance matrix
```

//TODO currently skip the middle sections


### Regularization (L2/L1/Maxnorm/Dropout)
* **L2 Regularization**

* **L1 Regularization**

* **Max norm constraints**

* **[Dropout](http://www.cs.toronto.edu/~rsalakhu/papers/srivastava14a.pdf)**
    - only keeping a neuron active with some probability **p** (a hyperparameter), or setting it to zero otherwise.

![](img/dropout.jpeg)

Dropout can be interpreted as **sampling** a Neural Network within the full Neural Network, and only updating the parameters of the sampled network based fon the input data.

Dropout implementation in an example 3-layer Neural Network:
```python
""" Vanilla Dropout: Not recommended implementation (see notes below) """

p = 0.5 # probability of keeping a unit active. higher = less dropout

def train_step(X):
  """ X contains the data """
  
  # forward pass for example 3-layer neural network
  H1 = np.maximum(0, np.dot(W1, X) + b1)
  U1 = np.random.rand(*H1.shape) < p # first dropout mask
  H1 *= U1 # drop!
  H2 = np.maximum(0, np.dot(W2, H1) + b2)
  U2 = np.random.rand(*H2.shape) < p # second dropout mask
  H2 *= U2 # drop!
  out = np.dot(W3, H2) + b3
  
  # backward pass: compute gradients... (not shown)
  # perform parameter update... (not shown)
  
def predict(X):
  # ensembled forward pass
  H1 = np.maximum(0, np.dot(W1, X) + b1) * p # NOTE: scale the activations
  H2 = np.maximum(0, np.dot(W2, H1) + b2) * p # NOTE: scale the activations
  out = np.dot(W3, H2) + b3
```

The undesirable property of the scheme above is that we scale the activations by **p** at *test time*. For test-time performance, it is preferable to use **inverted dropout**, which performs scaling at train time.

Inverted dropout looks as follows:
```python
""" 
Inverted Dropout: Recommended implementation example.
We drop and scale at train time and don't do anything at test time.
"""

p = 0.5 # probability of keeping a unit active. higher = less dropout

def train_step(X):
  # forward pass for example 3-layer neural network
  H1 = np.maximum(0, np.dot(W1, X) + b1)
  U1 = (np.random.rand(*H1.shape) < p) / p # first dropout mask. Notice /p!
  H1 *= U1 # drop!
  H2 = np.maximum(0, np.dot(W2, H1) + b2)
  U2 = (np.random.rand(*H2.shape) < p) / p # second dropout mask. Notice /p!
  H2 *= U2 # drop!
  out = np.dot(W3, H2) + b3
  
  # backward pass: compute gradients... (not shown)
  # perform parameter update... (not shown)
  
def predict(X):
  # ensembled forward pass
  H1 = np.maximum(0, np.dot(W1, X) + b1) # no scaling necessary
  H2 = np.maximum(0, np.dot(W2, H1) + b2)
  out = np.dot(W3, H2) + b3
```

    

