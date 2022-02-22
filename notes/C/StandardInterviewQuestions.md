## <span style="text-decoration:underline;">Operating Systems</span>

1. Describe inheritance, multithreading, watchdog timer, etc.
    1. Inheritance: Inheritance allows us to define a class in terms of another class, which makes it easier to create and maintain an application.    Inheritance allows to reuse the code functionally and allows fast implementation time.
    2. Multi-threading: Multi-threading is the ability of a program to manage its use by more than one user at a time and to even manage multiple requests by the same user without having to have multiple copies of the programming running in the computer.
    3.  Watchdog timer: WDT is a piece of hardware that can be used to automatically detect software anomalies and reset the processor if any occur.
2. What is virtual memory and caches(Also read upon Cache coherency) 
    4. Physical memory is scarce in machines, so virtual memory is an optimization to expand that
    5. Memory stored in pages in hard disk and by using caches  
3. What are priority inversion, reentrancy, spinlocks
    6. Priority Inversion: lower priority task running with semaphore, higher priority is waiting for semaphore. Medium priority task interrupts, runs, and then high priority can run
        1. Solution is to bump priority of low priority to highest priority and then it can’t be preempted by medium (It’s called priority inheritance)
    7. Reentrant: function is reentrant when during its execution if it gets interrupted, it can return and resume function without any change
        2. Can’t use global/static data
    8. Spin-lock: a task is waiting for a certain resource that is locked and is continually checking if it opened up, using most of the CPU resources
        3. Good rule of thumb - avoid them in user code
4. What is atomic programming/non-locking operation?
    9. Atomic operations are operations that are guaranteed to keep their values safe

        Atomicity


```
    In computer programming, an operation done by a computer is considered _atomic_ if it is guaranteed to be isolated from other operations that may be happening at the same time. Put another way, atomic operations are indivisible.
```

5. What is concurrency, parallelism and multithreading?
    10. Concurrency is essentially applicable when we talk about minimum two tasks or more. When an application is capable of executing two tasks virtually at same time, we call it concurrent application. Though here tasks run looks like simultaneously, but essentially they MAY not. They take advantage of CPU time-slicing feature of operating system where each task run part of its task and then go to waiting state. When first task is in waiting state, CPU is assigned to second task to complete it’s part of task. Operating system based on priority of tasks, thus, assigns CPU and other computing resources e.g. memory; turn by turn to all tasks and give them chance to complete. To end user, it seems that all tasks are running in parallel. This is called concurrency.
    11. Parallelism does not require two tasks to exist. It literally physically run parts of tasks OR multiple tasks, at the same time using multi-core infrastructure of CPU, by assigning one core to each task or sub-task. Parallelism requires hardware with multiple processing units, essentially. In single core CPU, you may get concurrency but NOT parallelism.
6. Difference between Thread and Process
    12. A process has all the resources needed to execute a program - memory space, registers, stack space, security etc
    13. A thread is a line of execution and exists within a process
