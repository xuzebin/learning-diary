# Recurrent Neural Networks

## Why Recurrent Neural Networks?

### Feed-Forward Networks:

- input size must be fixed.
- different inputs are independent.

### RNN:

- input size can be variable.
- inputs can have temporal dependencies (e.g. a sequence of words in a sentence).

## How RNN works

- We can unroll a recurrent network into a feed-forward network.

![](img/rnn_unfold.jpg)

## RNN: What is it Good for ?

- Learning Sequences: predict the next input of a sequence.
    - speech
    - actions in video
    - video summarization
    - music recognition
    - forcasting: weather, markets, politics