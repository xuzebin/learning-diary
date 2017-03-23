import java.util.Arrays;
import java.util.List;

public abstract class KdPoint<T extends Comparable<T>> {

    public final List<T> point;
    
    protected final int dimension;

    protected KdPoint(List<T> point, int dimension) {
        if (dimension != point.size()) {
            throw new IllegalArgumentException(String.format("Point's size should be same as dimension: %s", dimension));
        }
        this.point = point;
        this.dimension = dimension;
    }

    protected KdPoint(List<T> point) {
        this.point = point;
        this.dimension = point.size();
    }

    public int getDimension() {
        return dimension;
    }

    @Override public String toString() {
        return point.toString();
    }
 }