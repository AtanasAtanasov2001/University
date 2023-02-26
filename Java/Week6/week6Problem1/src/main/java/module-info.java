module com.example.week6problem1 {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.week6problem1 to javafx.fxml;
    exports com.example.week6problem1;
}