import java.io.*;
import java.net.*;

class Prog10C
{
	public static void main(String args[]) throws Exception
	{
		DatagramSocket socket = new DatagramSocket();
		BufferedReader inFromUser = new BufferedReader(new InputStreamReader(System.in));
		byte send[] = new byte[1024];
		byte receive[] = new byte[1024];
		InetAddress IPAddress = InetAddress.getByName("localhost");
		int port = 9876;
		
		send = "Sending initial msg from C to S".getBytes();
		DatagramPacket sendPacket = new DatagramPacket(send, send.length, IPAddress, port);
		socket.send(sendPacket);

		System.out.println("Receiving from Server : ");
		while(true)
		{
      receive = new byte[1024];
      DatagramPacket receivePacket = new DatagramPacket(receive, receive.length);
			socket.receive(receivePacket);
			String msg = new String(receivePacket.getData());
			System.out.println(msg);
		}
	}
}