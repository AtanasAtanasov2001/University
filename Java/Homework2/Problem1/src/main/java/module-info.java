module com.example.homework2 {
    requires javafx.controls;
    requires javafx.fxml;


    opens Problem1 to javafx.fxml;
    exports Problem1;
}