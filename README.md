# Bank Account Management System

## Giới thiệu

Đây là chương trình quản lý tài khoản ngân hàng đơn giản được xây dựng bằng ngôn ngữ C++ theo mô hình lập trình hướng đối tượng (OOP).

Chương trình cho phép:

* Tạo tài khoản mới
* Nạp tiền vào tài khoản
* Rút tiền từ tài khoản
* Xem thông tin tài khoản
* Tìm kiếm tài khoản theo số tài khoản
* Hiển thị danh sách tất cả tài khoản
* Khóa và xóa tài khoản nếu thực hiện giao dịch sai quá 5 lần

---

## Cấu trúc thư mục

```text
bank-account-management/
├── README.md
├── src/
│   ├── main.cpp
│   ├── BankAccount.h
│   └── BankAccount.cpp
└── .gitignore
```

---

## Giải thích các file

### 1. BankAccount.h

Đây là file khai báo lớp (Class Declaration).

Chứa:

* Các thuộc tính của tài khoản:

  * Số tài khoản
  * Tên chủ tài khoản
  * Số dư
  * Số lần giao dịch sai

* Các hàm thành viên:

  * Nạp tiền
  * Rút tiền
  * Hiển thị thông tin
  * Kiểm tra khóa tài khoản

File này đóng vai trò là "bản thiết kế" của đối tượng BankAccount.

---

### 2. BankAccount.cpp

Đây là file cài đặt (Implementation File).

Chứa phần định nghĩa chi tiết cho các hàm đã khai báo trong `BankAccount.h`.

Ví dụ:

* Constructor
* deposit()
* withdraw()
* displayInfo()
* increaseFailedAttempts()
* resetFailedAttempts()
* isLocked()

File này xử lý toàn bộ logic liên quan đến tài khoản ngân hàng.

---

### 3. main.cpp

Đây là file chính của chương trình.

Chức năng:

* Hiển thị menu
* Nhận dữ liệu từ người dùng
* Quản lý danh sách tài khoản bằng `vector`
* Gọi các hàm từ lớp `BankAccount`
* Thực hiện các chức năng:

  * Tạo tài khoản
  * Nạp tiền
  * Rút tiền
  * Tìm kiếm tài khoản
  * Hiển thị danh sách tài khoản

Chương trình bắt đầu thực thi từ hàm:

```cpp
int main()
```

---

## Invariant của chương trình

Các điều kiện luôn được đảm bảo:

* Số dư không được âm.
* Số tiền nạp phải lớn hơn 0.
* Số tiền rút phải lớn hơn 0.
* Không được rút vượt quá số dư hiện có.
* Sau 5 lần giao dịch sai liên tiếp, tài khoản sẽ bị khóa và xóa khỏi hệ thống.

---

## Cách biên dịch chương trình

### Bước 1: Mở Terminal hoặc PowerShell

Di chuyển tới thư mục gốc của dự án:

```bash
cd bank-account-management
```

### Bước 2: Biên dịch

```bash
g++ src/main.cpp src/BankAccount.cpp -o bank
```

Hoặc trên Windows:

```bash
g++ src/main.cpp src/BankAccount.cpp -o bank.exe
```

Sau khi biên dịch thành công sẽ tạo ra file:

```text
bank.exe
```

---

## Cách chạy chương trình

Trên Windows:

```bash
.\bank.exe
```

Hoặc:

```bash
bank.exe
```

Trên Linux/macOS:

```bash
./bank
```

---
