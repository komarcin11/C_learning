// ALL C SYNTAX (THAT I KNOW)

// HELLO WORLD in C
#include <stdio.h>
int main(void)
{
    printf("hello, World");
}

// --------- thats a syntax for a single line comment-----------
/*
and this is for multiple line comment
*/
#include <stdio.h> // that is a libary that needs to be added if you what its fukcionalytie stdio.h is a standart one that comes with C
#include <cs50.c> // is a additional libary you need to config it // using file.c you compile staticly external lib 
#include <cs50.h> // using file.h you compile dynamicly external lib // at that moment your not able to do so 


//---------COMPILING---------------
//  Dynamic compilation of additional libaries - you use .h files and than the compilor serches  for the file in the libary and compiles it into your binary code
//     when the compilor is not well configured you need to do it with use of bellow mention terminal cmd clang .\addition.c cs50.c -o addition.exe
//  Static compilation of additional lib - using .c files in include 
// to do a static compilation of additional lib you uce terminal cmd // clang .\addition.c -o addition.exe

//---------PREPROCESSING---------------
//preprocesing_first.c
#include <stdio.h>// #include includes the header file in the preprocoeeor stage before compiling the code
//you can use other keyword than #include to includ to pre processor
// #pragma
// #error 
// #warning
#include <stdlib.h>// memory management
#include <errno.h> //errno global variable and error code
#include <string.h> //string handling lig
#include <math.h>  // common math fun.
#include <time.h> // time and data utilities
#define PI 3.14 //create a macro like functnio that will be replaced in the preprocessor// here if we use later in code PI preprocessor will replace it wiht the assign value
#define AREA(r) (PI*(r)*(r))//here we have a macro fun that will take an argument. // no need for ;
//This is crusial (r)*(r) becouse if i use (PI*r*r) and i call the macro as AREA (r+1) the preprocessor will exchange it to (3.14*r+1*r+1), you want (3.14*(r+1)*(r+1))
int main(void) {
    float radius = 2;
    printf("Pi is %.2f\n",PI);
    printf("Area is :%.2f\n", AREA(radius));// ca
    printf("Area with radius+1 :%.2f\n", AREA(radius+1));
        return 0;
}

//preprocesing_predefined_macros.c
#include <stdio.h>
#include <string.h> 
int main(void) {
    printf("%s %s\n",__TIME__, __DATE__);//__TIME__, __DATE__ are predefined macros for time and data
    printf("line number in code %d\n", __LINE__);
    return 0;
}

//conditional_macro_compilation.c
// you would like to condition the macros definition if the included header files already do have some macros defined
#include <stdio.h>
#define RATE 0.08//define a macro (assining the value to a variable )
#ifndef TERM // checks if not defined and if not it will execute what is in indention
    #define TERM 24// this is executed
