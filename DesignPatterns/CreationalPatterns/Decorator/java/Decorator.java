public class Decorator implements WebClient {
    protected WebClient client;

    public Decorator(WebClient client) {
        this.client = client;
    }

    public void get(String url) {
        this.client.Get(url);
    }
}
