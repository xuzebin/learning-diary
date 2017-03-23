import java.util.List;

public class KdTree<T extends Comparable<T>> {

    protected KdNode<T> root;
    
    private final int dimension;

    public KdTree(int dimension) {
        this.dimension = dimension;
    }

    public int getDimension() {
        return dimension;
    }

    public void insert(List<T> point) {
        if (point.size() != this.dimension) {
            throw new IllegalArgumentException(String.format("Point's size should be same as dimension: %s", this.dimension));
        }
        System.out.printf("Inserting point %s...%n", point);
        this.root = insert(this.root, point, 0);
    }

    private KdNode<T> insert(KdNode<T> cur, List<T> point, int depth) {
        if (cur == null) {
            return new KdNode<T>(point);
        }
        int axis = depth % getDimension();
        if (point.get(axis).compareTo(cur.get(axis)) < 0) {
            cur.left = insert(cur.left, point, depth + 1);
        } else {
            cur.right = insert(cur.right, point, depth + 1);
        }
        return cur;
    }

    public boolean search(List<T> point) {
        System.out.printf("Search point %s...%n", point);
        return search(this.root, point, 0);
    }

    private boolean search(KdNode<T> cur, List<T> point, int depth) {
        if (cur == null) {
            return false;
        }
        if (cur.isSame(new KdNode<T>(point))) {
            System.out.println("same point");
            return true;
        }
        int axis = depth % getDimension();
        if (point.get(axis).compareTo(cur.get(axis)) < 0) {
            return search(cur.left, point, depth + 1);
        } else {
            return search(cur.right, point, depth + 1);
        }
    }
    
}