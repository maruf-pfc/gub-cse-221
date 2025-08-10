import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    public static void main(String[] args) throws IOException{
        int port = 5000;
        ServerSocket sc = new ServerSocket(port);
        System.out.println("Server is connected at port " + port);

        System.out.println("Server is connecting");
        System.out.println("Waiting for the client");

        Socket s = sc.accept();
        System.out.println("Client request is accepted at port: " + s.getLocalPort());

        System.out.println("Server's Communication Port: " + s.getLocalPort());
        DataInputStream input = new DataInputStream(s.getInputStream());

        String str = "";
        while(!str.equals("stop")){
            str = input.readUTF();
            System.out.println("Client Says: " + str);
        }

        s.close();
        input.close();
        // sc.close();
    }
}
