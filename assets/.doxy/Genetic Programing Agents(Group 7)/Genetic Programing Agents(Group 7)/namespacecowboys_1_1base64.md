

# Namespace cowboys::base64



[**Namespace List**](namespaces.md) **>** [**cowboys**](namespacecowboys.md) **>** [**base64**](namespacecowboys_1_1base64.md)



_A namespace for_ [_**base64**_](namespacecowboys_1_1base64.md) _encoding and decoding. Does not convert to and from_[_**base64**_](namespacecowboys_1_1base64.md) _in the typical way. Only guarantees that x == b64\_inv(b64(x)), aside from doubles which have problems with precision, so x ~= b64\_inv(b64(x))._
























## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  constexpr char | [**CHARS**](#variable-chars)   = = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ+/"<br>_The characters used to represent digits in_ [_**base64**_](namespacecowboys_1_1base64.md) _._ |
|  constexpr std::array&lt; size\_t, MAX\_CHAR+1 &gt; | [**CHAR\_TO\_IDX**](#variable-char_to_idx)   = = []() {
      std::array&lt;size\_t, MAX\_CHAR + 1&gt; indices{};
      for (size\_t i = 0; i &lt; 64; ++i) {
        indices[CHARS[i]] = i;
      }
      return indices;
    }()<br> |
|  constexpr size\_t | [**MAX\_CHAR**](#variable-max_char)   = = \*std::max\_element(CHARS, CHARS + 64)<br> |
















## Public Static Functions

| Type | Name |
| ---: | :--- |
|  std::string | [**B2ToB64**](#function-b2tob64) (const std::string & binary) <br>_Converts a binary string to a_ [_**base64**_](namespacecowboys_1_1base64.md) _string._ |
|  std::string | [**B64ToB2**](#function-b64tob2) (std::string base64) <br>_Converts a_ [_**base64**_](namespacecowboys_1_1base64.md) _string to a binary string._ |
|  double | [**B64ToDouble**](#function-b64todouble) (const std::string & value) <br>_Converts a_ [_**base64**_](namespacecowboys_1_1base64.md) _string to a double. See DoubleToB64 for precision issues._ |
|  size\_t | [**B64ToULL**](#function-b64toull) (std::string num\_base64) <br>_Converts a number in_ [_**base64**_](namespacecowboys_1_1base64.md) _to base10._ |
|  std::string | [**DoubleToB64**](#function-doubletob64) (double value) <br>_Converts a double to a_ [_**base64**_](namespacecowboys_1_1base64.md) _string. Assumes that the stoull(to\_string(value)) is possible. Only guarantees that x ~= b64\_inv(b64(x)) due to precision errors. Empirically accurate up to 3 decimal places, e.g. round(x, 3) = round(b64\_inv(b64(x)), 3)._ |
|  std::string | [**ULLToB64**](#function-ulltob64) (size\_t ull) <br>_Converts a number in base10 to_ [_**base64**_](namespacecowboys_1_1base64.md) _._ |


























## Public Static Attributes Documentation




### variable CHARS 

```C++
constexpr char CHARS[];
```






### variable CHAR\_TO\_IDX 

```C++
constexpr std::array<size_t, MAX_CHAR + 1> CHAR_TO_IDX;
```






### variable MAX\_CHAR 

```C++
constexpr size_t MAX_CHAR;
```



## Public Static Functions Documentation




### function B2ToB64 

_Converts a binary string to a_ [_**base64**_](namespacecowboys_1_1base64.md) _string._
```C++
static std::string cowboys::base64::B2ToB64 (
    const std::string & binary
) 
```





**Parameters:**


* `binary` A string of 1s and 0s representing binary. 



**Returns:**

The binary string in [**base64**](namespacecowboys_1_1base64.md). 





        



### function B64ToB2 

_Converts a_ [_**base64**_](namespacecowboys_1_1base64.md) _string to a binary string._
```C++
static std::string cowboys::base64::B64ToB2 (
    std::string base64
) 
```





**Parameters:**


* [**base64**](namespacecowboys_1_1base64.md) A string of [**base64**](namespacecowboys_1_1base64.md) characters. 



**Returns:**

The [**base64**](namespacecowboys_1_1base64.md) string in binary. 





        



### function B64ToDouble 

_Converts a_ [_**base64**_](namespacecowboys_1_1base64.md) _string to a double. See DoubleToB64 for precision issues._
```C++
static double cowboys::base64::B64ToDouble (
    const std::string & value
) 
```





**Parameters:**


* `value` The [**base64**](namespacecowboys_1_1base64.md) string to convert. 



**Returns:**

The [**base64**](namespacecowboys_1_1base64.md) string as a double. 





        



### function B64ToULL 

_Converts a number in_ [_**base64**_](namespacecowboys_1_1base64.md) _to base10._
```C++
static size_t cowboys::base64::B64ToULL (
    std::string num_base64
) 
```





**Parameters:**


* `num_base64` The number in [**base64**](namespacecowboys_1_1base64.md) as a string. 



**Returns:**

The number in base10. 





        



### function DoubleToB64 

_Converts a double to a_ [_**base64**_](namespacecowboys_1_1base64.md) _string. Assumes that the stoull(to\_string(value)) is possible. Only guarantees that x ~= b64\_inv(b64(x)) due to precision errors. Empirically accurate up to 3 decimal places, e.g. round(x, 3) = round(b64\_inv(b64(x)), 3)._
```C++
static std::string cowboys::base64::DoubleToB64 (
    double value
) 
```





**Parameters:**


* `value` The double to convert. 



**Returns:**

The double in [**base64**](namespacecowboys_1_1base64.md). 





        



### function ULLToB64 

_Converts a number in base10 to_ [_**base64**_](namespacecowboys_1_1base64.md) _._
```C++
static std::string cowboys::base64::ULLToB64 (
    size_t ull
) 
```





**Parameters:**


* `ull` The number to convert. 



**Returns:**

The number in [**base64**](namespacecowboys_1_1base64.md) as a string. 





        

------------------------------
The documentation for this class was generated from the following file `source/Agents/GP/CGPGenotype.hpp`

