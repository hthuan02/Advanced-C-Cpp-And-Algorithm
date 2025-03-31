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
> Macro `#include`, `#define` thì bị thay thế, còn lại giữ nguyên.

### 2. Complier
(chuyển file.i thành file.s)

> Tạo ra file hợp ngữ
>
> Thao tác trên RAM mượt mà hơn

### 3. Assembler
(chuyển file.s thành file.o)

> Source code chuyển thành các đoạn mã 0 1(ngôn ngữ máy)
>
> Nếu code trên VDK thì chương trình lưu vào bộ nhớ Flash

### 4. Linker
(Liên kết các file.o, build lại thành file.exe)

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

- ##: Gộp(nhóm) các chuỗi

_VD2:_

```c
  #define merge(x,y) x##y //xy
```

- #: Chuyển kí tự -> chuỗi

_VD3_
```c
  #define CREATE_FUNC(cmd) prinf(#cmd) // # Hỗ trợ chuẩn hóa vb thành chuỗi
```

- Variadic: Cho phép 1 hàm có thể nhận số lượng tham số truyền vào không xác định.

_VD4:_
```c
  #define sum(...) __VA_ARGS__ 
```

```c
  #define sum(...)                    \
  do {                                \
      int arr[] = {__VA_ARGS__, 0};   \
      int tong = 0;                   \
      int i = 0;                      \
      while (arr[i] != 0) {           \
          tong += arr[i];             \
          i++;                        \
      }                               \
      printf("Tong = %d\n", tong);    \
  } while (0)                         
```

- `__VA_ARGS__`: Là những giá trị đưa vào mảng.
- `0`: Là dấu hiệu kết thúc chuỗi.

### 3. Macro chỉ thị biên dịch có điều kiện

- #ifdef, #ifndef: Kiểm tra xem 1 macro có định nghĩa hay chưa

    - #ifdef: Nếu đã định nghĩa -->> thực thi chương trình
 
    - #ifndef: Nếu chưa định nghĩa -->> thì định nghĩa --> thực thi

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
