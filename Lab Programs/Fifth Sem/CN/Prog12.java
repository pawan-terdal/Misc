import java.util.*;

/**
 * Prog12
 */
public class Prog12 {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    System.out.print("Enter queue limit: ");
    int queueLimit = in.nextInt();
    System.out.print("Enter link speed: ");
    int linkSpeed = in.nextInt();
    System.out.print("Enter number of packets: ");
    int n = in.nextInt();
    System.out.print("Enter packet size for each packet: ");
    int currQ = 0;
    int[] packets = new int[n];
    for(int i = 0; i < n; i++)
      packets[i] = in.nextInt();
    System.out.println("Qstatus\tPktSize\tQStatus\tDropped\tSent\tQStatus");
    for(int packet: packets)
    {
      System.out.print(currQ + "\t");
      System.out.print(packet + "\t");
      int dropped = 0;
      if(currQ + packet > queueLimit) {
        dropped = (currQ + packet) - queueLimit;
        currQ = queueLimit;
      }
      else {
        currQ += packet;
      }
      System.out.print(currQ + "\t");
      System.out.print(dropped + "\t");
      int sent = linkSpeed;
      if(currQ - linkSpeed < 0) {
        sent = currQ;
        currQ = 0;
      }
      else {
        currQ -= linkSpeed;
      }
      System.out.print(sent + "\t");
      System.out.println(currQ + "\t");
    }
  }  
}