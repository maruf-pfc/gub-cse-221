import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.URL;

public class POSTMethod {
    public static void main(String[] args) throws IOException {
        // opening the connection to a URL webpage where we can post
        URL myUrl = new URL("https://jsonplaceholder.typicode.com/posts/");
        HttpURLConnection conn = (HttpURLConnection) myUrl.openConnection();
        // setting the method for this connection
        conn.setRequestMethod("POST");
        conn.setDoOutput(true);
        OutputStream out = conn.getOutputStream();
        String postedString = "Hello World!";
        out.write(postedString.getBytes());

        int responseCode = conn.getResponseCode();
        System.out.println("Response Code: " + responseCode);
        System.out.println("Response Message: " + conn.getResponseMessage());

        if(responseCode == HttpURLConnection.HTTP_CREATED){
            BufferedReader read = new BufferedReader(new InputStreamReader(conn.getInputStream()));
            StringBuffer str = new StringBuffer();
            String store = null;

            while((store = read.readLine()) != null){
                str.append(store);
            }
            read.close();
            System.out.println("GET Response: " + str.toString());
        }
    }
}