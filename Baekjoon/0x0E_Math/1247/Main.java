import java.util.*;
import java.math.*;

class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        for (int j = 0; j < 3; j++) {
            int n = sc.nextInt();
            String temp;
            BigDecimal sum = new BigDecimal("0");
            for (int i = 0; i < n; i++) {
                temp = sc.next();
                sum = sum.add(new BigDecimal(temp));
            }
            int comp = sum.compareTo(new BigDecimal ("0"));
            if (comp == 0) {
                System.out.println("0");      
            } else if (comp > 0) {
                System.out.println("+");
            } else {
                System.out.println("-");
            }
        }
    }
}