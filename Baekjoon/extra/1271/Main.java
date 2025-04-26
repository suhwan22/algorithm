import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigDecimal m = new BigDecimal(sc.next());
		BigDecimal n = new BigDecimal(sc.next());
		System.out.println(m.divide(n, RoundingMode.DOWN));
		System.out.println(m.remainder(n));
	}
}