#endif // ends the if statement
int main(void) {
    #undef RATE // undefines the RATE macro
    #ifdef RATE //check if defied, if true it will execute in the indention if false it will skipp code
        printf("the RATE is defined\n");`
        printf("Rediefining RATE\n");
    #else // this will execute if the above will be false 
        printf("this will not be compiled ");
        #define RATE 0.068
    #endif // ends the if statement
    printf("%.3f, %d\n", RATE, TERM);
    return 0;
}

//conditional_compilation.c
#include <stdio.h>
#define LEVEL 4
int main(void) {
    #if LEVEL > 6
        printf("LEVEL > 6\n");
    #elif LEVEL > 5
        printf("LEVEL > 5\n");
    #elif LEVEL > 4
        printf("LEVEL > 4\n");
    #else
        printf("LEVEL <= 4\n");
    #endif
    #if !defined(LEVEL)//cheching if the macro is defined 
        printf("LEVEL not defined\n");
    #elif defined(LEVEL)
        printf("LEVEL defined\n");
    #endif
    // int LEVEL = 3; // if you would have this line there would be a Compile Error
    return 0;
}

//compilation_operators_sololearn.c
//# - the strigification operator , tells the prepro. to convert the value of the variable to a string
//## - token pasting it pases the token together
#include <stdio.h>
#define YOUR_NAME(x) #x // # operator tells the preproces.. that x is a string
#define Var(a,b) a##b // it will paste the together 
int main(void) {
    printf("%s\n", YOUR_NAME(Tom));
    int w = 1;
    int z = 2;
    int Var(w,z) = w+z;
    printf("%d\n",wz); // it outputs the value of w+z not for example 12 
    return 0;
}


// --------- MAIN FUNCTION ------------
int main(void)// thats the "main" function it is initialyzed when the program is executed /int means it return a int //(void) means tha it does noe take any values to the functions
{
// thats the main
}


//--------- C VARIABLES--------
int i = 5// integer a digit wiht no.  ex. 4 has - 4 bytes
char c  = 'n' // single letter has ex. "f" - 4 bytes
bool b = 0 // a True/False statement // 0 is false anny other value is True - 4 bytes
float f = 4.5// is a digit with a floting point, a period ex. 4.2 - 4 bytes
double d = 2000000// a float with double the storage capasity - 8 bytes
long l = 2.000000001 // a int with doble the storage casity - 8 bytes
string  s = "hello" // is not a standart variable in C it comes with <cs50.h> lib or can come with other 
const int j = 2  // const is a cosntante you declare a variable to be a constant that can not be change during the program operation// there fore you need to declare a value of a const variable
// for clearance 1byte = 8bits, 1bit is a single 0 or 1 values, so with 8 bits you can count 0-255, with 4 bytes up to 4,294,967,296.

// ------PRINTING---------
#include <stdio.h>
int main(void) // that the difference between python to do anything you need to put it into a function
{
    int x = 3; // declering a variable - in C u need to tell what kind of variable it will be here a "int"// x-name of variable // = - is // 3 - value of variable// ; - in every "statement" you need to add a ; at the end
    printf("x is : %i\n", x); //printf comes from stdio.h lib in "" - you put your content do display %i you implay what type of variable value will be dispayed and after , you put the veriable // \n is a special carracter- means move to next line
    float y = 4.0015;
    printf("y is: %.5f\n", y); // %f - means insert a float, %.5f isert a float dispaying 5 dig after the period. in this exaple 4.00150
    printf("%s, %s", s, s);// this is how to insert two strings into a single print
} // there are many special characters ex. \n \t \\ \' ....
// that small prog display a puten into a program value in printf there are may types of variables %d %i %s ..... %c - char// %f - float// %i - integer // %li
// if you want to print a char you use ' ' not " "!!


// -------OPERATION ON VARIABLES--------------

//MATEMATICAL OPERATIONS
// with int  float double long  you can do all math operations in stdin.h + - * / and % - the rest of division
// on char-s you can do + - to shift thery value in ASCII chart
int a = 1; 
a++; // if you want to increment by 1 this is the same as a = a +1 or a += 1
a+=3 // will increment by 3 adding to the value
a-=2 // will increment by 2 retracting form the value
a-- // will retruct 1
a*=8// is the smimilar to a=a*8


//VARIABLE COMPERING
//you can compare with ease int bool float dobule but not strings
// the comparmet return is a boolien value 0 or any other than 0 ro true/false 
a == 1; // is equal to 
a != 2: // is not equal to // ! simply means is not ...
a == 1 || b != 1; // || is or
a == 1 && b != 1;// && is and
// () can be used if needed
(a==2 && b==3)|| c==5 || !(b!=3)
// you can use all of the following < > >= <= == !=


//TYPE CASTING (changing one variable to another) it is usefull to type cast in certain situation
//some variables have size limitation for example or precision that you would like to change
int b = 1;
c = (double)b ; // this is how you change a int into a double (that does not have any intugeroverflow issues)
#include <stdio.h>
#include <cs50.c>
int main(void)
{
    int x = 5, y = 7;
    printf("%lf\n", (double) x + y ); // typacasting to double and adding before displaying
}
//_______________________________________
//OPERATION ON STRINGS ARE ON IN ARRAYS 
//__________________________________


// there are othre lib that can make it easer
#include <stdio.h>
#include "cs50.h"
int main(void)
{
    int x = get_int("insert your int\n"); // you don need to declare in advance what type of varable it will be. 
    char y = get_char("insert your char\n"); 
    double z = get_double("insert your char\n");
    float w  = get_float("insert your float\n");
    string u = get_string("insert your string\n"); // while compiling need do complie with this comand clang  <file>.c -o <file> cs50.c
}


//----------------CONDITIONALS -----------

// exapmple bellow// if needed use || or operators or && and poerators to combine your conditions
#include <stdio.h>
#include <cs50.c>
int main(void)
{
    int x = get_int("What's x? "); // 
    int y = get_int("What's y? ");
    if (x < y)
    {
        printf("x is less than y\n");
    }
    else if (x > y)
    {
        printf("x is not less than y\n");
    }
    else
    {
        printf("x i equal to y\n");
    }
}

// switch not used  often
// it will compare the 
#include <stdio.h>
int main(void)
{
    int i = 2;
    switch(i)// it will compare the varaible in () with the valeuses in the cases
    {
        case 1: // if the values are the same tan it will execute the values after : if not it will skip but 
            printf("i = one\n"); // if it will execute the case than he will execute until it "hits the break
            break; // if the i value would be 1 and no break; here it would execute the case 1 and case 2 until hiting the break key ward
        case 2:
            printf("i = two\n");
            break;
        default:
            printf("i is not two or one");
    }
    return 0;
}

//---------------LOOPS---------------------

// FOR LOOP
#include <stdio.h>
int main(void)
{//printing Hi 3 times
    for (int i = 0; i < 3; i++) // it will loop until the condition is true
    {
        printf("Hi\n");
    }
}

// WHIEL LOOP
#include <stdio.h>
int main(void)
{
    int i = 0; // declaring the varialbe and its value in advance 
    while (i < 3) // while the condition is True it will loop
    {
        printf("Hi\n");
        i++;
    }
}

// DO WHILE LOOP
#include <stdio.h>
#include <stdbool.h>
int main(void)
{
    int n; // you need to declare a variable and its type to call on it 
    do // slight diference between the while loop the checed condition time is different
    {
        n = get_int("Size: "); // get_int is from cs50.h lib
    }
    while (n < 1);
}

//LOOPS WITH CONDITIONALS
#include <stdio.h>
#include <stdbool.h> // to have true operator  // otherwise you woud use 0 albo 1 
int main(void)
{
    int n = 0;
    while (true) 
    {
        n++;
        if(n!=3)
        {
            printf("n is not 3 its %d\n", n);
            continue; // the continue will push the program back to the loop begining not 
        }
        else if(n==3)
        {
            printf("n is equal to 3 \n");
            break; // break  - breaks out of the loop 
        }
    }
    printf("loop end\n");
}

//break/continue
#include <stdio.h>
int main(void){
    for(int i= 1 ; i<10; i++){
        if(i==9){
            break;//in here the breake will force to breakout of thhe loop
        }
        else if(i==5){
            continue; //continue will reexecute the loop skipping the i==5 printf command
        }
        printf("%d",i);
    }
}


//----------------------ARRAYS---------------------
// array is a order elements of pericular type

#include <stdio.h>
#include <cs50.c>
int main(void)
{
    int int_array[2] = {2,3}; // declaring a array// the elem are ints/ array name//[size of array] = {first elem, second element} 
    int a[] = {2,3,4,4} // if you specyfi the array elements you dont need to declare the array size
    printf("%i", int_array[0]); // it will print the first element in an array// index nr 0
    for (int i = 0; i <= 2; i++ )
    {
        int sum += int_array[i]; // ass you can see you can iterate throu the array elements
        printf("sum is %d",sum);
    }
}

// below some char arrya examples // which we call strings 
#include <stdio.h>
int main(void)
{
    char c1 = 'H';
    char c2 = 'I';
    printf("%i %i %c%c \n", c1, c2, c1, c2);// a arawy of chars can be a string // a char can be represeted as a integer value (ACSII)
}

#include <stdio.h>
#include <cs50.c>
int main(void)
{
    string s = "HI!";
    printf("%i %i %i\n", s[0], s[1],s[2] ); // so as pointed out strings is in deed a array // can be displayed as int or chars
}

//below an array of an array
#include <stdio.h>
#include <cs50.c>
int main(void)
{
    string words[2]; // as before the array needs to be a declared size
    words[0] = "Hi"; // this line will assing a first subarray to the 2 element array words
    words[1] = "bye";
    printf("%s %s \n", words[0], words[1] ); 
    printf("%i%i %i%i%i\n", words[0][0], words[0][1], words[1][0], words[1][1], words[1][2]); // so you can do a array of an array
    printf("%i %i %i %i \n", words[1][0], words[1][1], words[1][2], words[1][3]); // it should print so printed out 0 simpolizes null \0
}


// STRINGS AS ARRAYS 
//if the string is a arraych of charcters (chars) you can do array operations on it
char a[] = "hello"; //is declaration of an 'a' variable that is an array if chars like so

//operation on strings
#include <stdio.h>
#include <cs50.c>
#include <string.h> //a lib that has many strings functions like strlen() 
int main(void)
{
    string name = ("Thomas");
    int n = strlen(name);// strlen(<string>) is a function that will count the amout of letters in the words - elements in the arrays
    printf("the word is %i letters long\n",n);
    for (int i = 0; i < strlen(name); i++) // this loop will change letters to upper case
    {
        if(name[i]>= 'a' && name[i <= 'z'])
        {
            printf("%c", name[i]-32);
        }
        else
        {
            printf("%c", name[i]);
        }
    }
    printf("\n");
}

//the same thing can be achived with other libs
#include <stdio.h>
#include <cs50.c>
#include <string.h> //string operations
#include <ctype.h> // lib that hass many usefull operations lite toupper()
int main (void)
{
    string s = get_string("Before: ");// at the moment get_string does not work
    //printf("Before: %s\n", s);
    printf("After:  ");  
    for (int i = 0; i < strlen(s); i++)
    {
        printf("%c", toupper(s[i])); // changes the char to its upper "value"
    }
    printf("\n");
}

//strcmp() function form string.h
#include <stdio.h>
#include <cs50.c>
#include <string.h>
int main(void)
{
    string names[]={"tom", "dan", "bob", "rob"};  // this is who you can eter the value into an arrys
    //below lines usubstitudes get_string()
    char s[4] ;
    printf("what person are you looking for?: ");
    fgets(s, sizeof(s), stdin);
    //printf("You are looking for: %s\n", s); 

    int size = sizeof(names)/sizeof(names[0]); // this will give us a size of array
    //printf("how many names: %i\n", size);

    for(int i = 0; i < size; i++)
    {
        //printf("i is %i\n", i); // this lines where important to understand the search
        //printf("is %s, %s ? \n", s, names[i]);
        //printf("strcmp value is : %i\n", strcmp(names[i], s));
        if (strcmp(names[i], s) == 0) // you can not use == with string like in python// strcmp compers strings it will return a int 0 for True // from string.h
        {
            printf("person found\n");
            return 0;
        }
        //printf("\n");
    }
    printf("person not found\n");
    return 1;
}
//strcpy_s function from string.h
#include <string.h>
    strcpy_s(t, strlen(s)+1, s)// str copy function // form the documentation the strcpy_s needs !3 arguments ! (the char* that you copy to,lenght of the future string, the char* that you copy from)


//-----------------MULTIDIMENTIONAL ARRAYS----------------------
#include <stdio.h>
int main(void){
    int num[][2]={{1,2},{3,4},{5,6}};// while declarying an array you need to declare a size of the subarry otherwise an error will occure 
    for(int i = 0; i<3;i++){ // you can iterate througt the elements
        for(int j=0; j<2;j++){
            printf("%d\n", num[i][j]);
        }
    }
    printf("size is : %d elemtnts\n", (int)(sizeof(num)/sizeof(int))); // just for practice the array is 6 elements big using 
    printf("used memory space is : %d bits\n", (int)(sizeof(num))); 
}


//--------------FUNCTIONS-----------------
//if you want to declare a function that has a array in it you can without adding the arry size

//function with different value input and different output
#include <stdio.h>
#include <cs50.c>
int get_size(void); // idicate to a function that will be defined later // declaring a fun also caled protoype // definition is below 
void print_grid(int size);// a prototype is just use first line of a function 
int main(void) // Main function is a function beeing executed while the exetucaple is opened// All main funct return a int but can take any variable in here none.
{
    int n = get_size(); // here you can call the function
    print_grid(n);
}

int get_size(void) // here is the function def . // this function returns a int and will take(have imput of )nothing. void means that it takes nothing 
{
    int n;
    do
    {
        n = get_int("what size of grid?: ");
    }
    while(n<1);
    return n; // n variable (a int) will return from the function
}

void print_grid(int size)// here is the funciton definition // the function returns nothing(void), but takes (has a input of) a int.
{// the founction input can be anyting an int float char or even an array 
    for(int i = 0; i < size; i++)
    {
        for( int j = 0; j < size; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

//using the main function int return
#include <stdio.h>
#include <cs50.c>
int main (int argc, string argv[]) // here the main function will take values // 
// argc - is argument count (self expanotary) this is why its a int// argv an array of characer pointers (strings) in this case
{
    if(argc < 2)
    {
        printf("Missing valume\n");
        return 1; // it is convetion that if main outputs 1 it means that smth went wrong
    }
    else 
    {
        printf("hello, %s\n", argv[1]);
        return 0;// it convention if main performed corectly it outputed 0
    }
}


// ------------ POINTERS----------------
// location in memory is define in the hexadecimal system or base-16 // 0 1 2 3 4 5 6 7 8 9 A B C D E F// F=15 
// ex FF = 0x255 // 0x is a preffix so the computer know that is dealing with a base-16 system
// & is a symbol of an adress
// * is a sybol of a pointer
#include <stdio.h>
int main(void)
{
    int a = 3;    // Declare an integer variable 'a'
    int* b;     // Declare an pointer to a integure b' it is an adres 
    printf("value of a: %d\n", a);     // Print the value of 'a'
    printf("adres of a: %p\n", &a);    // Print the address of 'a'
    b = &a;// pointer 'b' is assing a adres to the variable 'a'
    printf("vale that b is pointing to: %d\n", *b);// Print the value pointed to by 'b'
    printf("adres stored in b: %p\n", (void*)b);// Print the address stored in 'b'
    int c = 4;// Declare an integer 'c' and initialize it to 4
    int *d = &c;// Declare an integer pointer 'd' and point it to the address of 'c'
    *d = 5;// Assign the value 5 of the variable that the d points to 
    printf("adress of c: %p\n", &c);// Print the address of 'c' (not the value of 'c')
    printf("the value of c:%d\n", *d); // prints the value that 'd' is pointing to, the variable c with value of '5'
    *b = *d; // here we derefrencing the pointers giving accases to the value that the pinter point to, 
    // one pointer give acces to change the value of that the pointer point to and the other assings the value that the pointer points to
    printf("the value of what the 'b' pointer point to: %d , which is the new value of 'a', reassig from the 'c' variable that the 'd' was pointing to\n", *b);
}

//swaping_int_values.c   a simplest use of pointers 
#include <stdio.h>
void swap(int* a,int* b)//pasing a pointers two pointers to a adreses to a intugure variable. So if this function calledn needs to be passed a adres of variable not its a
{
    int tmp = *a; // passing a value to the tmp. If not used * it would assing a adress not the value where the adres point to
    *a = *b; //*a is a dereferending operation it give acces to the value of that the pointer point to
    // step by step// /*a/ gives acces to the value that the a adress point to, /=/ assing /*b/ a value that the b adress points to
    *b = tmp;
}
// void swap(int a, int b)// that doesnt work
// {
//     int tmp = a;
//     a = b;
//     b = tmp;
// }
int main(void){
    int x,y;
    // inputing values x and y
    printf("x is: ");
    scanf_s("%d",&x);// scanf_s work in my clang but scanf() should work on any other
    printf("y is: ");
    scanf_s("%d",&y);

    //show the vales before a swap
    printf("befor swap x is %d and y is %d\n",x,y);
    
    swap(&x,&y); //pasing the adreses of the varables

    //show values after a swap
    printf("after swap x is %d and y is %d\n",x,y);
}


//--------CHAR POINTERS - STRINGS ----------------
// pointer to arrays declaration of a string can be doene char *s = "HI!" or char s[] = "HI! which can have different efect
// with chat *s you need to manage the memory allocation to ensure free space
#include <stdio.h>
int main(void)
{
    char* s = "HI!"; // this is a char pointer - a string notation char *s i the same as char s[]
    printf("%s\n",s); // printf know that it should display the values from the first character all the way to null \0 -
    printf("%p\n",s); // but when u use %p it will display the first character memory adress
    printf("%p\n",&s[0]); // & will show the memory adress of the first latter
    printf("%p\n",&s[1]); // the second
    printf("%c\n",*s); // %c will print the first charracter // *s means go to the adres
    printf("%c\n",*(s+1)); // %c will print the second charracter // you can do a pointer aritmetic this character + 1
    printf("%c\n",*(s+5)); // if you look for at a memory that you shouldend you will get the segmentation error
// becouse a string is just a pointer to a adres of the first character doing == to strings will not work
// == in strings will compare the adresses not the values in the adreses
}


//comparing strings.c
#include <stdio.h>
#include <string.h>
int main()
{
    char i[4] ; // in here i request for 4 chars in memory
    printf("i: ");
    scanf_s("%s5", i);
    char *j = "hi!";//*j is adres location
    //if (*i == *j) // in here if compares only the first character wich might me the same
    if (i == j) // here if compares the adresses of first charactes which will be alwys different(for different variables)
    {
        printf("same\n");
    }
    else
    {
        printf("Different\n");
    }
    // as pointed out by the below output the String content is the same but the adress is different and that is what is being compared
    printf("j: %s\n",j);
    printf("adress of j: %p\n", &j); // a
    printf("i: %s\n",i);
    printf("adress of i: %p\n", &i);
}


// ------------- DATA STRUCTURE ---------------

//------------STRUCTURE & TYPEDEF----------------
//structure data structures
//struct_data.c
#include <stdio.h>
#include <string.h>
struct student{ // this is a declaration of a user-defined data type// the declaration involves the structure tag, and a name and {};
    int id; //here we declara the variables of the data type, they can be any data type int, float, arrays, pointers of even other data structures ect.
    float grade_avr;
    char name[40];
};// structure is alsow reffered as composite or aggregate or in other languages a records

int main(void)
{
    //____declaring the structure "variants" with assigning the values to the scructure elements variables_____
    struct student s1; // data structure declaration. struct <name of the data type> <name variable>; like a variant of the declared earlier data type
    s1.id=01; //assigning a values to the data structure
    strcpy_s(s1.name,sizeof(s1.name), "tom");// a char[] indata structure is inmutable you need to copy the value in now assign it like in rest of the variables
    //strcpy is from the string.h lib
    s1.grade_avr=4.4;

    int size_of_struct_s1 = sizeof(s1);// the structure variable is stored in one continues memory block
    printf("size of the data structure : %d bytes \n", size_of_struct_s1);// output is 48bytes , int 4 bytes, float 4 bytes, char[40] 40 bytes,

    struct student s2 = {02, 5.5, "bob"};// another way of assigning the vales to data structure variables while declaring the structure variable.// keeing right order is crusial

    struct student s3; 
    s3 = (struct student) {03, 4.3, "rob"}; // another way of assigning the vales to data structure variables by type casting .// keeing right order in {} is crusial

    struct student s4 = {.id = 04, .grade_avr = 4.6, .name="ron"};//here w declaring new structure deta type variable while assigning the values to the variables but by the variable names.

    // ______accsesing the values from the assign structures to change______
    s4.grade_avr = 5.3; // here we can change the values of a data variable element

    struct student s5=s4;// here we can assigne all the elements from one structure to another
    s5=s3;// and reassign as well 

    // ____ accesing to read structure elements ________
    printf("student id: %d, average grade %0.1f, name: %s\n",s1.id, s1.grade_avr, s1.name);
    printf("student id: %d, average grade %0.1f, name: %s\n",s2.id, s2.grade_avr, s2.name);
    printf("student id: %d, average grade %0.1f, name: %s\n",s3.id, s3.grade_avr, s3.name);
    printf("student id: %d, average grade %0.1f, name: %s\n",s4.id, s4.grade_avr, s4.name);
    printf("student id: %d, average grade %0.1f, name: %s\n",s5.id, s5.grade_avr, s5.name);
    printf("\n");

    // if i want to iterate thour the elements just create a array of structures as so:
    struct student students[] = {s1, s2, s3, s4, s5};
    int array_len=(int)((sizeof(students))/(sizeof(students[0])));
    for (int i = 0; i<array_len; i ++){
        printf("student id: %d, average grade %0.1f, name: %s\n",students[i].id, students[i].grade_avr, students[i].name);
    }
}

//typedef_data.c
#include <stdio.h>
#include <string.h>
typedef struct { // typedef keyword creates a type definition tht can siplify code, typedef is used becouse it eliminates to write struct while declaring a structure variable(variant)
    int id; //as before here we declara the variables of the data type, 
    float grade_avr;
    char name[40];
} student ;

int main(void)
{
    //____declaring the structure "variants" with assigning the values to the scructure elements variables_____
    student s1; // with use of typedef no need to use struct before the structure name, and the rest is prete much the same

    s1.id=01;
    strcpy_s(s1.name,sizeof(s1.name), "tom");
    s1.grade_avr=4.4;
    student s2 = {02, 5.5, "bob"};
    student s3; 
    s3 = (student) {03, 4.3, "rob"};
    student s4 = {.id = 04, .grade_avr = 4.6, .name="ron"};

    s4.grade_avr = 5.3;
    student s5=s4;
    s5=s3;

    printf("student id: %d, average grade %0.1f, name: %s\n",s1.id, s1.grade_avr, s1.name);
    printf("student id: %d, average grade %0.1f, name: %s\n",s2.id, s2.grade_avr, s2.name);
    printf("student id: %d, average grade %0.1f, name: %s\n",s3.id, s3.grade_avr, s3.name);
    printf("student id: %d, average grade %0.1f, name: %s\n",s4.id, s4.grade_avr, s4.name);
    printf("student id: %d, average grade %0.1f, name: %s\n",s5.id, s5.grade_avr, s5.name);
    printf("\n");

    // even while creating a array of sructures no need for the struct student ...
    student students[] = {s1, s2, s3, s4, s5};
    int array_len=(int)((sizeof(students))/(sizeof(students[0])));
    for (int i = 0; i<array_len; i ++){
        printf("student id: %d, average grade %0.1f, name: %s\n",students[i].id, students[i].grade_avr, students[i].name);
    }
}

// structure_in_structure.c
#include <stdio.h>
typedef struct{
    int x;
    int y;
} point;

typedef struct{
    float radius;
    point center; // here we insert a part of a different data structure
} circle;

int main(void){
    circle c = {2.5,{2,3}};
    printf("circle with radius: %.1f, center in point x=%d , y=%d\n", c.radius, c.center.x, c.center.y ); // here we can refer it
};


// ----------------------UNIONS----------------------
// union is similar to structure, but it allows to store data types in the same memory location
// so union can have elements/members of different type but share the same memory location. If union has 3 elements/members only one is stored in the union, last assingned.
// it's a "OR" situation in structure there is space fore all in union you can have different variables but only one value
// unions are usede for memory management

//introduction_union.c
#include <stdio.h>
#include <string.h>

union val { // definition of a union, the name can be here 
    int int_num;
    float fl_num;
    char str[20];
}; // of it can be between } and ;

int main (void){
    union val u1; // creating a union variable
    union val u2;
    u1.int_num = 123; // assigning a values to an union member like in structures with . between the variable name and the element/mamber name
    u1.fl_num = 98.76; // overwriting the memory space 
    strcpy_s(u1.str,20,"tom"); // copying string to a union element (like in structures)
    u2=u1; // coping the vales from one union to another but 
    u1.int_num = 123; // the last assigne value to one of the u1 union element/member - int_num
    u2.fl_num = 98.76; // the last assigne value to one of the u2 union element/member - fl_num
    //when a mamber has an assigne values the memory location of the union is used to store the variable untiol another memebr is assigne 
    // trying to access a mamber that isnt occupyingh the memory location at the time can give unexpected resaults

    printf("u1 int: %d\n", u1.int_num); // correct version
    printf("u1 float: %.01f\n", u1.fl_num); // unexpected resaults
    printf("u1 string: %s\n", u1.str);// unexpected resaults
    printf("\n");
    printf("u2 int: %d\n", u2.int_num);// unexpected resaults
    printf("u2 float: %.01f\n", u2.fl_num);// correct version
    printf("u2 string: %s\n", u2.str);// unexpected resaults
    return 0;
}

//union_w_structures.c
//unions are usualy used in structures so the structure keep track which vales is stored in the union
#include <stdio.h>
#include <string.h>

typedef struct{
    char make[20];
    int model_year;
    int id_type;//if id_type 0 id_num, if id_type 1 vin
    union{ // the union can be declared in the struct if name at the end of decaration
        int id_num;
        char vin[20];
    }id; // name located here 
}vehicle;

int main (void){
    vehicle car1;
    strcpy_s(car1.make, 20, "Ford");
    
    car1.model_year = 2018;
    car1.id_type = 0;
    car1.id.id_num = 2123432;// this is how to access the vales of the union inside of the structure
    printf("%s made in %d with id:", car1.make, car1.model_year);
    if (car1.id_type==0){// in this example the id_type keeps track wich of the union element/memebr to access
        printf("%d .\n",car1.id.id_num);
    }
    else if (car1.id_type==1){
        printf("%s .\n",car1.id.vin);
    }
    return 0;
}


// -------------- DATA STRUCTURES AND ARRAYS------------

// ----------- ARRAY OF STRUCTS----------
// array_of_data_struct.c
#include <stdio.h>
#include <string.h>

typedef struct{
    int h;
    int w;
    int l;
}box;

int main(void){
    box boxes[3]= {{12,20,30},{30,50,40},{40,55,20}};// array of dara structure
    // it is useful beacuse you can easile itereat throu them
    // it is used in complicated data structures like likend lists, binary trees ect.
    for(int i = 0; i < 3; i ++){
        int volume = boxes[i].h*boxes[i].w*boxes[i].l;
        printf("box nr %d  Volume: %d.\n", i, volume);
    }
    return 0;
}

#include <stdio.h>
#include <cs50.c>
#include <string.h>
typedef struct // is a way to creating a data structure // typedef -declarse that type// is a keyword to define a new data type
{
    string name; // type of data , name of data 
    string number;
}
person; // the name of the data structure
//below a use if that defined data structure
int main(void)
{
    person people[2]; // accsing strucure elemt
    people[0].name = "tom";
    people[0].number = "69";

    people[1].name = "bob";
    people[1].number = "666";

    char s[4] ;
    printf("Whos number do you want?: ");
    fgets(s, sizeof(s), stdin);

    int size = sizeof(people)/sizeof(people[0]); // this will give us a size of array
    //printf("size of people is %i\n", size);
    for(int i = 0; i < size; i++)
    {
        if (strcmp(people[i].name, s) == 0) // you can not use == with string like in python// strcmp compers strings it will return a int 0 for True // from string.h
        {
            printf("person found\n");
            printf("The numebr is %s\n", people[i].number);
            return 0;
        }
        //printf("\n");
    }
    printf("person not found\n");
    return 1;
}


// -------ARRAYS OF UNIONS---------
//array_of_unions.c
#include <stdio.h>
#include <string.h>
union val { 
    int int_num;
    float fl_num;
    char str[20];
};
int main (void){
    union val nums[10]; // creating an array of val union
    int k;

    for(k=0; k<10; k++){
        nums[k].int_num = k;
    }

    for(k=0; k<10; k++){
        printf("%d ", nums[k].int_num);
    }
    printf("\n");
    return 0;}

//array_of_union_memebers.c
//arrya is a colection of the same data types is u use unions you can do an array of many element types
#include <stdio.h>
union type{
    int i_val;
    float f_val;
    char ch_val;
};
int main (void){
    union type arr[3];// creating an array of unions
    arr[0].i_val = 42;
    arr[1].f_val = 3.14;
    arr[2].ch_val = 'X'; // you can assign a single charater (string are diffrent)
    printf("1st elem is : %d\n2nd element: %f\n3rd element %c\n",arr[0].i_val, arr[1].f_val, arr[2].ch_val); // here accessing the union elements from the array with .
    return 0;
    }



// -------- POINTERS & DATA STRUCTURES-------------

// pointers_in_structures.c
#include <stdio.h>
#include <string.h>

struct student{ 
    int id; 
    float grade_avr;
    char name[40];
};
struct student s1 = {01, 5.5, "rob"};
struct student s2 = {02, 4.5, "bob"};
struct student s3 = {03, 5.2, "ron"};

//if you have a structure you can define a functiona that can get acces form tha data element values for coping or display
void show_student_data(struct student st){
    printf("student id: %d, average grade %0.1f, name: %s\n",st.id, st.grade_avr, st.name);
}

// but if you want u can use pointer to the structure to get the vales from the structure 
void show_student_data_with_pointers(struct student *stp){
    printf("student id: %d, average grade %0.1f, name: %s\n",(*stp).id, stp->grade_avr, stp->name); //(*st).id and st->id is the same
}

//that was only for acces but if you want to use a function to change the values in the data you MUST use a pointer in your function
// that will ensure t
void update_name(struct student *stp, char stp_name[40], float stp_avr){
    strcpy_s(stp->name, sizeof(40), stp_name);
    stp->grade_avr=stp_avr;
}

int main(void){
    show_student_data(s1); // here you pass the strcture to the function
    show_student_data(s2);
    show_student_data(s3);
    printf("\n");
    show_student_data_with_pointers(&s1);// but here you need to pass a adress to the structure not the structure
    show_student_data_with_pointers(&s2);
    show_student_data_with_pointers(&s3);
    printf("\n");

    update_name(&s1, "tom", 5.0);
    show_student_data_with_pointers(&s1);
};


//----------POINTERS TO UNIONS----------
//pointers_to_unions.c
// the same with use of pointer to structers 
#include <stdio.h>
union val { 
    int int_num;
    float fl_num;
    char str[20];
};
int main (void){
    union val info;
    union val *ptr = NULL; //definning a pinter to a union val
    ptr= &info; // assigning the pointer an adress
    ptr->int_num = 10;// accessing and changing the value of the union element/member  (*ptr).int_num is the same as ptr->int_num
    printf("info.int_num is %d \n", info.int_num);
}

//function_pointers_to_unions.c
// the same with use of pointer to structers 
#include <stdio.h>
union id { 
    int id_num;
    char name[20];
};

void set_id (union id *item, int a); // as in the structure to have access to change vale of a union element/member we need to use a pointer
void show_id (union id item);

int main (void){
    union id item;
    set_id(&item, 32);
    show_id(item);
    return 0;
}

void set_id (union id *item, int a){
    item->id_num = a;
}

void show_id (union id item){
    printf("ID is %d\n",item.id_num);
}


//-----------------RECURSION-----------------------
//recursion is a proces of function trigering itself
//iteration.c // which is not recursion
#include <cs50.c>
#include <stdio.h>
void draw(int n);
int main (void)
{
    int height = get_int("how high:? ");
    draw(height);
}
// the below function interates over with use of a loop // recurtion can be a bit more sufisticated 
void draw(int n)
{
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j  < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

//recurtion.c
#include <stdio.h>
#include <cs50.c>
void draw(int n);
int main (void)
{
    int height = get_int("how high:? ");
    draw(height);
}

void draw(int n)
{
    if (n<=0)
    {
        return;
    }
    //printf("current n value is : %i\n", n); // for debugging purpase
    draw(n-1);// it will diminish the value of n and reegnites the function// after tha it will unwind it self going from 1 all the way to n
    // printf("berofe the for loop n valune is %i\n", n); // for debugging purpase
    for(int i = 0; i<n; i++)
    {
        // printf("n valune is %i", n);
        printf("#");
    }
    printf("\n");
}


// --------------------ERRORS -----------------------
//there is no try function you just need to look what you do dont divide by 0 and so one
// use exit statements to enschure that you turne off the program and it does not crash
//perror("<string>") you can print a string massage to terminal 
// some functions as fopen will set an error code. The roor code is set in global variable name errno which is def in errno.h, while using errno set it to 0
//to output the error code dotred in errno you have to fpronf to stderr file stream, that is a good programing practice 
//outputing to file you can keep track

//sololear_error_handling.c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 10;
    int y = 0;

    if(y!=0){
        printf("x/y = %d\ns",x/y);
    }
    else{
        printf("division with 0\n");
        exit(EXIT_FAILURE);
        return 1;
    }
    return 0;
}

//sololearn_first_errno.c
#include <stdio.h>
#include <stdlib.h>//for errno
#include <errno.h>
#include <string.h> //to use strerror()

extern int errno;// that is needed to use the errno

int main(void) {
    FILE *fptr;
    int a;
    errno=0;//seting errno to 0 as a default
    a = fopen_s(&fptr,"c:\\nonexisting_file.txt","r");
    if (fptr==NULL || a!=0){
        fprintf(stderr,"Error opening file Error code:%d\n",errno);
        exit(EXIT_FAILURE);
    }

    errno=0;//seting errno to 0 again
    a = fopen_s(&fptr,"c:\\nonexisting_file.txt","r");
    if (fptr==NULL || a!=0){
        perror("Error");//prints out the profix to error message in () 
        char errorMessage[100];//this is adaptation for the strerror_s // insted of using sreerror_c
        strerror_s(errorMessage, sizeof(errorMessage), errno); // based on the errno it will print the error // no need to use perror and stererror but its good practice 
        // fprintf(stderr, "%s\n",strerror(errno)); //usually you use this
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i<135;i++){//this is how to print out all the posible error codes
        char errorMessage[100];
        strerror_s(errorMessage, sizeof(errorMessage), i);
        fprintf(stderr,"%d: %s\n",i,errorMessage);
    }
    fclose(fptr);
    return 0;
    }

//sololearn_EDOM_ERANGE.c
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h> 
#include <math.h> 
//when domain out of range some math.h function set errno to EDOM
//as well eith ERANGE

int main(void) {
    float k=-5;
    float num = 1000;
    float result;

    errno = 0;
    result = sqrt(k);
    if(errno == 0){
        printf("%f",result);
        
    }
    else if(errno==EDOM){
            char errorMessage[100];
            strerror_s(errorMessage, sizeof(errorMessage), errno);
            fprintf(stderr," %s\n",errorMessage);
    }
    errno = 0;
    result = exp(num);
    if (errno == 0){
        printf("%f", result);
    }
    else if (errno==ERANGE){
        char errorMessage[100];
        strerror_s(errorMessage, sizeof(errorMessage), errno);
        fprintf(stderr," %s\n",errorMessage);
    }
    return 0;
}

//sololearn_feof_ferror.c
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h> 
#include <math.h> 

int main(void) {
    FILE *fptr;
    char c;
    errno = 0;
    int a;
    a = fopen_s(&fptr,"c:\\nonexisting_file.txt","r");
    if (fptr==NULL || a!=0){
        char errorMessage[100];
        strerror_s(errorMessage, sizeof(errorMessage), errno);
        fprintf(stderr,"Erorr opening file: %s\n",errorMessage);
        exit(EXIT_FAILURE);
    }
    while((c=getc(fptr))!= EOF){
        printf("%c",c);
    }
    if(ferror(fptr)){//ferror retunrs 1 if error 0 if not
        printf("I/O error readin file.");
        exit(EXIT_FAILURE);
    }
    else if(feof(fptr)){//feof - returns a nonzero value if the end of stream has been reached, otherwise 0, 
        printf("I/O error readin file.");
        
    }
    fclose(fptr);
    return 0;
}


//cs50 errer handling.c
#include <stdio.h>
#include <cs50.c>
int main (int argc, string argv[])
{
    if(argc < 2)
    {
        printf("Missing valume\n");
        return 1; // it is convetion that if main outputs 1 it means that smth went wrong
    }
    else 
    {
        printf("hello, %s\n", argv[1]);
        return 0;// it convention if main performed corectly it outputed 0
    }
}


// ---------------- MEMORY------------------------
// location in memory is define in the hexadecimal system or base-16 // 0 1 2 3 4 5 6 7 8 9 A B C D E F// F=15 
// ex FF = 0x255 // 0x is a preffix so the computer know that is dealing with a base-16 system
// & is a symbol of an adress
// * is a sybol of a pointer or of derefrencing - going to the location and accesing that memory for change or the read

//-----------MALLOC & FREE------
// when declaring a varaible or an array there is a continues memory block allocated on the stack 
// if you want to manualy/dynamicly allocate memory on the heap you use malloc and ect. 
//all function of the dynamicly allocating memory are in <stdlib.h>
// malloc(byte) - return a pointer to the continues memory block specified by the function 
// calloc(num_itemm, item_size) - return a pointer to a contiguous block of memory that has num_items of each size of item_size (byte), the allocated memory is initialized to 0.
// relloc(ptr, bytes) resizez the moemory poited by 'ptr' to size 'bytes' the newly alloceted memory is not initialized.
// free(ptr), frees the memory pointed by the ptr
// string is a char with a pointer of the variable as pointed below
// sizeof() is used to declare the size of the memory needed if you have multiple dimensional array of example use (row*colum)* sizeof(data_type)
int x, u; // declaring an integer variable x and u that will take place in the stack
float y[x]; // declaring a float array of x elements on a stack 
float* z = malloc(x* sizeof(float)); // declaring a float array of x elements on a heap
char* word = malloc(n * sizeof(char)); // declering a array of chars (a string ) of size of n on a heap
free(word); // freeing the heap memory form the word array
// every memory block of memory malloc-ed needs to be freed, only memory malloc() needs to be free, dont free twice
int m;
int* a:
int* b= malloc(sizeof(int));
a=&m;
a=b; //a is poiting to the malloc-ed memory space
m = 10; // assignig a value of m
*b = m+2; // go to the value that a (,b) points to and asing that is m+2

//first_use_malloc_and_free.c
#include <stdio.h>
#include <stdlib.h>
int main(void){
    int* ptr;
    ptr = malloc(10*sizeof(*ptr));//using the *ptr in sizeof will insure to what ever the data type is used it will allocate enought memory
    printf("%d bytes\n",(int)(sizeof(*ptr))); 
    printf("%d bytes\n",(int)(sizeof(ptr)));
    printf("adress: %p\n", ptr);
    if(ptr != NULL){ // if the allocation is unsuccsesfull it will return NULL (this is what this if is for)
        *(ptr+2) = 50;// assigning the vale to the allocated 
    }
    printf("3rd element is %d\n", *(ptr+2));
    free(ptr);// freeing the memory block int adress that is pointed by ptr
    return 0;
}

//allocated memory is contiguous and can be treated as an array, insted of using [] u can use a pointer 
// just use + and in iterations ++ to change the addresses 

//copy_string_fail.c
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
    char s[] = "hello!"; 
    printf("%s\n", s);
    printf("%i\n", (int)strlen(s));
    printf("%i\n", (int)sizeof(s));
    char *t = s; // here i try to "copy" the value
    printf("%c\n", t[0]);
    printf("%c\n",t[0]-32 );
    if (strlen(t)>0)
    {
        t[0] = toupper(t[0]); // here i try to change the copied string first charracter
    }
    printf("s: %s\n", s); // here i can sea that i changed the fist charracter in both s and t
    printf("t: %s\n", t); // becouse in line "char *t = s" i copied the adress of the first charracter not its value
}

// copy_string.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main(void)
{
    char *s = "david";
    char *t = malloc(strlen(s)+1);// *t is a pointer to an unused memory that we request by malloc from the heap 
    printf ("t:%s\n", t);// printing a garbidge of the memory that t is pointing to 
    if (t == NULL ) // its good practise that when requesting a memory you check if there is any
    { // form the malloc doc. if there is no memory available it will reutn NULL
        return 1;
    }
    strcpy_s(t, strlen(s)+1, s); // str copy function // form the documentation the strcpy_s needs !3 arguments !
    printf("s:%s\n", s);
    printf("t:%s\n\n", t);
    if(strlen(t)>0)
    {
        t[0] = toupper(t[0]); 
    }
    printf("s:%s\n", s);
    printf("t:%s\n", t);// now the are diferent values
    free(t); // when your done with the variable free it 
    printf("t:%s\n", t);// again printing a garbidge vaules 
    return 0; 
}

// allocating_string.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char str20[20];
    char* str = NULL;
    strcpy_s(str20,(strlen("12345")+1),"12345"); // add + 1 to the strlen for the null
    printf("str20 size: %llu\n", sizeof("str20"));// sizeof will give you bytes
    printf("str20 lenght %llu\n", strlen(str20));// strlen will give you the number of characters
    str = malloc(strlen(str20)+1); // we need one more character for null charracter
    strcpy_s(str,(strlen(str20)+1),str20);
    printf("%s\n", str);
    return 0; 
}


//------------CALLOC----------------
//first_calloc.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int num;
    char* info;
} record;

int main(void){
    record* recs;
    int num_recs = 2;
    int k;
    char str[] = "this is information";
    printf("size of char*: %d\n",(int)(sizeof(recs->info)));
        recs = calloc(num_recs, sizeof(record)); //calloc allocates contignues memory blocks based on size of item times numebr of items
    if (recs != NULL){
        for (k=0; k<num_recs; k++){
            printf("adress: %p\n", (recs+k));
            printf("size at adress %d = %llu\n", k,sizeof(recs+k) ); // as you can see here by addin 1 to the adress is jumps 16 bytes to the next memory block
            (recs+k)->num = k; // by adding 1 or more to the pointer you can navigate thour the memory blocks
            (recs+k)->info= malloc(sizeof(str)); // to enter elements in the memory block you use a pointer to structure element/member
            strcpy_s((recs+k)->info,sizeof(str), str);//using pointer for the info member allows any string lenght to be stored this is dynamicly allocating memory
            printf("adress: of the string %p\n", (recs+k)->info);
            printf("size at adress of the string %d = %llu\n", k,sizeof((recs+k)->info));
        }
    }
    for (k=0;k<num_recs; k++){
        printf("%d\t%s\n", (recs+k)->num,(recs+k)->info); // here we navigating beetween the memory block
    }
    return 0;
}


// --------REALLOC------
// if you have a fixed number or alocated momory and you want to change it you use realloc(adres,size) as on the ex. below
//first_realloc.c
#include <stdio.h>
#include <stdlib.h>

int main (void){
    int* ptr;
    ptr = malloc(10* sizeof(*ptr)); //block of 10 ints
    if( ptr != NULL){
        *(ptr+2)=50; // third int = 50
    }
    ptr = realloc(ptr, 100 * sizeof(*ptr)); //block of 100 int-s// its a resizing function with assignin new memory
    *(ptr+30)=75;
    printf("%d %d\n",*(ptr+2),*(ptr+30) );
    return 0;
}

//list_reallocating_.c
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int *list=malloc(3 *sizeof(int));
    if (list==NULL)
    {
        return 1;
    }
    list[0]= 1;
    list[1]= 2;
    list[2]= 3;
    //....
    int *tmp = realloc(list, 4*sizeof(int)); // realloc is a function to reallocating memory with resizing
    if(tmp == NULL)
    {
        free(list);// here if there is no memory to allocate for the tmp lets free the list memory
        return 1;
    }
    list = tmp;
    tmp[3]= 4;
    for(int i = 0; i<4; i++)
    {
        printf("%i\n", list[i]);
    }
    free(tmp);
    return 0;
}


//----- DYNAMIC ARRAY-------------------

//dynamicly_allocating_string_chatgpt.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
    char* str = NULL;
    printf("Enter your string: ");
    //allocating memory for the string
    str = malloc(sizeof(char));
    if(str == NULL){
        printf("Memory allocation faile.\n");
        return 1;
        free(str);
    }
    char c;
    int len = 1;
    //read the string char by char
    while ((c=getchar())!='\n' && c != EOF){
        // printf("%c\n",c);
        str = realloc(str, (len + 1 )*sizeof(char));
        if (str == NULL){
            printf("Memory reallocation faile\n");
            free(str);
            return 1;
        }
        //showing the evolution of the reding of ther chars
        // for (int i=0; i<len-1;i++){
        //     printf("%d, %c ", len-1 ,str[i]);
        // }
        str[len-1] = c;

        str[len]='\0'; //setting the value of the last character to null
        len++;
        
    }
    printf("it this the same: %s \n",str);
    printf("length of sting(len): %d\n", len);
    printf("length of sting(strlen): %d\n", (int)strlen(str));
    for(int i = 0; i<=(int)(strlen(str)); i++){
        printf("%d:%c   ",i,str[i]);
    }
    printf("\n");
    free(str);
    return 0; 
}


//gpt_gen_dynamicly_alloc_int_array.c
#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int* array = NULL; // Initialize the array pointer
    size_t size = 0;    // Initialize the size of the array
    printf("Enter values (enter a non-integer to stop):\n");
    int input;
    while (scanf_s("%d", &input, sizeof(int)) == 1 && input != 0) {
        // Allocate memory for a new element
        int* temp = realloc(array, (size + 1) * sizeof(int));
        // Check if memory allocation was successful
        if (temp == NULL) {
            printf("Memory allocation failed.\n");
            free(array);
            return 1;
        }
        array = temp; // Update the array pointer
        array[size] = input; // Add the input to the array
        size++; // Increment the size of the array
    }
    if (feof(stdin)) {
        printf("End of input reached.\n");
    } else {
        printf("Invalid input.\n");
        // Clear the input buffer
        while (getchar() != '\n');
    }
    printf("Values in the array:\n");
    for (size_t i = 0; i < size; i++) {
        printf("%d\n", array[i]);
    }
    // Don't forget to free the allocated memory
    free(array);
    return 0;
}


// sololearn_dynamic_array.c// this is quite stupid 
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int* elements;
    int size;
    int cap;
} dyn_array;
int main(void){
    dyn_array arr;
    arr.size=0;
    arr.elements = calloc(1, sizeof(*arr.elements));
    arr.cap=1;
    arr.elements = realloc(arr.elements, (5+arr.cap)*sizeof(*arr.elements));
    if (arr.elements != NULL){
        arr.cap+=5;
    }
    else if (arr.elements == NULL){
        free(arr.elements);
    }
    if (arr.size < arr.cap) {
        arr.elements[arr.size]=50;
        arr.size++;
    }
    else{
        printf("NEED to expand array.");
    }

    for(int i=0;i < arr.cap; i++){
        printf("element %d: %d \n", i, arr.elements[i]);
    }
    free(arr.elements);
    return 0;
}


//--------------- MEMORY LEAKS CHECK-----------------
//memory.c // suposed to use valgrind but i did use drmemory // in terminal // drmemory -- filename.exe
#include <stdio.h>
#include <stdlib.h>
int main (void)
{
    int *x = malloc(3 * sizeof(int));
    if(x == NULL)
    {
        return 1;
    }
    x[1] = 72;
    x[2] = 73;
    x[3] = 33;
    free(x);
}




// ------ GARBADGE VALUES-------------
//garbage.c
#include <stdio.h>
#include <stdlib.h>
int main (void)
{
    int scores[1240];// without assigning values to an variable there will be garbadge values 
    for (int i = 0; i < sizeof(scores); i++)
    {
        printf("%i\n", scores) // printing garbadge values //there can be anything
    }
}

//------------INPUT--------------
//standart lib
#include <stdio.h>
int main(void)
{
    // scanf will take int floats, chars ect. and even string but with spaces
    // if scanf will detect a space it will take only the first word
    //fgets is used with string with multiple words separated by a space
    int _int;
    float _float;
    double _double;
    char _char;
    char _string[50]; // in stdio lib there is no string -- string is a array of chars
    printf("insert your int\n");
    scanf("%d", &_int); // this will look what is putten int the termian and assing a value to the variable called _int
    printf("insert your float\n");
    scanf("%f", &_float);
    printf("insert your double\n");
    scanf("%lf", &_double);
    printf("insert your char\n");
    scanf("%c", &_char);
    printf("insert your sting\n");
    fgets(_string, sizeof(char*50), stdin);
    printf("insert your sting\n");
    scanf_s("%s5", _string);// %s5 this will insert max 5 characters
}


//------- WORKING WITH FILES -----------------------
//usefull functions
//fopen(<filename>,<mode>); (returna a pointer, if file cannot be open it will retun NULL)<mode> 'r' read(file must exist), 'w' write(file can not exist),'a' append.(file can not exist), 'r+','w+','a+'a
//fclose(<file_pointe>), file pointer is the same file pointer that fopen returns, returns 0 if no error EOF if thers an error
// fgetc(<file_pointer>) will retunr a characeter from a file, if used in loop it will read the next char. when the EOF wash raeach it will return EOF
// fgets(<buffer>,<n>,<file_pointer>) reads n-1 chars from the pointed file, and stores it in the <buffer>, if the fgets encouter '\n' or EOF before the end of n-1 then its stops reading, 
//         if used in loop it will read the next line and store in the buffer next line as a string up to n-1 char
// fscanf(<file_pointer>,<conversion_specifier>,vars) 
// fscanf_s(<file_pointer>,<conversion_specifier>,vars, sizeof(vars)) 

// sololearn_reading_and_printing_file_content.c
#include <stdio.h>
#include <stdlib.h>
int main(void){
    //opening a file 
    FILE* notes;
    int a = fopen_s(&notes, "notes.txt","r");// if ussnig a '/' in file name path u schul use // insted
    if (a != 0 || notes == NULL){
        printf("errorn while opening\n");
        return 1;
    }
    // printing a file to terminal with fgetc - reads character by charracter
    char c;
    while((c = fgetc(notes))!= EOF){ 
        printf("%c",c);// can use putchar(c) this is a fun to put an single char to output 
    }
    rewind(notes);//after using fgetc the position indicator(of fgetc, fgets, etc ) is on EOF so you need to rewind
    printf("\n\n");
    // printing with fgets reads line by line 
    char line[100];
    int i = 1;
    while (fgets(line,sizeof(line),notes) != NULL ){
        printf("line %d:  %s",i,line);
        i++;
    }
    printf("\n\n");
    rewind(notes);
    // printing with fscanf_s reads word by word 
    i = 1;
    char word[20];
    while (fscanf_s(notes, "%s", word, sizeof(line)) != EOF) {
    printf("word %d: %s\n", i, word);
    i++;
    }  
    printf("\n");
    // but if conversion specifier is set correctly you can put out line by line
    rewind(notes);
    i = 1;
    while (fscanf_s(notes, "%99[^\n]\n", word, sizeof(line)) != EOF) {//%99[^\n]\n // %99-put out up to 99 char // [^\n]-read charracters unitl the new line // \n - end with new line
    printf("line %d, %s\n",  i, word);
    }  
   // closing the file
    fclose(notes);
    return 0;
}


// sololearn_reading_and_printing_file_content.c
#include <stdio.h>
#include <stdlib.h>
//added a function just to open afile, read, print to termianl and close the file
int read_print_closed(char a[], FILE *ptr){
    printf("\n___reding from file____\n");
    int x;
    x = fopen_s(&ptr, a,"r");
    // printf("pointer adress: %p\n", ptr);
    if (x != 0 || ptr == NULL){
        printf("errorn while opening\n");
        return 1;
    }
    char line[100];
    
    while (fgets(line,sizeof(line),ptr) != NULL ){
        printf("%s",line);
    }
    printf("\n");
    fclose(ptr);
    return 0;}
// ----
int main(void){
    //declaring variable
    FILE *fptr;
    int stock,a ;
    char b[100], item[20],c;
    float price;
    //opening file
    a = fopen_s(&fptr, "wrintg_prcatice.txt","w");
    if (a != 0 || fptr == NULL){
        printf("errorn while opening\n");
        return 1;
    }
    //writing to file
    fprintf(fptr,"first line\n");   //fprintf - after opening the file it will write the folowing line to the file
    fprintf(fptr,"%d %s %f\n",100, "widget",0.29);
    fputs("End of file", fptr);  //another fuction thats writes on the file // yo could use fputc() i will writes chars to the 
    fclose(fptr);
    //printing to terminal file content
    read_print_closed("wrintg_prcatice.txt",fptr);
    //reading values from file and assigning them to variales
    a = fopen_s(&fptr, "wrintg_prcatice.txt","r");
    if (a != 0 || fptr == NULL){
        printf("errorn while opening\n");
        return 1;
    }
    printf("\n____Reading the file and assigning to variables_______\n");
    fgets(b,sizeof(b),fptr);//reading first line storing it to 'b' variable
    printf("first line: %s",b); // printing to terminal
    fscanf_s(fptr, "%d %s %f",&stock, item, sizeof(item) ,&price );// assigning the values from file to variables in program
    printf("%d, %s, %0.2f",stock,item,price);
    while((c=fgetc(fptr))!=EOF){
        printf("%c",c);
    }
    printf("\n");
    fclose(fptr);
    return 0;
}

//WORKING WITH BINARY FILES
//fopen have modes that are dedicated to read binary files
// 'rb' open and read (file must exist)
// 'wb' open and write (file can not exist)
// 'ab; open for append (file can not exist)
// 'rb+' open for reading and writing, overiting file
// 'ab+' open for reading and writin, append to file
//fwrite(ptr,item_size, num_item,fp), writes num_item of item_size from ptr to the file pointed by fp
//fread(ptr,item_size, num_item,fp), reads num_item of item_size by file fp to memory pointed by ptr
//fclose(fp) closes file opened with file fp, reurning 0 if closed succsessful. EOF is returned i ther is an error in closing
//feof(fp) - Returns 0 when return of the file was reached

// working_with_binary_files.c
#include <stdio.h>

int main(void){
    //declaring variable
    FILE *fptr;
    int arr[10];
    int x[10];
    int k,a;

    //generating number arrays 
    for( k=0; k<10; k++){
        arr[k]=k;
    }

    //wrintg array to file 
    a=fopen_s(&fptr,"datafile.bin","wb");
    fwrite(arr,sizeof(arr[0]),sizeof(arr)/sizeof(arr[0]),fptr); // will write array 'arr' of 'sizeof(arr[0])', of numbers sizeof(arr)/sizeof(arr[0]) to file pointed by fptr
    fclose(fptr);

    //reading the array
    a=fopen_s(&fptr,"datafile.bin","rb");
    fread(x,sizeof(arr[0]), sizeof(arr)/sizeof(arr[0]), fptr); //writes to variable x items of sizeof(arr[0]) and number of sizeof(arr)/sizeof(arr[0]), from file fptr
    fclose(fptr);

    //print the array
    for (k=0; k<10;k++){
        printf("%d\n",x[k]);
    }
    return 0;
}


//CONSTRILING THE FILE POINTER
//ftell(fp) return a long int value corresponding to the fp file pointer position in number from strat of the file
//fseek(fp,num_bytes,from_pos) moves pf file pointer position by num_bytes relatively to the positino from_pos wich can be (SEEK_SET, SEEK_CUR, SEEK_END)
//SEEK_SET- star of file, SEEK_CUR-current position, SEEK_END - EOF)

//reading_records_from_bin_file.c
#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
} item;

int main(void){
    FILE *fptr;
    item first, second, secondf;

    //creating a record//
    first.id = 10276;
    strcpy_s(first.name,strlen("widget "),"widget");
    second.id = 11786;
    strcpy_s(second.name,strlen("Gadget "), "Gadget");

    //writing record to a file 
    int a;
    a = fopen_s(&fptr,"info.dat","wb");
    fwrite(&first,1,sizeof(first),fptr);
    fwrite(&second,1,sizeof(second),fptr);
    fclose(fptr);

    // reading the content of file
    a = fopen_s(&fptr,"info.dat","rb");

    //seekeing second record
    fseek(fptr, 0*sizeof(item), SEEK_SET);//the when you multipy by something yo can 
    fread(&secondf,1,sizeof(item), fptr);
    printf("%d %s\n", secondf.id,secondf.name);
    fseek(fptr, 1*sizeof(item), SEEK_SET);
    fread(&secondf,1,sizeof(item), fptr);
    printf("%d %s\n", secondf.id,secondf.name);
    fclose(fptr);
    return 0;
}


//gpt_reading_anny_bin_file_to_chars.c
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    int a;
    a = fopen_s(&file,"favorites.db", "rb");//.db file is a SQL binary database
    
    if (file == NULL ) {
        perror("Error opening file");
        return 1;
    }

    fseek(file, 0, SEEK_END);// Move to the end of the file
    long file_size = ftell(file);// Get the file size
    fseek(file, 0, SEEK_SET); // Move back to the beginning of the file rewind(file); would work as well


    char *buffer = (char *)malloc(file_size);// Allocate memory to store the file content
        if (buffer == NULL) {
        perror("Error allocating memory");// printing error value
        return 1;
    }

    fread(buffer, 1, file_size, file);// Read the entire file into the buffer
    fclose(file);
    
    //that will print out the valued of the buffer as a chars skipping the special charracters like NULL ect.
    for (long i = 0; i < file_size; i++) { 
        if(((int)buffer[i])<32 || ((int)buffer[i])>127){
            continue;
        }
        printf("%c ", (char)buffer[i]);
    }
    
    free(buffer); // free the buffer
    return 0;
}


// WORKING WITH CSV FILES
//working with csv files.c// cs50
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *csv_file;
int main(void)
{
    errno_t csvfile; // not quite know waht that syntax id for but you need a errno_t type of a variable to open a file
    csvfile = fopen_s(&csv_file, "cvs_file.csv","a"); // opens the file 
    char name[10];
    printf("name up to 10 charracters: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';//strcspn() searches for a first ocurance of a char i string returns the index of it
    //name[strcspn(name, "\n")] = '\0'; is to get rid of the \n that is automaticly in the string from the fgets()
    char number[10];
    printf("number up to 10 dig: ");
    fgets(number, sizeof(number), stdin);
    fprintf(csv_file, "%s,%s", name, number);
    fclose(csv_file);
}


//------- POINTERS IN DATA STRUCTURE & RECURSION -----------------------
//lined_list.c
#include <stdio.h>
#include <stdlib.h>
typedef struct node // you need to add here name of the node if the node apperse as a varibale in a data structure, so you can self refrence it (like a recursion)
{
    int number;
    struct node *next; // here you need to add struct as for the above reson
}
node; // name as usual 

int main(int argc, char *argv[]) // here we give command line arguments// remainder -a argc is the argument count, argv[] is a list of char pointers
{
    node *list = NULL; // now you have a list of 0 elements / list in the first pointer of the node structure
    // here the link list takes form the terminal the values and puts it into the linked list 
    // the list orders so that the new element is at the begining of the list
    for(int i = 1; i < argc ; i++) // i stars at 1 becouse 0 is the file name of the argv //as per the functions 
    {
        int num = atoi(argv[i]); // here we assign the current value from the command promt to the num variable
        // atoi is a function changes a str to an int atoi (ascii to int) 
        node *n = malloc(sizeof(node)); // here we declare a tmp vairable pointer of the node data type and assigning memory by using malloc
        if(n == NULL)
        {//here we check if we have enought space for the varibale 
            return 1; // but in situation that for the second or third element there will be no space you should free the previus nodes from the l.list
        } // so the code is not complete Valgrin or drmemory could point out potential memory leak

        n->number = num; // this gives the value to the element form the num variable // n->number = num; is the same as (*n).number = num;
        n->next = NULL; // here we make sure that the pointer to the next node from the current one is not garbadge value so we assign it NULL bacouse we didnt assign it any value

        n->next = list; // the next should point to the begining of the list which will point to the next element and so we will append 
        list=n; // here we assign the first element to the temp node structure // if that line of code would be before the prievus we would caused a memory leakby orthining the seconde and so one elem.
    }

    node *ptr = list;// declaring a tmp from nude struct pointer for displaying that points at the first element
    // while (ptr !=NULL) // it could be done with a for loop 
    // {
    //     printf("%i\n", ptr->number); // print what the ptr is pointing to 
    //     ptr = ptr->next; // move to the next pointer  
    // }
    for(node *ptr = list; ptr !=NULL; ptr=ptr->next ) // or a while loop as
    {
        printf("%i\n", ptr->number); // print what the ptr is pointing to 
        
    }

    ptr=list;// here ptr is again pointing to the begining of the list
    while (ptr != NULL)//here we free all the allocated memory that was used while creating the l. list
    {
        node *next= ptr->next; // here we create a tmp pointer next that points th the pointer of the first eleent 
        free(ptr); // here we free the vlalue of the first element
        ptr= next;//here we reassign the ptr pointer to point to the next element
    }
}


