## Quản lí vé máy bay
1.  Cấu hình:
Vào file "config.h" thay đổi giá trị các biến cho phù hợp với máy.
2. Khi chạy có lựa chọn 1, sẽ mở ra Notepad, cách nhập như sau, theo định dạng theo CSV:
* Khi các truy vấn có trả về kết quả như SELECT,... thì cách gõ như sau: 
[TÊN TABLE], [CÂU LỆNH]
Lưu ý có dấu ',', nếu không có sẽ chạy sai, và đúng tên BẢNG
* Khi các truy vấn không có trả về kết quả như INSERT, ALTER, UPDATE,... thì gõ như sau:
[NONE], [TABLE]
Lưu ý: 'NONE' viết hoa cả từ
* Có thể chứa nhiều câu lệnh, mỗi câu lệnh cách nhau bởi xuống hàng mới.
Ví dụ: 
MAYBAY, SELECT * FROM MAYBAY
NONE, INSERT MAYBAY VALUES(....)
* Sau khi nhập xong, lưu lại như bình thường, truy vấn sẽ được chạy ngay sau khi cửa sổ Notepad đóng lại.
3. Code có thể còn có BUG, với có thể tự do sửa theo ý thích
4. Các class khi định nghĩa, mỗi trường ('field') đều có 2 hàm kèo theo là: set, get. Chỉ nhằm mục đích đóng gói dữ liệu, kiểm soát được dữ liệu. Nhưng chưa có hàm nào dùng, nên có xóa nếu thấy dài hoặc rối.