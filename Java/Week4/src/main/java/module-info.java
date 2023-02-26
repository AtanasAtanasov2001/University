module com.example.week4 {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.week4 to javafx.fxml;
    exports com.example.week4;
}