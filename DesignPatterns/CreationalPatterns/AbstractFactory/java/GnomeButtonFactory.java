public class GnomeButtonFactory extends ButtonFactory {
    public Button createButton(String text) {
        Button btn = new GnomeButton(text);
        return btn;
    }
}
