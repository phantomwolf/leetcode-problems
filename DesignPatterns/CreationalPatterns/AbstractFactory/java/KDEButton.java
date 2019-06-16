public class KDEButton extends Button {
    public KDEButton(String text) {
        super(text);
    }

    public void click() {
        System.out.println("KDEButton: " + this.text);
    }
}
