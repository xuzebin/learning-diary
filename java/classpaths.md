# Classpath problems

Given two files:

main/src/java/edu/nyu/cs9053/Book.java

main/lib/java/com/example/Chaptor.java

```java
package com.example;
public class Chapter {
     public String getName() {
          return “Moby”;
    }
}
```

```java
package edu.nyu.cs9053;
import com.example.Chapter;

public class Book {
     public static void main(String[] args) {
          Chapter chapter = new Chapter();
          System.out.printf(“Chapter name: %s%n”, chapter.getName());
     }
}
```


### under main/ directory
* **compile java Files: Book.java and Chapter.java**
    
```
javac src/java/edu/nyu/cs9053/Book.java lib/java/com/example/Chapter.java
```
* **compile java File and class file: Book.java and Chapter.class**

main/src/java/edu/nyu/cs9053/Book.java

main/lib/java/com/example/Chapter.class

```
javac -cp lib/java/ src/java/edu/nyu/cs9053/Book.java
```

* **compile java file and jar file: Book.java and ChapterHelper.jar** (inside jar: com/example/Chapter.class) 

main/src/java/edu/nyu/cs9053/Book.java

main/lib/java/ChapterHelper.jar

```
javac -cp lib/java/ChapterHelper.jar src/java/edu/nyu/cs9053/Book.java
```
* **Run two class files**

main/src/java/edu/nyu/cs9053/Book.class

main/lib/java/com/example/Chapter.class

```
java -cp src/java/:lib/java/ edu.nyu.cs9053.Book
```
* **Run one class file that is dependent on another jar file**

main/src/java/edu/nyu/cs9053/Book.class

main/lib/java/ChapterHelper.jar

```
java -cp src/java/:lib/java/ChapterHelper.jar edu.nyu.cs9053.Book
```