import java.util.*;

class Main {
  private static boolean[][][] visit = new boolean[5][5][5];
  private static boolean[][][] cube = new boolean[5][5][5];
  private static boolean[][][] origin = new boolean[5][5][5];
  private static int[][] seq = new int[120][5];
  private static int seqIdx = 0;
  private static int[] seqTemp = new int[5];
  private static boolean[] used = new boolean[5];

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int input;
    int cnt = -1;
    for (int k = 0; k < 5; k++) {
      for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
          input = sc.nextInt();
          if (input == 1)
            origin[i][j][k] = true; 
          else
            origin[i][j][k] = false;
        }
      }
    }
    setSeq();
    Queue<Pos> q = new LinkedList<Pos>();
    Pos cur;
    Pos temp;
    int[] dx = {1, 0, -1, 0, 0, 0};
    int[] dy = {0, 1, 0, -1, 0, 0};
    int[] dz = {0, 0, 0, 0, 1, -1};
    int nx, ny, nz;

    for (int a = 0; a < 4; a++) {
      for (int b = 0; b < 4; b++) {
        for (int c = 0; c < 4; c++) {
          for (int d = 0; d < 4; d++) {
            for (int e = 0; e < 4; e++) {
              for (int s = 0; s < 120; s++) {
                shuffleCube(seq[s][0], seq[s][1], seq[s][2], seq[s][3], seq[s][4]);
                if (cube[0][0][0] == false || cube[4][4][4] == false) continue;
                resetVisit();
                cur = new Pos(0, 0, 0, 0);
                q.offer(cur);
                visit[0][0][0] = true;
                while (!q.isEmpty()) {
                  cur = q.peek();
                  q.poll();
                  if (cur.x == 4 && cur.y == 4 && cur.z == 4) {
                    if (cnt == -1 || cnt > cur.step)
                      cnt = cur.step;
                    continue;
                  }
                  for (int i = 0; i < 6; i++) {
                    nx = cur.x + dx[i];
                    ny = cur.y + dy[i];
                    nz = cur.z + dz[i];
                    if (nx < 0 || ny < 0 || nz < 0 || nx >= 5 || ny >= 5 || nz >= 5) continue;
                    if (visit[nx][ny][nz] || cube[nx][ny][nz] == false) continue;
                    visit[nx][ny][nz] = true;
                    temp = new Pos(nx, ny, nz, cur.step + 1);
                    q.offer(temp);
                  }
                }
              }
              rotCube(0);
            }
            rotCube(1);
          }
          rotCube(2);
        }
        rotCube(3);
      }
      rotCube(4);
    }
    System.out.println(cnt);
  }

  public static void resetVisit() {
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        for (int l = 0; l < 5; l++)
          visit[i][j][l] = false;
      }
    }
  }

  public static void rotCube(int idx) {
    boolean[][] temp = new boolean[5][5];
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        temp[i][j] = origin[j][5 - i - 1][idx];
      }
    }
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        origin[i][j][idx] = temp[i][j];
      }
    }
  }

  public static void shuffleCube(int a, int b, int c, int d, int e) {
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        cube[i][j][0] = origin[i][j][a];
        cube[i][j][1] = origin[i][j][b];
        cube[i][j][2] = origin[i][j][c];
        cube[i][j][3] = origin[i][j][d];
        cube[i][j][4] = origin[i][j][e];
      }
    }
  }

  public static void setSeq() {
    for (int i = 0; i < 5; i++) {
      used[i] = true;
      seqTemp[0] = i;
      dfs(1);
      used[i] = false;
    }
  }

  public static void dfs(int cnt) {
    if (cnt == 5) {
      for (int i = 0; i < 5; i++)
        seq[seqIdx][i] = seqTemp[i];
      seqIdx++;
      return ;
    }
    for (int i = 0; i < 5; i++) {
      if (used[i])
        continue;
      used[i] = true;
      seqTemp[cnt] = i;
      dfs(cnt + 1);
      used[i] =false;
    }
  }

  public static class Pos {
    public int x;
    public int y;
    public int z;
    public int step;
    public Pos(int a, int b, int c, int d) {
      x = a;
      y = b;
      z = c;
      step = d;
    }
    public Pos() {}
  }
}