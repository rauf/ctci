import java.util.*;

abstract class Animal{
	int timestamp;
	String name;

	public Animal(String n){
		name = n;
	}

	public int getTimeStamp() {
		return timestamp;
	}

	public void setTimestamp(int t){
		timestamp = t;
	}
}

class Dog extends Animal{

	public Dog(String n){
		super(n);
	}

}

class Cat extends Animal{

	public Cat(String n){
		super(n);
	}

}

class AnimalQueue {

	private LinkedList<Dog> dogs;
	private LinkedList<Cat> cats;
	private int time;

	AnimalQueue() {
		dogs = new LinkedList();
		cats = new LinkedList();
		time = 0;
	}

	public void enqueue(Animal animal) {

		animal.setTimestamp(time);
		time++;

		if (animal instanceof Dog) {
			dogs.add((Dog)animal);
		}
		if(animal instanceof Cat){
			cats.add((Cat)animal);
		}
	}

	public Dog dequeueDog(){
		return dogs.removeFirst();
	}

	public Cat dequeueCat(){
		return cats.removeFirst();
	}

	public Animal dequeueAny() {

		if(cats.size() == 0){
			return dequeueDog();
		}
		else if(dogs.size() == 0) {
			return dequeueCat();
		}

		if(cats.getFirst().getTimeStamp() < dogs.getFirst().getTimeStamp()){
			return dequeueCat();
		}
		else if(cats.getFirst().getTimeStamp() > dogs.getFirst().getTimeStamp()){
			return dequeueDog();
		}
		return null;
	}

}

public class Q3_7 {

	public static void main(String[] args) {
		AnimalQueue queue = new AnimalQueue();


	}
}