7. Mutexes and semaphores? what is the main difference between them? what is the difference between binary semaphore and mutex? how does locking happen i ln mutex?
    14. Mutex is for exclusive access to a resource. A Binary semaphore should be used for Synchronization (i.e. "Hey Someone! This occurred!").
    15. Semaphores signal between tasks
        4. B gives semaphore and A takes it, a task doesn't give and take it by itself
    16. [https://stackoverflow.com/questions/62814/difficult ference-between-binary-semaphore-and-mutex](https://stackoverflow.com/questions/62814/difference-between-binary-semaphore-and-mutex) 
8. What is thrashing? what is excessive paging? The main areas as seen on the believe as it is not 
    17. Have virtual memory that is > RAM size
    18. So OS constantly is àswapping contents in and out of virtual memory
    19. Thrashing is when this uses most of the processing power
9. What is dynamic loading? what is static loading? when to use dynamic loading? what are the advantages? give an example when to use dynamic loading?
    20. Dynamic loading is when code is loaded into memory dynamically
    21. Static is when it’s all resolved at compile time
10. Difference between regular OS and real-time OS
    22. RTOS used for time critical systems
    23. Task scheduling in RTOS is priority based, in regular OS is high throughput
    24. Kernels in RTOS are preemptable
        5. If high priority request comes in, they can preempt OS requests
11. OS concepts-what is mutual exclusion?
    25. When two processes try to enter a critical region one will be blocked
12. Priorities of OS programs?
    26. EL0 - general application
    27. EL1 - OS
    28. EL2 - hypervisor
    29. EL3 - security stuff
13. Describe critical section
14. [https://leetcode.com/discuss/interview-question/124638/what-happens-in-the-background-from-the-time-you-press-the-Power-button-until-the-Linux-login-prompt-appears/](https://leetcode.com/discuss/interview-question/124638/what-happens-in-the-background-from-the-time-you-press-the-Power-button-until-the-Linux-login-prompt-appears/) 

##  C/C++ Concepts

1. What is static in C?

    Static variable is one which <span style="text-decoration:underline;">maintains its value throughout the function invocations</span>.

    1. A static variable inside a function keeps its value between invocations.
    2. A static global variable or a function is "seen" only in the file it's declared in.
2. What is volatile keyword?

    A volatile variable <span style="text-decoration:underline;">can change unexpectedly and compiler cannot make any assumptions </span>about it 


```
[http://www.drdobbs.com/cpp/volatile-the-multithreaded-programmers-b/184403766](http://www.drdobbs.com/cpp/volatile-the-multithreaded-programmers-b/184403766) 
```

3. Difference between linked list and array? when to use linked list?

    Linked list are located in heap memory and its allocated dynamically.


```
Linked list relies on references where each node consists of the data and the references to the previous and next element.
```


```
Array is a continuous block of memory stored in sequential memory.
```


```
Arrays are index based data structure where each element associated with an index. 
```


<table>
  <tr>
   <td>
    BASIS FOR COMPARISON
   </td>
   <td>
    ARRAY
   </td>
   <td>
    LINKED LIST
   </td>
  </tr>
  <tr>
   <td>
    Basic
   </td>
   <td>
    It is a consistent set of a fixed number of data items.
   </td>
   <td>
    It is an ordered set comprising a variable number of data items.
   </td>
  </tr>
  <tr>
   <td>
    Size
   </td>
   <td>
    Specified during declaration.
   </td>
   <td>
    No need to specify; grow and shrink during execution.
   </td>
  </tr>
  <tr>
   <td>
    Storage Allocation
   </td>
   <td>
    Element location is allocated during compile time.
   </td>
   <td>
    Element position is assigned during run time.
   </td>
  </tr>
  <tr>
   <td>
    Order of the elements
   </td>
   <td>
    Stored consecutively my.
   </td>
   <td>
    Stored randomly.
   </td>
  </tr>
  <tr>
   <td>
    Accessing the element
   </td>
   <td>
    Direct or randomly accessed, i.e., Specify the array index or subscript.
   </td>
   <td>
    Sequentially accessed, i.e., Traverse starting from the first node in the list by the pointer.
   </td>
  </tr>
  <tr>
   <td>
    Insertion and deletion of element
   </td>
   <td>
    Slow relatively as shifting is required.
   </td>
   <td>
    Easier, fast and efficient.
   </td>
  </tr>
  <tr>
   <td>
    Searching
   </td>
   <td>
    Binary search and linear search.
   </td>
   <td>
    linear search.
   </td>
  </tr>
  <tr>
   <td>
    Memory required
   </td>
   <td>
    less.
   </td>
   <td>
    More.
   </td>
  </tr>
  <tr>
   <td>
    Memory Utilization
   </td>
   <td>
    Ineffective
   </td>
   <td>
    Efficient
   </td>
  </tr>
</table>



```
-->when to use linked list

3. you need constant-time insertions/deletions from the list (such as in real-time computing where time predictability is absolutely critical)
4. you don't know how many items will be in the list. With arrays, you may need to re-declare and copy memory if the array grows too big.
5. you don't need random access to any elements
6. you want to be able to insert items in the middle of the list (such as a priority queue)
```
4. What are dangling pointers? where to use them?
    7. A [dangling pointer](http://en.wikipedia.org/wiki/Dangling_pointer) points to memory that has already been freed. The storage is no longer allocated. Trying to access it might cause a Segmentation fault. A pointer pointing to a memory location that has been deleted (or freed) is called dangling pointer. 
    8. A [memory leak](http://www.ibm.com/developerworks/aix/library/au-toughgame/) is memory which hasn't been freed, there is no way to access (or free it) now, as there are no ways to get to it anymore. 
    9. Dangling pointers are not used knowingly. They must not be used at all because they result in program crash and segmentation fault. Also they eat up the memory space unnecessarily. So ONE MUST BE CAREFUL and deallocate or NULLIFY the pointer before deleting the variable pointed to by it.
5. What are structures and unions? when to use what? sizes ?
    10. Each member in struct gets own memory location in the section
    11. Size of union is the size of largest member
        1. Only one member can have a value at a time
    12. Unions are used when:
1. We create a discriminated union. That's probably what you were thinking of by "space optimization"
2. Also need an extra bit of data to know which member of the union is "alive" (has valid data in it)
6. What is free()? how does free know how much memory to deallocate?
    13. [https://stackoverflow.com/questions/1957099/how-do-free-and-malloc-work-in-c](https://stackoverflow.com/questions/1957099/how-do-free-and-malloc-work-in-c)

    When you malloc a block, it actually allocates a bit more memory than you asked for. This extra memory is used to store information such as the size of the allocated block, and a link to the next free/used block in a chain of block


```markdown
When you free your pointer, it uses that address to find the special information it added to the beginning (usually) of your allocated block. If you pass in a different address, it will access memory that contains garbage, and hence its behaviour is undefined (but most frequently will result in a crash)
```

7. What is the difference between class and object? does class or object create memory? basically learn every detail about classes and objects and just the definition.
    14. Classes are static, they just define properties of the object
    15. When a class is instantiated, it is an object and takes up memory

<span style="text-decoration:underline;">Class</span>: The building block of C++ that leads to Object Oriented programming is a Class. It is a user defined data type, which holds its own data members and member functions, which can be accessed and used by creating an instance of that class. A class is like a blueprint for an object.

An <span style="text-decoration:underline;">Object </span>is an instance of a Class. When a class is defined, no memory is allocated but when it is instantiated (i.e. an object is created) memory is allocated.

<span style="text-decoration:underline;">Examples</span>: If channel is a class, Star Sports, BBC, and ESPN are its objects. 

a class "CAR" : Its objects are Hyundai, Ford, Suzuki. It will have the same methods but different designs -> this is how you can relate objects and classes with the real world.

8. what are virtual functions? How are they used? Why are they used? When are they used? Example?
    16. To achieve runtime polymorphism
    17. They are defined in base classes - and overridden in derived classes
    18. For example, input vehicle...but don’t know if car, bus, or truck

A virtual function is a member function which is declared within base class and is re-defined (Overridden) by derived class. When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class’s version of the function.

* Virtual functions ensure that the correct function is called for an object, regardless of the type of reference (or pointer) used for function call.
* They are mainly used to achieve[ Runtime polymorphism](https://www.geeksforgeeks.org/polymorphism-in-c/)
* Functions are declared with a virtual keyword in base class.
* The resolving of function call is done at Run-time.
9. How is multiply is implemented?
    19. Set result to 0
    20. Repeat
    21. Shift 2nd multiplicand left until rightmost digit is lined up with leftmost 1 in first multiplicand
        2. Add 2nd multiplicand in that position to result
        3. Remove that 1 from 1st multiplicand
    22. Until 1st multiplicand is zero
    23. Result is correct
10. Design an elevator system
    24. I started from thinking about how many buttons (including buttons inside the elevator, and outside for every floor) should be tracked in this system.
    25. After that, considered how to implement an ISR (interrupt service routine) and what data structure should be used (maybe a queue for the next targeted store, and a array for status of all buttons) to track them, and use these information to control the elevator.
11. How post increment works.
    26. You use the value first and then increment it.
12. One questioner asked how to modify a malloc to guarantee that it was 32-byte aligned
    27. ptr & ~0x1F will set the last 5 bits to 0, making it 32 byte aligned
13. How do breakpoints in a C program work? 
1. [http://www.nynaeve.net/?p=80](http://www.nynaeve.net/?p=80) 
14. How does a debugger work? 
15. ISR & interrupt vector table
    28. ISR addresses stored in vector table
16. Float to int conversion
17. Memory map of program
    29. Output from linker script
    30. BSS is uninitialized data
    31. Data is initialized data
    32. Text is names, symbols etc
18. If we declare more number of variables than the registers available on the processor? Where they will be stored.
    33. In some memory block and they are loaded back appropriately into registers
    34. Have to remove something that’s in memory at that point
19. How to handle the Generic functions , like Void pointers
    35. Function that accepts void pointers should only accept one type
20. Data Struct/Class memory padding
    36. // char         1 byte
    37. // short int    2 bytes
    38. // int          4 bytes
    39. // double       8 bytes
    40. // pointer      4 bytes in 32 bit machine, 8 in 64-bit
    41. Memory is padded to nearest multiple
    42. For optimizing memory accesses for byte addressable memory
21. Difference between Macro and Inline?				
    43. Macros are used for repeating functions throughout the code, so you use #define at the top and the preprocessor typically takes care of this
    44. Inline functions tell the compiler that the function is also defined at that spot -so you save time by not jumping to another location, jumping back,
    45. Inline functions provides following advantages over macros.
* Since they are functions so type of arguments is checked by the compiler whether they are correct or not.
* There is no risk if called multiple times. But there is risk in macros which can be dangerous when the argument is an expression.
* They can include multiple lines of code without trailing backslashes.
* Inline functions have their own scope for variables and they can return a value.
* Debugging code is easy in case of Inline functions as compared to macros.
22. How to avoid overflow/underflow
    46. Use types like long double for more precision and more bits
23. How do you send data over the network between two machines with different endianess 
    47. [https://www.ibm.com/developerworks/aix/library/au-endianc/index.html](https://www.ibm.com/developerworks/aix/library/au-endianc/index.html) 
    48. [https://barrgroup.com/Embedded-Systems/How-To/Big-Endian-Little-Endian](https://barrgroup.com/Embedded-Systems/How-To/Big-Endian-Little-Endian)

## Coding

1. Write a C Program to reverse the words in a sentence
    1. I used pointer arithmetic to solve the problem. First I reversed the characters in the whole sentence and then in the next step, each word was reversed.
2. Write a C program to encode bits in a 32-bit number such that, most significant 16 bits should be reversed but lower 16 bits should be untouched. Then asked to generalize this to any number of bits.
    2. Reverse all with this [http://www.geeksforgeeks.org/write-an-efficient-c-program-to-reverse-bits-of-a-number/](http://www.geeksforgeeks.org/write-an-efficient-c-program-to-reverse-bits-of-a-number/) 
    3. Left shift by 16 so upper 16 are reversed
    4. AND original nbr with 0x0000FFFF to zero out upper 16
    5. XOR c and d 
3. Count the number of set bits in an integer
    6. Just do n &= (n-1) in a while loop and increment count, return count
    7. Subtraction of 1 from a number toggles all the bits (from right to left) till the rightmost set bit(including the rightmost set bit). So if we subtract a number by 1 and do bitwise & with itself (n & (n-1)), we unset the rightmost set bit. If we do n & (n-1) in a loop and count the no of times loop executes we get the set bit count.
    8. Beauty of the this solution is number of times it loops is equal to the number of set bits in a given integer.
    9. http://www.geeksforgeeks.org/count-set-bits-in-an-integer/
4. Bit manipulation questions - detect pattern of ones, write masks to insert pattern of ones in a 32 bit integer, swapping adjacent odd and even bits (Answer link: [https://www.geeksforgeeks.org/swap-all-odd-and-even-bits/](https://www.geeksforgeeks.org/swap-all-odd-and-even-bits/))
5. String and array manipulations - reverse string, reverse words in a string, find duplicates in an array  
6. Writs
7. Find the first non-recurring character in string. i.e. input "abbcdcaea" would return "d" 
    10. [https://www.glassdoor.com/Interview/white-board-find-the-first-non-recurring-character-in-a-string-i-e-input-abbcdcaea-would-return-d-QTN_1942494.htm](https://www.glassdoor.com/Interview/white-board-find-the-first-non-recurring-character-in-a-string-i-e-input-abbcdcaea-would-return-d-QTN_1942494.htm)
8. Implement a queue/fifo with push/pop functionality using linked lists
9. Create a custom malloc and free function using linked lists
10. Swap the values of two pointers without a temp variable
    11. Switch with 3 x ^ y…….x=, y=, and then x-
    12. http://www.geeksforgeeks.org/swap-two-numbers-without-using-temporary-variable/
11. Write a function that determines if a given variable is a power of 2 or not
    13. ((x != 0) && !(x & (x - 1)));
        1. Works for other than 0 so need another check for 0
12. Programming problem (live) (reverse a linked list)
13. Function that takes a 2D array of a "sudoku board", and checks to make sure it is a possible board
14. Explain and describe how binary search tree works
    14. O(n) worst, O(log n) average
15. Given a list from 1 to 100, name all the different ways you can determine if there are duplicates. Which is the most efficient?
    15. Double for loop O(n^2)
    16. Sum all the elements, if it is greater than n(n+1)/2 then duplicates O(n)
    17. Add elements in a set as you go, if it already exists there are duplicates O(n)
    18. Add into a hashmap, keeping count of nbr times it shows up O(n)
    19. Sort, and compare element to element before it O(n)
16. Another way to find the sizeof and data type without using sizeof()?
    20. ((&(var)+1) - &var)
17. Write a C++ program to find a loop in a linked list.
18. Write code in C that would hash a string and deal with collision resolution by implementing a linked list. Would this code be thread safe? 
19. How to change a string to integer
    21. Strtol method
20. Write a program to Delete a node , given only a pointer to the node in a Circular linked list
21. Write a own program for strstr function
    22. Returns first occurrence of str2 in str2
22. Write a program to convert a given singly Linked list to BST
* 1) Get the Middle of the linked list and make it root. \
2) Recursively do same for left half and right half. \
       a) Get the middle of left half and make it left child of the root \
          created in step 1. \
       b) Get the middle of right half and make it right child of the \
          root created in step 1.
23. Swapping Big Endian to Little Endian and vice versa
    23. https://stackoverflow.com/questions/2182002/convert-big-endian-to-little-endian-in-c-without-using-provided-func
24. Write a program to implement memcpy()
    24. Copies memory from one location to another for x bytes
25. Delete nth end from end of linked list
26.  Write a program to share a resource - [https://www.thecrazyprogrammer.com/2016/09/producer-consumer-problem-c.html](https://www.thecrazyprogrammer.com/2016/09/producer-consumer-problem-c.html) 
27. Write a program to identify Big Endian vs Little Endian 
28. Bit Manipulation questions - 
    25. Reverse the bits of an integer
    26. Check the parity of a given number
    27. Swap bits in a given integer(positions are provided)
29. Write your own functions for the following - 
    28. Sizeof Function 
    29. Memcpy
    30. Memmove
    31. Malloc
    32. Free
30. Asked to implement a dictionary(of strings) in C(storing and searching).
31. Find the smallest and largest number in an array of large elements.

## General

1. Finding the direction of a rotating disc
    1. Quadrature decoding
2. A brain teaser question where we have to find out 45 minutes with the help of two ropes. Given that one rope burns completely in 1 Hr and the rate or burning is not consistent.
    2. Burn first rope from both ends, and second rope from one end only.
    3. When First has completely burned, 30 mins will have passed and second rope will have 30 mins left on it.
    4. Now burn second rope, which has burned for 30 mins already, from both ends, this will burn a 30 minute rope at twice the speed, making it complete in 15 mins.
    5. This will be 45 minutes total.
3. What are interrupts and if you have less external interrupt pins on a processor, how to interface multiple interrupts?
4. Explain CDMA, LTE etc.
5. What is the difference between tcp and udp.
6. Call back functions
    6. Is a function that is passed as a parameter and is called after some event occurs

## UART

* Universal Asynchronous Receiver/Transmitter
* Serial data
* 2 wires
    * Rx & Tx
* No clock signal to synchronize the data
    * Adds stop and start bits to identify 
    * Both UARTs ports have to operate at similar baud rate
* Doesn’t support multiple masters/slaves, just 2 devices

## SPI

* Serial Peripheral Interface
* One master that can control multiple slaves
* MISO, MOSI, CLK, SS
* Data can be streamed continuously

```
No stop/start bits 
```

## I2C

* SDA/SCL
* Synchronized to the clock signal
* Start + Address Frame + ACK + Data Frames + ACK + Stop
* Both ways transfer

## CAN

* Controller Area Network
* Asynchronous Serial communication
* CSMA/CD (collision detection), but with priority levels for collision
* Normal state is around 2.5V, CANH is at 3.5V and CANL is at around 1.5V, differential signal

## Bluetooth Low Energy (BLE)

* Slave connections are exclusive
    * Master can connect to multiple slaves, but slave can only connect to one master
* GATT profile
    * Services - functions
    * Characteristics - data points
* Advertising mode - sends out info to nearby peripherals
* Connected mode - one on one connection where they share data
* Range of 100m (Bluetooth 5 Coded PHYs can extend this much further)
* Point to point, mesh network (Bluetooth Mesh has a separate specification)

Advantage of mesh is that they can communicate amongst themselves z without the need for a special gateway.

## 4G/LTE

* CDMA uses code division multiplexing
* LTE is an IP based system (data centric)
* IP tunnel
* High speed/low latency

## 5G

* Goal is to simultaneously be able to connect to thousands of devices
    * Increased throughput, decreased latency
* Higher frequency for faster transmission
* Not official yet


## Sorting Algorithms


<table>
  <tr>
   <td rowspan="2" >Sort
   </td>
   <td colspan="3" >Time Complexity
   </td>
   <td colspan="3" >Space Complexity
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>Best
   </td>
   <td>Worst
   </td>
   <td>Average
   </td>
   <td>Best
   </td>
   <td>Worst
   </td>
   <td>Average
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>Bubble Sort
   </td>
   <td>O(n^2)
   </td>
   <td>O(n^2)
   </td>
   <td>O(n^2)
   </td>
   <td>O(1)
   </td>
   <td>O(1)
   </td>
   <td>O(1)
   </td>
   <td>completes some pre sorting
   </td>
  </tr>
  <tr>
   <td>Adaptive Bubble
   </td>
   <td>O(n)
   </td>
   <td>O(n^2)
   </td>
   <td>O(n^2)
   </td>
   <td>O(1)
   </td>
   <td>O(1)
   </td>
   <td>O(1)
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>Selection Sort
   </td>
   <td>O(n^2)
   </td>
   <td>O(n^2)
   </td>
   <td>O(n^2)
   </td>
   <td>O(1)
   </td>
   <td>O(1)
   </td>
   <td>O(1)
   </td>
   <td>good for small arrays
   </td>
  </tr>
  <tr>
   <td>Insertion Sort
   </td>
   <td>O(n^2)
   </td>
   <td>O(n^2)
   </td>
   <td>O(n^2)
   </td>
   <td>O(1)
   </td>
   <td>O(1)
   </td>
   <td>O(1)
   </td>
   <td>good on partially sorted data
   </td>
  </tr>
  <tr>
   <td>Adaptive Insertion
   </td>
   <td>O(n^2)
   </td>
   <td>O(n^2)
   </td>
   <td>O(n^2)
   </td>
   <td>O(1)
   </td>
   <td>O(1)
   </td>
   <td>O(1)
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>Bucket Sort
   </td>
   <td>O(n)
   </td>
   <td>O(n)
   </td>
   <td>O(n)
   </td>
   <td>O(1)
   </td>
   <td>O(1)
   </td>
   <td>O(1)
   </td>
   <td>good for small universes
   </td>
  </tr>
  <tr>
   <td>Quick Sort
   </td>
   <td>O(n log n)
   </td>
   <td>O(n^2)
   </td>
   <td>O(n log n)
   </td>
   <td>O(1)
   </td>
   <td>O(log n)
   </td>
   <td>O(log n)
   </td>
   <td>fastest sort, good to start out and do insertion for internal loop
   </td>
  </tr>
  <tr>
   <td>Merge Sort
   </td>
   <td>O(n log n)
   </td>
   <td>O(n log n)
   </td>
   <td>O(n log n)
   </td>
   <td>O(n)
   </td>
   <td>O(n)
   </td>
   <td>O(n)
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>Heap Sort
   </td>
   <td>O(n log n)
   </td>
   <td>O(n log n)
   </td>
   <td>O(n log n)
   </td>
   <td>O(1)
   </td>
   <td>O(1)
   </td>
   <td>O(1)
   </td>
   <td>fixdown, fixup (log n), build heap (n) heapsort( build heap and fix down from bottom)
   </td>
  </tr>
</table>


Additional firmware interview Questions - from glassdoor

1. Swap two variables without using a temporary variable
2. How to invert all bits in a byte?
3. C function that takes two bit indices and an int, reverses the bits in the int between the two indices. 
4. Name a few different type of registers.
5. What is priority inversion and methods to avoid it?
6. Disadvantage of recursive function call in C in a resource constrained environment.
7. What is an interface?
8. What is an abstract class? - C++ concepts
9. How many pins in JTAG cable? - 20
10. What techniques would you use to reduce power consumption in an embedded system?
    1. Sleep modes , refresh operation
11. What kind of data structure you will use to store data from a serial receive line?
    2. Queue - FIFO

     12. Write a C program to determine endianness of a microprocessor

     13. Detect loop in a linked list

     14. Difference between semaphore, mutex and spinlock

     15. What are some ways in which UART can have communication error?

     16. Traversing Binary Tree 

     17. Find an element using Binary Search in array

     18. Switch debouncing software logic

     19. Where do global variables get stored?

     20. Inter thread communication, Inter process communication

     21. What is extern variable?

5 Memory Segments in C:

## 1. Code Segment

* The code segment, also referred as the text segment, is the area of memory which contains the frequently executed code.
* The code segment is often read-only to avoid risk of getting overridden by programming bugs like buffer-overflow, etc.
* The code segment does not contain program variables like local variable (_also called as automatic variables in C_), global variables, etc.
* Based on the C implementation, the code segment can also contain read-only string literals. For example, when you do printf("Hello, world") then string "Hello, world" gets created in the code/text segment. You can verify this using size command in Linux OS.
* [Further reading](https://en.wikipedia.org/wiki/Code_segment)


## Data Segment

The data segment is divided in the below two parts and typically lies below the heap area or in some implementations above the stack, but the data segment never lies between the heap and stack area.

### 2. Uninitialized data segment

* This segment is also known as bss.
* This is the portion of memory which contains:
    1. Uninitialized global variables _(including pointer variables)_
    2. Uninitialized constant global variables.
    3. Uninitialized local static variables.
* Any global or static local variable which is not initialized will be stored in the uninitialized data segment
* For example: global variable int globalVar; or static local variable static int localStatic;will be stored in the uninitialized data segment.
* If you declare a global variable and initialize it as 0 or NULL then still it would go to uninitialized data segment or bss.
* [Further reading](https://en.wikipedia.org/wiki/.bss)

### 3. Initialized data segment

* This segment stores:
    1. Initialized global variables _(including pointer variables)_
    2. Initialized constant global variables.
    3. Initialized local static variables.
* For example: global variable int globalVar = 1; or static local variable static int localStatic = 1; will be stored in initialized data segment.
* This segment can be further classified into initialized read-only area and initialized read-write area. _Initialized constant global variables will go in the initialized read-only area while variables whose values can be modified at runtime will go in the initialized read-write area_.
* _The size of this segment is determined by the size of the values in the program's source code, and does not change at run time_.
* [Further reading](https://en.wikipedia.org/wiki/Data_segment)

## 4. Stack Segment

* Stack segment is used to store variables which are created inside functions (_function could be main function or user-defined function_), variable like
    1. Local variables of the function _(including pointer variables)_
    2. Arguments passed to function
    3. Return address
* Variables stored in the stack will be removed as soon as the function execution finishes.
* [Further reading](https://en.wikipedia.org/wiki/Stack-based_memory_allocation)

## 5. Heap Segment

* This segment is to support dynamic memory allocation. If the programmer wants to allocate some memory dynamically then in C it is done using the malloc, calloc, or realloc methods.
* For example, when int* prt = malloc(sizeof(int) * 2) then eight bytes will be allocated in heap and memory address of that location will be returned and stored in ptr variable. The ptrvariable will be on either the stack or data segment depending on the way it is declared/used.