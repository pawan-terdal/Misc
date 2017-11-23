import java.io.*;
import java.net.*;

class Prog10S
{
	public static void main(String args[]) throws Exception
	{
		DatagramSocket socket = new DatagramSocket(9876);
		byte[] receive = new byte[1024];
		byte[] send = new byte[1024];

    DatagramPacket receivePacket = new DatagramPacket(receive, receive.length);
    socket.receive(receivePacket);
    String recdmsg = new String(receivePacket.getData());
    System.out.println("Received from Client: " + recdmsg);
    InetAddress IPAddress = receivePacket.getAddress();
    int port = receivePacket.getPort();
    
    System.out.println("Type the message to echo at the client side ");
    while(true)
    {
      send = new byte[1024];
      //System.out.println("Type the message to echo at the client side ");
      BufferedReader inFromUser = new BufferedReader(new InputStreamReader(System.in));
      String msg = inFromUser.readLine();
      send = msg.getBytes();
      DatagramPacket sendPacket = new DatagramPacket(send, send.length, IPAddress, port);
      socket.send(sendPacket);
    }
	}
}