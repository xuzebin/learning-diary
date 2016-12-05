## Neural Networks Part 2: Setting up the Data and the Loss

### Setting up the Data and the Model

#### Data Prepocessing
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



