module com.example.homework1 {
    requires javafx.controls;
    requires javafx.fxml;


    opens Problem1 to javafx.fxml;
    exports Problem1;
    opens Problem2 to javafx.fxml;
    exports Problem2;
}