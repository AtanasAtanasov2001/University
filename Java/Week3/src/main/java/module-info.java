module com.example.week3 {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.week3 to javafx.fxml;
    exports com.example.week3;
}