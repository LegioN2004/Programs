
# Table of Contents

1.  [structure of a java file](#orgab53309)
    1.  [every file that ends with an extensions .java is a class itself; eg: main.java](#org001a09b)
    2.  [since it&rsquo;s name is main.java(or something before .java) it should contain a class with that name (as in before the extension) in the file itself](#org873c5b9)
    3.  [all the code that we&rsquo;ll be writing will be in this class main/name](#org1a0e181)
    4.  [remember if a variable name starts with a capital letter then it is a class name (by convention)](#orgf87e99f)
    5.  [if the class with the name of the file is in the file then that will be a class of the public type , in this case main is the public class type](#orgcb0e2eb)
    6.  [public class means that this class will be accessible by all other files , classes, etc](#orgf869872)
    7.  [like cpp , java also has a main function (by convention) from where the program starts , whenever we run the program the compiler will look for main , if it is not present then the compiler will throw error](#org884b716)
        1.  [function is a block/collection of code which can be used again and again](#orgab71c4c)
    8.  [you can run with javac <span class="underline">name</span>.java and then java <span class="underline">name</span> (where name is the class as well as the file name) , also while running the executable with java you can use the name only to run](#orgea11360)
    9.  [explanation of the main.java file](#org9f5cf80)
    10. [here class is name group of properties and functions , in the above eg&rsquo;s class we have this function](#org2452f8b)
    11. [all the functions that are in the classes are knows as methods](#orgbbfd9c8)
    12. [also the function name has to be main only #+begin<sub>src</sub> public static void main(String[] args) #+end<sub>src</sub>  it is reserved to be here if it is not main it will not run](#org7f92bc2)
    13. [here public means the same as in the class name part <s public static void main(String[] args) > since main is necessary to run the program so it makes sense to make it available to be executed from anywhere i.e public class type , if we make it private then it will not be available like the public class and hence it will not be valid](#org7108cd0)
        1.  [main function is the entry point of the function](#orgf7ef662)
        2.  [here static means:this main function/method is a part of the -Main- class also main is required to be run without creating an object of this Main class ,so we use the static type . Since nothing is running before the main() function then there is no use of making an object there](#orga72bd40)
        3.  [so static variables and functions are the variables and functions that don&rsquo;t depend on the object](#org95de226)
        4.  [void is the return type of the function, since we don&rsquo;t want any value here so we have used void(like in cpp)](#orgf080199)
        5.  [(String[] args) are the arguments , collection of strings](#org32c0f40)
        6.  [here args is the arguments given in the terminal with java command (like java Main 50 100 &#x2026;) after compiling with the javac(like javac Main(class/file name)) and the no inside the [] is the index of the array to which the values given with the java command will be printed , the values given with the java command is stored in the String[] array](#org0692014)
        7.  [javac -d <span class="underline">directory</span> <span class="underline">name</span>: this -d flag is used to give a directory to store the .class file](#org9c95fcf)
        8.  [package is the folder where the java file will lie, eg package com.kunal , this com.kunal is a subfolder in the com folder (you can make more of those subfolders) , &rsquo;.&rsquo; period means subfolder](#org1ed47f0)



<a id="orgab53309"></a>

# structure of a java file


<a id="org001a09b"></a>

## every file that ends with an extensions .java is a class itself; eg: main.java


<a id="org873c5b9"></a>

## since it&rsquo;s name is main.java(or something before .java) it should contain a class with that name (as in before the extension) in the file itself


<a id="org1a0e181"></a>

## all the code that we&rsquo;ll be writing will be in this class main/name


<a id="orgf87e99f"></a>

## remember if a variable name starts with a capital letter then it is a class name (by convention)


<a id="orgcb0e2eb"></a>

## if the class with the name of the file is in the file then that will be a class of the public type , in this case main is the public class type


<a id="orgf869872"></a>

## public class means that this class will be accessible by all other files , classes, etc


<a id="org884b716"></a>

## like cpp , java also has a main function (by convention) from where the program starts , whenever we run the program the compiler will look for main , if it is not present then the compiler will throw error


<a id="orgab71c4c"></a>

### function is a block/collection of code which can be used again and again


<a id="orgea11360"></a>

## you can run with javac <span class="underline">name</span>.java and then java <span class="underline">name</span> (where name is the class as well as the file name) , also while running the executable with java you can use the name only to run


<a id="org9f5cf80"></a>

## explanation of the main.java file

     public class main { // inside this block of {} is the int main of java as found in cpp
    	public static void main(String[] args) {
    		System.out.println("hello world!!");
    	}
    }


<a id="org2452f8b"></a>

## here class is name group of properties and functions , in the above eg&rsquo;s class we have this function

     public static void main(String[] args) {
    	System.out.println("hello world!!");
    }


<a id="orgbbfd9c8"></a>

## all the functions that are in the classes are knows as methods


<a id="org7f92bc2"></a>

## also the function name has to be main only #+begin<sub>src</sub> public static void main(String[] args) #+end<sub>src</sub>  it is reserved to be here if it is not main it will not run


<a id="org7108cd0"></a>

## here public means the same as in the class name part <s public static void main(String[] args) > since main is necessary to run the program so it makes sense to make it available to be executed from anywhere i.e public class type , if we make it private then it will not be available like the public class and hence it will not be valid


<a id="orgf7ef662"></a>

### main function is the entry point of the function


<a id="orga72bd40"></a>

### here static means:this main function/method is a part of the -Main- class also main is required to be run without creating an object of this Main class ,so we use the static type . Since nothing is running before the main() function then there is no use of making an object there


<a id="org95de226"></a>

### so static variables and functions are the variables and functions that don&rsquo;t depend on the object


<a id="orgf080199"></a>

### void is the return type of the function, since we don&rsquo;t want any value here so we have used void(like in cpp)


<a id="org32c0f40"></a>

### (String[] args) are the arguments , collection of strings


<a id="org0692014"></a>

### here args is the arguments given in the terminal with java command (like java Main 50 100 &#x2026;) after compiling with the javac(like javac Main(class/file name)) and the no inside the [] is the index of the array to which the values given with the java command will be printed , the values given with the java command is stored in the String[] array


<a id="org9c95fcf"></a>

### javac -d <span class="underline">directory</span> <span class="underline">name</span>: this -d flag is used to give a directory to store the .class file


<a id="org1ed47f0"></a>

### package is the folder where the java file will lie, eg package com.kunal , this com.kunal is a subfolder in the com folder (you can make more of those subfolders) , &rsquo;.&rsquo; period means subfolder

