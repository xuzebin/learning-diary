## Enum


Look at this code:
```java
enum Country {
    China,
    UnitedStates,
    Canada,
    India
}

Country[] countries = Country.values();
    
```

The method `values()` is not stated in the Java documentation of **Enum**.

**Enum** has implicitly declared methods:  (From [jls](http://docs.oracle.com/javase/specs/jls/se7/html/jls-8.html#jls-8.9.2))

```java
/**
* Returns an array containing the constants of this enum 
* type, in the order they're declared.  This method may be
* used to iterate over the constants as follows:
*
*    for(E c : E.values())
*        System.out.println(c);
*
* @return an array containing the constants of this enum 
* type, in the order they're declared
*/
public static E[] values();

/**
* Returns the enum constant of this type with the specified
* name.
* The string must match exactly an identifier used to declare
* an enum constant in this type.  (Extraneous whitespace 
* characters are not permitted.)
* 
* @return the enum constant with the specified name
* @throws IllegalArgumentException if this enum type has no
* constant with the specified name
*/
public static E valueOf(String name);
```

**What if we define an empty Enum ?**

For example:
```java
enum Country {}
```    

It compiles. But what if we call its static method `values()`?


It does not return a `null`. Instead, it returns an **empty array**.



