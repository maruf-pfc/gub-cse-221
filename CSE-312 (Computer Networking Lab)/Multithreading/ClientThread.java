import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.Socket;
import java.util.Scanner;

public class ClientThread {
    public static void main(String[] args) {
        try{
            Socket clientsocket = new Socket ("localhost", 5000);
            System.out.println("Connected at server Handshaking port " + clientsocket.getPort());
            System.out.println("Client is connecting at Communication Port " + clientsocket.getLocalPort());
            System.out.println("Client is Connected");

            Scanner sc = new Scanner(System.in);
            DataOutputStream dos = new DataOutputStream(clientsocket.getOutputStream());
            DataInputStream dis = new DataInputStream(clientsocket.getInputStream());

            while(true){
                String inLine = dis.readUTF();
                System.out.println(inLine);
                String outLine = sc.nextLine();
                dos.writeUTF(outLine);

                if(outLine.equals("yes")){
                    System.out.println("Closing the connecting "+ clientsocket);
                    clientsocket.close();
                    System.out.println("Connection Closed");
                    break;
                }
                String received = dis.readUTF();
                System.out.println(received);

                String in = sc.nextLine();
                dos.writeUTF(in);

                String receivedtime = dis.readUTF();
                System.out.println(receivedtime);
            }
            dos.close();
            dis.close();
            clientsocket.close();
        }catch (Exception err){
            System.out.println(err);
        }
    }
}
