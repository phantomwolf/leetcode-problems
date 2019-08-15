import java.lang.*;
import java.util.*;
import java.io.*;
import java.net.*;

public class ConcreteClient implements WebClient {
    public void get(String u) throws MalformedURLException, IOException, ProtocolException {
        URL url = new URL(u);
        HttpURLConnection con = (HttpURLConnection) url.openConnection();
        con.setRequestMethod("GET");
        BufferedReader in = new BufferedReader(new InputStreamReader(con.getInputStream()));
        String inputLine;
        StringBuffer content = new StringBuffer();
        while ((inputLine = in.readLine()) != null) {
            content.append(inputLine);
        }
        in.close();
        System.out.println(content);
    }

    public static void main(String[] args) {
        ConcreteClient c = new ConcreteClient();
        c.get("http://www.baidu.com");
    }
}
