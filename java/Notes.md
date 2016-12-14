# Notes

1. When comparing Strings, try to place the constant in the left hand side. For example:
```java
String s = "java";
//prefer    
if ("c".equals(s)) {
//..
}

//not prefer: because s may be null, which will throw NullPointerException.
if (s.equals("c")) {
}        
```
