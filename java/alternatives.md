# A Collecion of Concise Alternative APIs for Java

```java
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

//Note that Arrays.asList returns a fix-sized list which is unmodifiable.
//It means that you can't add or remove to the list.
//If you might add or remove element, an alternative can be:
list.add(new LinkedList<>(Arrays.asList(1, 2, 3)));
```

