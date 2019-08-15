public class LogDecorator extends Decorator {
    public LogDecorator(WebClient client) {
        super(client);
    }

    @Override
    public void get(String url) {
        System.out.printf("GET %s\n", url);
        super.get(url);
    }
}
