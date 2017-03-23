import java.util.Arrays;

public class KdNodeFactory {

    public static KdNode<Integer> createNode2dInt(Integer...point) {
        return new KdNode<Integer>(Arrays.asList(point), 2);
    }

    public static KdNode<Integer> createNode3dInt(Integer...point) {
        return new KdNode<Integer>(Arrays.asList(point), 3);
    }

    public static KdNode<Double> createNode2dDouble(Double...point) {
        return new KdNode<Double>(Arrays.asList(point), 2);
    }

    public static KdNode<Double> createNode3dDouble(Double...point) {
        return new KdNode<Double>(Arrays.asList(point), 3);
    }
}