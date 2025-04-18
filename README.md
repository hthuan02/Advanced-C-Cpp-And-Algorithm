# Phần I: C & Algorithm
---

<details>
  <summary><h3>Bài 1: Compiler - Macro</h3></summary>

IDE gồm: `Dev-C++, VS Code(đã cài Extensions), Arduino IDE, KeilC, STM32CubeIDE,...`

- Editor: Phần mềm soạn thảo.

- Complier: Trình biên dịch, chuyển đổi ngôn ngữ bậc cao sang ngôn ngữ máy.

## I. Quá trình Compiler

![](E:\Desktop\AUTOSAR\Advanced-C-Cpp-and-Algorithm\C\Bai1_Complier_Macro\Complier\img)

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
  <summary><h4>VD3: (Hoàn thiện nhất) Tính tổng không biết số lượng phần tử truyền vào, có số 0 trong phần tử</h4></summary>

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

## II. Assert (đang làm)

</details>

<details>
  <summary><h3>Bài 4: Pointer</h3></summary>

# A. Phần 1

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
  int *ptr_int;       // con trỏ đến kiểu int
  char *ptr_char;     // con trỏ đến kiểu char
  float *ptr_float;   // con trỏ đến kiểu float
```

- **Lấy địa chỉ của biến**
```c
  int x = 10;
  int *ptr_x = &x;  // ptr_x chứa địa chỉ của x
```
- **Truy cập giá trị (giải tham chiếu - dereference)**
```c
  int y = *ptr_x    // y sẽ bằng giá trị của x
  ptr_x = &x;
  *ptr_x = *(0x01) = 10;
```

## 1. Kích thước của Con trỏ
- Phụ thuộc vào kiến trúc của máy tinh và trình biên dịch.
_VD:_ Laptop 64bit --> 8byte

- Trên MCU phụ thuộc vào kiến thúc vi xử lý.
_VD:_  STM32/32bit --> 4byte

       STM8/8bit   --> 1byte

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

_VD: (Lấy ở đầu bài)_
```c
  int var = 10;
  int *ptr = &var;
```

## 3. Array Pointer(Con trỏ với mảng)

> Vùng nhớ câp phát cho mảng(kích thước của mảng) phụ thuộc vào (số lượng phần tử) * (kiểu dữ liệu).

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

_VD: Hoán đổi swap(a,b)_


# B. Phần 2

## 4. Void Pointer
> Là 1 biến, có thể trỏ đến bất kỳ địa chỉ có kiểu dữ liệu nào cũng được, nó không quan tâm các kiểu dữ liệu như (char, int, float, double,...).

- Ưu điểm: Tại địa chỉ trỏ đến có thể đọc và thay đổi giá trị, với điều kiện phải ép kiểu con trỏ void.

```c
  void * ptr; //Khai bao con tro Void
```
- _VD1: Xuất giá trị kiểu int, char._

```c
  #include <stdio.h>

  int main(int argc, char const *argv[]){
      void *ptr;

      int a = 10;
      ptr = &a;
      printf("Dia chi: %p, Gia tri: %d\n", ptr, *(int*)(ptr));

      char c = 'C';
      ptr = &c;
      printf("Dia chi: %p, Gia tri: %c\n", ptr, *(char*)(ptr));
  }
```

## 5. Function Pointer
> Là 1 biến, có thể trỏ đến địa chỉ của 1 hàm có kiểu dữ liệu cụ thể.
>
>Đây là biến giữ địa chỉ của hàm, mỗi thời điểm chỉ trỏ 1 hàm.

- Thông thường sử dụng theo 2 cách:
    - Là tham số truyền vào của 1 hàm.
    - Lưu trữ địa chỉ của 1 hàm. 

```c
   void (*func_ptr)(int, int);  // Khai bao con tro
