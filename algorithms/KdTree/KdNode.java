import java.util.Arrays;
import java.util.List;

public class KdNode<T extends Comparable<T>> extends KdPoint<T> {

    public KdNode<T> left;

    public KdNode<T> right;
    
    public KdNode(List<T> point, int dimension) {
        super(point, dimension);
        this.left = null;
        this.right = null;
    }

    public KdNode(List<T> point) {
        this(point, point.size());
    }

    public T get(int axis) {
        return point.get(axis % dimension);
    }

    public boolean isSame(KdNode<T> other) {
        if (getDimension() != other.getDimension()) {
            return false;
        }
        for (int i = 0; i < this.dimension; i++) {
            System.out.printf("comparing %s and %s.%n", get(i), other.get(i));
            if (!get(i).equals(other.get(i))) {
                return false;
            }
        }
        return true;
    }

//     @Override public boolean equals(Object o) {
//         if (this == o) {
//             return true;
//         }
//         if ((o == null) || (getClass() != o.getClass())) {
//             return false;
//         }
//         KdNode<T> other = (KdNode<T>) o;
//         if (point != null ? !Arrays.deepEquals(point, other.point) : other.point != null) {
//             return false;
//         }
//         return true;
//     }

//     @Override public int hashCode() {
//         final int prime = 31;
//         int result = 17;
//         result = prime * result + (point == null ? 0 : point.hashCode());
//         return result;
//     }
}