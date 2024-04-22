interface Comparable<T> {
  // returns <0,  0, >0 when this object
  //      is < , ==, >       that object
  int compareTo(T that);
}
// Comparable<>  is    defined in the Java API
// the following is an example of how Comparable<> is used
public class City implements Comparable<City> {
  private String name; // name
  private double area; // land area  (square miles)
  private int    pop;  // population (thousands)
 
  public City(String name, double area, int pop) {
    this.name = name; this.area = area; this.pop = pop;
  }
  public String getName   () { return this.name; }
  public double getArea   () { return this.area; }
  public int    getPop    () { return this.pop ; }

  public String toString  () {
    return getName() + ": " + getArea() + ", " + getPop();
  }
  public int    compareTo (City that) {
    // subtract areas and cast from double to int
    return (int)Math.signum( this.area - that.area );
  }
 
  public static final City // named constants
    CHI = new City("Chicago" , 227.6, 2700),
    LAX = new City("LA"      , 468.7, 3800),
    NYC = new City("New York", 302.6, 8200);
 
  public static void demo() {
    System.out.println(
      CHI + " vs " + LAX + " : " + CHI.compareTo(LAX));
    System.out.println(
      LAX + " vs " + NYC + " : " + LAX.compareTo(NYC));
  }

} // end class City


interface Comparator<T> {
  int     compare(T o1, T o2); // return <,=,> for o1 vs v2
  boolean equals (Object obj); // are 2 Comparators equal?
}
// Comparator<>  is  declared in the Java API
// the following are examples of how Comparator is used
public class StringCompI implements Comparator<String> {
  public int     compare(String s1, String s2) {
    return s1.compareToIgnoreCase(s2); 
  }
  public boolean equals (Object o) { return false; }
}
public class StringCompL implements Comparator<String> {
  public int     compare(String s1, String s2) {
    return (int)Math.signum( s1.length() - s2.length() ); 
  }
  public boolean equals (Object o) { return false; }
}
public class CityCompA implements Comparator<City> {
  public int     compare(City c1, City c2) {
    return (int)( c1.getArea() - c2.getArea() );
  }
  public boolean equals (Object o) { return false; }
}
public class CityCompP implements Comparator<City> {
  public int    compare(City c1, City c2) {
    return ( c1.getPop() - c2.getPop() );
  }
  public boolean equals (Object o) { return false; }
}
  public static void demoComparator() {
    Comparator<City> cca = new CityCompA(),
                     ccp = new CityCompP();
    System.out.println(
      CHI + " vs " + LAX + " : " + cca.compare(CHI,LAX));
    System.out.println(
      LAX + " vs " + NYC + " : " + ccp.compare(LAX,NYC));
  }

