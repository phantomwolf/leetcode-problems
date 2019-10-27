package test;

import java.lang.reflect.*;

class MyClass {
	public String name;
	
	public MyClass(String name) {
		this.name = name;
	}
	
	public void show(String msg) {
		System.out.printf("%s: %s\n", name, msg);
	}
}

public class Test {
	public static void main(String[] args) {
		try {
			// Constructor
			Constructor<MyClass> con = MyClass.class.getConstructor(String.class);
			MyClass obj = con.newInstance("foobar");
			// Read & Write field
			Field f = obj.getClass().getField("name");
			if (f.getType() == String.class) {
				// If "name" field is an instance of String
				System.out.printf("before change:\t%s\n", (String) f.get(obj));
				String newName = "barfoo";
				f.set(obj, newName);
				// Print again
				System.out.printf("after change:\t%s\n", (String) f.get(obj));
			}
			// Invoke method
			Method m = obj.getClass().getMethod("show", String.class);
			m.invoke(obj, "secret message");
		} catch (NoSuchMethodException | SecurityException e) {
			e.printStackTrace();
		} catch (InstantiationException e) {
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			e.printStackTrace();
		} catch (IllegalArgumentException e) {
			e.printStackTrace();
		} catch (InvocationTargetException e) {
			e.printStackTrace();
		} catch (NoSuchFieldException e) {
			e.printStackTrace();
		}
	}
}

