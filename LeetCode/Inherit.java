class Parent{
	void first(){
		System.out.println("Parent first");
	}
	void second(){
		System.out.println("Parent second");
		this.first();
	}

}
class Child extends Parent{
	void first(){
		System.out.println("Child first");
		super.first();
	}
	void second(){
		System.out.println("Child second");
		super.second();
	}


}


public class Inherit{
	public static void main(String[] args) {
		Child child=new Child();
		child.second();
	}
}  