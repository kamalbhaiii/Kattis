// Problem name: 10 Kinds of People
// @author Kamal
// Method: Breadth-First Search (BFS) with Flood Fill algorithm
// Status: Accepted
// Run-time: 0.68s

import java.util.*;

public class Tenkindsofpeople {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            sc.nextLine(); // Consume the newline character after integers

            String[] map = new String[n];
            int[][] color = new int[n][m];
            for (int i = 0; i < n; i++) {
                map[i] = sc.nextLine();
                Arrays.fill(color[i], -1); // Initialize color array with -1
            }

            int currentColor = 0;
            int[] dx = { -1, 1, 0, 0 }; // Directions for row movement (up, down)
            int[] dy = { 0, 0, -1, 1 }; // Directions for column movement (left, right)

            // BFS to color each connected component
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (color[i][j] == -1) {
                        currentColor++;

                        Queue<Integer> qx = new LinkedList<>();
                        Queue<Integer> qy = new LinkedList<>();

                        qx.add(i);
                        qy.add(j);

                        while (!qx.isEmpty()) {
                            int x = qx.poll();
                            int y = qy.poll();

                            color[x][y] = currentColor;

                            for (int k = 0; k < 4; k++) {
                                int nx = x + dx[k];
                                int ny = y + dy[k];

                                if (nx < 0 || ny < 0 || nx >= n || ny >= m || color[nx][ny] != -1
                                        || map[nx].charAt(ny) != map[i].charAt(j)) {
                                    continue;
                                }

                                color[nx][ny] = currentColor;
                                qx.add(nx);
                                qy.add(ny);
                            }
                        }
                    }
                }
            }

            int queries = sc.nextInt();

            // Process each query
            for (int q = 0; q < queries; q++) {
                int sx = sc.nextInt() - 1; // Source row (convert to 0-indexed)
                int sy = sc.nextInt() - 1; // Source column (convert to 0-indexed)
                int fx = sc.nextInt() - 1; // Target row (convert to 0-indexed)
                int fy = sc.nextInt() - 1; // Target column (convert to 0-indexed)

                if (color[sx][sy] != color[fx][fy]) {
                    System.out.println("neither");
                } else if (map[sx].charAt(sy) == '0') {
                    System.out.println("binary");
                } else {
                    System.out.println("decimal");
                }
            }
        }
        sc.close();
    }
}