import java.util.*;
//deactivate java:S106

//javac Hello.java && java Hello < t.in
public class Hello {
  public static void main(String[] args) {
      Scanner sn = new Scanner(System.in);

      int cases = sn.nextInt();
      for( int testCase = 0; testCase < cases; testCase++ ) {
        int[] arr = new int[3];
        for( int i = 0; i < 3; i++ ) {
          arr[i] = sn.nextInt();
        }
        Arrays.sort(arr);
        System.out.println(arr[0]+arr[1] == arr[2] ? "YES" : "NO");//NOSONAR
      }

      sn.close();
  }
}