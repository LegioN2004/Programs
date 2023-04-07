
# Table of Contents

1.  [First java program input/output debugging and datatypes](#org2863bb9)
    1.  [structure of a java file](#org82c71ec)
        1.  [every file that ends with an extensions .java is a class itself; eg: main.java](#org64e7fd2)
        2.  [since it's name is main.java(or something before .java) it should contain a class with that name (as in before the extension) in the file itself](#org21f180a)
        3.  [all the code that we'll be writing will be in this class main/name](#orgfe6408b)
        4.  [remember if a variable name starts with a capital letter then it is a class name (by convention)](#orgc75f025)
        5.  [if the class with the name of the file is in the file then that will be a class of the public type , in this case main is the public class type](#org05278a4)
        6.  [like cpp , java also has a main function (by convention) from where the program starts](#orgff33591)
        7.  [you can run with javac <span class="underline">name</span>.java and then java <span class="underline">name</span> (where name is the class as well as the file name) , also while running the executable with java you can use the name only to run](#org1a14897)
    2.  [explanation of the main.java file](#org1f94cd4)
        1.  [here class is name group of properties and functions , in the above eg's class we have this function](#org443978c)
        2.  [all the functions that are in the classes are knows as methods](#orgc1923b6)
        3.  [also the function name has to be main only <s public static void main(String[] args) > it is reserved to be here if it is not main it will not run](#org1730a92)
        4.  [here public means the same as the class name <s public static void main(String[] args) > " does it not make sense to make it available to be executed from anywhere](#org9b5a6ab)
        5.  [here static means](#org64014e3)


<a id="org2863bb9"></a>

# First java program input/output debugging and datatypes


<a id="org82c71ec"></a>

## structure of a java file


<a id="org64e7fd2"></a>

### every file that ends with an extensions .java is a class itself; eg: main.java


<a id="org21f180a"></a>

### since it's name is main.java(or something before .java) it should contain a class with that name (as in before the extension) in the file itself


<a id="orgfe6408b"></a>

### all the code that we'll be writing will be in this class main/name


<a id="orgc75f025"></a>

### remember if a variable name starts with a capital letter then it is a class name (by convention)


<a id="org05278a4"></a>

### if the class with the name of the file is in the file then that will be a class of the public type , in this case main is the public class type

1.  public class means that this class will be accessible by all other files , classes, etc


<a id="orgff33591"></a>

### like cpp , java also has a main function (by convention) from where the program starts

1.  function is a block/collection of code which can be used again and again


<a id="org1a14897"></a>

### you can run with javac <span class="underline">name</span>.java and then java <span class="underline">name</span> (where name is the class as well as the file name) , also while running the executable with java you can use the name only to run


<a id="org1f94cd4"></a>

## explanation of the main.java file

<s public class main { // inside this block of {} is the int main of java as found in cpp
	public static void main(String[] args) {
		System.out.println("hello world!!");
	}
}
>


<a id="org443978c"></a>

### here class is name group of properties and functions , in the above eg's class we have this function

	<s public static void main(String[] args) {
		System.out.println("hello world!!");
	}
>


<a id="orgc1923b6"></a>

### all the functions that are in the classes are knows as methods


<a id="org1730a92"></a>

### also the function name has to be main only <s public static void main(String[] args) > it is reserved to be here if it is not main it will not run


<a id="org9b5a6ab"></a>

### here public means the same as the class name <s public static void main(String[] args) > " does it not make sense to make it available to be executed from anywhere


<a id="org64014e3"></a>

### here static means

