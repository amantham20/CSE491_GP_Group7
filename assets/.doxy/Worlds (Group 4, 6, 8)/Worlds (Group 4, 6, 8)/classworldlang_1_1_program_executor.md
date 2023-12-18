

# Class worldlang::ProgramExecutor



[**ClassList**](annotated.md) **>** [**worldlang**](namespaceworldlang.md) **>** [**ProgramExecutor**](classworldlang_1_1_program_executor.md)



_Class that manages program execution._ [More...](#detailed-description)

* `#include <ProgramExecutor.hpp>`















## Classes

| Type | Name |
| ---: | :--- |
| struct | [**Identifier**](structworldlang_1_1_program_executor_1_1_identifier.md) <br> |


## Public Types

| Type | Name |
| ---: | :--- |
| typedef std::function&lt; void([**ProgramExecutor**](classworldlang_1_1_program_executor.md) &)&gt; | [**Callable**](#typedef-callable)  <br> |
| typedef std::variant&lt; size\_t, double, std::string, [**Callable**](classworldlang_1_1_program_executor.md#typedef-callable), [**Identifier**](structworldlang_1_1_program_executor_1_1_identifier.md) &gt; | [**Value**](#typedef-value)  <br>_Variant type containing all possible values types for variables._  |




















## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**ProgramExecutor**](#function-programexecutor-12) () <br>_Constructor._  |
|   | [**ProgramExecutor**](#function-programexecutor-22) (cse491::WorldBase & world) <br>_Constructor with function registration._  |
|  T | [**as**](#function-as) (const [**Value**](classworldlang_1_1_program_executor.md#typedef-value) & a) <br>_Get a value of type T from provided Value._  |
|  void | [**error**](#function-error) (const std::string & error) <br>_Sets the error message and end interpreter execution._  |
|  std::string | [**getErrorMessage**](#function-geterrormessage) () <br>_Gets the error message stored._  |
|  bool | [**has**](#function-has) (const [**Value**](classworldlang_1_1_program_executor.md#typedef-value) & a) <br>_Check whether or not this Value contains the expected type._  |
|  std::vector&lt; [**Value**](classworldlang_1_1_program_executor.md#typedef-value) &gt; | [**popArgs**](#function-popargs) () <br>_Returns all arguments passed to an interpreter function._  |
|  [**Value**](classworldlang_1_1_program_executor.md#typedef-value) | [**popStack**](#function-popstack) () <br>_Retrieves a single value from the interpreter value stack._  |
|  void | [**pushStack**](#function-pushstack) ([**Value**](classworldlang_1_1_program_executor.md#typedef-value) value) <br>_Pushes a single Value onto the interpreter value stack._  |
|  void | [**registerFunction**](#function-registerfunction) (std::string name, [**Callable**](classworldlang_1_1_program_executor.md#typedef-callable) callable) <br>_Registers a function on this_ [_**ProgramExecutor**_](classworldlang_1_1_program_executor.md) _object._ |
|  bool | [**run**](#function-run-12) (const std::string & program) <br>_Executes a program from a string._  |
|  bool | [**run**](#function-run-22) () <br> |
|  bool | [**runFile**](#function-runfile) (const std::string & filename) <br>_Executes a program from a file._  |
|  void | [**setVariable**](#function-setvariable) (const std::string & name, [**Value**](classworldlang_1_1_program_executor.md#typedef-value) value) <br> |
|  void | [**skipBlock**](#function-skipblock) (int nest=0) <br> |
|  T | [**var**](#function-var) (const std::string & name) <br>_Gets the value of a variable as type T._  |
| virtual  | [**~ProgramExecutor**](#function-programexecutor) () = default<br> |




























# Detailed Description


Handles run-time state of program and contains the interpreter function.


Native C++ functions can be registered on this object to extend the functionality. 


    
## Public Types Documentation




### typedef Callable 


```C++
using Callable =  std::function<void(ProgramExecutor&)>;
```



This is the signature interpreter functions should have.


To read the arguments passed to the function, use [**ProgramExecutor::popArgs()**](classworldlang_1_1_program_executor.md#function-popargs). To return values from a function, use [**ProgramExecutor::pushStack()**](classworldlang_1_1_program_executor.md#function-pushstack). 


        



### typedef Value 

```C++
using Value =  std::variant < size_t, double, std::string, Callable, Identifier >;
```



## Public Functions Documentation




### function ProgramExecutor [1/2]

```C++
inline worldlang::ProgramExecutor::ProgramExecutor () 
```






### function ProgramExecutor [2/2]

```C++
inline worldlang::ProgramExecutor::ProgramExecutor (
    cse491::WorldBase & world
) 
```






### function as 

_Get a value of type T from provided Value._ 
```C++
template<typename T typename T>
inline T worldlang::ProgramExecutor::as (
    const Value & a
) 
```



Gets the value of type T from given Value whether it contains a value or an identifier storing that value.


If the value cannot be accessed, sets the error message and returns a default-constructed value.


For example, if your program consists of `a=5` and `b=a` then as&lt;double&gt; will handle both 5 and a correctly as arguments std::get&lt;double&gt; is longer and only handles 5.




**Parameters:**


* `a` Value to retrieve value from 



**Returns:**

Value of type T 





        



### function error 

_Sets the error message and end interpreter execution._ 
```C++
inline void worldlang::ProgramExecutor::error (
    const std::string & error
) 
```



Sets the stored error message for the interpreter. Only the first error set is saved.




**Parameters:**


* `error` Message to store 




        



### function getErrorMessage 

_Gets the error message stored._ 
```C++
inline std::string worldlang::ProgramExecutor::getErrorMessage () 
```



Gets the error message from the interpreter. If no error was set, this will be the empty string.




**Returns:**

Error message 





        



### function has 

_Check whether or not this Value contains the expected type._ 
```C++
template<typename T typename T>
inline bool worldlang::ProgramExecutor::has (
    const Value & a
) 
```



Checks the type of the given Value. If the type does not match and cannot be obtained, sets the interpreter error message and returns false. Otherwise, returns true.




**Parameters:**


* `a` Value to validate type of. 



**Returns:**

true if type is usable 





        



### function popArgs 

_Returns all arguments passed to an interpreter function._ 
```C++
inline std::vector< Value > worldlang::ProgramExecutor::popArgs () 
```



This function retrieves the arguments of the function in the same order as in the source code. The end of the argument list is determined by an internal special [**Identifier**](structworldlang_1_1_program_executor_1_1_identifier.md)


This function should be called once for any Callable to get the arguments passed.




**Returns:**

Vector of Values provided to an interpreter function. 





        



### function popStack 

_Retrieves a single value from the interpreter value stack._ 
```C++
inline Value worldlang::ProgramExecutor::popStack () 
```





**Returns:**

Value object from stack. 





        



### function pushStack 

_Pushes a single Value onto the interpreter value stack._ 
```C++
inline void worldlang::ProgramExecutor::pushStack (
    Value value
) 
```





**Parameters:**


* `value` Value to push to interpreter stack 




        



### function registerFunction 

_Registers a function on this_ [_**ProgramExecutor**_](classworldlang_1_1_program_executor.md) _object._
```C++
inline void worldlang::ProgramExecutor::registerFunction (
    std::string name,
    Callable callable
) 
```



This allows the given function to be called from the interpreter via a function called `name`.




**Note:**

Names can be overridden by the user's program if they overwrite `name`.




**Parameters:**


* `name` Function name 
* `callable` Function accepting a [**ProgramExecutor**](classworldlang_1_1_program_executor.md)& with no return. 




        



### function run [1/2]

_Executes a program from a string._ 
```C++
inline bool worldlang::ProgramExecutor::run (
    const std::string & program
) 
```



Executes a program from a string. This is the main interpreter function. See Language.hpp for most interesting syntax and parsing details.




**Parameters:**


* `program` Program to run. 



**Returns:**

true if program ran successfully, false if an error occured 





        



### function run [2/2]

```C++
inline bool worldlang::ProgramExecutor::run () 
```






### function runFile 

_Executes a program from a file._ 
```C++
inline bool worldlang::ProgramExecutor::runFile (
    const std::string & filename
) 
```





**Parameters:**


* `filename` File to load 



**Returns:**

true if program ran successfully, false if an error occured 





        



### function setVariable 

```C++
inline void worldlang::ProgramExecutor::setVariable (
    const std::string & name,
    Value value
) 
```






### function skipBlock 


```C++
inline void worldlang::ProgramExecutor::skipBlock (
    int nest=0
) 
```



Moves the interpreter's program counter to the end of the current block.




**Parameters:**


* `nest` Optional starting nest value (defaults to zero) Begins as if it was nested within this many `start_block` operations. 




        



### function var 

_Gets the value of a variable as type T._ 
```C++
template<typename T typename T>
inline T worldlang::ProgramExecutor::var (
    const std::string & name
) 
```





**Exception:**


* `std::out_of_range` if it is not defined 
* `std::bad_variant_access` if variable is wrong type 



**Parameters:**


* `name` Variable name to check 



**Returns:**

Value of variable as type T 





        



### function ~ProgramExecutor 

```C++
virtual worldlang::ProgramExecutor::~ProgramExecutor () = default
```




------------------------------
The documentation for this class was generated from the following file `source/Worlds/ProgramExecutor.hpp`

