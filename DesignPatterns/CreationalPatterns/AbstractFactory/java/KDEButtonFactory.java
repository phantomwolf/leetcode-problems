public class KDEButtonFactory extends ButtonFactory {
    public Button createButton(String text) {
        Button btn = new KDEButton(text);
        return btn;
    }
}
