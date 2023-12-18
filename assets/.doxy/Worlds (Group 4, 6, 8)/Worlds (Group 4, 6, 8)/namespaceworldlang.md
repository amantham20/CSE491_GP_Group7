

# Namespace worldlang



[**Namespace List**](namespaces.md) **>** [**worldlang**](namespaceworldlang.md)



_Namespace for scripting language stuff._ 
















## Classes

| Type | Name |
| ---: | :--- |
| class | [**ProgramExecutor**](classworldlang_1_1_program_executor.md) <br>_Class that manages program execution._  |
| struct | [**Unit**](structworldlang_1_1_unit.md) <br> |
| struct | [**add**](structworldlang_1_1add.md) <br> |
| struct | [**add\_a**](structworldlang_1_1add__a.md) <br> |
| struct | [**assignment**](structworldlang_1_1assignment.md) <br> |
| struct | [**code\_block**](structworldlang_1_1code__block.md) <br> |
| struct | [**comment**](structworldlang_1_1comment.md) <br> |
| struct | [**comp**](structworldlang_1_1comp.md) <br> |
| struct | [**comp\_a**](structworldlang_1_1comp__a.md) <br> |
| struct | [**element**](structworldlang_1_1element.md) <br> |
| struct | [**expression**](structworldlang_1_1expression.md) <br> |
| struct | [**expression\_list**](structworldlang_1_1expression__list.md) <br> |
| struct | [**function**](structworldlang_1_1function.md) <br> |
| struct | [**identifier**](structworldlang_1_1identifier.md) <br> |
| struct | [**identifier\_list**](structworldlang_1_1identifier__list.md) <br> |
| struct | [**mul**](structworldlang_1_1mul.md) <br> |
| struct | [**mul\_a**](structworldlang_1_1mul__a.md) <br> |
| struct | [**number**](structworldlang_1_1number.md) <br> |
| struct | [**op\_prio\_add**](structworldlang_1_1op__prio__add.md) <br> |
| struct | [**op\_prio\_comp**](structworldlang_1_1op__prio__comp.md) <br> |
| struct | [**op\_prio\_mul**](structworldlang_1_1op__prio__mul.md) <br> |
| struct | [**program**](structworldlang_1_1program.md) <br> |
| struct | [**statement**](structworldlang_1_1statement.md) <br> |
| struct | [**statement\_list**](structworldlang_1_1statement__list.md) <br> |
| struct | [**string**](structworldlang_1_1string.md) <br> |


## Public Types

| Type | Name |
| ---: | :--- |
| typedef tao::pegtl::parse\_tree::selector&lt; Rule, tao::pegtl::parse\_tree::store\_content::on&lt; [**number**](structworldlang_1_1number.md), [**string**](structworldlang_1_1string.md), [**function**](structworldlang_1_1function.md), [**identifier**](structworldlang_1_1identifier.md), [**identifier\_list**](structworldlang_1_1identifier__list.md), [**expression**](structworldlang_1_1expression.md), [**expression\_list**](structworldlang_1_1expression__list.md), [**statement**](structworldlang_1_1statement.md), [**statement\_list**](structworldlang_1_1statement__list.md), [**code\_block**](structworldlang_1_1code__block.md), [**program**](structworldlang_1_1program.md), [**assignment**](structworldlang_1_1assignment.md), [**op\_prio\_add**](structworldlang_1_1op__prio__add.md), [**op\_prio\_mul**](structworldlang_1_1op__prio__mul.md), [**op\_prio\_comp**](structworldlang_1_1op__prio__comp.md) &gt;, tao::pegtl::parse\_tree::fold\_one::on&lt; [**add\_a**](structworldlang_1_1add__a.md), [**mul\_a**](structworldlang_1_1mul__a.md) &gt; &gt; | [**selector**](#typedef-selector)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  std::vector&lt; [**Unit**](structworldlang_1_1_unit.md) &gt; | [**parse\_to\_code**](#function-parse_to_code) (std::string program) <br> |
|  std::string | [**stripWhitespace**](#function-stripwhitespace) (const std::string & input) <br> |




























## Public Types Documentation




### typedef selector 


```C++
using selector =  tao::pegtl::parse_tree::selector< Rule, tao::pegtl::parse_tree::store_content::on< number, string, function, identifier, identifier_list, expression, expression_list, statement, statement_list, code_block, program, assignment, op_prio_add, op_prio_mul, op_prio_comp >, tao::pegtl::parse_tree::fold_one::on< add_a, mul_a > >;
```



Selector for tree generation This is used by PEGTL's parse\_tree function to determine which nodes are kept, which are folded into their parent when possible, and which are ignored (these are not listed here). 


        
## Public Functions Documentation




### function parse\_to\_code 


```C++
std::vector< Unit > worldlang::parse_to_code (
    std::string program
) 
```



Converts a program string into code units using PEGTL 


        



### function stripWhitespace 


```C++
std::string worldlang::stripWhitespace (
    const std::string & input
) 
```



function to strip whitespace 


        

------------------------------
The documentation for this class was generated from the following file `source/Worlds/Language.hpp`

