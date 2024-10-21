// Problem name: Class Picture
// Solved by: Kamal

import java.util.*;

public class classpicture {

    static boolean[] visited;

    public static boolean solve(List<List<Integer>> graph, int node, List<Integer> order) {
        for (int neighbor : graph.get(node)) {
            if (!order.isEmpty() && order.get(order.size() - 1) == neighbor) {
                return false;
            }
        }
        visited[node] = true;
        order.add(node);
        if (order.size() == graph.size()) {
            return true;
        }
        for (int i = 0; i < graph.size(); i++) {
            if (visited[i]) {
                continue;
            }
            if (solve(graph, i, order)) {
                return true;
            }
        }
        visited[node] = false;
        order.remove(order.size() - 1);
        return false;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            List<String> names = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                names.add(scanner.next());
            }
            Collections.sort(names); // Sort names

            Map<String, Integer> idMap = new HashMap<>();
            for (int i = 0; i < n; i++) {
                idMap.put(names.get(i), i);
            }

            List<List<Integer>> graph = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                graph.add(new ArrayList<>());
            }

            int m = scanner.nextInt();
            for (int i = 0; i < m; i++) {
                String a = scanner.next();
                String b = scanner.next();
                int u = idMap.get(a);
                int v = idMap.get(b);
                graph.get(u).add(v);
                graph.get(v).add(u); // Undirected graph
            }

            visited = new boolean[n];
            boolean foundOrder = false;
            for (int i = 0; i < n; i++) {
                List<Integer> order = new ArrayList<>();
                if (solve(graph, i, order)) {
                    for (int student : order) {
                        System.out.print(names.get(student) + " ");
                    }
                    foundOrder = true;
                    break;
                }
            }

            if (!foundOrder) {
                System.out.println("You all need therapy.");
            }
            System.out.println();
        }
        scanner.close();
    }
}
