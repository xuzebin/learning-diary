# Detecting Arbitrary Oriented Text in the Wild with a Visual Attention Model

## Curriculum Learning
    - Start with easy examples: train text with length of 2 first. Increase the length of text to be trained until the average loss drops to an acceptable range (< 9, i.e. 3 pixels away from the ground truth).
    - Stop moving forward and start back-propagation when the current predicted center (average loss) is far from the ground truth.
