# Phần I: C & Algorithm
---

<details>
  <summary><h3>Bài 1: Compiler - Macro</h3></summary>

IDE gồm: `Dev-C++, VS Code(đã cài Extensions), Arduino IDE, KeilC, STM32CubeIDE,...`

- Editor: Phần mềm soạn thảo.

- Complier: Trình biên dịch, chuyển đổi ngôn ngữ bậc cao sang ngôn ngữ máy.

## I. Quá trình Compiler

![](https://github.com/hthuan02/Advanced-C-Cpp-and-Algorithm/blob/main/C/Bai1_Complier_Macro/Complier/img/GCC_CompilationProcess.png)

Gồm 4 bước chính:

- Tiền xử lý (Preprocessor)

- Biên dịch (Compiler)

- Dịch hợp ngữ (Asembler)

- Liên kết (Linker)

### 1. Tiền xử lý (Preprocessor)
(Chuyển file a.c, file b.h thành file main.i)

`gcc -E main.c -o main.i`

> Copy toàn bộ mã nguồn vào file main.i
>
> Xóa comment.
>
> Macro `#define` thì bị thay thế bằng đối tượng khác, còn lại giữ nguyên.

### 2. Biên dịch (Complier)
(Chuyển file main.i thành file main.s)

`gcc -S main.i -o main.s`

> Tạo ra file hợp ngữ (file Assembly).
>
> Thao tác trên RAM mượt mà hơn.

### 3. Dịch hợp ngữ (Assembler)
(Chuyển file main.s thành file main.o)

`gcc -c main.s -o main.o`

> Mã nguồn chuyển thành các đoạn mã 0 1 (ngôn ngữ máy).
>
> Nếu code trên VDK thì chương trình lưu vào bộ nhớ Flash.

### 4. Liên kết (Linker)
(Liên kết các file main.o, build lại thành file main.exe)

`gcc main.o test.o -o main`

`./main`

## II. Macro

> Macro là những từ chỉ thông tin xử lý, xảy ra ở quá trình tiền xử lý (`#include`, `#define`, `#ifndef`, `#if`, `#endif`,... là các macro).

### 1. Macro chỉ thị bao hàm tệp

- #include< >: Tìm file trong thư mục cài đặt.

- #include" ": Tìm file ở thư mục hiện tại.

### 2. Macro chỉ thị định nghĩa

- #define: Định nghĩa 1 đối tượng(biến, hàm, mảng)

_VD1: define trên nhiều dòng_ 

```c
  #define CREATE_FUNC(name_func, cmd) \
  void name_func(){                   \
    printf(cmd);                      \
  }                                   \
```

- #undef: Xóa định nghĩa #define

#### 3 toán tử macro #define

- ##: Nối các chuỗi

_VD2:_

```c
  #define CREATE_VAR(name)    \
  int int_##name              \
  double double_##name        \

  int main(int argc, char const *argv[])
  {
    CREATE_VAR(abd);   // Kết quả: int int_abd double double_abd;

    return 0;
  }  
```

- #: Chuẩn hóa lên chuỗi
_VD3_
```c
  #define CREATE_STRING(cmd) printf(#cmd)

  int main(int argc, char const *argv[])
  {
    CREATE_STRING(123abc); // Kết quả: printf("123abc")

    return 0;
  }  
```

- Macro Variadic: Cho phép 1 hàm có thể nhận số lượng tham số truyền vào không xác định.

```c
#define sum(...) __VA_ARGS__
```

_VD4: Tính tổng với số lượng số bất kỳ (1 sum)_
```c
  #define sum(...)              \
  int arr[] = {__VA_ARGS__, 0}; \
  int tong = 0;                 \
  int i = 0;                    \
  while (arr[i] !=0){           \
    tong += arr[i];             \
    i++;                        \
  }                             \
  printf("Tong = %d\n", tong); 

int main(int argc, char const *argv[])
  {
    sum(1,2);
    return 0;
  }  
```
_(Nhiều sum)_
```c
#include <stdio.h>

#define sum(...)                    \
do {                                \
    int arr[] = {__VA_ARGS__, 0};   \
    int tong = 0;                   \
    int i = 0;                      \
    while (arr[i] != 0) {           \
        tong += arr[i];             \
        i++;                        \
    }                               \
    printf("Tong = %d\n", tong);     \
} while (0)                         

int main(int argc, char const *argv[])
{
    sum(1, 2);
    sum(1, 2, 3);
    sum(1, 3, 5, 7, 9, 12, 15);

    return 0;
}                        
```

- `__VA_ARGS__`: Là những giá trị đưa vào mảng.

- `0`: Dấu hiệu kết thúc chuỗi, vòng lặp sẽ dừng khi gặp số 0.

- **Tại sao sử dụng do...while(0) ở chương trình nhiều sum?**

  > Giả sử không có `do...while(0)`, thì khi gọi `sum()` lần 2 thì nó sẽ tạo 2 mảng `arr[]` thêm 2 lần. Tạo thành 2 biến cục bộ bị trùng tên trong main -> Bị lỗi.
  >
  > Khi sử dụng `do...while(0)` nó giống như 1 cái hàm, `int arr` trở thành biến cục bộ trong 1 hàm. Khi gọi `sum()` 2 lần thì nó trở thành 2 biến cục bộ trong hàm `do...while` -> Không bị mâu thuẫn.


### 3. Macro chỉ thị biên dịch có điều kiện

- #ifdef, #ifndef: Kiểm tra xem 1 macro có định nghĩa hay chưa

  - #ifdef: Nếu đã định nghĩa -->> thực thi chương trình
 
  - #ifndef: Nếu chưa định nghĩa -->> thì định nghĩa --> thực thi

  -> Kết thúc: #endif

- #if, #else, #elif: đây là các macro kiểm tra điều kiện giống (if-else-else if)

## SỬ DỤNG MACRO VÀ FUNCTION CÓ GÌ KHÁC NHAU? 

- Function: Không cấp phát bộ nhớ, vì có bộ nhớ riêng, tốc độ châm, đầu tiên lưu vào stack --> lấy vào địa

- Macro: Tốn bộ nhớ chương trình, để khởi tạo và lưu lại, tốc độ nhanh hơn--> bộ đếm chương trình tuần tự

</details>

<details>
  <summary><h3>Bài 2: STDARG - ASSERT</h3></summary>

## I. Thư viện stdarg
(Tương tự macro variadic)

> Cho phép làm việc với những hàm có số lượng tham số truyền vào (input parameter) không xác định (VD: Hàm `printf`, `scanf`).

### 1. va_list

> `va_list`: Khai báo biến để duyệt các đối số

```c
  void test(int count, ...)
  {
    // `int count`: xác định số lượng tham số.
    // `...`: danh sách đối số không xác định.

    va_list args;
    // typedef char* va_list;
    // char* args;
    // args = "int count, 1, 2, 6"
  }
```
- va_list: là một kiểu dữ liệu đã được định nghĩa lại, là 1 chuỗi. Có thể viết `typedef char* va_list;`

- `va_list args`: tương đương khai báo `char* arg;`, là một biến con trỏ thuộc kiểu char, có 2 TH sử dụng:

  - Có thể hoạt động như 1 mảng, từng phần tử trong mảng là kí tự. 

  - Lưu trữ chuỗi (chuỗi đó tương ứng với tham số `int count,...`)
    VD: args = "int count, 1, 2, 6"
    
### 2. va_start

> `va_start`: Dùng để truy xuất ra danh sách đối số cần thao tác.

```c
  void test(int count, ...)
  {
    // `int count`: xác định số lượng tham số.
    // `...`: danh sách đối số không xác định.

    va_list args;

    va_start(args, count); // args = "1,2,6" / args = {'\1','\2','\3'}(escape character)
  }
```
- `va_start(args, count)`: 
  
  - Tham số đầu tiên `args` chứa dữ liệu bắt đầu thao tác là chuỗi `args = "int count, 1, 2, 6"`

  - Tham số thứ 2: Truyền vào tên biến `count`, để tách ra "1,2,6".

- Thực hiện so sánh chuối `"int count, 1, 2, 6"` với `count`. Xóa `int count` để tách ra `1,2,6`.

### 3. va_arg
> `va_arg`: Lấy từng đối số trong danh sách ra và ép kiểu 

```c
  void test(int count, ...)
  { 
      va_list args; 

      va_start(args, count); // args = "1,2,6" / args = {'\1','\2','\3'}

      printf("value 1: %d\n",va_arg(args, int)); // (int)'\1' = 1, ép kiểu int
      printf("value 2: %d\n",va_arg(args, int)); // (int)'\2' = 2, int
      printf("value 3: %d\n",va_arg(args, int));
      printf("value 4: %f\n",va_arg(args, double));
      printf("value 5: %c\n",va_arg(args, char*)); // Chuỗi phải ép về kiểu `char*`
      printf("value 6: %s\n",va_arg(args, char*));

  }

  int main(int argc, char const *argv[])
  {
      test(6, 1, 2, 6, 3.15, 'a',"HELLO");  // count: để xác định số lượng tham số
      
      return 0; 
  }
```

- `va_arg(args, int)`: Trong đó
  
  - `args`: Là kết sau sau khi `va_start()` thực hiện

  - `int`: Dùng để ép kiểu dữ liệu

- Mỗi lần macro `va_arg()` gọi ra thì sẽ lấy ra 1 giá trị và ép kiểu dữ liệu, sau đó trỏ đến phần tử tiếp theo. Gọi lần lượt từ `1`, `2`, `6`.

### 4. va_end
> `va_end`: Kết thúc thao tác với `args`, nói cách khác là thu hồi địa chỉ của con trỏ 

### 5. va_copy
> `va_copy`: Sao chép dữ liệu giữa 2 biến cùng kiểu va_list.

### 6. Ứng dụng của thư viện stdarg

<details>
  <summary><h4>VD1: Tính tổng biết số lượng phần tử truyền vào</h4></summary>
  
```c
  #include <stdio.h>
  #include <stdarg.h>

  int sum(int count, ...) // count: tham số cố định, đại diện cho số lượng tham số biến đổi
  {
      va_list args;
      va_start(args, count);

      int result = 0;
      for (int i = 0; i < count; i++)
      {
          result += va_arg(args, int);
      }

      va_end(args);
      return result;
  }

  int main()
  {
      printf("Sum: %d\n", sum(3, 1, 5, 9));
      
      printf("Sum: %d\n", sum(5, 1, 5, 9, 10, 15));

      return 0;
  }
```
#### Nhược điểm: Bị phụ thuộc vào tham số đầu tiên `count`
</details>

<details>
  <summary><h4>VD2: Tính tổng không biết số lượng phần tử truyền vào</h4></summary>

#### Khắc phục: sử dụng thêm macro variadic
```c
#include <stdio.h>
#include <stdarg.h>

#define tong(...)   sum(__VA_ARGS__, 0)

// tong(3,1,4,5,-1,-2) -> sum(3,1,4,5,-1,-2,0) 

// K biết được số lượng tham số ban đầu -> while
int sum(int count, ...)
{
    va_list args;

    va_start(args, count);

    /************************************************************************
     * Khởi tạo result mang giá trị tham số đầu tiên count
     * Khi tính tổng thì đã có sẵn giá trị rồi và cộng dồn giá trị tiếp theo
     ************************************************************************/
    int result = count; 
    
    int value; // Biến tạm, để lưu trữ tạm thời giá trị để so sánh

    // Duyệt qua từng phần tử, khác 0 thì cộng dồn vào
    while ((value = va_arg(args, int)) != 0)
    {
        result += value;

        // Nếu không dùng biến tạm
        /**********************************************************************
         * result += va_arg(args, int);
         *
         * Gặp vấn đề: 
         * va_arg() lấy giá trị trước để so sánh
         * nhưng khi cộng thì cộng giá trị tiếp theo, bỏ qua 1 giá trị
         **********************************************************************/
    }
    
    va_end(args);
    
    return result;
}

int main()
{
    printf("Tổng: %d\n", tong(3, 1, -1, 0, 1, 2, 3, 15)); // 3    // Nhược điểm là chỉ tính tổng số trước số 0, tới 0 while sẽ dừng lại 

    return 0;
}
```
#### Nhược điểm: Nếu bên trong các phần tử có số 0, thì while sẽ dừng lại không cộng nữa.

</details>

<details>
  <summary><h4>VD3:(Hoàn thiện) Tính tổng không biết số lượng phần tử truyền vào, có số 0 bên trong phần tử</h4></summary>

```c
#include <stdio.h>
#include <stdarg.h>

#define tong(...)   sum(__VA_ARGS__, '\n')

int sum(int count, ...)
{
    va_list args;
    va_list check;

    va_start(args, count);
    va_copy(check, args);

    int result = count; 
    
    while ((va_arg(check, char*)) != (char*)'\n')
    {
        result += va_arg(args, int);
    }
    
    va_end(args);
    
    return result;
}

int main()
{
    printf("Tổng: %d\n", tong(3, 1, -1, 0, 1, 2, 3, 15)); // 24

    return 0;
}

```

</details>

**Lưu ý:** Nếu 1 hệ thống sử dụng nhiều cảm biến, mà viết nhiều hàm thì chương trình sẽ phức tạp. Thì thư viện stdarg có thể giúp viết 1 hàm mà sử dụng nhiều loại CB khác nhau. 

## II. Thư viện Assert

> Thư viện sử dụng để debug(kiểm tra chương trình có lỗi hay không). Dùng `#define NDEBUG` để tắt debug.
> 
> Cung cấp macro assert, để kiểm tra một điều kiện. 

- Nếu điều kiện đúng (true), không có gì xảy ra và chương trình tiếp tục thực thi.

- Nếu điều kiện sai (false), chương trình dừng lại và thông báo một thông điệp lỗi.

_VD1:_

```c
#include <stdio.h>
#include <assert.h>

int main()
{
    int x = 5;

    assert(x == 6); // Sai

    // Chương trình sẽ tiếp tục thực thi nếu điều kiện là đúng.
    printf("X is: %d", x);
   
    return 0;
}
```
- Chương trình chạy sai sẽ in ra vị trí, dòng lỗi và file lỗi.
`Assertion failed: x == 6, file Ex1.c, line 8`

#### Macro dùng để debug

```c
#define LOG(condition, cmd) assert(condition && #cmd)
```
_VD2:_
```c
#include <stdio.h>
#include <assert.h>

#define LOG(condition, cmd) assert(condition && #cmd)

double divide(int a, int b)
{   

    // assert(b != 0 && "Lỗi chia cho 0");
    LOG(b != 0, Lỗi chia cho 0);
    return (double)a/b;
}

int main(int argc, char const *argv[])
{
    int x = 5;

    // assert(x == 5 && "X phải bằng 5");

    LOG(x == 5, X phải bằng 5);
    printf("x = %d\n", x);

    printf("Kết quả phép chia: %f\n",divide(2,0));
    return 0;
}
```

</details>


<details>
  <summary><h3>Bài 3: Bitmask</h3></summary>

> Bitmask là kỹ thuật thao tác từng bit trong 1 biến. Mỗi bit có thể lưu trữ thông tin, thao tác với các cờ (flags) hoặc trạng thái khác nhau.
>
> Bitmask dùng để tối ưu hóa bộ nhớ.

_VD11: Rút gọn kích thước bộ nhớ_

```c
  #include<stdio.h >

  int gender; // 4 byte
  int status; 
  int xemay;  
  int maybay; 
  int oto;    
  int tau;    

  // Tổng 24byte
  int main()
  {

    return 0;
  }
```

_VD1.1:_
```c
  #include<stdio.h >
  #include<stdint.h> // Thư viện sử để sd kiểu dl uint8_t, uint16_t, uint32_t

  // int8_t, uint8_t          1 byte = 8bit 
  // int16_t, uint16_t        2 byte = 16bit
  // int32_t, uint32_t, int   4 byte = 32 bit

  uint8_t gender; // 1 byte
  uint8_t status; 
  uint8_t xemay;  
  uint8_t maybay;
  uint8_t oto;    
  uint8_t tau;   

  // Tổng 6byte
  int main()
  {

    return 0;
  }
```

_VD1.2:_

```c
  #include<stdio.h >
  #include<stdint.h> // Thư viện sử để sd kiểu dl uint8_t, uint16_t, uint32_t

  uint8_t user; // 0bxxxx xxxx
  // bit 0: gender
  // bit 1: status
  // ...
  // bit 5: tau
  
  // Tổng 1 byte
  int main()
  {

    return 0;
  }
```

## 1. Phép toán với Bit (Bitwise)

<img src="https://github.com/hthuan02/Advanced-C-Cpp-and-Algorithm/blob/main/C/Bai3_Bitmask/img/bang%20chan%20tri.png" alt="Memory Layout" width="650"/>

| Toán tử | Ký hiệu | Ví dụ                                 |
|---------|---------|----------------------------------------|
| NOT     | `~`     | `~0b00001111 = 0b11110000`             |
| AND     | `&`     | `0b1100 & 0b1010 = 0b1000`             |
| OR      | `\|`    | `0b1100 \| 0b1010 = 0b1110`            |
| XOR     | `^`     | `0b1100 ^ 0b1010 = 0b0110`             |

#### Shift left - Shift right bitwise

- Dịch trái `<<`, các bit ở bên phải sẽ được dịch sang trái, và các bit trái cùng được đặt giá trị 0.

- Dịch phải `>>`, các bit ở bên trái sẽ được dịch sang phải, và các bit phải cùng được đặt giá trị 0 hoặc 1 tùy thuộc vào giá trị của bit cao nhất .
 
_VD2:_ 
```c
uint8_t user1 = 0b00001111;
uint8_t user2 = 0b11110001;

user1 = user1 << 1; // 0b00011110
user1 <<= 2;        // 0b00111100
user1 <<= 5;        // 0b11100000

user2 = user2 >> 1; // 0b01111000
user2 >>= 4;        // 0b00001111
```

## 2. Thao tác với Bit

| Thao tác    | Phép toán       | Mô tả                                                  |
|-------------|-----------------|--------------------------------------------------------|
| **Set bit** | `\|` (OR)        | Đặt bit từ 0 -> 1.                                    |
| **Reset/Clear bit** | `& ~` (AND - NOT) | Xóa bit 1 -> 0.                                        |
| **Check bit** | `&` (AND)       | Kiểm tra giá trị của bit.                              |


_VD3: Thực hiện thao tác với từng bit_

  ```c
  #include <stdio.h>
  #include <stdint.h>

  // Quy định từng bit mang thông tin gì, bằng macro định nghĩa
  #define GENDER        1 << 0  // Bit 0: 0 = Nữ, 1 = Nam                 0b00000001 << 0
  #define TSHIRT        1 << 1  // Bit 1: 0 = Không, 1 = Có               0b00000010
  #define HAT           1 << 2  // Bit 2: 0 = Không, 1 = Có               0b00000100
  #define SHOES         1 << 3  // Bit 3: 0 = Không, 1 = Có               0b00001000      
  #define FEATURE1      1 << 4  // Bit 4: Tính năng 1                     0b00010000
  #define FEATURE2      1 << 5  // Bit 5: Tính năng 2                     0b00100000
  #define FEATURE3      1 << 6  // Bit 6: Tính năng 3                     0b01000000
  #define FEATURE4      1 << 7  // Bit 7: Tính năng 4                     0b10000000


  // enable bit (0 -> 1) - đặt bit
  void enableFeature(uint8_t *options, uint8_t feature)// 0xa5 (0b00000000): 0x01 
  {
      // Truyền vào con trỏ `*options` lưu địa chỉ gốc, để thực hiện thao tác thay đổi địa chỉ từng bit
      // Giải tham chiếu
      // options: địa chỉ
      // *options: giá trị
      *options |= feature; // *option = *option | feature

      //      0bxxxxxxxx
      // OR   0b00000001 (bit 0)
      //      0bxxxxxxx1
      // OR   0b00001000 (bit 3)
      //      0bxxxx1001 (result)

      // enable bit (0->1)
  }

  // disable bit (1 -> 0)- Xóa bít
  void disableFeature(uint8_t *options, uint8_t feature)
  {
      *options &= ~feature; // *options = *options & (~feature);

      // ~ 0b00000001 (bit 0) = 0b11111110
      // ~ 0b00001000 (bit 3) = 0b11110111
      
      //      0bxxxx1xx1 (result hàm 1)
      // AND  0b11111110 (bit 0)
      //      0bxxxx1xx0 
      // AND  0b11110111 (bit 0)
      //      0bxxxx0xx0

      // disable (1->0)
  }

  // check bit 
  int8_t isFeatureEnabled(uint8_t options, uint8_t feature)
  {
      return ((options & feature) != 0); // != thì bit đó đang bật lên

      // AND với chính nó
      // 0b1xx1xx1x & 0b10010010
  }

  // Liệt kê các tính năng đã bật
  void listSelectedFeatures(uint8_t options)
  {
      printf("Selected Features:\n");

      const char* featureName[] = {
          "Gender",
          "Shirt",
          "Hat",
          "Shoes",
          "Feature 1",
          "Feature 2",
          "Feature 3",
          "Feature 4"
      };

      for (int i = 0; i < 8; i++)
      {
          if ((options >> i) & 1)
          {
              printf("- %s\n", featureName[i]);
          }
      }
  }


  int main()
  {   
      uint8_t options = 0;    // 0x01: 0b0000 0000

      // Thêm tính năng
      // 0b00000001
      // 0b00000010
      // 0b00000100
      // 0b00000111
      enableFeature(&options, GENDER | TSHIRT | HAT | FEATURE1);

      // Xóa tính năng
      disableFeature(&options, HAT | GENDER);

      // Liệt kê các tính năng đã chọn
      listSelectedFeatures(options);
    
      return 0;
  }
```
#### Bit field

> Được sử dụng trong struct, dùng để quy định số bit cụ thể để sử dụng.

_VD4: Quản lý thông tin cho 1 chiếc xe gồm: màu sắc, năng lượng, động cơ và thông tin bổ sung._

```c
  // Thông tin mang nhiều giá trị cần nhiều bit tương ứng
  #define COLOR_RED   0 // 0b0000 0000
  #define COLOR_BLUE  1 // 0b0000 0001
  #define COLOR_BLACK 2 // 0b0000 0010
  #define COLOR_WHITE 3 // 0b0000 0011

  #define POWER_100HP 0
  #define POWER_150HP 1
  #define POWER_200HP 2

  #define ENGINE_1_5L 0
  #define ENGINE_2_0L 1

  typedef uint8_t CarColor; // typedef là từ khóa định nghĩa lại biến
  typedef uint8_t CarPower;
  typedef uint8_t CarEngine;

  // Các thông tin bổ sung, cần 2 bit lưu trữ 
  #define SUNROOF_MASK        1 << 0  // 0001 
  #define PREMIUM_AUDIO_MASK  1 << 1  // 0010
  #define SPORTS_PACKAGE_MASK 1 << 2  // 0100

  // Để quản lý cùng lúc nhiều thông tin, phải dùng struct để gom tất cả thông tin
  typedef struct
  {   
      /******************************************************************
       * bit-field: quy định số bit cụ thể để sử dụng
       * VD:
       * `Carcolor color : 2` sử dụng 2 bit trong tổng số 8 bit khai báo(uint8_t)
       * `Carpower power : 3` sử dụng 3 bit trong tổng sổ 8 bit(uint8_t)
       * `CarEngine engine;` chiếm 1 byte kích thước
       *****************************************************************/

      CarColor color : 2;            // 2 bit cho màu sắc 
      CarPower power : 2;            // 2 bit cho năng lượng
      CarEngine engine : 1;          // 1 bit cho động cơ 
      uint8_t additionalOptions : 3; // 3 bit  cho các tùy chọn bổ sung
  } CarOptions; // struct tên là CarOptions

```

</details>

<details>
  <summary><h3>Bài 4: Pointer</h3></summary>


<details>
  <summary><h2>A. Thao tác với con trỏ</h2></summary>

> Con trỏ là 1 biến, không dùng lưu giá trị mà nó dùng để lưu địa chỉ của 1 đối tượng(biến, hàm, mảng,...)

_Sự khác nhau biến & con trỏ:_

  |                   | `int var = 0;`     | `int *ptr = &var;` |
  |-------------------|-----------------------|---------------------------|
  | **Address**       | `0x01 0x02 0x03 0x04`(int-4byte)  | `0xc1` `0xc2` `0xc3` `0xc4` `0xc5`...`0xc8`(Kiến trúc máy tính 64bit-8byte)                  |
  | **Value**         | `0b00..00`(32bit)             | `0x01` `0x02` `0x03` `0x04` `0x00`...`0x00` (Lưu 4byte int, không còn thì 0x00)                     |

  - `0b00000000(MSB) 00000000 00000000 00000000(LSB)`: LSB(Thấp nhất) -> MSB(Cao nhất)

## 0. Cách sử dụng Pointer

- **Khai báo con trỏ**
```c
  int *ptr;      // con trỏ đến kiểu int
  char *ptr;     // con trỏ đến kiểu char
  float *ptr;   // con trỏ đến kiểu float
```

- **Lấy địa chỉ của biến**
```c
  int x = 10;
  int *ptr = &x;  // ptr_x chứa địa chỉ của x
```
- **Truy cập giá trị (giải tham chiếu - dereference)**
```c
  int y = *ptr    // y sẽ bằng giá trị của x
  ptr = &x;
  *ptr = *(0x01) = 10;
```

## 1. Kích thước của con trỏ

- Phụ thuộc vào kiến trúc của máy tinh và trình biên dịch.

_VD:_ Laptop 64bit -> 8byte

- Trên MCU phụ thuộc vào kiến thúc vi xử lý.

_VD:_ STM32(32bit) -> 4byte

      STM8(8bit)   -> 1byte

```c
  #include <stdio.h>

  int main()
  {
    printf("Sizeof pointer: %d bytes\n", sizeof(int*)); // 8byte
    printf("Sizeof pointer: %d bytes\n", sizeof(short*)); // 8
    printf("Sizeof pointer: %d bytes\n", sizeof(float*)); // 8
    printf("Sizeof pointer: %d bytes\n", sizeof(double*)); // 8
    return 0;
  }
```
## 2. Regular Pointer(Con trỏ với biến)

> Kiểu dữ liệu ảnh hưởng đến việc truy xuất giá trị, quyết định đọc bao nhiêu byte trong vùng nhớ.
>
> Kiểu dữ liệu khai báo biến và kiểu dữ liệu con trỏ phải đồng bộ với nhau.

```c
  int var = 10;
  int *ptr = &var;
```

## 3. Array Pointer(Con trỏ với mảng)

> Vùng nhớ câp phát cho mảng (kích thước của mảng) phụ thuộc vào (số lượng phần tử) * (kiểu dữ liệu).

_VD:_
```c
  #include<stdio.h>
    
  int main(){
    int arr[] = {1, 2, 3, 4, 5}; // Số lượng * sizeof(int) = 20byte

    int n = (sizeof(arr)/sizeof(arr[0])); // Tính số lượng

    int *ptr = arr; // mảng thì không cần dấu '&'

    // ptr:    vùng địa chỉ phần tử 0
    // ptr+1:  vùng địa chỉ phần tử thứ 1
    // ptr+2:  vùng địa chỉ phần tử thứ 2
    
    // ptr + i.sizeof(data_type)
    for (int i = 0; i < n; i++)
    {
        printf("Địa chỉ = %p - Giá trị: %d\n", ptr+i, *(ptr+i)); // Giải tham chiếu tìm giá trị
    }

    return 0;
  }
```
## 4. Ứng dụng con trỏ

_VD: Hoán đổi giá tị a và b_
 
- Nếu không sử dụng con trỏ (SAI)

```c
  #include <stdio.h>

  void swap(int a, int b) // 0xb0 = 10, 0xe5 = 20
  {
      int tmp = a; // tmp = 10
      a = b;       // a = 20
      b = tmp;     // b = 10
  }

  int main()
  {
    int a = 10, b = 20; // 0x01: 10; 0xa4: 20
    swap(a, b);
    printf("value a is: %d\n", a); 
    printf("value b is: %d\n", b);
    return 0;
  }
```
- Hàm `swap()` không thể thay đổi giá trị `a` và `b`:

  - Vì tham số `a` và `b` truyền vào `swap()` không phải là con trỏ, không lưu địa chỉ của giá trị gốc. Mà nó tự cấp phát 2 vùng địa chỉ mới.

  - 2 vùng địa chỉ mới của `a` và `b` trong hàm `swap()` khác 2 vùng địa chỉ `a` và `b` trong hàm main (địa chỉ gốc). Nên việc thay đổi giá trị hàm `swap()` không ảnh hưởng đến địa chỉ gốc 
  
  -> `a` và `b` không thể thay đổi giá trị.

- Để khắc phục thì truyền vào con trỏ trong hàm `swap()`

```c
  #include <stdio.h>

  void swap(int *a, int *b) // 0x01 = 10, 0xa4 = 20
  {
      int tmp = *a; // tmp = 10
      *a = *b;       // a = 20
      *b = tmp;     // b = 10
  }

  int main()
  {
    int a = 10, b = 20; // 0x01: 10; 0xa4: 20
    swap(&a, &b);
    printf("value a is: %d\n", a); // 20
    printf("value b is: %d\n", b); // 10
    return 0;
  }
```
- Chương trình hoàn chỉnh

```c
  #include <stdio.h>

  void swap(int *a, int *b) // 0x01 = 10, 0xa4 = 20
  {
      int tmp = *a; // tmp = 10
      *a = *b;       // a = 20
      *b = tmp;     // b = 10
  }

  void input(int *a, int *b)
  {   
      // Truyền vào `a` không truyền `&a`
      // Nếu truyền vào `&a` là đọc địa chỉ của con trỏ, không phải lấy địa chỉ con trỏ lưu bên trong
      printf("Nhập a: "); scanf("%d", a); 
      printf("Nhập b: "); scanf("%d", b);
  }

  int main()
  {
    int a = 10, b = 20; // 0x01: 10; 0xa4: 20
    input(&a, &b);
    swap(&a, &b);
    printf("value a is: %d\n", a); // 20
    printf("value b is: %d\n", b); // 10
    return 0;
  }
```

</details>

<details>
  <summary><h2> B. Phân loại con trỏ </h2></summary>

## 1. Void Pointer

> Là con trỏ có thể trỏ đến bất kỳ địa chỉ, mà không cần quan tâm đến kiểu dữ liệu nào tại địa chỉ đó.

```c
  void * ptr;
```
- _VD1: Xuất giá trị kiểu int, char._

```c
  #include <stdio.h>

  int main(int argc, char const *argv[]){
      void *ptr;

      int a = 10;
      ptr = &a;

      // (int*): ép kiểu cho con trỏ `*ptr`
      // *(int*)(ptr): giải tham chiếu
      printf("Dia chi: %p, Gia tri: %d\n", ptr, *(int*)(ptr));

      double a = 5.5;
      ptr = &a;
      printf("Dia chi: %p, Gia tri: %f\n", ptr, *(double*)(ptr));

      char c = 'C';
      ptr = &c;
      printf("Dia chi: %p, Gia tri: %c\n", ptr, *(char*)(ptr));

      char arr[] = "HELLLO";
      ptr = arr;
      printf("Dia chi: %p, Gia tri: %s\n", ptr, *(char*)(ptr));
  }
```

#### Mảng con trỏ void

- Thay vì khai báo từng con trỏ void thì gộp lại thành 1 mảng.
#include <stdio.h>

```c
  int main(int argc, char const *argv[]){
      int a = 10;
      double b = 5.5;
      char c = 'C';
      char arr[] = "HELLLO"; // ký tự NULL ('\0') // báo hiệu kết 

      // Khai báo mảng lưu trữ địa chỉ của các biến trên
      // Mảng con trỏ void, từng phần tử của nó là địa chỉ của biến khác
      void *ptr1[] = {&a, &b, &c, &arr};
      printf("Dia chi: %p, Gia tri: %d\n", ptr1[0], *(int*)(ptr1[0]));
      printf("Dia chi: %p, Gia tri: %f\n", ptr1[1], *(double*)(ptr1[1]));

      return 0;
  } 
```

**Ưu điểm con trỏ void:** 

- Tối ưu bộ nhó RAM (Vì mỗi con trỏ cần khai báo mỗi kiểu dữ liệu, nhiều kiểu dữ liệu thì tốn nhiều bộ nhớ).

- 1 con trỏ có thể trỏ tới tất cả các biến. 

## 2. Function Pointer

> Con trỏ hàm là 1 biến, có thể trỏ đến địa chỉ của 1 hàm có kiểu dữ liệu cụ thể.
>
> Là biến lưu địa chỉ của hàm, mỗi thời điểm chỉ trỏ 1 hàm.

- Thông thường sử dụng theo 2 cách:

  - Là tham số truyền vào của 1 hàm.

  - Lưu trữ địa chỉ của 1 hàm. 

Cú pháp:

```c
  <return_type> (*func_pointer)(<data_type_1>, <data_type_2>);
```

_VD1.0:_
```c
  void funcA();

  void (*ptr)();  // 2 tham số truyền vào(data_type) hoặc bỏ trống nếu k có
  ptr = &funcA; //  hoặc không cần `&`
```
_VD1.1:_
```c
  int sum (int a, int b);
  int (*ptr)(int, int);
  ptr = sum;
```

#### 3 cách gọi hàm ra

```c
  // Cách 1. funcA();
  // Cách 2. ptr();
  // Cách 3. (*ptr);
```

_VD2: Tính tổng, hiệu, tích, thương bằng con trỏ hàm với 3 cách._

  ```c
  #include<stdio.h>

  void tong(int a, int b){ printf("Tổng: %d\n", a+b);}

  void hieu(int a, int b){ printf("Hiệu: %d\n", a-b);}
          
  void tich(int a, int b){ printf("Tích: %d\n", a*b);}

  void thuong(int a, int b){ printf("Hiệu: %f\n", (double)a/b);}

  void tinhtoan(void(*pheptinh)(int, int), int a, int b){ pheptinh(a,b); }


  int main(){
      
      // Cách 1: Khai báo con trỏ hàm như biến
      // void (*ptr)(int, int);
      
      // ptr = tong;
      // ptr(2,3);

      // ptr = hieu;
      // ptr(2,3);

      // ptr = tich;
      // ptr(2,3);

      // ptr = thuong;
      // ptr(2,3);

      // Cách 2: Khai báo con trỏ hàm như 1 mảng
      // void (*ptr1[])(int, int) = {tong, hieu, tich, thuong};
      
      // ptr1[0](2,3);
      // ptr1[1](2,3);
      // ptr1[2](2,3);
      // ptr1[3](2,3);

      // Cách 3: Khai báo con trỏ hàm như thâm số truyền vào 
      tinhtoan(tong, 2, 3);
      tinhtoan(hieu, 2, 3);
      tinhtoan(tich, 2, 3);
      tinhtoan(thuong, 2, 3);

      return 0;
  }
```

**Ưu điểm:** Tính linh hoạt cao, thường dùng trong lập trình game các tác vụ di chuyển không có độ trễ.

**Nhược điểm:** Sẽ chậm hơn so với gọi hàm trực tiếp, vì nó gọi trung gian qua con trỏ hàm.

## 3. Pointer to Constant (Con trỏ hằng)
(Chỉ đọc - Không thể ghi)

> Là con trỏ có thể thay đổi địa chỉ mà nó trỏ đến, nhưng không thể thay đổi giá trị tại địa chỉ đó thông qua giải tham chiếu.
>
> Có thể trỏ đến nhiều địa chỉ.

```c
  // Có 2 cách để khai báo
  <data_type> const *ptr_const;
  const <data_type> *ptr_const;
```

- _VD3:_
```c
  #include <stdio.h>

  int main()
  {
      int value = 5;
      int test = 8;
      int const *ptr_const = &value;

      //*ptr_const = 7;    // wrong, k thể thay đổi giá trị bằng giải tham chiểu
      //ptr_const = &test; // right, thay đổi địa chỉ trỏ đến
      
      printf("value: %d\n", *ptr_const);

      value = 9;
      printf("value: %d\n", *ptr_const);
      return 0;
  }
```

#### Ngoài lề:

Một con trỏ trỏ đến địa chỉ của hằng số, nếu hằng số đó là:

- Biến cục bộ (local-variables): Có thể thay đổi giá trị

```c
  #include <stdio.h>

  int main()
  {
      const int value = 5;
      int *ptr_const = &value;

      printf("value: %d\n", *ptr_const); // 5

      *ptr_const = 7; // giải tham chiếu
      printf("value: %d\n", *ptr_const); // 7
      return 0;
  }
```
- Biến toàn cục (global-variables): Không thể thay đổi giá trị

#### Ứng dụng:
- Giữ lại dữ liệu trước đó, đảm bảo dữ liệu không bị thay đổi trong quá trình xử lý dữ liệu (struct, JSON, dữ liệu trong thanh ghi IDR)

-> Đọc dữ liệu không được phép thay đổi.

## 4. Constant Pointer (Hằng con trỏ) 
(Vừa đọc - Vừa ghi)

> Là con trỏ mà tại địa chỉ trỏ đến không thể thay đổi được địa chỉ, chỉ thay đổi được giá trị.
>
> Chỉ được trỏ đến 1 địa chỉ duy nhất.

```c
  int *const ptr = &value;
```

- _VD4:_

```c
  #include<stdio.h>

  int a = 10;
  int b = 3;
  int *const ptr = &a;

  int main()
  {
      printf("%p\n", ptr);
      printf("%d\n", *ptr); // ptr_const = 10

      *ptr = 15; // Thay đổi giá trị tại con trỏ
      printf("%p\n", ptr);
      printf("%d\n", *ptr); // ptr_const = 15
  }
```
**Ứng dụng:**
VD1: Hằng con trỏ

- Thay đổi dữ liệu thanh ghi (IDR) mà dữ liệu thanh ghi (ODR) không bị thay đổi

VD2: Kết hợp con trỏ hằng + hằng con trỏ

```c
  const int *const ptr_const = &value;
  // con trỏ hằng: Không cho phép thay đổi dữ liệu
  // hằng con trỏ: Không cho phep thay đổi địa chỉ
  // `&value` là địa chỉ duy nhất trỏ đến
```
- Chỉ thao tác (ODR), mà không thể thay đổi dữ liệu và không thể trỏ đến địa chỉ khác ngoài (ODR)

## 5. NULL Pointer

> Là con trỏ không trỏ đến bất kỳ đối tượng hay vùng nhớ nào.
>
> Khai báo nhưng chưa sử dụng liền. 

**Lưu ý:** 

- Khi khai báo con trỏ mà chưa sử dụng thì dùng con trỏ NULL sẽ không bị **random** giá trị vào địa chỉ rác hoặc trùng lặp địa.

- Sử dụng trong 2 trường hợp, khởi tạo và kết thúc phải gán NULL.

```c
  int *ptr = NULL;
```
   
## 6. Pointer to Pointer (Con trỏ đến con trỏ)

> Là con trỏ lưu trữ địa chỉ của con trỏ khác, có nhiều cấp độ con trỏ (con trỏ cấp 2, 3,...).

```c
  int a = 10;
  int *ptr = &a; // Con trỏ cấp 1
  int **ptr = &ptr; // Con trỏ cấp 2
```
**Lưu ý:** 

- Ứng dụng trong kiểu dữ liệu Json, cấu trúc dữ liệu linked list.

- Đối với con trỏ cấp 2 là lưu địa chỉ của con trỏ cấp 1, chứ không phải lưu địa chỉ mà con trỏ đang trỏ đến.             

</details>

</details>
<details>
  <summary><h3>Bài 5: Storage Classes</h3></summary>

## 1. Extern

> Cho phép những file trong cùng 1 thư mục chia sẻ tài nguyên với nhau (biến, hàm, mảng).
>
> Các biến chỉ khai báo, không được khởi tạo.
>
> Khai báo biến cấp độ cao nhất - toàn cục.

**Ưu điểm quan trọng:** Tiết kiệm được bộ nhớ.

- Muốn sử dụng lại các biến đã khai báo trong file trước đó. Theo thông thường ta phải khai báo `#include"file.h"` hoặc `#define_FILE1_H`, đối với xử lý nhiều file thì việc khai báo cho file main.c sẽ tốn rất nhiều bộ nhớ.

_VD1:_ Ta có 3 file
     
          file1.c

          file2.c

          main.c 

➡️ Để sử dụng các biến của 1 và 2, ta khai báo `extern int a;` hoặc `extern int b;`.

## 2. Static

### 2.1 Satic - local variables(bss & data)

> Được sử dụng, giới hạn phạm vi trong 1 hàm. 
>
> Giữ lại giá trị sau những lần gọi hàm, địa chỉ tổn tại trong suốt chương trình.
>
> Static cục bộ không thể thay đổi giá trị bên ngoài, nếu muốn thay đổi thì sử dụng con trỏ.

_VD2: Static biến cục bộ_

```c
     #include<stdio.h>
     void count(){
          int a=5;
          a++;
          printf("Gia tri: %d\n",a);
     }

     int main(int argc, char const *argv[]){
          count(); //6
          count(); //6
          count(); //6
          count(); //6
     }
```
- Hàm `count` dù được gọi bao nhiêu lần vẫn in ra giá trị là 6. Vì biến `a` được khai báo là 1 biến cục bộ trong hàm `count()`
- Sau khi hàm `count` đầu tiền hoàn thành, `a` sẽ bị hủy giá trị (cấp thoát địa chỉ) và các giá trị tiếp theo vẫn = 6. 
- Nếu ở thêm biến `static` cục bộ vào `int a=5;` là `static int a=5;` thì giá trị `a` mới có thể tăng dần lên 7, 8,... theo số lần gọi hàm `count`.
- Có thể dùng con trỏ để thay đổi giá trị 
```c
     #include<stdio.h>

     int *ptr = NULL;
     void count(){
          static int a=5;
          ptr = &a;
          a++;
          printf("Gia tri: %d\n",a);
     }

     int main(int argc, char const *argv[]){
          count(); //6
          count(); //7
          count(); //8
          *ptr = 99;
          count(); //100
     }
```

### 2.2 Satic - global variables

> Giới hạn phạm vị sử dụng trong 1 file, không thể liên kết file (các file khác không dùng Extern để gọi ra được). 
>
> Không thể dùng con trỏ để thay đổi giá trị.

**- Ưu điểm:** Sử dụng static toàn cục để ẩn ở quá trình trung gian tính ra kết quả. Như tính delta trong phương trình bậc 2.

### 2.3 Satic - class (hướng đối tượng trong C++), học sau

## 3. Volatile

**Biến volatile là gì?** Khai báo biến mà biến này không sử dụng, tránh bị complier tối ưu hóa xóa cái biến này đi.

> Dùng trong code cho MCU, ép buộc 1 biến truy cập đến địa chỉ và nó không bị xóa khỏi bộ nhớ khi biến đó k được sử dụng.

```c
     // Dùng trong code VDK

     #include "stm32f4xx.h"
     volatile unit8_t var = 0;

```

**Ứng dụng:** Đọc giá trị cảm biến nhiệt độ nhiệt độ, ví dụ có 10 giá trị 30 độ C giống nhau, thì có nguy cơ biến CB nhiệt độ bị xóa khỏi bộ nhớ. Vì vậy, sử dụng biến Volatile đảm bảo cảm biến nhận đúng giá trị không bị cấp thoát, hạn chế sai số.

## 4. Register

![](https://github.com/hthuan02/Advanced-C-Cpp-and-Algorithm/blob/main/C/Bai5_Storage%20Classes/register.png)

Khi thực thi 1 chương trình sẽ trải qua 4 giai đoạn:

**(1):** Lưu trữ từ trong bộ nhớ RAM, thực hiện tính toán.

**(2):** Thao tác tính toán các giá trị.

**(3):** Tính xong thì lưu giá trị trong thanh ghi.

**(4):** Lấy giá trị trong thanh ghi trả về biến trong RAM, kết quả = 6.


**Ứng dụng của biến register:**

- Khai báo biến register, thì chương trình chỉ thực hiện tính toán và lưu giá trị trên thanh ghi( bị lượt bỏ 2 bước đầu-cuối: Lưu trữ trên RAM và trả kqua từ thanh ghi lên RAM). Giúp rút ngắn thời gian chạy và tăng hiệu suất làm việc của chương trình.
     
- Chỉ sử dụng cho biến cục bộ.

</details>

<details>
  <summary><h3>Bài 6: Goto - Setjmp</h3></summary>
  
## I. Goto
>Cho phép đoạn code nhảy đến label(nhãn) mà mình chỉ , label có để đặt bất cứ vị trí nào trong cùng 1 hàm.

- _VD1: Tạo Menu sử dụng lệnh Goto_
   
```c
  #include<stdio.h>

  int main(int argc, char const *argv[])
  {
    int option;
    menu1:
    do{
      printf("Menu1\n");
      printf("1: Tao ra menu thu ....\n");
      printf("2....\n");
      printf("3....\n");
      printf("%d....\n",option);
    } while(option != 1);

  switch (option){
    case 1:
      printf("Menu2\n");
      printf("0: Quay lai Menu 1\n");
      printf("1: Ket thuc chuong trinh\n");
      printf("2....\n");
      scanf("%d",&option);
      break;
    
      switch (option){
        case 0:
          /* goto <label> */
          goto menu1;
        case 1:
          goto thoatchuongtrinh;
        case 2:
          break;
        }
        break;

        case 2:
          /* code */
        break;

      case 3:
        /* code */
      break;

      default:
        break;         
    }
    thoatchuongtrinh:
    return 0;
  }
```

   - Chương trình chạy tuần tự từ Menu1 đến Menu2. Nhưng ở Menu2 có 2 Option:
      - `case 0:`: Dùng lệnh `goto menu1;` và đặt lệnh `menu1:` ở đầu Menu1, chương trình sẽ trở về Menu1.
      - `case 1`: Lệnh `goto thoatchuongtrinh;` và đặt lệnh `thoatchuongtrinh:` ở cuối, chỉ định chương trình thoát ra khỏi switch để kết thúc chương trình.
  
## Nhược điểm của Goto:
-  Vì chương trình không chạy tuần tự, nên code khó đọc, khó quản lý và bảo trì.
-  Khó debug, vì khó xác định được vị trí gây lỗi.

## Ưu điểm:

### 1. Thoát khỏi nhiều cấp độ vòng lặp
   
>Đối chương trình nhiều cấp độ vòng lặp, mình muốn thoát ra thì phải xét điều kiện và break để thoát chương trình, sẽ phức tạp.

_- VD2:_
   
```c
   int i,j;

   while(1){
      for(i=1; i<5; i++ ){
         for(j=1; j<5; j++ ){
            if (i == 2 && j == 3){
               printf("break for j\n");
               break; //Chi thoat duoc For cua j 
            }
         if (i == 2 && j == 3){
               printf("break for i\n");
               break; //Thoat duoc For cua i 
            }
         }
      }
      if (i == 2 && j == 3){
         printf("break while \n");
         break; //Thoat duoc For cua while       
      }
   } 
```
- Sử dụng `goto` để thoát chương trình nhanh hơn.

```c
   int i,j;

   while(1){
      for(i=1; i<5; i++ ){
         for(j=1; j<5; j++ ){
               if (i == 2 && j == 3){
               printf("Thoat chuong trinh\n");
               goto thoat; //1 lenh goto, thoat duoc 3 vong lap
         }
      }
   thoat: 
   return 0;
   }
```
### ỨNG DỤNG
 Dùng trong Led ma trận, kết hợp với thuật toán quét led.

## II. Thư viện <setjmp.h>
> Cho phép chương trình có thể nhảy từ nhãn đặt trong hàm này sang nhãn đặt trong hàm khác thông qua setjmp và longjmp.
>
> Thư viện setjmp.h bao gồm 2 hàm setjmp và longjmp.
>
> Xử lý ngoại lệ 

### 1. Hàm setjmp
```c
   int setjmp(jmp_buf);
```

- Khi gọi `setjmp` lần đầu, thì mặc định trả về 0.

### 2. Hàm longjmp
```c
   longjmp(jmp_buf, int value);
```

- Khi gọi `longjmp` thì luồng của chương trình sẽ nhảy về `setjmp`. Sau đó, gán giá trị của `int value` vào giá trị mới của `setjmp`

_- VD3:_


### 3. Xử lý ngoại lệ(TRY, CATCH, THROW) (Chưa hoàn thành)
</details>

<details>
  <summary><h3>Bài 7: Struct & Union</h3></summary>

## 1. Struct

> Struct là 1 dạng kiểu dữ liệu, cho phép người dùng tự định nghĩa. Nhóm các kiểu dữ liệu như: int, char, double,... lại thành kiểu dữ liệu mới. 
>
> Kích thước của Struct = Tổng các kích thước dữ liệu + padding 


```c
    #include <stdio.h>
    #include <stdint.h> // Thư viện để sử dụng uint32_t, uint8_t, uint16_t

    struct Data {
      int a;
      double b;
      char c;
    };

    struct Data data1, data2, data3;

```

hoặc:
```c
    typedef struct Data{
      int a;
      double b;
      char c;
    } Data;

    Data *data1, data2, data3;

```

- Trong hàm `main.c` thì `data.a = 0;`
- Đối với con trỏ `*ptr` thì `data ->a = 0;`

_VD1:_

```c
    #include <stdio.h>
    #include <stdint.h> // Thư viện để sử dụng uint32_t, uint8_t, uint16_t

    typedef struct {
      uint32_t var1;
      uint8_t var2;
      uint16_t var3;
    } data; // Tên kiểu dữ liệu là data

    int main(int argc, char const *argv[]) {
      printf(" Size of data: %d\n");
      data data;

      printf("Address of var1: %p\n", &data.var1);
      printf("Address of var2: %p\n", &data.var2);
      printf("Address of var3: %p\n", &data.var3);

      return 0;
    }
```
## Data alignment & padding

- Data alignment: Là việc canh chỉnh, sắp xếp dữ liệu được sắp xếp dữ liệu vào đúng kích thước của CPU (gồm 2 byte, 4 byte, 8 byte,..). Đảm bảo hiệu suất hoạt động của bộ nhớ, dễ dàng truy cập và xử lý nhanh hơn.

- Padding(đệm vào): Khi canh chỉnh, sắp xếp bộ nhớ còn dư ra 1 vài byte trên tổng số ổ đĩa thì đó là padding.

```c
    //double(8byte): Chia het 8, 0x00 0x08 0x10 0x18,..
    //int, int32_t, uint32_t(4byte): 0x00 0x04 0x08 0x0C...
    //float, init16_t, uint16_t(2byte): 0x00 0x02 0x04 0x06...
    //padding
```
➡️ Kích thước của Struct = tổng các kiểu dữ liệu + padding
  
**_VD2: Tìm kích thước struct VD1_**

```c
    typedef struct {
      uint32_t var1; //Chia hết cho 8 (4byte) 
      uint8_t var2; //1byte
      uint16_t var3; //2byte
    } data;
```
- Giải thích: Ưu tiên kích thước dữ liệu lớn nhất làm chuẩn (4byte).
    - var1 (4byte)

    - var2 (1byte) + var3 (2byte) = 3 byte (dư 1 byte) -> 1 padding

    - Tổng = 8

**_VD3: Tìm kích thước_**

```c
      uint8_t var1[9]; //1byte 
      uint64_t var2[3]; //8byte
      uint16_t var3[10]; //2byte
      uint32_t var4[2]; //4byte

```

- Giải thích:
    - Kích thước lớn nhất là 8 byte.
    
    - var1: 8byte(làm chuẩn) + (1byte lẻ + 7padding) = 16  
    
    - var2: 8byte *3 = 24
    
    - var3: 8byte *2 + (4byte lẻ + 4padding) = 24
    
    - var4: 8byte
    
    - Tổng kích thước = 72 byte

### Ứng dụng của Struct: 
    
- Json
- Cấu trúc dữ liệu list
- Giao thức trong MCU, mỗi thông số đều có cấu hình khác nhau -> Dùng Struct để gom các thông số về.

## 2. Union

>
> Giống với struct, đây là kiểu dữ liệu người dùng tự định nghĩa bằng cách nhóm các kiểu dữ liệu lại.
>
> Union sử dụng chung vùng nhớ, các thành phần đều chung địa chỉ -> Giá trị này thay đổi thì những giá trị khác sẽ thay đổi.
>
> Kích thước Union = Tổng member có kích thước lớn nhất + padding.

**_VD4: Kiểm tra kích thước của Union_**
```c    
#include <stdio.h>
#include <stdint.h>

typedef union
{
    uint8_t var1; // 1byte
    uint32_t var2; // 4 byte
    uint16_t var3; // 2 byte

    // Union sẽ lấy kiểu dữ liệu có kích thước lớn nhất 24 byte
} frame;

int main(int argc, char const *argv[])
{

    printf("Size = %d\n", sizeof(frame)); //Kích thước lớn nhất 4byte
    frame data;

    data.var1 = 5;
    data.var2 = 6;
    data.var3 = 7;
    //Vì dữ liệu kiểu Union-> SD chung vùng nhớ
    //Lấy data sau cùng
    printf("Var1 = %d\n", data.var1);   //7
    printf("Var2 = %d\n", data.var2);   //7
    printf("Var3 = %d\n", data.var3);   //7
    return 0;
}
```

**Trường hợp đặc biệt của VD4:**

```c
    int main(int argc, char const *argv[])
    {
    
        printf("Size = %d\n", sizeof(frame));
        frame data;

        data.var2 = 4294967294;

        printf("Var1 = %d\n", data.var1); //254   
        printf("Var2 = %u\n", data.var2); //4294967294
        printf("Var3 = %d\n", data.var3); //65534
        return 0;
    }
```

- Giải thích:
    - Vì `data.var2 = 4294967294;` chuyển sang binary = 11111111 11111111 11111111 11111110
    
    - Địa chỉ bắt đầu, 0x01 lưu byte thấp nhất.
  
        | 0x01 | 0x02 | 0x03|0x04|
        | :---: | --- | ---: | ---: |
        | 11111110 | 11111111 | 11111111 | 11111111 |
        | 254 | 65535 | 65535 | 65535 |

    -  var1: 1byte = 254 (0x01)
  
    -  var2: 4byte = 4294967294 (4 ô địa chỉ)

    -  var3: 2byte = 65534 (0x01+0x02)

</details>


<details>
  <summary><h3>Bài 8: Memory Layout</h3></summary>


<details>
  <summary><h2> A. 5 Phân vùng nhớ</h2></summary>

- Memory Layout: Là sự tổ chức và sắp xếp các vùng nhớ (chứa mã lệnh, biến, và dữ liệu) trong bộ nhớ RAM khi chương trình thực thi.  

- Gồm có 5 phân vùng bộ nhớ, theo thứ tự từ trên xuống:

<img src="https://github.com/hthuan02/Advanced-C-Cpp-and-Algorithm/blob/main/C/Bai8_Memory_layout/img/memorylayout.png" alt="Memory Layout" width="500"/>

## 1. Text segment

> Chỉ có quyền đọc, không thể ghi(chỉnh sửa).
>
> lưu các giá trị const, char *ptr.

_- VD1:_
```c
    int const a = 10;

    int main(int argc, char const *argv[])
    {
        /*Code*/
        return 0;
    }
```
và:

```c
    char *str = "hello word";

    int main(int argc, char const *agrv[])
    {
        printf("String: %s\n", *str);
        return 0;
    } 
```
- Cả 2 chương trình trên chỉ có thể đọc (Read Only), không thể thay đổi giá trị.

## 2. Initialized Data (DS)
(Khởi tạo dữ liệu)

> Gồm các biến toàn cục, giá trị khác 0.
>
> Biến Static (global + local) khác 0.
> 
> Có thể đọc và ghi giá trị (Read + Write).

_VD2:_

```c
    #include <stdio.h>

    int a = 5;
    static int b = 6; // Lưu ở data (Static global)
    void *ptr = &b;   // Data

    void test()
    {
        static int c = 7; // Static local
    }

    int main(int argc, char const *ptr[])
    {
        a = 15;
        b = 16;
        printf("a=%d\n", a);
        printf("b=%d\n", b);
        return 0;
    }
```
- Trong chương trình trên, có thể đọc và thay đổi giá trị a b. Nếu muốn thay đổi giá trị c, thì phải dùng *ptr.

## 3. Unintialized Data (Bss)
(Dữ liệu không được khởi tạo)

> Biến toàn cục giá trị = 0 hoặc NULL(không gán giá trị).
>
> Static(global + local) =0.

_VD3:_

```c
    #include <stdio.h>

    typedef struct
    {
        int x;
        int y;
    } Point_data;

    Point_data p1 = {5, 7}; // data
    Point_data p2;          // bss

    int a = 0; // bss
    int b = 5; // data

    static int m = 0; // bss
    static int n;     // bss

    void test()
    {
        static int c = 0; // bss
        static int d;     // bss
    }

    int main(int argc, char const *argv[])
    {
        /*code*/
        return 0;
    }
```
## 4. Stack segment

> Chứa biến cục bộ (trừ static cục bộ).
>
> Có thể đọc và ghi.
>
> Sau khi kết thúc 1 lần gọi hàm  địa chỉ của biến cục bộ bị thu hồi LIFO(Last In - First Out) 

_VD4:_

```c
    #include <stdio.h>

    int total(int a, int b)
    {
        int c; //stack
        c = a + b;
        return c;
    }
    
    int main(int argc, char const *argv[])
    {
        printf("a+b = %d\n", total(5, 6));
        return 0;
    }
```
➡️➡️➡️ Để đọc và ghi dữ liệu ở biến cục bộ, phân vùng stack thì dùng `*ptr`.

_VD5:_

```c
    #include <stdio.h>

    int *ptr = NULL;
    void test()
    {
        const int a = 10; // stack -> cục bộ
        ptr = &a;
    }

    int main(int argc, char const *argv[])
    {
        test();
        *ptr = 20;
        printf("a= %d\n", *ptr); // a=20, thay đổi được giá trị nhưng WARNING!!
        return 0;
    }
```

## 5. Heap segment

> Dùng để cấp phát động bộ nhớ.
>
> Đi kèm với các hàm như: malloc(), calloc(), realloc(), free().
>
> Khai báo thư viện `#include<stdlib.h>`.

**Cấp phát động là gì?**
- Ví dụ khai báo 1 mảng có 12 kí tự `char array[12]`, nhập tên từ bàn phím vào mảng này
    - Nếu kí tự nhập vào > 12: xảy ra hiện tượng tràn bộ nhớ.

    - Nếu kí tự nhập vào < 12: xảy ra hiện tượng lãng phí bộ nhớ.

-> Trong ngôn ngữ C, sinh ra khái niệm cấp phát động để tối ưu bộ nhớ. Tránh việc tràn hoặc lãng phí bộ nhớ.

</details>

<details>
  <summary><h2>B. Heap segment - Cấp phát động</h2></summary>

> Khai báo thư viện `#include<stdlib.h>`
>
> Giải phóng bộ nhớ `free(ptr)`
  
## I. Các hàm cấp phát động

### 1. Hàm Malloc()

> `malloc`: Cấp phát bộ nhớ động, không khởi tạo giá trị.
>
> Giá trị của hàm trả về là 1 `*void`, cần ép kiểu dữ liệu.
>
> Giá trị trong ô nhớ được cấp phát là 1 giá trị random(giá trị rác).

```c
  ptr = (cast_type*)malloc(byte_size);
```

- `ptr`: Con trỏ lưu trữ ô nhớ đầu tiên của vùng nhớ cấp phát.

- `cast_type`: Kiểu con trỏ muốn ép kiểu sang.

- `byte_size`: Kích thước byte cần cấp phát.

_VD1:_

```c
    #include <stdio.h>
    #include <stdlib.h>

    int main(int argc, char const *argv[])
    {
        // Cấp phát vùng nhớ mảng 100 phần tử int
        // sizeof(int) = 4
        int *a = (int *)malloc(100 * sizeof(int)); // 400

        // Cấp phát vùng nhớ mảng 1000 phần tử char
        // sizeof(char) = 1
        char *c = (char *)malloc(1000 * sizeof(char)); //1000
        return 0;
    }
```
- Trường hợp không cấp phát đủ vùng nhớ, thì `malloc()` sẽ trả về con trỏ NULL.

_VD2:_
```c
  #include <stdio.h>
  #include <stdlib.h>

  int main(int argc, char const *argv[])
  {
      int n = 10;
      int *a = (int *)malloc(n * sizeof(int)); //vùng nhớ 40 byte
      if (a == NULL)
      {
          printf("Cap phat khong thanh cong !\n");
      }
      else
      {
          int i = 0;
          printf("Cap phat thanh cong !\n");
          for (i = 0; i < n; i++)
          {
              a[i] = 28 + i; // *(a + i) = 28 cũng được
          }
          for (i = 0; i < n; i++)
          {
              printf("%d ", a[i]); // 28 29 ... 37
          }
          free(a); // Hàm giải phóng vùng nhớ
          printf("\nGiai phong thanh cong !\n"); 
      }
      return 0;
  }

```
- Giải thích:

/*
ban đầu  int = 0

0    1    2    3....9

28 29 30 31...37

40 (byte cấp phát malloc) - 10 byte(sử dụng) = (dư) 30 byte 

-> Nhưng vì sử dụng hàm malloc(Cấp phát động).

-> Nên không xảy ra hiện tượng lãng phí bộ nhớ khi dư 30 byte.
*/

### 2. Hàm Calloc()

> Hàm cấp phát bộ nhớ động tương tự `malloc`, `calloc` có khởi tạo tất cả vùng bộ nhớ về giá trị 0.
>
```c
    ptr = (cast_type*) calloc(n, element_size)
```
- `ptr`: Con trỏ đầu tiên của vùng nhớ được cấp phát.

- `cast_type*`: Kiểu con trỏ muốn ép kiểu.

- `n`: Số lượng phần tử muốn cấp phát.
- `element_size`: Kích thước 1 phần tử(byte).

_VD3:_
```c
    #include <stdio.h>
    #include <stdlib.h>

    int main()
    {
        int n = 10;
        int *a = (int *)calloc(n, sizeof(int));
        if (a == NULL)
        {
            printf("Cap phat khong thanh cong !\n");
        }
        else
        {
            int i = 0;
            printf("Cap phat thanh cong !\n");
            printf("Mang ban dau : ");

            for (i = 0; i < n; i++)
            {
                printf("%d ", a[i]);
            }
            for (i = 0; i < n; i++)
            {
                a[i] = 28 + i; // *(a + i) = 28 cũng được
            }
            printf("\nMang sau khi thay doi : ");
            for (i = 0; i < n; i++)
            {
                printf("%d ", a[i]);
            }
            free(a); // Hàm giải phóng vùng nhớ
            printf("\nGiai phong thanh cong !\n"); 
        }
        return 0;
    } 
```

**Giải thích:**
- Cách thức hoạt động của `calloc()` tương tự `malloc`, nhưng 10 giá trị ban đầu
của mảng là 0:  0  0  0  0  0  0  0  0  0  0  0

- Mảng  sau khi thay đổi là: 28 29 30   ...   37

### 3. Hàm Realloc()

> Là hàm cấp phát lại, có thay đổi kích thước của vùng nhớ đã cấp phát trước đó.

```c
    ptr = (cast_type*)realloc(ptr,new_size)
```

- `ptr`: Con trỏ đến vùng nhớ đã được cấp phát trước đó.

- `new_size`: Kích thước mới của bộ nhớ cần thay đổi.

_VD4:_

```c
    //Cấp phát mảng 10 phần tử, kích thước 40byte 
    int *array = (int *) malloc(10 * sizeof(int));

    //Thay đổi, tăng kích thước mảng lên 20 phần từ, 80byte
    array = (int *) realloc(array, 10 * sizeof(int));  

    free(array); //Giải phóng bộ nhớ
```

## II. So sánh malloc, calloc và realloc

| Đặc điểm               | `malloc`                                       | `calloc`                                         | `realloc`                                      |
|-----------------------|------------------------------------------------|-------------------------------------------------|------------------------------------------------|
| **Công dụng**         | Cấp phát bộ nhớ động, không khởi tạo giá trị                           | Cấp phát bộ nhớ động và khởi tạo về 0          | Thay đổi kích thước vùng nhớ đã được cấp phát |
| **Cú pháp**           | `void* malloc(byte_size);`                  | `void* calloc(n, element_size);`     | `void* realloc(void *ptr, new_size);`     |
| **Giá trị khởi tạo**  | Không khởi tạo, dữ liệu là rác                 | Khởi tạo tất cả phần tử về 0                     | Không khởi tạo, dữ liệu giữ nguyên (có thể mất dữ liệu mới nếu mở rộng) |
| **Kích thước**        | Cấp phát bộ nhớ theo kích thước được chỉ định  | Cấp phát bộ nhớ cho số phần tử × kích thước phần tử | Cấp phát hoặc thu nhỏ bộ nhớ theo kích thước mới |
| **Trả về**            | Con trỏ đến vùng nhớ đã cấp phát hoặc `NULL`  | Con trỏ đến vùng nhớ đã cấp phát hoặc `NULL`   | Con trỏ đến vùng nhớ đã thay đổi hoặc `NULL`  |

- Kết thúc chường trình phải có hàm `free(ptr)`: Để thu hồi, reset lại vùng nhớ.

## III. So sánh stack & heap

<img src="https://github.com/hthuan02/Advanced-C-Cpp-and-Algorithm/blob/main/C/Bai8_Memory_layout/img/stack_heap.png" alt="Memory Layout" width="220"/>

### 1. Giống nhau:

- Đều nằm trong RAM và dùng để lưu trữ dữ liệu.

- Hỗ trợ nhiều kiểu dữ liệu.

- Ảnh hưởng đến hiệu suất chương trình.

- Có thể gây tràn bộ nhớ nếu dùng sai cách.

### 2. Khác nhau:

| **Tiêu chí**              | **Stack**                                                                 | **Heap**                                                          |
|---------------------------|---------------------------------------------------------------------------|-------------------------------------------------------------------|
| **Lưu trữ**              | Biến cục bộ, tham số hàm                                              | Vùng nhớ cấp phát động: malloc, calloc, realloc                                   |                                      |
| **Tốc độ**                | Nhanh                                                                    | Chậm hơn Stack.                                                   |
| **Giải phóng**            | Khi kết thúc hàm                                                 | `free()` hoặc `delete`                                 |
| **Kích thước**            | Cố định (nhỏ hơn)                                                        | Linh hoạt (lớn hơn)                                              |
| **Thời điểm cấp phát**    | Lúc biên dịch.                                                            | Lúc chạy chương trình.                                            |
| **Tràn bộ nhớ**           | Stack overflow khi dùng quá nhiều bộ nhớ (VD: Gọi hàm mà không có điều kiện dừng)                                 | Heap overflow khi không giải phóng hoặc cấp phát quá lớn(Vùng nhớ quá lớn so với Heap)         |

</details>

</details>




<details>
  <summary><h3>Bài 12: Algorithm</h3></summary>

<details>
  <summary><h3>A. Bubble Sort (Sắp xếp nổi bọt)</h3></summary>

> Là thuật toán hoán đổi các phần tử liền kề để đưa các phần tử lớn hơn về cuối dãy (phần tử nhỏ hơn thì ở đầu dãy)

- Thuật toán gồm các bước:
  
  - B1: Duyệt qua danh sách từ đầu đến cuối.

  - B2: So sánh hai phần tử liền kề, nếu phần tử trước lớn hơn phần tử sau, thì hoán đổi vị trí.
  
  - B3: Lặp lại quá trình cho đến khi không còn sự hoán đổi nào xảy ra (mảng đã được sắp xếp).

_VD: Sắp xếp mảng 6 phần tử tăng dần_

<img src="https://github.com/hthuan02/Advanced-C-Cpp-and-Algorithm/blob/main/C/Bai12_Algorithm/img/Bubble_Sort1.png" alt="Memory Layout" width="400"/>

Thực hiện:

### Lượt 1: Tìm phần tử có giá trị lớn nhất hoán đổi ra vị trí cuối cùng (phần tử 5)
  
- Lần 1: Hoán đổi phần tử đầu 0 và phần tử liền kề 1, `5` với `3` 

  - `3` nhỏ hơn -> Hoán đổi ra đầu.
  
  - `5` lớn hơn -> Hoán đổi ra sau 

  - Output: `3, 5, 8, 6, 2, -3`

- Lần 2: Hoán đổi 2 phần tử thứ 1 và phần tử liền kề thứ 2, `5` với `8` (giữ nguyên vì tăng dần)

  - Output: `3, 5, 8, 6, 2, -3`

- Lần 3: Hoán đổi phần từ thứ 2 và phần tử liền kề thứ 3, `8` với `6`

  - `8` lớn hơn -> Hoán đổi ra sau

  - `6` nhỏ hơn -> Hoán đổi ra trước

  - Ouput: `3, 5, 6, 8, 2, -3`

- Lần 4: Hoán đổi phần từ thứ 3 và phần tử liền kề thứ 4, `8` với `2`

  - `8` lớn hơn -> Hoán đổi ra sau

  - `2` nhỏ hơn -> Hoán đổi ra trước

  - Ouput: `3, 5, 6, 2, 8, -3`

- Lần 5: Hoán đổi phần từ thứ 4 và phần tử liền kề thứ 5, `8` với `-3`

  - `8` lớn hơn -> Hoán đổi ra sau

  - `-3` nhỏ hơn -> Hoán đổi ra trước

  - Ouput: `3, 5, 6, 2, -3, 8`

#### Phần tử cuối cùng có giá trị `8`, kết thúc lượt 1

<img src="https://github.com/hthuan02/Advanced-C-Cpp-and-Algorithm/blob/main/C/Ba12_Algorithm/img/Bubble_Sort5.png" alt="Memory Layout" width="550"/>


### Lượt 2: Tìm phần tử lớn thứ 2, thực hiện hoán đổi trước phần tử cuối (phần tử 4)

- Hoán đổi `3` với `5` giữ nguyên, vì tăng dần

- Hoán đổi `5` với `6` giữ nguyên, vì tăng dần

- Hoán đổi `6` với `2` -> Ouput: `3, 5, 2, 6, -3, 8`

- Hoán đổi `6` với `-3` -> Ouput: `3, 5, 2, -3, 6, 8`

#### Phần tử lớn thứ 2 là `6`, kết thúc lượt 2

<img src="https://github.com/hthuan02/Advanced-C-Cpp-and-Algorithm/blob/main/C/Bai12_Algorithm/img/Bubble_Sort6.png" alt="Memory Layout" width="550"/>

### Lượt 3: Tìm phần tử lớn thứ 3, hoán đổi trước phần tử thứ 4

- Hoán đổi `3` với `5` giữ nguyên, vì tăng dần

- Hoán đổi `5` với `2` -> `3, 2, 5, -3, 6, 8`

- Hoán đổi `5` với `-3` -> `3, 2, -3, 5, 6, 8`

#### Phần tử lớn thứ 3 là `5`, kết thúc lượt 3

<img src="https://github.com/hthuan02/Advanced-C-Cpp-and-Algorithm/blob/main/C/Bai12_Algorithm/img/Bubble_Sort7.png" alt="Memory Layout" width="550"/>


### Lượt 4: Tìm phần tử lớn thứ 4, hoán đổi trước phần tử lớn thứ 3

- Hoán đổi `3` với `2` -> `2, 3, -3, 5, 6, 8` 

- Hoán đổi `3` với `-3` -> `2, -3, 3, 5, 6, 8`

#### Phần tử lớn thứ 4 là `3`, kết thúc lượt 4

<img src="https://github.com/hthuan02/Advanced-C-Cpp-and-Algorithm/blob/main/C/Bai12_Algorithm/img/Bubble_Sort8.png" alt="Memory Layout" width="550"/>


#### Lượt 5: Tìm phần tử lớn thứ 5, hoán đổi trước phần tử lớn thứ 2

- Hoán đổi `2` với `-3` -> `-3, 2, -3, 5, 6, 8` 

#### Phần tử lớn thứ 5 là `2`, kết thúc lượt 5

<img src="https://github.com/hthuan02/Advanced-C-Cpp-and-Algorithm/blob/main/C/Bai12_Algorithm/img/Bubble_Sort9.png" alt="Memory Layout" width="550"/>



</details>

</details>
