public class Main {
    public static void main(String[] args) throws Exception {
        String type = "gnome";
        if (args.length > 0) {
            type = args[0];
        }
        // Create ButtonFactory according to argument
        ButtonFactory btnFactory;
        if (type.equals("gnome")) {
            btnFactory = new GnomeButtonFactory();
        } else if (type.equals("kde")) {
            btnFactory = new KDEButtonFactory();
        } else {
            throw new Exception("Wrong button type '" + type + "'. Supported: gnome, kde");
        }
        // Create button
        Button btn = btnFactory.createButton("OK");
        btn.click();
    }
}
