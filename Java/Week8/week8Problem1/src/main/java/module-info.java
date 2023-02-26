module com.example.week8 {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.week8 to javafx.fxml;
    exports com.example.week8;
}