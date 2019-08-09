public class Main {
    public static void main(String[] args) throws NoSuchMethodException {
        Mainboard mb = new Mainboard("MSI", 20);
        System.out.printf("Mainboard: %s, Power %dW\n", mb.getName(), (int)mb.getPower());
        GPU gtx1070 = new GPU("NVidia GTX1070", 300);
        GPU amd480 = new GPU("AMD 480", 400);
        try {
            mb.add(gtx1070);
            System.out.printf("GPU: %s, Power %dW\n", gtx1070.getName(), (int)gtx1070.getPower());
            mb.add(amd480);
            System.out.printf("GPU: %s, Power %dW\n", amd480.getName(), (int)amd480.getPower());
        } catch (NoSuchMethodException e) {
            throw e;
        }
        System.out.printf("Total power: %dW\n", (int)mb.getPower());
    }
}
