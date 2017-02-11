# A Collecion of Concise Alternative APIs for Java

```
List<List<Integer>> list = new LinkedList<>();

// Very often, we need to do the following:
// Create a sublist with some elements and add it to the list.
List<Integer> subList = new ArrayList<>(3);
subList.add(1);
subList.add(2);
subList.add(3);
list.add(subList);

//A concise alternative:
list.add(Arrays.asList(1, 2, 3));
```

