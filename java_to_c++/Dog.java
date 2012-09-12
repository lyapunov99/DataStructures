public class Dog
{
	private boolean sex;
	private String name;
	private int age;
	
	public Dog()
	{
		age = 0;
		name = "UNKNOWN";
	}
	
	public String bark()
	{
		return name + " says ARF!";
	}
	
	public String bark (String something)
	{
		return name + " says " + something;
	}
	
	public void setName (String name)
	{
		this.name = name;
	}
	
	public String getName()
	{
		return name;
	}

	public static void main (String [] args)
	{
		Dog d = new Dog();
		d.setName("Fido");
		System.out.println(d.bark());
	}
}
