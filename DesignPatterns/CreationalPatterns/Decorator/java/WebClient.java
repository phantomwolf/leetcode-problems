import java.net.*;
import java.io.*;

public interface WebClient {
    public void get(String url) throws MalformedURLException, IOException, ProtocolException;
}
