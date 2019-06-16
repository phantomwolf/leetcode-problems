public class GnomeButton extends Button {
    public GnomeButton(String text) {
        super(text);
    }

    public void click() {
        System.out.println("GnomeButton: " + this.text);
    }
}
