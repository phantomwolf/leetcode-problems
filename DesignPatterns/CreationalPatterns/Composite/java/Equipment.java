import java.util.List;
import java.util.ArrayList;

// Role: Component(interface)
public class Equipment {
    private String name;
    private double power;

    public Equipment(String name, double power) {
        this.name = name;
        this.power = power;
    }

    public String getName() {
        return this.name;
    }

    public double getPower() {
        return this.power;
    }

    public List<Equipment> getChildren() throws NoSuchMethodException {
        throw new NoSuchMethodException("Leaf class doesn't support getChildren method");
    }

    public void add(Equipment eqpt) throws NoSuchMethodException {
        throw new NoSuchMethodException("Leaf class doesn't support add method");
    }

    public void remove(Equipment eqpt) throws NoSuchMethodException {
        throw new NoSuchMethodException("Leaf class doesn't support remove method");
    }
}
