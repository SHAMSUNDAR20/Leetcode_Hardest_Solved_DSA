public class Solution {
    public Node Connect(Node root) {
        if (root == null) return null;
        Queue<Node> queue = new Queue<Node>();
        queue.Enqueue(root);
        while (queue.Count > 0) {
            int size = queue.Count;
            for (int i = 0; i < size; i++) {
                Node node = queue.Dequeue();
                if (i < size - 1) {
                    node.next = queue.Peek();
                }
                if (node.left != null) queue.Enqueue(node.left);
                if (node.right != null) queue.Enqueue(node.right);
            }
        }
        return root;
    }
}