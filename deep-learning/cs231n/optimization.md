# Optimization
> Optimization is the process of finding the set of parameters **W** that minimize the loss function.

**Content**
* Optimization
    - Strategy 1: Random Search
    - Strategy 2: Random Local Search
    - Strategy 3: Following the Gradient
* Computing the gradient
    - Numerically with finte differences
    - Analytically with calculus
* Gradient descent
* Summary

## Optimization

### Strategy 1: Random Search (bad idea solution)
1. Simply try out many different random weights and keep track of what works best.
2. Iteratively refine them over time to get lower loss.

### Strategy 2: Random Local Search (still computationally expensive)
1. Start with a random **W**, generate random perturbations **deltaW** to it and if the loss at the perturbed **W + deltaW** is lower, perform an update.

### Strategy 3: Following the Gradient
* Compute the best direction along which we should change the weight vector.
* The direction will be related to the **gradient** of the loss function.
    - **Gradient** is a generalization of slop for functions that don't take a single number but a vector of numbers.
    - **Gradient** is just a vector of slopes (derivatives) for each dimension in the input space.
* **Partial derivatives**: takes a vector of numbers instead of a single number. The **gradient** is the vector of **partial derivatives** in each dimension.
* The Gradient tells us:
    - the slope of the loss function along each dimension (by computing the partial derivatives in each dimension).
    - the direction in which the loss function has the steepest rate of *increase*. (The negative gradient tells the direction of the steepeset *decrease* in the loss function.)

* **Step size**: tells how far along the direction we should step. Also called the **learning rate**.
    - Small steps may lead to consistent but slow progress.
    - Large stpes may lead to better progress but may make the loss worse.

## Computing the Gradient
Two ways to compute:
* **numerical gradient**: slow, approximate but easy.
* **analytic gradient**: fast, exact but more error-prone that requires calculus.

### Computing the gradient numerically with finite differences
1. Iterate over all dimensions one by one.
2. In each interation, make s mall change **h** along the dimension and calculates the partial derivatives of the loss function.

**Downsides**
* It is approximate, since we have to pick a small value of **h**, while the true gradient is defined as the limit as **h** goes to zero.
* Not scalable, computationally expensive.

Gotcha:
* In the mathematical formulation, the gradient is defined in the limit as **h** goes towards zero. But in practice it's sufficient to use a very small value (such as 1e-5)
* In practice it works better using the **centered difference formula: [f(x + h) - f(x - h)] / 2h**.


### Computing the gradient analytically with Calculus
* Derive a direct formula for the gradient (no approximations).

**Upside**
* Fast to compute.

**Downside**
* more error prone to implement.

Gotcha:
* **gradient check**
    * compute the *analytic gradient* and compare it to the *numerical gradient* to check the correctness of your implementation.

## Gradient descent
The procedure of repeatedly evaluating the gradient and then performing a parameter update.

```python
while True:
  weights_grad = evaluate_gradient(loss_fun, data, weights)
  weights += - step_size * weights_grad # perform parameter update
```

### Mini-batch gradient descent
* Compute the gradient over **batches** of the training data.
* Each batch is used to perform a parameter update.

For example, a typical batch contains 256 examples from the entire training set of 1.2 million.

```python
while True:
  data_batch = sample_training_data(data, 256) # sample 256 examples
  weights_grad = evaluate_gradient(loss_fun, data_batch, weights)
  weights += - step_size * weights_grad # perform parameter update
```


## Summary

![](img/dataflow.jpeg)

* The dataset of pairs of (x,y) is given and fixed.
* The weights **W** start out as random numbers and can change.
* During the *forward pass* the score function computes class scores, stored in vector **f**.
* The loss function **L** contains 2 components:
    1. The data loss: computes the compatibility between the scores **f** and the labels **y**.
    2. The regularization loss: a function of the weights.
* During Gradient Descent, we compute the gradient on the weights and use them to perform a parameter update.



