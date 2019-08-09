import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;

/* 为什么不用具体的composite class直接继承Equipment？
 * 因为composite class也有很多共有的操作，引入一个CompositeEquipment基类，
 * 可以直接在具体的composite class里直接继承它，而无需重复实现*/
public class CompositeEquipment extends Equipment {
    private Map<String, Equipment> children;

    public CompositeEquipment(String name, double power) {
        super(name, power);
        this.children = new HashMap<String, Equipment>();
    }
    // Returns the total power of itself and all its children
    @Override
    public double getPower() {
        double power = super.getPower();
        for (Map.Entry<String, Equipment> entry : this.children.entrySet()) {
            power += entry.getValue().getPower();
        }
        return power;
    }

    @Override
    public List<Equipment> getChildren() throws NoSuchMethodException {
        List<Equipment> result = new ArrayList<Equipment>();
        for (Equipment eqpt : this.children.values()) {
            result.add(eqpt);
        }
        return result;
    }

    @Override
    public void add(Equipment eqpt) throws NoSuchMethodException {
        this.children.put(eqpt.getName(), eqpt);
    }

    @Override
    public void remove(Equipment eqpt) throws NoSuchMethodException {
        this.children.remove(eqpt.getName());
    }
}
