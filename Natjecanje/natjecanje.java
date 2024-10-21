// Problem name: Natjecanje
// Solved by: Kamal

import java.util.*;

public class natjecanje {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int s = sc.nextInt();
        int r = sc.nextInt();

        Set<Integer> missing = new HashSet<>();
        Set<Integer> reserve = new HashSet<>();

        for (int i = 0; i < s; i++) {
            missing.add(sc.nextInt());
        }

        for (int i = 0; i < r; i++) {
            reserve.add(sc.nextInt());
        }

        for (int i = 1; i <= n; i++) {
            if (missing.contains(i)) {
                if (i > 1 && reserve.contains(i - 1)) {
                    reserve.remove(i - 1);
                    missing.remove(i);
                } else if (i < n && reserve.contains(i + 1)) {
                    reserve.remove(i + 1);
                    missing.remove(i);
                }
            }
        }

        System.out.println(missing.size());
    }
}