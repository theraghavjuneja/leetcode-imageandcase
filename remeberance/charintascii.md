#### Okay so each character has some ASCII code got it?
##### First of all there is to_string() which converts an entire number to string?
- to_string() converts numbers to string
- example to_string(42) will give "42"
- If you use to_string on char example to_string('4') -> "52" (ASCII value mein)
- Okay leave 2nd point, we will be using to_string only for first point. so to_string(integer)->string

#### stoi
- converts string(of digits)-> integer 
```cpp
string s="42"
int num=stoi(s) //num=42 now
```
#### char &int
```cpp
char ch='1';
// okay so '1' must have some ascii code and '0' too if i just subtract them 
// example '1'=100 (say) '0'=99(say) so '1'-'0'=1 (ascii subt)
int num=ch-'0';
```

### now lets try the reverse Int 1-> char '1'
```cpp
int num=1;
char ch=num+'0' //ascii of 0 added
```
<!-- remember '1'-'0'=1 -->
<!-- subtraction in char is just unka ascii subt -->


### now how to convert char to ascii and vice versa
- example 'a' to 97 (its ascii)
```cpp
char ch='a';
int ascii=ch;
//thats all we needed

```
<!-- 59 to ascii -->
```cpp
int num=59;
char ch=static_cast<char>(num);

```