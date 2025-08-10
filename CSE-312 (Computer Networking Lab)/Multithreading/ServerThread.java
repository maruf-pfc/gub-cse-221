import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerThread {
    public static void main(String[] args) throws IOException {
        ServerSocket handshake = new ServerSocket(5000);
        System.out.println("Server Connected at " + handshake.getLocalPort());
        System.out.println("Server is Connected");
        System.out.println("Wait for the client");

        // 1. For Unlimited Client --> while(true)
        // 2. For Limited Client -->
        // int totalClient = 10;
        // while(totalClient --> 0)
        while(true){
            Socket con_socket = handshake.accept();
            System.out.println("A new client is connected " + con_socket);
            DataOutputStream dos = new DataOutputStream(con_socket.getOutputStream());
            DataInputStream dis = new DataInputStream(con_socket.getInputStream());
            System.out.println("A new thread is assigning...");
            Thread new_tunnel = new ClientHandler(con_socket, dis, dos);
            new_tunnel.start();
        }
    }
}