import java.util.List;
import java.util.Arrays;

public class Test {
    public static void main(String[] args) {
        //Test KdNode
        List<Integer> p = Arrays.asList(1, 2);
        KdNode<Integer> node = new KdNode<>(p, 2);
        KdNode<Double> dnode = new KdNode<>(Arrays.asList(3.2, 4.1), 2);
        KdNode<Double> dnode3 = new KdNode<>(Arrays.asList(3.2, 4.1, 5.3), 3);
        
        System.out.println(node);
        System.out.println(dnode);
        System.out.println(dnode3);

        //Test KdNodeFactory
        System.out.println(KdNodeFactory.createNode2dInt(3, 4));
        System.out.println(KdNodeFactory.createNode3dInt(3, 4, 5));
        System.out.println(KdNodeFactory.createNode2dDouble(3.0, 4.1));
        System.out.println(KdNodeFactory.createNode3dDouble(3.1, 4.2, 5d));


        KdTree<Double> tree = new KdTree<>(2);
        tree.insert(Arrays.asList(3d, 4d));
        tree.insert(Arrays.asList(7.2, 5.1));
        tree.insert(Arrays.asList(6.3, 4.8));
        tree.insert(Arrays.asList(-1d, -2.3));
        System.out.println(tree.search(Arrays.asList(6.3, 4.8)));
        System.out.println(tree.search(Arrays.asList(6.3, 4.7)));


        Tree2D<Double> tree2 = new Tree2D<>();
        tree2.insert(3d, 4d);
        tree2.insert(7.2, 5.1);
        tree2.insert(6.3, 4.8);
        tree2.insert(1d, -2.3);
        System.out.println(tree2.search(6.3, 4.8));
        System.out.println(tree2.search(6.3, 9d));
    }
}