import java.util.Arrays;

public class Tree2D<T extends Comparable<T>> extends KdTree<T> {
    
    public Tree2D() {
        super(2);
    }

    public void insert(T x, T y) {
        insert(Arrays.asList(x, y));
    }

    public boolean search(T x, T y) {
        return search(Arrays.asList(x, y));
    }
}