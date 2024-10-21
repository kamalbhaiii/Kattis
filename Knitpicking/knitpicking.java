// Problem name: Knitpicking
// Solved by: Kamal

import java.util.*;

public class knitpicking {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<String, Integer> mp = new HashMap<>();
        long[][] v = new long[6005][3];
        int cnt = 0;

        for (int i = 1; i <= n; i++) {
            String s1 = sc.next();
            String s2 = sc.next();
            long x = sc.nextLong();
            if (!mp.containsKey(s1)) mp.put(s1, ++cnt);
            int tt = mp.get(s1);
            if (s2.equals("any")) v[tt][0] = x;
            else if (s2.equals("left")) v[tt][1] = x;
            else v[tt][2] = x;
        }

        boolean f = false;
        for (int i = 1; i <= cnt; i++) {
            if (v[i][0] >= 2 || (v[i][0] != 0 && (v[i][1] != 0 || v[i][2] != 0)) || (v[i][1] != 0 && v[i][2] != 0)) {
                f = true;
                break;
            }
        }
        if (!f) {
            System.out.println("impossible");
            return;
        }

        long ans = 0;
        for (int i = 1; i <= cnt; i++) {
            if (v[i][0] != 0 && v[i][1] == 0 && v[i][2] == 0) {
                ans++;
            } else if (v[i][1] != 0 || v[i][2] != 0) {
                ans += Math.max(v[i][1], v[i][2]);
            }
        }
        System.out.println(ans + 1);
    }
}
