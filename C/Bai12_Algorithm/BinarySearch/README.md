#### Binary Search

- Sắp xếp mảng từ bé đến lớn

- Đặt 2 biến Left(ở đâu) và Right(ở cuối)

- Đặt Mid = (Left + Right)/2, so sánh Mid

    - Mid = Giá trị tìm kiếm -> Trả về kết quả

    - Mid > Giá trị tìm kiếm
      
        + Tìm kiếm mảng sau Mid (Phải)

        + Lặp lại đến khi tìm được giá trị

    - Mid < Giá trị tìm kiếm

        + Tìm kiếm mảng trước Mid(Trái)

        + Lặp lại 