```

- _VD2: Tổng, hiệu, tích, thương._

```c
  #include<stdio.h>

  void tong(int a, int b){
      printf("%d + %d = %d\n",a ,b, a + b); 
  }
  void hieu(int a, int b){
      printf("%d - %d = %d\n",a ,b, a - b); 
  }
  void tich(int a, int b){
      printf("%d * %d = %d\n",a ,b, a * b); 
  }
  void thuong(int a, int b){
      printf("%d / %d = %d\n",a ,b, a / b);
  }

  int main(int argc, char *argv[]) {
  int a = 10, b = 5;

  //Khai bao mang con tro Ham
  void (*cal[])(int, int) = {tong, hieu, tich, thuong};
  for (int i = 0; i < 4; i++) {
      cal[i](a, b);
  }
```

## 6. Pointer to Constant(Con trỏ hằng)

> Khi trỏ đến 1 địa chỉ, không thể thay đổi đc giá trị tại địa chỉ đó (chỉ có thể đọc và không thể thay đổi).
>
> Có thể trỏ đến nhiều địa chỉ khác nhau.

```c
  int const *ptr_const;
  const int *ptr_const;
```

- _VD3:_
```c
  #include<stdio.h>

  int a = 10;
  int b = 3; //Khai bao ptr_const cua b duoc.
  const int *ptr_const = &a;

  int main(int argc, char const *argv[])
  {
    printf("%p\n", ptr_const);
    printf("%d\n", *ptr_const); //ptr_const = 10

    // *ptr_const = 5;
    // Dong nay sai, chi co the thay doi gia tri tai a.
    // VD: a = 15 -> *ptr_const =

    a = 15;
    printf("%p\n", ptr_const);
    printf("%d\n", *ptr_const); //ptr_const = 15
  }
```
## 7. Constant Pointer(Hằng con trỏ)

> Tại địa chỉ trỏ đến không thể thay đổi được địa chỉ, còn giá trị có thể thay đổi được.
>
> Chỉ trỏ đến 1 địa chỉ cố đinh, khi đã trỏ đến 1 địa chỉ rồi thì không thể trỏ đến địa chỉ khác được nữa.

```c
    int *const const_ptr = &value;
```

- _VD4:_

```c
  #include<stdio.h>

  int a = 10;
  int b = 3; // Khong khai bao duoc const_ptr cua b!!!
  int *const const_ptr = &a;

  int main(int argc, char const *argv[])
  {
      printf("%p\n", const_ptr);
      printf("%d\n", *const_ptr); //ptr_const = 10
  
      *const_ptr = 15; // hay doi gia tri tai con tro luon.
      printf("%p\n", ptr_const);
      printf("%d\n", *ptr_const); //ptr_const = 15
  }
```


### Bảng so sánh Con Trỏ Hằng VS Hằng Con trỏ

| Khác nhau | Con trỏ hằng | Hằng con trỏ |
| :---: | --- | ---: |
| 1 |Có thể trỏ đến nhiều địa chỉ khác | Chỉ trỏ đến 1 địa chỉ duy nhất |
| 2 |Chỉ có thể đọc, không thể thay đổi giá trị(giá trị chỉ được thay đổi tại biến)| Có thể thay đổi giá trị |

   
## 8. NULL Pointer
>Con trỏ trống, không trỏ đến vùng nhớ nào.
>
>Khai báo nhưng chưa sử dụng liền.

**Lưu ý:** 
- Khi khai báo con trỏ mà chưa sử dụng thì dùng con trỏ NULL sẽ không bị **random** giá trị vào địa chỉ rác hoặc trùng lặp địa .
- Khởi tạo và kết thúc phải gán NULL.

```c
  int *ptr = NULL;
```
   
## 9. Pointer to Pointer(Con trỏ đến con trỏ)
>Là con trỏ mà có thể trỏ đến địa chỉ của các con trỏ khác, có nhiều cấp độ con trỏ (con trỏ cấp 2, 3,...).

```c
  int a = 10;
  int *ptr = &a;
  int **ptr = &ptr;
```
**Lưu ý:** 
- Được sử dụng trong kiểu dữ liệu Json, cấu trúc dữ liệu list.
- Đối với con trỏ cấp 2 là lưu địa chỉ của con trỏ cấp 1, chứ không phải lưu địa chỉ mà con trỏ đang trỏ đến.             

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
