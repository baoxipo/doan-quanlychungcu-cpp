# Đồ án tin học 

## Giới thiệu 

Đồ án tin học về mô phỏng chương trình quản lý chung cư ra màn hình console (không có giao diện đồ họa). Đồ án mô phỏng chính vào cách vận hành của chương trình bằng cấu trúc danh sách liên kết đơn (không dù thư viện cấu trúc có sẵn như Vector hay Array để lưu trữ)

---  

## Thông tin đồ án 

- Tác giả      : Trần Minh Gia Bảo
- Ngày bắt đầu : 14/10/2026
- Hạn nộp      : Cuối học kỳ 1  
- Đề tài       : Quản lý chung cư C++ Console

---

## Tìm hiểu về nghiệp vụ 

- Chương trình dùng để quản lý căn hộ, cư dân và hóa đơn trong chung cư
- Lần đầu chạy chương trình sẽ tạo dữ liệu mẫu và lưu vào thư mục data
- Những lần sau chương trình sẽ nạp dữ liệu từ file trước khi vào menu
- Mỗi căn hộ có tên, tầng, trạng thái, danh sách cư dân và danh sách hóa đơn
- Người dùng có thể thêm, xóa, sửa tên hoặc tầng căn hộ và không được đặt trùng tên căn hộ
- Người dùng có thể xem danh sách căn hộ, xem chủ hộ hoặc xem thông tin chi tiết
- Người dùng có thể thêm cư dân vào căn hộ, nếu đã có chủ hộ thì hỏi có muốn thêm người mới làm thành viên không
- Người dùng có thể chuyển toàn bộ cư dân sang căn hộ khác và chọn cách xử lý khi căn hộ đó đã có cư dân
- Người dùng có thể tìm căn hộ theo tên căn hộ, tên chủ hộ hoặc CCCD chủ hộ
- Người dùng có thể lọc căn hộ theo tầng hoặc trạng thái và sắp xếp theo tên
- Hóa đơn căn hộ gồm tiền quản lý, tiền điện, tiền nước, tiền gửi xe và trạng thái thanh toán
- Người dùng có thể xem hóa đơn và tạo hóa đơn tháng hiện tại cho căn hộ có cư dân
- Người dùng có thể đánh dấu hóa đơn đã thanh toán và xem hóa đơn đã đóng hoặc chưa đóng
- Chương trình có chức năng thống kê căn hộ, cư dân theo tầng và doanh thu đã thu hoặc còn nợ

---

## Menu 10 tính năng theo yêu cầu của giảng viên 

Giảng viên yêu cầu (Thêm, Xóa, Sửa) là 1 tính năng 

Menu 10 tính năng cơ bản của chương trình
- 1 Quản lý căn hộ (thêm / xóa / sửa)
- 2 Hiển thị danh sách căn hộ
- 3 Thêm cư dân mới vào căn hộ (thêm theo số lượng)
- 4 Chuyển cư dân đi (xóa cư dân khỏi căn hộ cũ và thêm vào căn hộ mới)
- 5 Tìm kiếm căn hộ theo cư dân
- 6 Lọc căn hộ
- 7 Sắp xếp căn hộ
- 8 Tạo và xem hóa đơn hàng tháng
- 9 Thu phí (đánh dấu đã đóng)
- 10 Thống kê

---

## Cấu trúc 

Cấu trúc thư mục đầy đủ của dự án

```txt
    📁 QuanLyChungCu
    ├── 📁 data/
    ├── 📁 src/
    │   ├── 📁 lib/
    │   │   ├── ⚡ canho.h
    │   │   ├── ⚡ cudan.h
    │   │   ├── ⚡ hamphu.h
    │   │   ├── ⚡ hoadon.h
    │   │   ├── ⚡ includetatca.h
    │   │   ├── ⚡ menuvahamxuly.h
    │   │   ├── ⚡ saoluuvanapdulieu.h
    │   │   ├── ⚡ thongke.h
    │   │   └── ⚡ thuvienchung.h
    │   ├── ⚡ canho.cpp
    │   ├── ⚡ cudan.cpp
    │   ├── ⚡ hamphu.cpp
    │   ├── ⚡ hoadon.cpp
    │   ├── ⚡ main.cpp
    │   ├── ⚡ menuvahamxuly.cpp
    │   ├── ⚡ saoluuvanapdulieu.cpp
    │   └── ⚡ thongke.cpp
    ├── ⚙️ .gitignore
    ├── 📄 LICENSE
    ├── 📝 README.md
    └── ⚡ run.cpp
``` 

