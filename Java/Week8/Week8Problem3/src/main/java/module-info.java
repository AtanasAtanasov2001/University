module com.example.week8problem3 {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.week8problem3 to javafx.fxml;
    exports com.example.week8problem3;
}