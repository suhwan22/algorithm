import java.util.*;

@SuppressWarnings("unchecked")
class Main {

  static int cnt = 1;
  static boolean visit[][][];
  static boolean board[][];
  static ArrayList<Pos>[][] input;

  public static void main(String[] arg) {
    Scanner sc = new Scanner(System.in);
    int n, m;
    n = sc.nextInt();
    visit = new boolean[n*n+1][n+1][n+1];
    board = new boolean[n+1][n+1];
    input = new ArrayList[101][101];
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        input[i][j] = new ArrayList<Pos>();
      }
    }
    m = sc.nextInt();
    int x1, y1, x2, y2;
    for (int i = 0; i < m; i++) {
      x1 = sc.nextInt();
      y1 = sc.nextInt();
      x2 = sc.nextInt();
      y2 = sc.nextInt();
      Pos temp = new Pos(x2, y2);
      input[x1][y1].add(temp);
    }
    visit[0][1][1] = true;
    board[1][1] = true;
    Queue<Pos> q = new LinkedList<>();
    Pos cur = new Pos(1, 1);
    q.offer(cur);
    int[] dx = {1, 0, -1, 0};
    int[] dy = {0, 1, 0, -1};
    int nx, ny;
    Pos temp;
    while (!q.isEmpty()) {
      cur = q.peek();
      q.poll();
      for (Pos e : input[cur.x][cur.y]) {
        if (board[e.x][e.y] == false) {
          cnt++;
          board[e.x][e.y] = true;
        }
      }
      for (int i = 0; i < 4; i++) {
        nx = cur.x + dx[i];
        ny = cur.y + dy[i];
        if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
        if (board[nx][ny] == false || visit[cnt][nx][ny]) continue;
        visit[cnt][nx][ny] = true;
        temp = new Pos(nx, ny);
        q.offer(temp);
      }
    }
    System.out.println(cnt);
  }

  public static class Pos {
    public int x;
    public int y;
    public Pos(int a, int b) {
      x = a;
      y = b;
    }
    public Pos() {}
  }
}