---

## Mô phỏng 

Mô phỏng quy trình vận hành của danh sách liên kết đơn 
Bên trong node có danh sách liên kết con là danh sách của thành viên trong căn hộ và danh sách hóa đơn của căn hộ đó 
```txt
head
  │
  ▼
┌───────────────────────┐      ┌───────────────────────┐      ┌───────────────────────┐      ┌───────────────────────┐
│                       │      │                       │      │                       │      │                       │
│                       │      │                       │      │                       │      │                       │
│ [ |*]-->[ |*]--> NULL │─────>│ [ |*]-->[ |*]--> NULL │─────>│ [ |*]-->[ |*]--> NULL │─────>│ [ |*]-->[ |*]--> NULL │─────> NULL
│                       │      │                       │      │                       │      │                       │
│                       │      │                       │      │                       │      │                       │
└───────────────────────┘      └───────────────────────┘      └───────────────────────┘      └───────────────────────┘
         Node 1                         Node 2                         Node 3                         Node 4
```

---

## Quy trình vận hành 

Khi chạy chương trình lần đầu (chưa có dữ liệu)
   - Chương trình sẽ lấy dữ liệu mẫu có sẵn ghi vào file trong folder `data/`
   - Cấu trúc thư mục `data/` bao gồm:
      ```txt
           📁 data
              ├── 📁 A101
              │   ├── 📄 canho.txt
              │   ├── 📄 cudan.txt
              │   └── 📄 hoadon.txt
              ├── 📁 A102
              │   ├── 📄 canho.txt
              │   ├── 📄 cudan.txt
              │   └── 📄 hoadon.txt
              ├── 📁 A...
      ```
      - Các folder con (mỗi folder con là mỗi folder của 1 căn hộ theo tên căn hộ)
      - Trong folder con chứa các file.txt về căn hộ, cư dân (thành viên), hóa đơn
   - Từ lần 2 khi chạy chương trình sẽ load dữ liệu từ file lên
   - Chương trình không có tính năng sao lưu, vì tích hợp sẵn tự động sao lưu sau mỗi thao tác (tránh trường hợp không sao lưu làm mất dữ liệu), đây cũng là tính năng mà hầu hết các app quản lý hay các ứng dụng đều có để bảo toàn dữ liệu 
   - Khi chạy xong chương trình sẽ gọi đến các hàm `GiaiPhong` để trả vùng nhớ cho `Ram` tránh `rò rĩ bộ nhớ`

---

- Với danh sách cư dân chỉ tính trong 1 phòng (căn)
- Với danh sách căn hộ sẽ chứa trong đó 1 danh sách cư dân 
- Không có danh sách liên kết tất cả thành viên trong chung cư với nhau
> Nghĩa là danh sách căn hộ là danh sách chính liên kết nhiều căn hộ với nhau, trong mỗi căn hộ sẽ có danh sách dân cư (là gia đình/thành viên) của căn hộ đó, và bên trong căn hộ còn có danh sách của hóa đơn (nhiều hóa đơn của nhiều tháng liên kết với nhau)

---

## Ưu và nhược điểm 

**Ưu điểm**
- Có coding convention rõ ràng (tên biến, hàm, dễ đọc hiểu)
- Phân chia các module rõ ràng dễ bảo trì sau này 
- Chống nhập sai nhiều lớp 

**Nhược điểm**

- Chưa tối ưu và tinh gọn code
- Một vài output khi thoát sẽ mặc định không tự động
- Code bị lặp nhiều chổ (như là so sánh với NULL)

---

## Tác giả 

**Trần Minh Gia Bảo**<br>
**Nguyễn Trường Chinh (đóng góp)**<br>
**GitHub:** [https://github.com/baoxipo](https://github.com/baoxipo)<br>
**GitHub:** [https://github.com/Interstellar-OS](https://github.com/Interstellar-OS)<br>