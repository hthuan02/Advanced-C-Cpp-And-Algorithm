# Phần I: C & Algorithm
---

<details>
  <summary><h3>Bài 1: Compiler - Marco</h3></summary>

IDE gồm: `Dev-C++, VS Code(đã cài Extensions), Arduino IDE, KeilC, STM32CubeIDE,...`

- Editor: Phần mềm soạn thảo.

- Complier: Trình biên dịch, chuyển đổi ngôn ngữ bậc cao sang ngôn ngữ máy.

## I. Quá trình Compiler
Gồm 4 bước chính:

- Tiền xử lý (Preprocessor).

- Compiler.

- Asembler.

- Linker.

### 1. Tiền xử lý (Preprocessor)
(Chuyển file a.c, file b.h thành file main.i)

`gcc -E main.c -o main.i`

> Copy toàn bộ mã nguồn vào file main.i
>
> Xóa comment.
>
> Macro `#define` thì bị thay thế bằng đối tượng khác, còn lại giữ nguyên.

### 2. Complier
(chuyển file main.i thành file main.s)

`gcc -S main.i -o main.s`

> Tạo ra file hợp ngữ (file Assembly).
>
> Thao tác trên RAM mượt mà hơn.

### 3. Assembler
(chuyển file main.s thành file main.o)

`gcc -c main.s -o main.o`

> Mã nguồn chuyển thành các đoạn mã 0 1 (ngôn ngữ máy).
>
> Nếu code trên VDK thì chương trình lưu vào bộ nhớ Flash.

### 4. Linker
(Liên kết các file main.o, build lại thành file main.exe)

`gcc main.o test.o -o main`

`./main`

## II. Marcro

> Macro là những từ chỉ thông tin xử lý, xảy ra ở quá trình tiền xử lý `#include`, `#define`, `#ifndef`, `#if`,...

### 1. Macro chỉ thị bao hàm tệp

- #include< >: Tìm file trong thư mục cài đặt.

- #include" ": Tìm file trong thư mục hiện tại.

### 2. Macro chỉ thị định nghĩa

- #define: Định nghĩa 1 đối tượng(biến, hàm, mảng)

_VD1: Define trên nhiều dòng_ 

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
  #define sum(...) __VA_ARGS__  \
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

- **Tại sao sử dụng do...while(0)?**

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

</details>

<details>
  <summary><h3>Bài 3: Bitmask</h3></summary>

</details>

<details>
  <summary><h3>Bài 4: Pointer</h3></summary>

</details>

<details>
  <summary><h3>Bài 5: Storage Classes</h3></summary>

</details>

<details>
  <summary><h3>Bài 6: Goto - Setjmp</h3></summary>

</details>
